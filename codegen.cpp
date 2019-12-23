#include "codegen.h"
#define ISTYPE(value, id) (value->getType()->getTypeID() == id)

using namespace std;

static Value* CastToBoolean(CodeGenContext& context,Value* condValue){
	if( ISTYPE(condValue, Type::IntegerTyID) ){
		condValue = context.builder.CreateIntCast(condValue, Type::getInt1Ty(MyContext), true);
		return context.builder.CreateICmpNE(condValue, ConstantInt::get(Type::getInt1Ty(MyContext), 0, true));

    }else if( ISTYPE(condValue, Type::DoubleTyID) ){
		return context.builder.CreateFCmpONE(condValue, ConstantFP::get(MyContext, APFloat(0.0)));
    }else{

	return condValue;

    }

}

static Value* calcArrayIndex(shared_ptr<ArrayIndex> index, CodeGenContext &context){
    auto sizeVec = context.getArraySize(index->arrayName.name);
    cout << "sizeVec:" << sizeVec.size() << ", expressions: " << index->arrayList->size() << endl;
    assert(sizeVec.size() > 0 && sizeVec.size() == index->arrayList->size());

    auto expression = *(index->arrayList->rbegin());

    for(unsigned int i=sizeVec.size()-1; i>=1; i--){
        auto temp = make_shared<BinaryExpression>(make_shared<IntExpression>(sizeVec[i]), MUL, index->arrayList->at(i-1));
        expression = make_shared<BinaryExpression>(temp, ADD, expression);
    }
    return expression->codeGen(context);
}

void CodeGenContext::generateCode(Block& root){
	std::cout<<"Generating code...\n";

	std::vector<Type*> argTypes;
	FunctionType *FT = FunctionType::get(Type::getVoidTy(MyContext), makeArrayRef(argTypes), false);
	Function *mainFunction = Function::Create(FT, GlobalValue::InternalLinkage, "main", module);
	BasicBlock* rootBlock = BasicBlock::Create(MyContext,"entry",mainFunction,0);

//genarating
	pushBlock(rootBlock);
	root.codeGen(*this);
	ReturnInst::Create(MyContext,rootBlock);
	popBlock();

	std::cout<<"Code Generated...\n";

//pass youhuaxiangguan
	legacy::PassManager pm;
	pm.add(createPrintModulePass(outs()));
	pm.run(*module);
	return;
}

GenericValue CodeGenContext::runCode(){
	std::cout<<"Running code...\n";
	ExecutionEngine* ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
	ee->finalizeObject();
	std::vector<GenericValue> args;
	GenericValue v = ee->runFunction(mainFunction,args);
	std::cout<<"Code was Run...\n";
	return v;
}

static Type* typeOf(const Identifier& type,CodeGenContext& context){
	return context.typeSystem.getVarType(type);
}

Value* IntExpression::codeGen(CodeGenContext& context){
	std::cout<<"Creating Int: "<<value<<"\n";
	return ConstantInt::get(Type::getInt64Ty(MyContext),value);

}

Value* DoubleExpression::codeGen(CodeGenContext& context){
	std::cout<<"Creating Double: "<<value<<"\n";
	return ConstantFP::get(Type::getDoubleTy(MyContext),value);
}

Value* Identifier::codeGen(CodeGenContext& context){
	std::cout << "Creating identifier reference: " << name << endl;
	Value* value = context.getSymbolValue(name);
	if (!value) {
		return LogErrorV("Unknown variable name " + name);
	}

	if( value->getType()->isPointerTy() ){
		auto arrayPtr = context.builder.CreateLoad(value, "arrayPtr");
		if( arrayPtr->getType()->isArrayTy() ){
		cout << "(Array Type)" << endl;

//            arrayPtr->setAlignment(16);
		std::vector<Value*> indices;
		indices.push_back(ConstantInt::get(context.typeSystem.intTy, 0, false));
		auto ptr = context.builder.CreateInBoundsGEP(value, indices, "arrayPtr");
		return ptr;

        }

    }
	return context.builder.CreateLoad(value, false, "");
}

Value* AssignExpression::codeGen(CodeGenContext& context){
	std::cout << "Creating assignment for " << lhr.name << endl;
	Value* meValue = context.getSymbolValue(lhr.name);
	auto meType = context.getSymbolType(lhr.name);
	if (!meValue) {
		std::cerr << "undeclared variable " << lhr.name << "\n";
		return NULL;
	}
	Value* e = rhr.codeGen(context);
	context.typeSystem.cast(e,context.typeSystem.getVarType(meType->name),context.currentBlock());
	context.builder.CreateStore(e, meValue);
	return meValue;
}

Value* BinaryExpression::codeGen(CodeGenContext& context){
	printf("Creating binary operation: %d\n",op);
	Value* L = lhr->codeGen(context);
	Value* R = rhr->codeGen(context);
	bool fp = false;
	if(L->getType()->getTypeID() == Type::DoubleTyID || R->getType()->getTypeID() == Type::DoubleTyID){
		fp = true;
		if(R->getType()->getTypeID() != Type::DoubleTyID)
			R = context.builder.CreateUIToFP(R, Type::getDoubleTy(MyContext), "ftmp");
		else if(L->getType()->getTypeID() != Type::DoubleTyID)
			L = context.builder.CreateUIToFP(L, Type::getDoubleTy(MyContext), "ftmp");

	}
	switch (op) {
		case ADD: 	return fp ? context.builder.CreateFAdd(L, R, "addftmp") : context.builder.CreateAdd(L, R, "addtmp");
		case SUB: 	return fp ? context.builder.CreateFSub(L, R, "subftmp") : context.builder.CreateSub(L, R, "subtmp");
		case MUL: 	return fp ? context.builder.CreateFMul(L, R, "mulftmp") : context.builder.CreateAdd(L, R, "multmp");
		case DIV: 	return fp ? context.builder.CreateFDiv(L, R, "divftmp") : context.builder.CreateAdd(L, R, "divtmp");
		default:
			return LogErrorV("Unknown binary operator");
				
	}

}

Value* CallExpression::codeGen(CodeGenContext& context){

	Function *CalleeF = context.module->getFunction(callee.name);
	if ( CalleeF == NULL){
		LogErrorV("Function name not found");
	}

	std::vector<Value*> ArgsV;
	ExpressionList::const_iterator it;
	for( it = arguments.begin(); it != arguments.end(); it++){
		ArgsV.push_back((**it).codeGen(context));
	}

	std::cout << "Creating method call: " << callee.name << endl;
	return context.builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

Value* Block::codeGen(CodeGenContext& context){

	StateList::const_iterator it;
	Value *last = NULL;
	printf("got in block\n");
	for( it = statements.begin(); it != statements.end(); it++){
		std::cout << "Generating code for " << typeid(**it).name() << endl;
		last = (**it).codeGen(context);
	}
	std::cout << "Creating block\n";
	return last;
}

Value* ExpressionStatement::codeGen(CodeGenContext& context){
	std::cout << "Generating code for " << typeid(exp).name() << endl;
	return exp.codeGen(context);
	
}

Value* ReturnStatement::codeGen(CodeGenContext& context){
	std::cout << "Generating return code for " << typeid(exp).name() << endl;
	Value *returnValue = exp.codeGen(context);
	context.setReturnValue(returnValue);
	return returnValue;
	
}

Value* VariableDecration::codeGen(CodeGenContext& context){
	std::cout<<"Creating variable declaration: type = " << type->name << ", id = " << id.name << "\n";
	Type* meType = typeOf(*type,context);
	Value* inst = nullptr;

	if( type->isArray ){
		uint64_t arraySize = 1;
		std::vector<uint64_t> arraySizes;
		for(auto it= type->arraySize->begin(); it!=type->arraySize->end(); it++){
			IntExpression* integer = dynamic_cast<IntExpression*>(it->get());
			arraySize *= integer->value;
			arraySizes.push_back(integer->value);
        }

        context.setArraySize(id.name, arraySizes);
        Value* arraySizeValue = IntExpression(arraySize).codeGen(context);
        auto arrayType = ArrayType::get(context.typeSystem.getVarType(type->name), arraySize);
        inst = context.builder.CreateAlloca(arrayType, arraySizeValue, "arraytmp");
    }else{
	inst = context.builder.CreateAlloca(meType);
    }

	context.setSymbolType(id.name, type);
	context.setSymbolValue(id.name, inst);

	if (content != NULL){
		AssignExpression assignExpression(id,*content);
		assignExpression.codeGen(context);
		}
	return inst;
}

Value* FuncStatement::codeGen(CodeGenContext& context){
	std::vector<Type*> argTypes;
	for(auto &arg: arguments){
		if( arg->type->isArray ){
			argTypes.push_back(PointerType::get(context.typeSystem.getVarType(arg->type->name), 0));
       		 } else{
			argTypes.push_back(typeOf(*arg->type, context));
			}
	}
	Type *retType = nullptr;
	if( type.isArray )
		retType = PointerType::get(context.typeSystem.getVarType(type.name), 0);
	else
		retType = typeOf(type, context);


	FunctionType *FT = FunctionType::get(retType, makeArrayRef(argTypes), false);
	Function *function = Function::Create(FT, GlobalValue::ExternalLinkage, id.name, context.module);

	if( !this->isExternal ){
		BasicBlock* basicBlock = BasicBlock::Create(MyContext, "entry", function, nullptr);
		context.builder.SetInsertPoint(basicBlock);
		context.pushBlock(basicBlock);
		auto origin_arg = this->arguments.begin();
		for(auto &ir_arg_it: function->args()){
			ir_arg_it.setName((*origin_arg)->id.name);
			Value* argAlloc;
			if( (*origin_arg)->type->isArray )
				argAlloc = context.builder.CreateAlloca(PointerType::get(context.typeSystem.getVarType((*origin_arg)->type->name), 0));
			else
				argAlloc = (*origin_arg)->codeGen(context);

			context.builder.CreateStore(&ir_arg_it, argAlloc, false);
			context.setSymbolValue((*origin_arg)->id.name, argAlloc);
			context.setSymbolType((*origin_arg)->id.name, (*origin_arg)->type);
			context.setFuncArg((*origin_arg)->id.name, true);
			origin_arg++;
		}

		this->block.codeGen(context);
		if( context.getCurrentValue() ){
			context.builder.CreateRet(context.getCurrentValue());
		} else{
			return LogErrorV("Function block return value not founded");
			}
		context.popBlock();
	}

	return function;

}

Value* IfStatement::codeGen(CodeGenContext& context){
	std::cout<< "Generating if statement\n";
	Value* conValue = condition->codeGen(context);
	if (!conValue){
		return nullptr;
	}

	conValue = CastToBoolean(context,conValue);
	cout<<"testing 1\n";
	Function* theFunction = context.builder.GetInsertBlock()->getParent();
	cout<<"testing 2\n";

	BasicBlock *conditionB = BasicBlock::Create(MyContext, "then", theFunction);
	BasicBlock *falseB = BasicBlock::Create(MyContext, "false");
	BasicBlock *trueB = BasicBlock::Create(MyContext, "true");

	if (falseBlock){
		context.builder.CreateCondBr(conValue, conditionB, falseB);
	}
	else
		context.builder.CreateCondBr(conValue, conditionB, trueB);

	context.builder.SetInsertPoint(conditionB);
	context.pushBlock(conditionB);
	trueBlock->codeGen(context);
	context.popBlock();
	
	conditionB = context.builder.GetInsertBlock();

	if( conditionB->getTerminator() == nullptr ){
		context.builder.CreateBr(trueB);
	}

	if( this->falseBlock ){
        	theFunction->getBasicBlockList().push_back(falseB);
		context.builder.SetInsertPoint(falseB);
        	context.pushBlock(conditionB);
		falseBlock->codeGen(context);
		context.popBlock();
		context.builder.CreateBr(trueB);

    }
	theFunction->getBasicBlockList().push_back(trueB);        //
	context.builder.SetInsertPoint(trueB);        //
	return nullptr;
}

Value* ForStatement::codeGen(CodeGenContext &context) {
	Function* theFunction = context.builder.GetInsertBlock()->getParent();
	BasicBlock *block = BasicBlock::Create(MyContext, "forloop", theFunction);
	BasicBlock *after = BasicBlock::Create(MyContext, "forcont");

	if( initial )
		initial->codeGen(context);
	Value* condValue = condition->codeGen(context);
	if( !condValue )
		return nullptr;

	condValue = CastToBoolean(context,condValue);
	context.builder.CreateCondBr(condValue, block, after);
	context.builder.SetInsertPoint(block);
	context.pushBlock(block);
	forBlock->codeGen(context);
	context.popBlock();

	if( this->increment ){
		increment->codeGen(context);
    	}
	condValue = condition->codeGen(context);
	condValue = CastToBoolean(context,condValue);
	context.builder.CreateCondBr(condValue, block, after);

	theFunction->getBasicBlockList().push_back(after);
	context.builder.SetInsertPoint(after);
	return nullptr;
}

Value* ArrayIndex::codeGen(CodeGenContext &context) {
	cout << "Generating array index expression of " << arrayName.name << endl;
	auto varPtr = context.getSymbolValue(arrayName.name);
	auto type = context.getSymbolType(arrayName.name);
	string typeStr = type->name;
	assert(type->isArray);

	auto value = calcArrayIndex(make_shared<ArrayIndex>(*this), context);
	if(context.isFuncArg(arrayName.name) ){
		std::cout << "isFuncArg\n";
		varPtr = context.builder.CreateLoad(varPtr, "actualArrayPtr");
		ArrayRef<Value*> indices = {value};
		auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "elementPtr");
		return context.builder.CreateAlignedLoad(ptr, 4);

    }else if( varPtr->getType()->isPointerTy() ){
	cout << arrayName.name << "Not isFuncArg\n";
        ArrayRef<Value*> indices = {ConstantInt::get(Type::getInt64Ty(MyContext), 0), value};
	auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "elementPtr");
	return context.builder.CreateAlignedLoad(ptr, 4);
    }else{
        return LogErrorV("The variable is not array");
    }

}

Value *ArrayAssignment::codeGen(CodeGenContext &context) {
	cout << "Generating array index assignment of " << arrayIndex->arrayName.name << endl;
	auto varPtr = context.getSymbolValue(arrayIndex->arrayName.name);

	if( varPtr == nullptr ){
		return LogErrorV("Unknown variable name");
	}

	auto arrayPtr = context.builder.CreateLoad(varPtr, "arrayPtr");

	if( !arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy() ){
        	return LogErrorV("The variable is not array");
	}

//    std::vector<Value*> indices;

	auto index = calcArrayIndex(arrayIndex, context);

//    cout << "here2" << endl;
	ArrayRef<Value*> gep2_array{ ConstantInt::get(Type::getInt64Ty(MyContext), 0), index };
	auto ptr = context.builder.CreateInBoundsGEP(varPtr, gep2_array, "elementPtr");

	return context.builder.CreateAlignedStore(expression.codeGen(context), ptr, 4);

}

Value *ArrayInitialization::codeGen(CodeGenContext &context) {
    cout << "Generating array initialization of " << declaration.id.name << endl;
    auto arrayPtr = declaration.codeGen(context);
    auto sizeVec = context.getArraySize(declaration.id.name);
    assert(sizeVec.size() == 1);
    for(int index=0; index < expressionList.size(); index++){
        shared_ptr<IntExpression> indexValue = make_shared<IntExpression>(index);
        shared_ptr<ArrayIndex> arrayIndex = make_shared<ArrayIndex>(declaration.id, indexValue);
        ArrayAssignment assignment(arrayIndex, *expressionList.at(index));
        assignment.codeGen(context);
    }

    return nullptr;

}



Value* Literal::codeGen(CodeGenContext &context) {
    return context.builder.CreateGlobalString(value, "string");
}

std::unique_ptr<Expression> LogError(const char *str) {
    fprintf(stderr, "LogError: %s\n", str);
    return nullptr;
}


Value *LogErrorV(string str){
    return LogErrorV(str.c_str());
}



Value *LogErrorV(const char *str) {
    LogError(str);
    return nullptr;
}
