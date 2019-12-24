%{
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include"node.h"
Block *programBlock;
extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s\n", s); }
long long changeToInt(const char* str);
double changeToDouble(const char* str);
%}

%union{
	Node* node;
	Block *block;
	Statement *stmt;
	Expression *expr;
	Identifier *ident;
	ArrayIndex *index;
	VariableList *varvec;
	ExpressionList *exprvec;
	VariableDecration *var_decl;
	std::string *str;
	int token;
};

%token<str> Int Float Double Long Short Signed Char Unsigned Auto Bool
%token<token> Break Case Const Else For If Return While
%token<str> INT DOUBLE ID
%token<token> EQ GT LT EQEQ GE LE NE
%token<token> LPAREN RPAREN LBRACE RBRACE LMBRA RMBRA
%token<token> ADD SUB MUL DIV
%token<token> SEMI DOT COMMA

%type<index> array_index
%type<ident> mytype primary_type array_type
%type<ident>  ident
%type<expr>  number expr assign
%type<varvec>  func_argv
%type<exprvec> call_argv
%type<block>  program stmts block
%type<stmt>  stmt var_decl func_decl if_stmt for_stmt while_stmt
%type<token> comprison


%left ADD SUB
%left MUL DIV

%start program
%%
	program: stmts { programBlock = $1; }
                ;

	stmts:
                stmt { $$ = new Block(); $$->statements.push_back($1); }
                |
                stmts stmt { $1->statements.push_back($2); }
                ;

	stmt:
		var_decl | func_decl
		| expr { $$ = new ExpressionStatement(*$1); }
		| Return expr { $$ = new ReturnStatement(*$2); }
		| if_stmt { printf("if_stmt created\n"); }
		| for_stmt { printf("for_stmt created\n"); }
		| while_stmt { printf("while_stmt created\n"); }
                ;

	var_decl:
		mytype ident {$$ = new VariableDecration(shared_ptr<Identifier>($1),*$2);  }
		| mytype ident EQ expr {$$ = new VariableDecration(shared_ptr<Identifier>($1),*$2,$4); }
		| mytype ident EQ LMBRA call_argv RMBRA { auto varial = new VariableDecration(shared_ptr<Identifier>($1),*$2); $$ = new ArrayInitialization(*varial,*$5);}
		;

	func_decl:
		mytype ident LPAREN func_argv RPAREN block { $$ = new FuncStatement(*$1,*$2,*$4,*$6); }
                ;

	block:
		LBRACE RBRACE { $$ = new Block(); }
		| LBRACE stmts RBRACE { $$ = $2; }
                ;

	func_argv: { $$ = new VariableList(); }
		| var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
		| func_argv COMMA var_decl { $1->push_back($<var_decl>3); }
		;

	assign:
		ident EQ expr { $$ = new AssignExpression(*$1,*$3); }
		|
		array_index EQ expr { $$ = new ArrayAssignment(shared_ptr<ArrayIndex>($1),*$3);}
		;

	expr:
		assign { $$ = $1; }
		| ident LPAREN call_argv RPAREN { $$ = new CallExpression(*$1,*$3);}
		| ident { $$ = $1;}
		| number
		| expr MUL expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr DIV expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr ADD expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr SUB expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr comprison expr { $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3));}
		| LPAREN expr RPAREN { $$ = $2;}
		| array_index { $$ = $1;}
		;

	call_argv:{ $$ = new ExpressionList; }
		| expr { $$ = new ExpressionList; $$->push_back($1); }
		| call_argv COMMA expr { $1->push_back($3); }
		;

	comprison:
		GT | LT | EQEQ | GE | LE | NE
		;
	ident:
		ID { $$ = new Identifier(*$1); }
		;

	array_index:
		ident LMBRA expr RMBRA { $$ = new ArrayIndex(*$1,shared_ptr<Expression>($3)); }
		;
	number:
		INT { long long a = std::stoll(*$1); $$ = new IntExpression(a); }
		| DOUBLE {double a = changeToDouble($1->c_str()); $$ = new DoubleExpression(a); }
		;

	primary_type:
		Int { $$ = new Identifier(*$1); $$->isType = true; }
		| Float { $$ = new Identifier(*$1); $$->isType = true; }
		| Double { $$ = new Identifier(*$1); $$->isType = true; }
		| Long { $$ = new Identifier(*$1); $$->isType = true; }
		| Short { $$ = new Identifier(*$1); $$->isType = true; }
		| Signed { $$ = new Identifier(*$1); $$->isType = true; }
		| Char { $$ = new Identifier(*$1); $$->isType = true; }
		| Unsigned { $$ = new Identifier(*$1); $$->isType = true; }
		| Auto { $$ = new Identifier(*$1); $$->isType = true; }
		| Bool { $$ = new Identifier(*$1); $$->isType = true; }
		;

	array_type:
		primary_type LMBRA INT RMBRA {long long a = std::stoll(*$3);  $1->isArray = true; $1->arraySize->push_back(make_shared<IntExpression>(a)); $$ = $1;}
		;

	mytype: 
		primary_type { $$ = $1;}
		| array_type { $$ = $1;}
		;


	if_stmt:
		If expr block { $$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>($3)); }
		| If expr block Else block { $$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>($3),shared_ptr<Block>($5)); }
		| If expr block Else if_stmt { auto blk = new Block(); blk->statements.push_back($5); 
		$$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>(blk)); }
		;

	for_stmt:
		For LPAREN expr SEMI expr SEMI expr RPAREN block { $$ = new ForStatement(shared_ptr<Block>($9),shared_ptr<Expression>($3),shared_ptr<Expression>($5),shared_ptr<Expression>($7)); }
		;

	while_stmt:
		While LPAREN expr RPAREN block { $$ = new ForStatement(shared_ptr<Block>($5),nullptr,shared_ptr<Expression>($3),nullptr); }
		;
%%

long long changeToInt(const char* str){
	long long sum = atol(str);
	return sum;
}

double changeToDouble(const char* str){
	double sum = atof(str);
	return sum;
}
