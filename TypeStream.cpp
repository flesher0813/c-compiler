#include "TypeStream.h"
#include "codegen.h"
TypeStream::TypeStream(LLVMContext& context):context(context){
	addCast(intTy,floatTy,llvm::CastInst::SIToFP);
	addCast(intTy,doubleTy,llvm::CastInst::SIToFP);
	addCast(boolTy,doubleTy,llvm::CastInst::SIToFP);
	addCast(floatTy,doubleTy,llvm::CastInst::FPExt);
	addCast(floatTy,intTy,llvm::CastInst::FPToSI);
	addCast(doubleTy,intTy,llvm::CastInst::FPToSI);
}


Type* TypeStream::getVarType(string typeStr){
	if( typeStr.compare("int") == 0 ){
		return this->intTy;
	}
	else if( typeStr.compare("double") == 0 ){
		return this->doubleTy;
	}
	else if( typeStr.compare("float") == 0 ){
		return this->floatTy;
	}
	else if( typeStr.compare("char") == 0 ){
		return this->charTy;
	}
	else if( typeStr.compare("bool") == 0 ){
		return this->boolTy;
	}
	else if( typeStr.compare("void") == 0 ){
		return this->voidTy;
	}
	else if( typeStr.compare("string") == 0 ){
		return this->stringTy;
	}
	else
		return nullptr;
}

Type* TypeStream::getVarType(const Identifier& value){
	assert(value.isType);
	if(value.isArray){
		return PointerType::get(getVarType(value.name),0);
	}
	return getVarType(value.name);

}

Value* TypeStream::getDefaultValue(string typeStr, LLVMContext &context) {
	Type* type = this->getVarType(typeStr);
	if( type == this->intTy ){
		return ConstantInt::get(type, 0, true);
		}
	else if( type == this->doubleTy || type == this->floatTy ){
		return ConstantFP::get(type, 0);
		}
    return nullptr;
}

void TypeStream::addCast(Type* from,Type* to,CastInst::CastOps op){
	if(_castTable.find(from) == _castTable.end()){
		_castTable[from] = std::map<Type*,CastInst::CastOps>();
	}
	_castTable[from][to] = op;
}

Value* TypeStream::cast(Value* value,Type* type,BasicBlock* block){
	Type* from = value->getType();
	if(from == type) return value;
	if (_castTable.find(from) == _castTable.end()){
		return value;
	}
	if(_castTable[from].find(type) == _castTable[from].end()){
		return value;
	}
	return CastInst::Create(_castTable[from][type], value, type, "cast", block);
}

string TypeStream::llvmTypeToString(Type* value){
	Type::TypeID typeID;
	if (value){
		typeID = value->getTypeID();
	}
	else
		return "Value is nullptr";
	switch(typeID){
		case Type::VoidTyID:
			return "VoidTyID";
		case Type::IntegerTyID:
			return "IntegerTyID";
		case Type::FloatTyID:
			return "FloatTyID";
		case Type::DoubleTyID:
			return "DoubleTyID";
		case Type::ArrayTyID:
			return "ArrayTyID";
		case Type::PointerTyID:
			return "PointerTyID";
		default:
			return "Unknow Type";

	}

}

string TypeStream::llvmTypeToString(Value* value){
	if(value)
		return llvmTypeToString(value->getType());
	else
		return "Value is nullptr";
}

