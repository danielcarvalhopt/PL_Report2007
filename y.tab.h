/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEGIN_REPORT = 258,
     END_REPORT = 259,
     BEGIN_FM = 260,
     END_FM = 261,
     BEGIN_TITLE = 262,
     END_TITLE = 263,
     BEGIN_SUBTITLE = 264,
     END_SUBTITLE = 265,
     BEGIN_DATE = 266,
     END_DATE = 267,
     TODAY = 268,
     BEGIN_AUTHOR = 269,
     END_AUTHOR = 270,
     BEGIN_NAME = 271,
     END_NAME = 272,
     BEGIN_NUMBER = 273,
     END_NUMBER = 274,
     BEGIN_MAIL = 275,
     END_MAIL = 276,
     BEGIN_ABS = 277,
     END_ABS = 278,
     BEGIN_AKN = 279,
     END_AKN = 280,
     BEGIN_BODY = 281,
     END_BODY = 282,
     BEGIN_CHAP = 283,
     END_CHAP = 284,
     BEGIN_PARA = 285,
     END_PARA = 286,
     BEGIN_ELEM = 287,
     END_ELEM = 288,
     BEGIN_FIG = 289,
     END_FIG = 290,
     BEGIN_GRAPH = 291,
     END_GRAPH = 292,
     BEGIN_CAPTION = 293,
     END_CAPTION = 294,
     BEGIN_PATH = 295,
     END_PATH = 296,
     BEGIN_FORMAT = 297,
     END_FORMAT = 298,
     BEGIN_SIZE = 299,
     END_SIZE = 300,
     BEGIN_TABLE = 301,
     END_TABLE = 302,
     TEXT = 303
   };
#endif
/* Tokens.  */
#define BEGIN_REPORT 258
#define END_REPORT 259
#define BEGIN_FM 260
#define END_FM 261
#define BEGIN_TITLE 262
#define END_TITLE 263
#define BEGIN_SUBTITLE 264
#define END_SUBTITLE 265
#define BEGIN_DATE 266
#define END_DATE 267
#define TODAY 268
#define BEGIN_AUTHOR 269
#define END_AUTHOR 270
#define BEGIN_NAME 271
#define END_NAME 272
#define BEGIN_NUMBER 273
#define END_NUMBER 274
#define BEGIN_MAIL 275
#define END_MAIL 276
#define BEGIN_ABS 277
#define END_ABS 278
#define BEGIN_AKN 279
#define END_AKN 280
#define BEGIN_BODY 281
#define END_BODY 282
#define BEGIN_CHAP 283
#define END_CHAP 284
#define BEGIN_PARA 285
#define END_PARA 286
#define BEGIN_ELEM 287
#define END_ELEM 288
#define BEGIN_FIG 289
#define END_FIG 290
#define BEGIN_GRAPH 291
#define END_GRAPH 292
#define BEGIN_CAPTION 293
#define END_CAPTION 294
#define BEGIN_PATH 295
#define END_PATH 296
#define BEGIN_FORMAT 297
#define END_FORMAT 298
#define BEGIN_SIZE 299
#define END_SIZE 300
#define BEGIN_TABLE 301
#define END_TABLE 302
#define TEXT 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 19 "report.y"

    char *str;



/* Line 2068 of yacc.c  */
#line 152 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


