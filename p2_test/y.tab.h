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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AND = 258,
    OR = 259,
    EQ = 260,
    LE_EQ = 261,
    GR_EQ = 262,
    NEQ = 263,
    ARRAY = 264,
    BOOLEAN = 265,
    BEGIN = 266,
    BREAK = 267,
    CHAR = 268,
    CASE = 269,
    CONST = 270,
    CONTINUE = 271,
    DO = 272,
    ELSE = 273,
    END = 274,
    EXIT = 275,
    FALSE = 276,
    FOR = 277,
    FN = 278,
    IF = 279,
    IN = 280,
    INTEGER = 281,
    LOOP = 282,
    MODULE = 283,
    PRINT = 284,
    PRINTLN = 285,
    PROCEDURE = 286,
    REPEAT = 287,
    RETURN = 288,
    REAL = 289,
    STRING = 290,
    RECORD = 291,
    THEN = 292,
    TURE = 293,
    TYPE = 294,
    USE = 295,
    UTIL = 296,
    VAR = 297,
    WHILE = 298,
    OF = 299,
    READ = 300,
    IDENTIFIERS = 301,
    INT_CONST = 302,
    REAL_CONST = 303,
    STR_CONST = 304,
    BOOL_CONST = 305,
    UMINUS = 306
  };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define EQ 260
#define LE_EQ 261
#define GR_EQ 262
#define NEQ 263
#define ARRAY 264
#define BOOLEAN 265
#define BEGIN 266
#define BREAK 267
#define CHAR 268
#define CASE 269
#define CONST 270
#define CONTINUE 271
#define DO 272
#define ELSE 273
#define END 274
#define EXIT 275
#define FALSE 276
#define FOR 277
#define FN 278
#define IF 279
#define IN 280
#define INTEGER 281
#define LOOP 282
#define MODULE 283
#define PRINT 284
#define PRINTLN 285
#define PROCEDURE 286
#define REPEAT 287
#define RETURN 288
#define REAL 289
#define STRING 290
#define RECORD 291
#define THEN 292
#define TURE 293
#define TYPE 294
#define USE 295
#define UTIL 296
#define VAR 297
#define WHILE 298
#define OF 299
#define READ 300
#define IDENTIFIERS 301
#define INT_CONST 302
#define REAL_CONST 303
#define STR_CONST 304
#define BOOL_CONST 305
#define UMINUS 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "test1.y" /* yacc.c:1909  */

    int val;
    double dval;
    string* sval;
    int type;
    int bval;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
