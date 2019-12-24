/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Int = 258,
    Float = 259,
    Double = 260,
    Long = 261,
    Short = 262,
    Signed = 263,
    Char = 264,
    Unsigned = 265,
    Auto = 266,
    Bool = 267,
    Break = 268,
    Case = 269,
    Const = 270,
    Else = 271,
    For = 272,
    If = 273,
    Return = 274,
    While = 275,
    INT = 276,
    DOUBLE = 277,
    ID = 278,
    EQ = 279,
    GT = 280,
    LT = 281,
    EQEQ = 282,
    GE = 283,
    LE = 284,
    NE = 285,
    LPAREN = 286,
    RPAREN = 287,
    LBRACE = 288,
    RBRACE = 289,
    LMBRA = 290,
    RMBRA = 291,
    ADD = 292,
    SUB = 293,
    MUL = 294,
    DIV = 295,
    SEMI = 296,
    DOT = 297,
    COMMA = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:1909  */

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

#line 112 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
