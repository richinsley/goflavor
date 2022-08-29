/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
     CHAR = 258,
     BIT = 259,
     INT = 260,
     FLOAT = 261,
     DOUBLE = 262,
     CLASS = 263,
     IF = 264,
     ELSE = 265,
     DO = 266,
     WHILE = 267,
     FOR = 268,
     GOTO = 269,
     BREAK = 270,
     CONTINUE = 271,
     REPEAT = 272,
     MAP = 273,
     EXTENDS = 274,
     SWITCH = 275,
     CASE = 276,
     DEFAULT = 277,
     BAC = 278,
     PRAGMA = 279,
     PRAGMA_ARRAY = 280,
     PRAGMA_GET = 281,
     PRAGMA_NOGET = 282,
     PRAGMA_PUT = 283,
     PRAGMA_NOPUT = 284,
     PRAGMA_PUTXML = 285,
     PRAGMA_NOPUTXML = 286,
     PRAGMA_TRACE = 287,
     PRAGMA_NOTRACE = 288,
     PRAGMA_LINE = 289,
     PRAGMA_NOLINE = 290,
     PRAGMA_INCLUDES = 291,
     PRAGMA_NULLSTRINGS = 292,
     PRAGMA_NONULLSTRINGS = 293,
     PRAGMA_NOINCLUDES = 294,
     PRAGMA_BITSTREAM = 295,
     PRAGMA_PREFIX = 296,
     PRAGMA_ERROR_FUNC = 297,
     PRAGMA_TRACE_FUNC = 298,
     BAC_PREC = 299,
     BAC_OOC = 300,
     BAC_SOC = 301,
     BAC_TE = 302,
     BAC_RENORM = 303,
     BAC_BS = 304,
     BAC_INIT = 305,
     BAC_END = 306,
     BAC_RTABLE = 307,
     BAC_NEXTI = 308,
     BAC_TRANS = 309,
     BAC_EXCH = 310,
     INCLUDE = 311,
     IMPORT = 312,
     PUSHINCLUDE = 313,
     POPINCLUDE = 314,
     UNSIGNED = 315,
     SIGNED = 316,
     SHORT = 317,
     LONG = 318,
     CONST = 319,
     ALIGNED = 320,
     STATIC = 321,
     ABSTRACT = 322,
     LITTLE = 323,
     BIG = 324,
     EXPGOLOMB = 325,
     VARLEN = 326,
     INT_LITERAL = 327,
     DOUBLE_LITERAL = 328,
     BIT_LITERAL = 329,
     STRING_LITERAL = 330,
     VARIABLE = 331,
     CLASS_TYPE = 332,
     MAP_TYPE = 333,
     BAC_TYPE = 334,
     LABEL = 335,
     LS = 336,
     RS = 337,
     GE = 338,
     LE = 339,
     NE = 340,
     EQ = 341,
     OR = 342,
     AND = 343,
     INC = 344,
     DEC = 345,
     RANGE = 346,
     CLCL = 347,
     MUL_ASSIGN = 348,
     DIV_ASSIGN = 349,
     MOD_ASSIGN = 350,
     ADD_ASSIGN = 351,
     SUB_ASSIGN = 352,
     LS_ASSIGN = 353,
     RS_ASSIGN = 354,
     AND_ASSIGN = 355,
     XOR_ASSIGN = 356,
     OR_ASSIGN = 357,
     DBL_BRACE_L = 358,
     DBL_BRACE_R = 359,
     DECL = 360,
     EXPR = 361,
     VERBATIM = 362,
     VERBATIM_GET = 363,
     VERBATIM_PUT = 364,
     VERBATIM_BOTH = 365,
     VERBATIM_C = 366,
     VERBATIM_C_CPP = 367,
     VERBATIM_GET_C = 368,
     VERBATIM_PUT_C = 369,
     VERBATIM_BOTH_C = 370,
     VERBATIM_J = 371,
     VERBATIM_GET_J = 372,
     VERBATIM_PUT_J = 373,
     VERBATIM_BOTH_J = 374,
     VERBATIM_A = 375,
     VERBATIM_GET_A = 376,
     VERBATIM_PUT_A = 377,
     VERBATIM_BOTH_A = 378,
     LENGTHOF = 379,
     ISIDOF = 380,
     SKIPBITS = 381,
     NEXTBITS = 382,
     SNEXTBITS = 383,
     LITTLE_NEXTBITS = 384,
     LITTLE_SNEXTBITS = 385,
     NEXTCODE = 386,
     NUMBITS = 387,
     ESC_FTYPE = 388,
     ESC_MAP = 389,
     ARRAY = 390,
     LOWER_THAN_ELSE = 391
   };
#endif
/* Tokens.  */
#define CHAR 258
#define BIT 259
#define INT 260
#define FLOAT 261
#define DOUBLE 262
#define CLASS 263
#define IF 264
#define ELSE 265
#define DO 266
#define WHILE 267
#define FOR 268
#define GOTO 269
#define BREAK 270
#define CONTINUE 271
#define REPEAT 272
#define MAP 273
#define EXTENDS 274
#define SWITCH 275
#define CASE 276
#define DEFAULT 277
#define BAC 278
#define PRAGMA 279
#define PRAGMA_ARRAY 280
#define PRAGMA_GET 281
#define PRAGMA_NOGET 282
#define PRAGMA_PUT 283
#define PRAGMA_NOPUT 284
#define PRAGMA_PUTXML 285
#define PRAGMA_NOPUTXML 286
#define PRAGMA_TRACE 287
#define PRAGMA_NOTRACE 288
#define PRAGMA_LINE 289
#define PRAGMA_NOLINE 290
#define PRAGMA_INCLUDES 291
#define PRAGMA_NULLSTRINGS 292
#define PRAGMA_NONULLSTRINGS 293
#define PRAGMA_NOINCLUDES 294
#define PRAGMA_BITSTREAM 295
#define PRAGMA_PREFIX 296
#define PRAGMA_ERROR_FUNC 297
#define PRAGMA_TRACE_FUNC 298
#define BAC_PREC 299
#define BAC_OOC 300
#define BAC_SOC 301
#define BAC_TE 302
#define BAC_RENORM 303
#define BAC_BS 304
#define BAC_INIT 305
#define BAC_END 306
#define BAC_RTABLE 307
#define BAC_NEXTI 308
#define BAC_TRANS 309
#define BAC_EXCH 310
#define INCLUDE 311
#define IMPORT 312
#define PUSHINCLUDE 313
#define POPINCLUDE 314
#define UNSIGNED 315
#define SIGNED 316
#define SHORT 317
#define LONG 318
#define CONST 319
#define ALIGNED 320
#define STATIC 321
#define ABSTRACT 322
#define LITTLE 323
#define BIG 324
#define EXPGOLOMB 325
#define VARLEN 326
#define INT_LITERAL 327
#define DOUBLE_LITERAL 328
#define BIT_LITERAL 329
#define STRING_LITERAL 330
#define VARIABLE 331
#define CLASS_TYPE 332
#define MAP_TYPE 333
#define BAC_TYPE 334
#define LABEL 335
#define LS 336
#define RS 337
#define GE 338
#define LE 339
#define NE 340
#define EQ 341
#define OR 342
#define AND 343
#define INC 344
#define DEC 345
#define RANGE 346
#define CLCL 347
#define MUL_ASSIGN 348
#define DIV_ASSIGN 349
#define MOD_ASSIGN 350
#define ADD_ASSIGN 351
#define SUB_ASSIGN 352
#define LS_ASSIGN 353
#define RS_ASSIGN 354
#define AND_ASSIGN 355
#define XOR_ASSIGN 356
#define OR_ASSIGN 357
#define DBL_BRACE_L 358
#define DBL_BRACE_R 359
#define DECL 360
#define EXPR 361
#define VERBATIM 362
#define VERBATIM_GET 363
#define VERBATIM_PUT 364
#define VERBATIM_BOTH 365
#define VERBATIM_C 366
#define VERBATIM_C_CPP 367
#define VERBATIM_GET_C 368
#define VERBATIM_PUT_C 369
#define VERBATIM_BOTH_C 370
#define VERBATIM_J 371
#define VERBATIM_GET_J 372
#define VERBATIM_PUT_J 373
#define VERBATIM_BOTH_J 374
#define VERBATIM_A 375
#define VERBATIM_GET_A 376
#define VERBATIM_PUT_A 377
#define VERBATIM_BOTH_A 378
#define LENGTHOF 379
#define ISIDOF 380
#define SKIPBITS 381
#define NEXTBITS 382
#define SNEXTBITS 383
#define LITTLE_NEXTBITS 384
#define LITTLE_SNEXTBITS 385
#define NEXTCODE 386
#define NUMBITS 387
#define ESC_FTYPE 388
#define ESC_MAP 389
#define ARRAY 390
#define LOWER_THAN_ELSE 391




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
    char                *string;
    long long           ival;
    double              dval;
    unsigned long long  uival;
    bit_t               *bit;
    list_t              *lp;
    symbol_t            *sp;
    node_t              *np;
    verbatim_t	        *vp;
}
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

