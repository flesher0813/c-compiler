%{
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include"node.h"
Block *programBlock;
extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s\n", s); }
int changeToInt(char* str);
double changeToDouble(char* str);
%}

%union{
	Node* node;
	Block *block;
	Statement *stmt;
	Expression *expr;
	Identifier *ident;
	VariableList *varvec;
	ExpressionList *exprvec;
	VariableDecration *var_decl;
	std::string *str;
	int token;
};

%token<str> Int Float Double Long Short Signed Char Unsigned Auto Break Case Const Else For If Return
%token<str> INT DOUBLE ID
%token<token> EQ GT LT EQEQ GE LE NE
%token<token> LPAREN RPAREN LBRACE RBRACE LMBRA RMBRA
%token<token> ADD SUB MUL DIV
%token<token> SEMI DOT COMMA
%token<token> RETURN

%type<ident> type
%type<ident>  ident
%type<expr>  number expr
%type<varvec>  func_argv
%type<exprvec> call_argv
%type<block>  program stmts block
%type<stmt>  stmt var_decl func_decl
%type<token> comprison


%left ADD SUB
%left MUL DIV

%start program
%%
	program: stmts { programBlock = $1; }
                ;

	stmts:
                stmt { $$ = new Block();$$->statements.push_back($<stmt>1); }
                |
                stmts stmt { $1->statements.push_back($<stmt>2); }
                ;

	stmt:
		var_decl | func_decl
		| expr { $$ = new ExpressionStatement(*$1); }
		| RETURN expr { $$ = new ReturnStatement(*$2); }
                ;

	var_decl:
		type ident { $$ = new VariableDecration(shared_ptr<Identifier>($1),*$2);}
		| type ident EQ expr { $$ = new VariableDecration(shared_ptr<Identifier>($1),*$2,$4);}
		;

	func_decl:
		type ident LPAREN func_argv RPAREN block { $$ = new FuncStatement(*$1,*$2,*$4,*$6); delete $4;}
                ;

	block:
		LBRACE RBRACE { $$ = new Block(); }
		| LBRACE stmts RBRACE { $$ = $2; }
                ;

	func_argv: { $$ = new VariableList(); }
		| var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1);}
		| func_argv COMMA var_decl { $1->push_back($<var_decl>3); }
		;

	expr:
		ident EQ expr { $$ = new AssignExpression(*$<ident>1,*$3); }
		| ident LPAREN call_argv RPAREN { $$ = new CallExpression(*$1,*$3);delete $3; }
		| ident {$<ident>$ = $1;}
		| number
		| expr MUL expr { $$ = new BinaryExpression(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3) ); }
		| expr DIV expr { $$ = new BinaryExpression(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3) ); }
		| expr ADD expr { $$ = new BinaryExpression(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3) ); }
		| expr SUB expr { $$ = new BinaryExpression(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3) ); }
		| expr comprison expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3) ); }
		| LPAREN expr RPAREN { $$ = $2; }
		;

	call_argv:{  $$ = new ExpressionList(); }
		| expr { $$ = new ExpressionList(); $$->push_back($1);}
		| call_argv COMMA expr { $1->push_back($3); }
		;

	comprison:
		GT | LT | EQEQ | GE | LE | NE
		;
	ident:
		ID { $$ = new Identifier(*$1); delete $1; }
		;
	number:
		INT {  $$ = new IntExpression(atol($1->c_str()));delete $1; }
		| DOUBLE { $$ = new DoubleExpression(atof($1->c_str()));delete $1; }
		;

	type:
		Int {$$ = new Identifier(*$1);delete $1; }
		| Float {$$ = new Identifier(*$1);delete $1; }
		| Double {$$ = new Identifier(*$1);delete $1; }
		| Long {$$ = new Identifier(*$1);delete $1; }
		| Short {$$ = new Identifier(*$1);delete $1; }
		| Signed {$$ = new Identifier(*$1);delete $1; }
		| Char {$$ = new Identifier(*$1);delete $1; }
		| Unsigned {$$ = new Identifier(*$1);delete $1; }
		| Auto {$$ = new Identifier(*$1);delete $1; }
		;
%%

int changeToInt(char* str){
	long long sum = atol(str);
	return sum;
}

double changeToDouble(char* str){
	double sum = atof(str);
	return sum;
}
