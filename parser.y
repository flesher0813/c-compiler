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

%token<str> Int Float Double Long Short Signed Char Unsigned Auto
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
	program: stmts { printf("program created\n"); programBlock = $1; }
                ;

	stmts:
                stmt { printf("stmt created\n"); $$ = new Block(); $$->statements.push_back($1); }
                |
                stmts stmt { printf("stmts stmt created\n"); $1->statements.push_back($2); }
                ;

	stmt:
		var_decl | func_decl
		| expr { printf("stmt expr created\n"); $$ = new ExpressionStatement(*$1); }
		| Return expr { printf("stmt RETURN expr created\n"); $$ = new ReturnStatement(*$2); }
		| if_stmt { printf("if_stmt created\n"); }
		| for_stmt { printf("for_stmt created\n"); }
		| while_stmt { printf("while_stmt created\n"); }
                ;

	var_decl:
		mytype ident { printf("type ident created\n");$$ = new VariableDecration(shared_ptr<Identifier>($1),*$2);  }
		| mytype ident EQ expr { printf("type ident EQ expr created\n");$$ = new VariableDecration(shared_ptr<Identifier>($1),*$2,$4); }
		| mytype ident EQ LMBRA call_argv RMBRA { printf("type ident EQ LMBRA call_argv RMBRA"); 
			auto varial = new VariableDecration(shared_ptr<Identifier>($1),*$2);
			$$ = new ArrayInitialization(*varial,*$5);}
		;

	func_decl:
		mytype ident LPAREN func_argv RPAREN block { printf("type ident LPAREN func_argv RPAREN block created\n");$$ = new FuncStatement(*$1,*$2,*$4,*$6); }
                ;

	block:
		LBRACE RBRACE { printf("block created\n"); $$ = new Block(); }
		| LBRACE stmts RBRACE { printf("LBRACE stmts RBRACE\n");$$ = $2; }
                ;

	func_argv: { printf("func_argv created\n"); $$ = new VariableList(); }
		| var_decl { printf("var_decl created\n");$$ = new VariableList(); $$->push_back($<var_decl>1); }
		| func_argv COMMA var_decl { printf("func_argv COMMA var_decl\n"); $1->push_back($<var_decl>3); }
		;

	assign:
		ident EQ expr { printf("assign ident EQ expr\n"); $$ = new AssignExpression(*$1,*$3); }
		|
		array_index EQ expr {printf("assign array_index EQ expr\n"); $$ = new ArrayAssignment(shared_ptr<ArrayIndex>($1),*$3);}
		;

	expr:
		assign { printf("assign started\n"); $$ = $1; }
		| ident LPAREN call_argv RPAREN { printf("expr ident LPAREN call_argv RPAREN\n"); $$ = new CallExpression(*$1,*$3);}
		| ident { printf("expr ident created\n"); $$ = $1;}
		| number { printf("expr number created\n");}
		| expr MUL expr { printf("expr expr MUL expr created\n"); $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr DIV expr { printf("expr expr DIV expr created\n"); $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr ADD expr { printf("expr expr ADD expr created\n"); $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr SUB expr { printf("expr expr SUB expr created\n"); $$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3)); }
		| expr comprison expr { printf("expr expr comprison expr created\n");$$ = new BinaryExpression(shared_ptr<Expression>($1),$2,shared_ptr<Expression>($3));}
		| LPAREN expr RPAREN { printf("expr LPAREN expr RPAREN created\n"); $$ = $2;}
		| array_index { printf("expr array_index created\n"); $$ = $1;}
		;

	call_argv:{  printf("call_argv created\n"); $$ = new ExpressionList; }
		| expr { printf("call_argv expr created\n"); $$ = new ExpressionList; $$->push_back($1); }
		| call_argv COMMA expr { printf("call_argv COMMA expr created\n"); $1->push_back($3); }
		;

	comprison:
		GT | LT | EQEQ | GE | LE | NE
		;
	ident:
		ID { printf("ident created\n"); $$ = new Identifier(*$1); }
		;

	array_index:
		ident LMBRA expr RMBRA { printf("array_index created\n"); $$ = new ArrayIndex(*$1,shared_ptr<Expression>($3)); }
		;
	number:
		INT {  printf("INT created\n"); long long a = std::stoll(*$1); $$ = new IntExpression(a); }
		| DOUBLE { printf("DOUBLE created\n");double a = changeToDouble($1->c_str()); $$ = new DoubleExpression(a); }
		;

	primary_type:
		Int { printf("type int created\n");std::cout<<*$1; $$ = new Identifier(*$1);printf("identifier done\n"); $$->isType = true; }
		| Float { printf("type float created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Double { printf("type double created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Long { printf("type long created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Short { printf("type short created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Signed { printf("type sighed created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Char { printf("type char created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Unsigned { printf("type unsighed created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		| Auto { printf("type auto created\n"); $$ = new Identifier(*$1); $$->isType = true; }
		;

	array_type:
		primary_type LMBRA INT RMBRA {printf("array_type:_type created\n");long long a = std::stoll(*$3);  $1->isArray = true; $1->arraySize->push_back(make_shared<IntExpression>(a)); $$ = $1;}
		;

	mytype: 
		primary_type {printf("type primary_type created\n"); $$ = $1;}
		| array_type { printf("type array_type created\n"); $$ = $1;}
		;


	if_stmt:
		If expr block { printf("a If created\n"); $$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>($3)); }
		| If expr block Else block { printf("a If/Else created\n"); $$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>($3),shared_ptr<Block>($5)); }
		| If expr block Else if_stmt { printf("multi If/Else created\n"); auto blk = new Block(); blk->statements.push_back($5); 
		$$ = new IfStatement(shared_ptr<Expression>($2),shared_ptr<Block>(blk)); }
		;

	for_stmt:
		For LPAREN expr SEMI expr SEMI expr RPAREN block { printf("for_stmt created\n"); $$ = new ForStatement(shared_ptr<Block>($9),shared_ptr<Expression>($3),shared_ptr<Expression>($5),shared_ptr<Expression>($7)); }
		;

	while_stmt:
		While LPAREN expr RPAREN block { printf("while_stmt created\n");$$ = new ForStatement(shared_ptr<Block>($5),nullptr,shared_ptr<Expression>($3),nullptr); }
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
