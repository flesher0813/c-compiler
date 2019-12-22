#ifndef TINYCOMPILER_TYPESYSTEM_H
#define TINYCOMPILER_TYPESYSTEM_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <string>
#include <map>
#include <vector>
#include "node.h"
using std::string;
using namespace llvm;

using TypeNamePair = std::pair<string,string>;

class TypeStream{
	LLVMContext& context;
	std::map<Type*,std::map<Type*,CastInst::CastOps>> _castTable;
	void addCast(Type* from,Type* to,CastInst::CastOps op);
public:
	Type* floatTy =Type::getFloatTy(context);
	Type* intTy =Type::getInt32Ty(context);
	Type* charTy =Type::getInt8Ty(context);
	Type* doubleTy =Type::getFloatTy(context);
	Type* stringTy = Type::getInt8PtrTy(context);
	Type* voidTy = Type::getVoidTy(context);
	Type* boolTy = Type::getInt1Ty(context);

	TypeStream(LLVMContext& context);
	
	Type* getVarType(const Identifier& value);
	Type* getVarType(string typeStr);

	Value* getDefaultValue(string typeStr,LLVMContext& context);
	Value* cast(Value* value,Type* type,BasicBlock* block);

	static string llvmTypeToString(Value* value);
	static string llvmTypeToString(Type* value);

};
#endif
