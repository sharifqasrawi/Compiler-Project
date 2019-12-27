/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     IDENTIFIER = 259,
     RETURN = 260,
     INTEGER = 261,
     DOUBLENUM = 262,
     CLASS = 263,
     FOR = 264,
     NEW = 265,
     IF = 266,
     WHILE = 267,
     DOUBLE = 268,
     BOOL = 269,
     VOID = 270,
     TRUE = 271,
     FALSE = 272,
     IFPREC = 273,
     ELSE = 274,
     OR = 275,
     AND = 276,
     NEQ = 277,
     EQ = 278,
     LOQ = 279,
     MOQ = 280,
     MINUS = 281,
     INCREMENT = 282,
     DECREMENT = 283,
     NOT = 284
   };
#endif
/* Tokens.  */
#define INT 258
#define IDENTIFIER 259
#define RETURN 260
#define INTEGER 261
#define DOUBLENUM 262
#define CLASS 263
#define FOR 264
#define NEW 265
#define IF 266
#define WHILE 267
#define DOUBLE 268
#define BOOL 269
#define VOID 270
#define TRUE 271
#define FALSE 272
#define IFPREC 273
#define ELSE 274
#define OR 275
#define AND 276
#define NEQ 277
#define EQ 278
#define LOQ 279
#define MOQ 280
#define MINUS 281
#define INCREMENT 282
#define DECREMENT 283
#define NOT 284




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 17 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
typedef union YYSTYPE {
	 Ident* tIdent;
	 IdentExpr* tIdExpr;
	 Expr* tExpr;
	 ExprList* tExprs;
	 Integer* tInt;
	 Double* tDouble;
	 Bool* tBool;
	 Minus* tMinus;
	 Variable* tVar;
	 Variables* tVars;
	 Type* tType;
	 Primitive_Type* tPtype;
	 Array_Type* tArrType;
	 Param* tParam;
	 Params* tParams;
	 Stmnt* tStmnt;
	 Stmnts* tStmnts;
	 Global* tGlobal;
	 Func* tFunc;
	 Field* tField;
	 Fields* tFields;
	 Class* tClass;
	 Root* tRoot;

} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 123 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



