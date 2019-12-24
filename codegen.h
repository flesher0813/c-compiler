#ifndef __CODEGEN_H__
#define __CODEGEN_H__
#include <stack>
#include<vector>
#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Bitcode/BitstreamReader.h>
#include <llvm/Bitcode/BitstreamWriter.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include "node.h"
#include "parser.hpp"
#include "TypeStream.h"
using namespace llvm;
using std::cout;
using std::endl;

static LLVMContext MyContext;

class CodeGenBlock{
	public:
		BasicBlock* block;
		std::map<std::string, Value*> locals;
		std::map<string, shared_ptr<Identifier>> types;
		Value *returnValue;
		std::map<string, bool> isFuncArg;
		std::map<string, std::vector<uint64_t>> arraySizes;
};

class CodeGenContext{
	std::vector<CodeGenBlock *> blocks;
	Function *mainFunction;

	public:
		TypeStream typeSystem;
		IRBuilder<> builder;
		Module* module;
		CodeGenContext(): builder(MyContext), typeSystem(MyContext){  module = new Module("main",MyContext); }
		void generateCode(Block& root);
		GenericValue runCode();	
		std::map<std::string, Value*>& locals() { return blocks.back()->locals; }
		BasicBlock* currentBlock() { return blocks.back()->block; }
		void pushBlock(BasicBlock* block){ blocks.push_back( new CodeGenBlock() ); blocks.back()->block = block; blocks.back()->returnValue = NULL; }
		void popBlock() { CodeGenBlock *block = blocks.back(); blocks.pop_back(); delete block; }
		Value* getCurrentValue() { return blocks.back()->returnValue; }
		void setReturnValue(Value *value) { blocks.back()->returnValue = value; }
		Value* getSymbolValue(string name) const{
			for(auto it=blocks.rbegin(); it!=blocks.rend(); it++){
				if( (*it)->locals.find(name) != (*it)->locals.end() ){
					return (*it)->locals[name];
					}
			}
       			 return nullptr;
		}
		shared_ptr<Identifier> getSymbolType(string name) const{
			for(auto it=blocks.rbegin(); it!=blocks.rend(); it++){
				if( (*it)->types.find(name) != (*it)->types.end() ){
					return (*it)->types[name];
					}

			}
       			 return nullptr;
		}
		void setSymbolValue(string name,Value* value) {
			blocks.back()->locals[name] = value;

		}
		void setSymbolType(string name,shared_ptr<Identifier> value) {
			blocks.back()->types[name] = value;

		}
		bool isFuncArg(string name) const{
        		for(auto it=blocks.rbegin(); it!=blocks.rend(); it++){
          	 	 if( (*it)->isFuncArg.find(name) != (*it)->isFuncArg.end() ){
               			 return (*it)->isFuncArg[name];
          			  }
       			 }
       			 return false;
		}
		void setFuncArg(string name,bool value){
			cout << "Set " << name << " as func arg" << endl;
			blocks.back()->isFuncArg[name] = value;
		}
		void setArraySize(string name, std::vector<uint64_t> value){
			cout << "1111111111111111111111111111111111111111111111111111111111111setArraySize: " << name << ": " << value.size() << endl;
			blocks.back()->arraySizes[name] = value;
		}
		std::vector<uint64_t> getArraySize(string name){
			for(auto it=blocks.rbegin(); it!=blocks.rend(); it++){
            			if( (*it)->arraySizes.find(name) != (*it)->arraySizes.end() ){
					return (*it)->arraySizes[name];
            			}
       			}
        		return blocks.back()->arraySizes[name];
		}


};

Value* LogErrorV(const char* str);
Value* LogErrorV(string str);
#endif
