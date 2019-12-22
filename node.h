#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include<vector>
#include <memory>
#include<stdlib.h>
#include<string.h>
#include<llvm/IR/Value.h>
using std::shared_ptr;
using std::make_shared;
using std::string;

class Block;
class CodeGenContext;
class Expression;
class Statement;
class VariableDecration;

typedef std::vector<Expression*> ExpressionList;
typedef std::vector<Statement*> StateList;
typedef std::vector<VariableDecration*> VariableList;
typedef std::vector<shared_ptr<Expression>> NExpressionList;
class Node{
	public:
		~Node(){}
		virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

class Expression:public Node{
	public:
};

class Statement:public Node{
	public:
};

class IntExpression:public Expression{
	public:
		long long value;
		IntExpression(long long val):value(val){ }
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class DoubleExpression:public Expression{
	public:
		double value;
		DoubleExpression(double val):value(val){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Identifier:public Expression{
	public:
		std::string name;
		bool isType = false;
		bool isArray = false;
		shared_ptr<NExpressionList> arraySize = make_shared<NExpressionList>();

		Identifier(const std::string& na):name(na){ }
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class AssignExpression:public Expression{
	public:
		Identifier &lhr;
		Expression &rhr;
		AssignExpression(Identifier& lh,Expression& rh):lhr(lh),rhr(rh){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class BinaryExpression:public Expression{
	public:
		int op;
		shared_ptr<Expression> lhr;
		shared_ptr<Expression> rhr;
		BinaryExpression(shared_ptr<Expression> lh,int o,shared_ptr<Expression> rh):lhr(lh),op(o),rhr(rh){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};


class CallExpression:public Expression{
	public:
		const Identifier &callee;
		ExpressionList arguments;
		CallExpression(const Identifier &ca,ExpressionList &argv):callee(ca),arguments(argv){}
		CallExpression(const Identifier &ca):callee(ca){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ArrayIndex:public Expression{
	public:
		Identifier &arrayName;
		shared_ptr<NExpressionList> arrayList = make_shared<NExpressionList>();
		ArrayIndex(Identifier &arrayN,shared_ptr<NExpressionList> arrayL):arrayName(arrayN),arrayList(arrayL){}
		ArrayIndex(Identifier &arrayN,shared_ptr<Expression> arr):arrayName(arrayN){ arrayList->push_back(arr); }
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ArrayAssignment:public Expression{
	public:
		shared_ptr<ArrayIndex>arrayIndex;
		Expression& expression;
		ArrayAssignment(shared_ptr<ArrayIndex>arrayI,Expression& exp):arrayIndex(arrayI),expression(exp){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ArrayInitialization:public Statement{
	public:
		VariableDecration& declaration;
		ExpressionList expressionList;
		ArrayInitialization(VariableDecration& dec,ExpressionList exps):declaration(dec),expressionList(exps){}
		virtual llvm::Value* codeGen(CodeGenContext& context);

};

class Block:public Statement{
	public:
		StateList statements;
		Block(){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ExpressionStatement:public Statement{
	public:
		Expression &exp;
		ExpressionStatement(Expression &ex):exp(ex){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ReturnStatement:public Statement{
	public:
		Expression &exp;
		ReturnStatement(Expression &ex):exp(ex){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class IfStatement:public Statement{
	public:
		shared_ptr<Expression> condition;
		shared_ptr<Block> trueBlock;
		shared_ptr<Block> falseBlock;
		IfStatement(){}
		IfStatement(shared_ptr<Expression> cond,shared_ptr<Block> trueB,shared_ptr<Block> falseB = nullptr):condition(cond),trueBlock(trueB),falseBlock(falseB){}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ForStatement:public IfStatement{
	public:
		shared_ptr<Expression> initial,condition,increment;
		shared_ptr<Block> forBlock;
		ForStatement(shared_ptr<Block> forB,shared_ptr<Expression> init = nullptr,shared_ptr<Expression> cond = nullptr,shared_ptr<Expression> inc = nullptr):initial(init),condition(cond),increment(inc),forBlock(forB){
			if(condition == nullptr)
				condition = make_shared<IntExpression>(1);
	}
		virtual llvm::Value* codeGen(CodeGenContext& context);

};

class VariableDecration:public Statement{
	public:
		const shared_ptr<Identifier> type;
		Identifier& id;
		Expression* content;
		VariableDecration(const shared_ptr<Identifier> ty,Identifier& identity,Expression *cont = NULL):type(ty),id(identity),content(cont){
			assert(type->isType);
			assert(!type->isArray || (type->isArray && type->arraySize != nullptr));
		}
		virtual llvm::Value* codeGen(CodeGenContext& context);
};

class FuncStatement:public Statement{
	public:
		const Identifier& type;
		const Identifier& id;
		VariableList arguments;
		Block &block;
		bool isExternal;
		FuncStatement(const Identifier& ty,const Identifier& identity,const VariableList argv,Block &blo, bool Ext = false):type(ty),id(identity),arguments(argv),block(blo),isExternal(Ext){ assert(type.isType); }
		virtual llvm::Value* codeGen(CodeGenContext& context);

};

class Literal: public Expression{
public:
	string value;
	Literal(const string &str) {
        value = str.substr(1, str.length()-2);
    }

	llvm::Value *codeGen(CodeGenContext &context);

};
#endif
