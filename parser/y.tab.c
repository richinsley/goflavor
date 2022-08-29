/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */



/*
 * Copyright (c) 1997-2005 Alexandros Eleftheriadis, Danny Hong and 
 * Yuntai Kyong.
 *
 * This file is part of Flavor, developed at Columbia University
 * (http://flavor.sourceforge.net).
 *
 * Flavor is free software; you can redistribute it and/or modify
 * it under the terms of the Flavor Artistic License as described in
 * the file COPYING.txt. 
 *
 */

/*
 * Authors:
 * Alexandros Eleftheriadis <eleft@ee.columbia.edu>
 * Danny Hong <danny@ee.columbia.edu>
 * Yuntai Kyong <yuntaikyong@ieee.org>
 *
 */

/*
 *  Yacc parser for Flavor translator
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "port.h"
#include "error.h"
#include "globals.h"
#include "symbol.h"
#include "ptree.h"
#include "check.h"
#include "util.h"
#include "eval.h"
//#include "compile.h"
#include "carray_unroll.h"

/* defined in the lexical analyzer */
void yyerror(char *fmt, ...);
int yywrap();
int include(char *file, int import);
int pushinclude(char *file);
int popinclude(char *file);

extern int yylex (void);

/* Disable 'unreferenced label' warning from Microsoft Visual C++.
 * MKS Yacc generates various labels that are not used.
 */
#if defined(_WIN32_) || defined(WIN32)
#pragma warning(disable : 4102)
#endif

/* jl - use mem tracker */
#include "util.h"
#undef YYMALLOC
#define YYMALLOC getmem

#undef YYFREE
#define YYFREE free_memt


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  108
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  304
/* YYNRULES -- Number of states.  */
#define YYNSTATES  561

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   391

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,     2,     2,     2,    98,    96,     2,
      85,    86,    91,    89,    82,    90,   101,    92,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    81,
      93,   116,    94,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    99,     2,   100,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,    95,    88,   102,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    19,
      24,    27,    30,    33,    36,    38,    40,    43,    48,    55,
      60,    62,    67,    74,    78,    83,    90,    97,   106,   108,
     112,   114,   116,   118,   120,   122,   124,   126,   130,   134,
     138,   140,   144,   148,   150,   154,   158,   162,   166,   170,
     172,   176,   180,   184,   188,   192,   196,   198,   202,   204,
     208,   210,   216,   218,   222,   224,   226,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   250,   252,   256,
     259,   262,   266,   269,   272,   274,   276,   279,   284,   289,
     294,   300,   306,   312,   317,   322,   328,   334,   340,   346,
     353,   360,   365,   367,   370,   372,   374,   376,   378,   380,
     382,   384,   386,   388,   389,   391,   396,   398,   400,   402,
     404,   406,   408,   410,   412,   414,   418,   422,   424,   426,
     430,   432,   434,   438,   440,   442,   444,   449,   456,   461,
     467,   469,   471,   473,   475,   477,   479,   481,   485,   490,
     494,   497,   501,   503,   506,   508,   510,   512,   514,   516,
     518,   520,   522,   524,   527,   533,   541,   547,   553,   561,
     568,   576,   584,   593,   601,   610,   619,   629,   633,   636,
     639,   641,   644,   646,   648,   650,   652,   654,   656,   658,
     660,   662,   664,   667,   670,   672,   676,   680,   682,   686,
     690,   692,   697,   700,   703,   707,   710,   714,   723,   733,
     742,   751,   761,   770,   781,   793,   804,   815,   827,   838,
     842,   847,   850,   854,   856,   860,   863,   865,   867,   869,
     871,   873,   875,   877,   879,   881,   883,   885,   887,   889,
     891,   893,   895,   897,   899,   902,   904,   908,   912,   914,
     916,   918,   920,   922,   924,   926,   928,   930,   932,   934,
     936,   938,   940,   944,   948,   952,   956,   959,   962,   965,
     968,   971,   977,   983,   990,   994,   996,  1000,  1004,  1006,
    1008,  1012,  1017,  1023,  1025,  1029,  1031,  1035,  1037,  1041,
    1043,  1046,  1049,  1053,  1055,  1059,  1063,  1065,  1067,  1069,
    1073,  1075,  1077,  1081,  1085
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     209,     0,    -1,   163,    -1,    72,    -1,    73,    -1,    74,
      -1,    85,   178,    86,    -1,    76,    -1,   162,    -1,   164,
      99,   178,   100,    -1,   165,   163,    -1,   164,   112,    -1,
     164,   113,    -1,   164,   101,    -1,   167,    -1,   164,    -1,
     170,   166,    -1,   148,    85,   164,    86,    -1,   149,    85,
      77,    82,   178,    86,    -1,   150,    85,   178,    86,    -1,
     168,    -1,   155,    85,    74,    86,    -1,   155,    85,   189,
      82,    74,    86,    -1,   156,    85,    86,    -1,   151,    85,
     178,    86,    -1,   151,    85,   169,    82,   178,    86,    -1,
     151,    85,   189,    82,   178,    86,    -1,   151,    85,   189,
      82,   169,    82,   178,    86,    -1,   188,    -1,   169,    82,
     188,    -1,   112,    -1,   113,    -1,    89,    -1,    90,    -1,
     102,    -1,   103,    -1,   166,    -1,   171,    91,   166,    -1,
     171,    92,   166,    -1,   171,    98,   166,    -1,   171,    -1,
     172,    89,   171,    -1,   172,    90,   171,    -1,   172,    -1,
     173,   104,   172,    -1,   173,   105,   172,    -1,   173,    96,
     172,    -1,   173,    97,   172,    -1,   173,    95,   172,    -1,
     173,    -1,   174,    93,   173,    -1,   174,    94,   173,    -1,
     174,   107,   173,    -1,   174,   106,   173,    -1,   174,   109,
     173,    -1,   174,   108,   173,    -1,   174,    -1,   175,   111,
     174,    -1,   175,    -1,   176,   110,   175,    -1,   176,    -1,
     176,    83,   177,    84,   177,    -1,   177,    -1,   166,   179,
     178,    -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,
     120,    -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,
     125,    -1,   126,    -1,   178,    -1,   180,    82,   178,    -1,
     178,    -1,   178,    82,   181,    -1,   183,    81,    -1,   184,
     193,    -1,   183,    82,   193,    -1,   189,   185,    -1,   189,
     186,    -1,   190,    -1,   187,    -1,   187,   190,    -1,   191,
      85,   177,    86,    -1,   191,    85,    78,    86,    -1,   192,
      85,    78,    86,    -1,   191,    85,   177,    86,    91,    -1,
     191,    85,    78,    86,    91,    -1,   192,    85,    78,    86,
      91,    -1,   187,    85,   177,    86,    -1,   187,    85,    78,
      86,    -1,   187,    85,   177,    86,    91,    -1,   187,    85,
      78,    86,    91,    -1,   187,   191,    85,   177,    86,    -1,
     187,   191,    85,    78,    86,    -1,   187,   191,    85,   177,
      86,    91,    -1,   187,   191,    85,    78,    86,    91,    -1,
     191,    85,    79,    86,    -1,   188,    -1,   187,   188,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    -1,    65,
      -1,    65,    85,   177,    86,    -1,   191,    -1,   192,    -1,
       4,    -1,     3,    -1,     5,    -1,     6,    -1,     7,    -1,
      77,    -1,   197,    -1,   197,   116,   178,    -1,   197,   116,
     194,    -1,   198,    -1,   199,    -1,    87,   195,    88,    -1,
      75,    -1,   196,    -1,   195,    82,   196,    -1,   178,    -1,
     194,    -1,   163,    -1,   197,    99,   178,   100,    -1,   197,
      99,    99,   178,   100,   100,    -1,   197,    85,   181,    86,
      -1,   197,   116,   177,   114,   177,    -1,   201,    -1,   202,
      -1,   205,    -1,   206,    -1,   207,    -1,   208,    -1,   248,
      -1,   163,    84,   204,    -1,    21,   177,    84,   204,    -1,
      22,    84,   204,    -1,    87,    88,    -1,    87,   203,    88,
      -1,   204,    -1,   203,   204,    -1,   200,    -1,   182,    -1,
     222,    -1,   223,    -1,   227,    -1,   226,    -1,   228,    -1,
     229,    -1,    81,    -1,   178,    81,    -1,     9,    85,   176,
      86,   204,    -1,     9,    85,   176,    86,   204,    10,   204,
      -1,    20,    85,   178,    86,   204,    -1,    12,    85,   176,
      86,   204,    -1,    11,   204,    12,    85,   176,    86,    81,
      -1,    13,    85,    81,    81,    86,   204,    -1,    13,    85,
      81,    81,   180,    86,   204,    -1,    13,    85,    81,   176,
      81,    86,   204,    -1,    13,    85,    81,   176,    81,   180,
      86,   204,    -1,    13,    85,   180,    81,    81,    86,   204,
      -1,    13,    85,   180,    81,    81,   180,    86,   204,    -1,
      13,    85,   180,    81,   176,    81,    86,   204,    -1,    13,
      85,   180,    81,   176,    81,   180,    86,   204,    -1,    14,
      80,    81,    -1,    16,    81,    -1,    15,    81,    -1,   210,
      -1,   209,   210,    -1,   182,    -1,   211,    -1,   230,    -1,
     222,    -1,   223,    -1,   227,    -1,   226,    -1,   228,    -1,
     229,    -1,   240,    -1,   212,   219,    -1,   212,    81,    -1,
     213,    -1,   213,    84,   217,    -1,   213,    84,   218,    -1,
     214,    -1,   214,    19,    77,    -1,   214,    19,   163,    -1,
     215,    -1,   215,    85,   220,    86,    -1,   189,   216,    -1,
       8,   163,    -1,    67,     8,   163,    -1,     8,    77,    -1,
      67,     8,    77,    -1,   189,   191,    85,   177,    86,   163,
     116,   177,    -1,   189,   187,   191,    85,   177,    86,   163,
     116,   177,    -1,   189,   187,    85,   177,    86,   163,   116,
     177,    -1,   189,   191,    85,    78,    86,   163,   116,   177,
      -1,   189,   187,   191,    85,    78,    86,   163,   116,   177,
      -1,   189,   187,    85,    78,    86,   163,   116,   177,    -1,
     189,   191,    85,   177,    86,   163,   116,   177,   114,   177,
      -1,   189,   187,   191,    85,   177,    86,   163,   116,   177,
     114,   177,    -1,   189,   187,    85,   177,    86,   163,   116,
     177,   114,   177,    -1,   189,   191,    85,    78,    86,   163,
     116,   177,   114,   177,    -1,   189,   187,   191,    85,    78,
      86,   163,   116,   177,   114,   177,    -1,   189,   187,    85,
      78,    86,   163,   116,   177,   114,   177,    -1,    87,   203,
      88,    -1,    87,   203,    88,    81,    -1,    87,    88,    -1,
      87,    88,    81,    -1,   221,    -1,   220,    82,   221,    -1,
     185,   197,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   137,    -1,   138,    -1,   139,    -1,   136,
      -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,    24,    -1,    24,
     224,    -1,   225,    -1,   224,    82,   225,    -1,    25,   116,
      72,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    37,    -1,    38,    -1,    36,    -1,    39,    -1,
      40,   116,    75,    -1,    41,   116,    75,    -1,    42,   116,
      75,    -1,    43,   116,    75,    -1,    57,    75,    -1,    56,
      75,    -1,    58,    75,    -1,    59,    75,    -1,   231,   232,
      -1,    18,   163,    85,   190,    86,    -1,    18,   163,    85,
     187,    86,    -1,    18,   163,    85,   187,   191,    86,    -1,
      87,   233,    88,    -1,   234,    -1,   233,    82,   234,    -1,
     235,    82,   239,    -1,    74,    -1,   177,    -1,   236,    82,
     177,    -1,   191,    85,   177,    86,    -1,   187,   191,    85,
     177,    86,    -1,   237,    -1,   238,    82,   237,    -1,   177,
      -1,    87,   236,    88,    -1,   237,    -1,    87,   238,    88,
      -1,    75,    -1,   241,   242,    -1,    23,   163,    -1,    87,
     243,    88,    -1,   244,    -1,   243,    82,   244,    -1,   245,
      82,   246,    -1,    75,    -1,   177,    -1,    75,    -1,    87,
     247,    88,    -1,   177,    -1,    75,    -1,   247,    82,   177,
      -1,   247,    82,    75,    -1,    79,    85,    72,    86,    81,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   222,   222,   223,   224,   225,   226,   231,   236,   237,
     240,   247,   248,   252,   262,   263,   264,   268,   269,   270,
     271,   272,   276,   280,   284,   285,   286,   287,   291,   292,
     296,   297,   298,   299,   300,   301,   305,   306,   307,   308,
     312,   313,   314,   318,   319,   320,   321,   322,   323,   327,
     328,   329,   330,   331,   332,   333,   337,   338,   342,   343,
     347,   348,   352,   353,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   371,   372,   376,   377,   385,
     389,   417,   435,   436,   440,   441,   445,   451,   452,   453,
     454,   455,   456,   457,   461,   465,   469,   473,   476,   479,
     482,   485,   491,   492,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   508,   509,   510,   514,   515,   519,   520,
     521,   522,   523,   527,   535,   536,   541,   546,   547,   551,
     556,   564,   565,   574,   575,   579,   580,   587,   596,   604,
     614,   615,   616,   617,   618,   619,   620,   624,   630,   636,
     640,   641,   645,   646,   650,   651,   652,   653,   654,   655,
     656,   657,   661,   662,   666,   667,   668,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   690,   691,   692,
     696,   701,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   722,   737,   770,   778,   785,   795,   796,   821,
     829,   838,   848,   856,   867,   879,   890,   905,   910,   915,
     921,   926,   931,   941,   946,   951,   957,   962,   967,   978,
     979,   980,   981,   985,   986,   990,  1006,  1007,  1011,  1015,
    1019,  1020,  1024,  1028,  1032,  1036,  1037,  1041,  1045,  1049,
    1050,  1054,  1058,  1069,  1070,  1074,  1075,  1079,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1110,  1122,  1133,  1143,
    1157,  1164,  1171,  1177,  1186,  1190,  1191,  1199,  1204,  1213,
    1214,  1218,  1221,  1240,  1241,  1245,  1246,  1247,  1256,  1265,
    1277,  1285,  1294,  1298,  1299,  1303,  1307,  1311,  1312,  1313,
    1317,  1318,  1319,  1320,  1324
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "BIT", "INT", "FLOAT", "DOUBLE",
  "CLASS", "IF", "ELSE", "DO", "WHILE", "FOR", "GOTO", "BREAK", "CONTINUE",
  "REPEAT", "MAP", "EXTENDS", "SWITCH", "CASE", "DEFAULT", "BAC", "PRAGMA",
  "PRAGMA_ARRAY", "PRAGMA_GET", "PRAGMA_NOGET", "PRAGMA_PUT",
  "PRAGMA_NOPUT", "PRAGMA_PUTXML", "PRAGMA_NOPUTXML", "PRAGMA_TRACE",
  "PRAGMA_NOTRACE", "PRAGMA_LINE", "PRAGMA_NOLINE", "PRAGMA_INCLUDES",
  "PRAGMA_NULLSTRINGS", "PRAGMA_NONULLSTRINGS", "PRAGMA_NOINCLUDES",
  "PRAGMA_BITSTREAM", "PRAGMA_PREFIX", "PRAGMA_ERROR_FUNC",
  "PRAGMA_TRACE_FUNC", "BAC_PREC", "BAC_OOC", "BAC_SOC", "BAC_TE",
  "BAC_RENORM", "BAC_BS", "BAC_INIT", "BAC_END", "BAC_RTABLE", "BAC_NEXTI",
  "BAC_TRANS", "BAC_EXCH", "INCLUDE", "IMPORT", "PUSHINCLUDE",
  "POPINCLUDE", "UNSIGNED", "SIGNED", "SHORT", "LONG", "CONST", "ALIGNED",
  "STATIC", "ABSTRACT", "LITTLE", "BIG", "EXPGOLOMB", "VARLEN",
  "INT_LITERAL", "DOUBLE_LITERAL", "BIT_LITERAL", "STRING_LITERAL",
  "VARIABLE", "CLASS_TYPE", "MAP_TYPE", "BAC_TYPE", "LABEL", "';'", "','",
  "'?'", "':'", "'('", "')'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'",
  "'<'", "'>'", "'|'", "'&'", "'^'", "'%'", "'['", "']'", "'.'", "'~'",
  "'!'", "LS", "RS", "GE", "LE", "NE", "EQ", "OR", "AND", "INC", "DEC",
  "RANGE", "CLCL", "'='", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LS_ASSIGN", "RS_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "DBL_BRACE_L", "DBL_BRACE_R", "DECL", "EXPR",
  "VERBATIM", "VERBATIM_GET", "VERBATIM_PUT", "VERBATIM_BOTH",
  "VERBATIM_C", "VERBATIM_C_CPP", "VERBATIM_GET_C", "VERBATIM_PUT_C",
  "VERBATIM_BOTH_C", "VERBATIM_J", "VERBATIM_GET_J", "VERBATIM_PUT_J",
  "VERBATIM_BOTH_J", "VERBATIM_A", "VERBATIM_GET_A", "VERBATIM_PUT_A",
  "VERBATIM_BOTH_A", "LENGTHOF", "ISIDOF", "SKIPBITS", "NEXTBITS",
  "SNEXTBITS", "LITTLE_NEXTBITS", "LITTLE_SNEXTBITS", "NEXTCODE",
  "NUMBITS", "ESC_FTYPE", "ESC_MAP", "ARRAY", "LOWER_THAN_ELSE", "$accept",
  "primary_expr", "identifier", "postfix_expr", "rescoped_expr",
  "unary_expr", "builtin_function", "nextbits_function", "modifier_list",
  "unary_operator", "multiplicative_expr", "additive_expr", "shift_expr",
  "relational_expr", "logical_and_expr", "logical_or_expr",
  "conditional_expr", "assignment_expr", "assignment_operator",
  "assignment_expr_list", "argument_expr_list", "declaration",
  "declaration_list", "type_info", "plain_type_info", "parsable_type_info",
  "declaration_modifiers", "modifier", "alignment_modifier",
  "type_specifier", "builtin_type_specifier", "user_type_specifier",
  "init_declarator", "array", "array_expr_list", "array_expr",
  "declarator", "declarator_with_params", "declarator_with_range",
  "statement", "labeled_statement", "compound_statement",
  "statement_or_declaration_list", "statement_or_declaration",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_definition", "class_definition",
  "complex_class_declarator", "derived_class_declarator",
  "param_class_declarator", "aligned_class_declarator", "class_declarator",
  "id_declarator", "id_range_declarator", "class_body", "parameter_list",
  "parameter_declaration", "verbatim", "pragma", "pragma_list",
  "pragma_item", "import_file", "include_file", "push_include_file",
  "pop_include_file", "map_definition", "map_declarator", "map_body",
  "map_entry_list", "map_entry", "map_code", "map_entry_item_list",
  "map_entry_item_escape", "map_entry_item_escape_list", "map_entry_item",
  "bac_definition", "bac_declarator", "bac_body", "bac_entry_list",
  "bac_entry", "bac_keyword", "bac_entry_item", "bac_entry_item_list",
  "bac_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,    59,    44,    63,    58,    40,    41,   123,   125,    43,
      45,    42,    47,    60,    62,   124,    38,    94,    37,    91,
      93,    46,   126,    33,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,    61,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   161,   162,   162,   162,   162,   162,   163,   164,   164,
     164,   164,   164,   165,   166,   166,   166,   167,   167,   167,
     167,   167,   167,   167,   168,   168,   168,   168,   169,   169,
     170,   170,   170,   170,   170,   170,   171,   171,   171,   171,
     172,   172,   172,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   176,   176,
     177,   177,   178,   178,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   180,   180,   181,   181,   182,
     183,   183,   184,   184,   185,   185,   185,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   187,   187,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   189,   189,   189,   190,   190,   191,   191,
     191,   191,   191,   192,   193,   193,   193,   193,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   197,   198,   199,
     200,   200,   200,   200,   200,   200,   200,   201,   201,   201,
     202,   202,   203,   203,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   206,   206,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   208,   208,   208,
     209,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   212,   212,   212,   213,   213,   213,
     214,   214,   215,   216,   216,   216,   216,   217,   217,   217,
     217,   217,   217,   218,   218,   218,   218,   218,   218,   219,
     219,   219,   219,   220,   220,   221,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   223,   223,   224,   224,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   227,   228,   229,
     230,   231,   231,   231,   232,   233,   233,   234,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   239,   239,   239,
     240,   241,   242,   243,   243,   244,   245,   246,   246,   246,
     247,   247,   247,   247,   248
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     4,
       2,     2,     2,     2,     1,     1,     2,     4,     6,     4,
       1,     4,     6,     3,     4,     6,     6,     8,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       2,     3,     2,     2,     1,     1,     2,     4,     4,     4,
       5,     5,     5,     4,     4,     5,     5,     5,     5,     6,
       6,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     4,     6,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     7,     8,     7,     8,     8,     9,     3,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     3,     1,     3,     3,
       1,     4,     2,     2,     3,     2,     3,     8,     9,     8,
       8,     9,     8,    10,    11,    10,    10,    11,    10,     3,
       4,     2,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     5,     5,     6,     3,     1,     3,     3,     1,     1,
       3,     4,     5,     1,     3,     1,     3,     1,     3,     1,
       2,     2,     3,     1,     3,     3,     1,     1,     1,     3,
       1,     1,     3,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     113,     0,     0,   243,     0,     0,     0,     0,   114,   226,
     227,   228,   229,   230,   234,   231,   232,   233,   235,   236,
     237,   238,   239,   240,   241,   242,   182,     0,     0,     0,
     113,   180,   183,     0,   194,   197,   200,   185,   186,   188,
     187,   189,   190,   184,     0,   191,     0,     7,     0,   291,
       0,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   260,   258,   259,   261,     0,     0,     0,     0,   244,
     245,   267,   266,   268,   269,     0,    79,     0,   135,    80,
     124,   127,   128,   119,   118,   120,   121,   122,     0,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   123,
      82,    83,    85,   102,    84,   116,   117,   202,     1,   181,
     193,   113,   192,   113,     0,     0,     0,   270,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       0,    32,    33,    34,    35,    30,    31,     0,     0,     0,
       0,     0,     0,     8,     2,    15,     0,    36,    14,    20,
       0,    40,    43,    49,    56,    58,    60,     0,    81,     0,
       0,     0,   205,   203,     0,     0,   103,    86,   116,   117,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   113,   221,     2,    36,    62,     0,
     155,     0,   154,   140,   141,   113,   152,   142,   143,   144,
     145,   156,   157,   159,   158,   160,   161,   146,     0,   195,
     196,   198,   199,     0,    85,   116,     0,   223,   278,     0,
     275,     0,   296,     0,   293,     0,     0,     0,   247,   262,
     263,   264,   265,   246,     0,     0,     0,     0,   113,   113,
       0,     0,    13,    11,    12,    10,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,    77,     0,     0,
       0,   130,     0,    62,   125,   126,   206,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   178,     0,     0,   113,     0,   150,   113,   222,   113,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,   163,   219,   153,     0,     0,   225,     0,   201,
       0,   274,     0,     0,   292,     0,   272,     0,   271,     6,
       0,     0,     0,     0,     0,    28,     0,     0,     0,    23,
       0,    37,    38,    39,    41,    42,    48,    46,    47,    44,
      45,    50,    51,    53,    52,    55,    54,    57,     0,    59,
       0,   138,     0,   136,   133,   134,     0,   131,     0,    94,
      93,     0,     0,    88,   101,    87,    89,     0,     0,     0,
       0,    75,     0,   177,     0,   113,   149,     0,   151,   147,
      63,   220,     0,     0,     0,   224,   276,   289,     0,   285,
       0,     0,   287,   277,   294,   298,     0,   297,   295,   273,
      17,     0,    19,     0,    24,     0,    21,     0,     9,     0,
      78,     0,     0,   129,   139,    96,    95,    98,    97,    91,
      90,    92,   113,     0,   113,     0,     0,     0,     0,   113,
     148,     0,     0,     0,     0,     0,     0,   279,     0,   283,
       0,     0,     0,   301,   300,     0,     0,     0,    29,     0,
       0,     0,    61,   137,   132,   100,    99,   164,     0,   167,
     113,     0,     0,     0,     0,    76,   166,   304,     0,     0,
       0,     0,     0,     0,     0,   286,     0,   288,     0,     0,
       0,   299,    18,    25,     0,    26,    22,   113,     0,   169,
     113,   113,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   284,     0,   281,   303,   302,     0,   165,
     168,   170,   171,   113,   173,   113,   113,     0,     0,     0,
       0,     0,     0,     0,   282,    27,   172,   174,   175,   113,
     212,   209,     0,     0,   210,   207,   176,     0,     0,   211,
     208,     0,     0,   218,   215,     0,     0,   216,   213,   217,
     214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   143,   144,   145,   146,   147,   148,   149,   333,   150,
     151,   152,   153,   154,   155,   156,   188,   189,   311,   382,
     268,   190,    27,    28,   100,   101,   400,   103,   191,   104,
     215,   169,    79,   365,   366,   367,    80,    81,    82,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    30,    31,
      32,    33,    34,    35,    36,   107,   209,   210,   112,   216,
     217,   201,   202,    69,    70,   203,   204,   205,   206,    43,
      44,   117,   219,   220,   221,   448,   402,   450,   403,    45,
      46,   119,   223,   224,   225,   408,   455,   207
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -407
static const yytype_int16 yypact[] =
{
    1312,     3,     3,  2153,   -39,     8,    51,    72,    29,  -407,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,   -60,     3,  1354,
     618,  -407,  -407,   -57,   -13,    69,    83,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,     6,  -407,    34,  -407,    85,  -407,
      43,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,  -407,    80,    82,    95,    98,   123,
    -407,  -407,  -407,  -407,  -407,  2002,  -407,     3,  -407,  -407,
     -62,  -407,  -407,  -407,  -407,  -407,  -407,  -407,    39,  -407,
    -407,  -407,  -407,  -407,   199,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,   803,  -407,  -407,   131,   159,  -407,  -407,  -407,
    -407,   833,  -407,   164,   116,  2056,   171,  -407,   172,  -407,
    2056,   181,   185,   187,   188,   190,  2153,  -407,  -407,  -407,
    2002,  -407,  -407,  -407,  -407,  -407,  -407,   186,   189,   195,
     196,   197,   201,  -407,  -407,   -81,     3,  -407,  -407,  -407,
    2002,    -6,   120,    36,   130,   161,     1,   184,  -407,  2002,
      77,   128,  -407,  -407,   144,  1451,  -407,  -407,   202,  -407,
    1419,   211,   205,  1253,   206,   209,   220,   194,   221,   218,
    2002,   222,   224,  -407,   938,   226,   227,   435,  -407,   231,
    -407,  2056,  -407,  -407,  -407,  1043,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  2106,  -407,
    -407,  -407,  -407,     3,  2056,  -407,    20,  -407,  -407,    -8,
    -407,   236,  -407,    37,  -407,   238,   348,   237,  -407,  -407,
    -407,  -407,  -407,  -407,   239,   176,   245,  2002,   -12,   -46,
     240,  2002,  -407,  -407,  -407,  -407,  -407,  2002,  2002,  2002,
    2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,
    2002,  2002,  2002,  2002,  2002,  2002,  -407,   247,   241,  2002,
     213,  -407,   128,   216,  -407,  -407,  -407,  -407,   246,   249,
    1506,   251,   252,   255,   256,  2002,   319,  2002,  1539,   262,
    -407,  -407,  2002,   260,  1253,   261,  -407,  1148,  -407,  1253,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,  2002,  -407,   264,  -407,   765,   271,   248,  2056,  -407,
     171,  -407,   627,   172,  -407,   460,  -407,   263,  -407,  -407,
      -4,   275,   274,   280,   277,  -407,   282,   279,   284,  -407,
     267,  -407,  -407,  -407,    -6,    -6,   120,   120,   120,   120,
     120,    36,    36,    36,    36,    36,    36,   130,   285,   161,
    2002,  -407,   268,  -407,  -407,  -407,    46,  -407,  2002,   283,
     287,   290,   293,   291,  -407,   292,   294,   -71,   296,   -14,
    1594,  -407,   153,  -407,   301,  1253,  -407,   302,  -407,  -407,
    -407,  -407,  1626,   304,  1645,  -407,  -407,  -407,   728,  -407,
    2106,   305,  -407,  -407,  -407,  -407,  1695,  -407,  -407,  -407,
    -407,  2002,  -407,  1400,  -407,  1400,  -407,   272,  -407,  2002,
    -407,   270,   128,  -407,  -407,  -407,  -407,   306,   308,  -407,
    -407,  -407,  1253,  2002,  1253,  1745,   -41,  1795,  2002,  1253,
    -407,   314,   315,   320,  1814,   321,   327,  -407,    47,  -407,
      64,   329,  2002,  -407,  -407,    66,   334,   335,  -407,   318,
     336,   337,  -407,  -407,  -407,  -407,  -407,   395,    -5,  -407,
    1253,    74,  1846,  1901,   -40,  -407,  -407,  -407,     3,     3,
     339,   342,     3,     3,  2002,  -407,  2106,  -407,  2002,   343,
    1933,  -407,  -407,  -407,  1400,  -407,  -407,  1253,   354,  -407,
    1253,  1253,    89,  1253,    91,  1952,   299,   323,     3,     3,
     324,   325,  -407,  -407,   350,  -407,  -407,  -407,   351,  -407,
    -407,  -407,  -407,  1253,  -407,  1253,  1253,   109,  2002,  2002,
     326,   328,  2002,  2002,  -407,  -407,  -407,  -407,  -407,  1253,
     331,   332,  2002,  2002,   341,   344,  -407,  2002,  2002,   346,
     347,  2002,  2002,  -407,  -407,  2002,  2002,  -407,  -407,  -407,
    -407
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -407,  -407,    -1,   215,  -407,   155,  -407,  -407,    41,  -407,
      18,   -68,    -3,   204,   183,  -276,   -58,  -114,  -407,  -406,
      93,    12,  -407,  -407,  -110,  -407,   -26,   -96,     4,   -94,
     -27,   -22,   374,   303,  -407,    40,   244,  -407,  -407,  -407,
    -407,  -407,   281,    78,  -407,  -407,  -407,  -407,  -407,   438,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
     154,    13,    14,  -407,   353,    25,    33,    35,    38,  -407,
    -407,  -407,  -407,   156,  -407,  -407,  -388,  -407,  -407,  -407,
    -407,  -407,  -407,   150,  -407,  -407,  -407,  -407
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      48,    49,   105,   102,    29,   213,   166,   106,   167,   377,
     449,   379,    26,    37,    38,   432,   234,   157,   241,     8,
     242,    76,    77,   159,   110,    39,   227,    78,   337,   471,
     111,   243,   244,    40,    29,    41,    71,   160,    42,   265,
     472,   505,    26,    37,    38,   267,   270,   274,    89,    90,
      91,    92,    93,     8,   161,    39,    95,    96,    97,    98,
     127,   128,   129,    40,    47,    41,   502,   504,    42,   265,
     265,   113,   434,   130,   320,   168,    78,   131,   132,    47,
     321,   498,   410,    72,   264,   247,   248,   163,   114,   214,
     133,   134,   249,   116,   226,   241,   265,   242,   513,   527,
     135,   136,   318,   273,   436,   265,   319,   279,   243,   244,
     186,   265,   283,   212,    75,    47,   162,   208,   166,   323,
     167,   118,   293,   332,   334,   324,    73,   340,   422,   484,
     166,   252,   253,   254,   423,   485,   137,   138,   139,   140,
     255,   256,   335,   141,   142,   245,   486,    74,   490,   127,
     128,   129,   487,    47,   491,   362,   438,   468,   364,   121,
     500,   474,   130,   277,   105,   102,   131,   132,   115,   106,
     120,   438,   186,   438,   381,   523,   269,   525,   384,   133,
     134,   316,   315,   186,   346,   347,   348,   349,   350,   135,
     136,   438,    47,   211,   186,   539,   122,   390,   123,   327,
     127,   128,   129,   271,    47,   126,   358,   164,   213,   250,
     251,   124,    78,   130,   125,   272,   170,   131,   132,   166,
      47,   276,   372,   257,   258,   137,   138,   139,   140,     8,
     133,   134,   141,   142,   437,   438,   259,   260,   261,   262,
     135,   136,   336,   338,   171,   218,   267,   222,   127,   128,
     129,   286,    47,   228,   351,   352,   353,   354,   355,   356,
     229,   130,   230,   231,   399,   232,   187,   407,   344,   345,
     266,   235,   263,   314,   236,   290,   137,   138,   139,   140,
     237,   238,   239,   141,   142,   187,   240,   280,   393,   284,
     285,   287,   214,   186,   288,   401,   186,   456,   186,   457,
     289,   460,   291,   292,   166,   246,   294,   298,   364,   295,
     424,   299,   312,   363,   187,   187,   187,   458,   322,   335,
     325,   381,   331,   328,   475,   329,   339,   361,   187,   360,
     368,   378,   369,   387,   443,   370,   446,   373,   374,   187,
     447,   375,   376,   383,   385,   391,   461,   160,   454,   409,
     187,    83,    84,    85,    86,    87,   394,   411,   381,   381,
     412,   462,   413,   414,   415,   416,   417,   418,   421,   419,
     463,   401,   386,   451,   425,   314,   427,   389,   426,   428,
     518,   433,   429,   430,   186,   431,   481,   439,   441,   444,
     452,   381,   187,   187,   489,   477,   187,   465,   458,   466,
     494,   478,   341,   342,   343,   497,   479,   482,    89,    90,
      91,    92,    93,   483,   488,   528,    95,    96,    97,    98,
     492,   493,   495,   496,   187,   508,   512,   187,   509,   515,
     514,   186,   517,   186,   326,   520,   534,   535,   186,   529,
     532,   533,   542,   187,   543,   547,   548,   187,   359,   187,
     330,   158,   187,   420,   187,   551,   459,   317,   552,   401,
     555,   556,   464,   440,   275,   297,   187,   357,   109,   186,
     540,   541,   395,   404,   544,   545,   396,   506,   507,   233,
       0,   510,   511,     0,   549,   550,     0,     0,     0,   553,
     554,     0,     0,   557,   558,     0,   186,   559,   560,   186,
     186,     0,   186,     0,     0,     0,     0,   530,   531,     0,
     467,     0,   469,     0,     0,   187,     0,   476,     0,     0,
       0,     0,   186,     0,   186,   186,     0,     0,     0,     0,
       0,     0,   127,   128,   129,   405,    47,     0,   186,     0,
     187,     0,     0,     0,     0,   130,     0,   406,   499,   131,
     132,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   133,   134,     0,     0,   187,     0,   187,     0,
     187,     0,   135,   136,     0,   519,     0,   187,   521,   522,
       0,   524,     0,     0,     0,     0,     0,   187,     0,   187,
     187,     0,     0,   187,   187,     0,     0,     0,     0,     0,
       0,   536,     0,   537,   538,     0,     0,     0,   137,   138,
     139,   140,     0,     0,     0,   141,   142,   546,   108,     0,
       0,     0,     0,     0,     0,   187,     0,   187,   187,     0,
      83,    84,    85,    86,    87,     0,     1,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   187,
       0,     0,   187,     0,     0,   187,   187,     0,   187,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,   187,     0,
     187,   187,     0,     8,     0,     0,     0,    89,    90,    91,
      92,    93,     0,     0,   187,    95,    96,    97,    98,   127,
     128,   129,   397,    47,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,   398,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
     134,    83,    84,    85,    86,    87,     0,     0,     0,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,    83,    84,
      85,    86,    87,     0,     0,   137,   138,   139,   140,     0,
       0,     0,   141,   142,     0,     0,     0,     0,    89,    90,
      91,    92,    93,     0,     0,     0,    95,    96,    97,    98,
     127,   128,   129,     0,    47,     0,    83,    84,    85,    86,
      87,     0,     0,   130,     0,     0,     0,   131,   132,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
     133,   134,     0,    95,    96,    97,    98,     0,     0,     0,
     135,   136,   172,     0,   173,   174,   175,   176,   177,   178,
     392,     0,     0,   179,   180,   181,     0,     3,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,     0,     0,
       0,    95,    96,    97,    98,     0,   137,   138,   139,   140,
      99,     0,     0,   141,   142,     0,     0,     0,   165,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,   127,   128,   129,     0,    47,
       0,     0,   182,     0,   183,     0,     0,     0,   130,     0,
     184,   185,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   172,     0,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   179,   180,
     181,     0,     3,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   137,   138,   139,   140,     0,     0,     0,   141,   142,
       0,     0,     0,     0,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
     127,   128,   129,     0,    47,     0,     0,   182,     0,   183,
       0,     0,     0,   130,     0,   184,   296,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   172,     0,   173,   174,   175,   176,   177,   178,
       0,     0,     0,   179,   180,   181,     0,     3,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   137,   138,   139,   140,
       0,     0,     0,   141,   142,     0,     0,     0,     0,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,   127,   128,   129,     0,    47,
       0,     0,   182,     0,   183,     0,     0,     0,   130,     0,
     184,   313,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   172,     0,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   179,   180,
     181,     0,     3,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   137,   138,   139,   140,     0,     0,     0,   141,   142,
       0,     0,     0,     0,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
     127,   128,   129,     0,    47,     0,     0,   182,     0,   183,
       0,     0,     0,   130,     0,   184,   388,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   172,     0,   173,   174,   175,   176,   177,   178,
       0,     0,     0,   179,   180,   181,     0,     3,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   137,   138,   139,   140,
       0,     0,     0,   141,   142,     0,     0,     0,     0,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,   127,   128,   129,     0,    47,
       1,     0,   182,     0,   183,     2,     3,     0,   130,     0,
     184,     0,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,    83,    84,    85,
      86,    87,    88,     0,     0,   135,   136,     0,     4,     5,
       6,     7,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   137,   138,   139,   140,     0,     0,     0,   141,   142,
       0,     0,     0,     0,    89,    90,    91,    92,    93,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      89,    90,    91,    92,    93,     0,     0,     0,    95,    96,
      97,    98,   127,   128,   129,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   131,
     132,   127,   128,   129,     0,    47,     0,   281,   282,     0,
       0,     0,   133,   134,   130,     0,     0,     0,   131,   132,
       0,     0,   135,   136,     0,     0,     0,     0,     0,     0,
       0,   133,   134,   127,   128,   129,     0,    47,     0,   278,
       0,   135,   136,     0,     0,     0,   130,     0,     0,     0,
     131,   132,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,     0,   133,   134,   141,   142,     0,     0,     0,
       0,     0,     0,   135,   136,     0,     0,   137,   138,   139,
     140,     0,     0,     0,   141,   142,     0,     0,   127,   128,
     129,     0,    47,     0,   371,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   131,   132,     0,     0,   137,
     138,   139,   140,     0,     0,     0,   141,   142,   133,   134,
       0,   127,   128,   129,     0,    47,     0,     0,   135,   136,
     380,     0,     0,     0,   130,     0,     0,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,     0,   137,   138,   139,   140,     0,     0,
       0,   141,   142,     0,     0,     0,   127,   128,   129,     0,
      47,     0,     0,     0,     0,   435,     0,     0,     0,   130,
       0,     0,     0,   131,   132,     0,     0,   137,   138,   139,
     140,     0,     0,     0,   141,   142,   133,   134,   127,   128,
     129,     0,    47,     0,   442,     0,   135,   136,     0,     0,
       0,   130,     0,     0,     0,   131,   132,   127,   128,   129,
       0,    47,     0,   445,     0,     0,     0,     0,   133,   134,
     130,     0,     0,     0,   131,   132,     0,     0,   135,   136,
       0,     0,   137,   138,   139,   140,     0,   133,   134,   141,
     142,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   129,
     453,    47,     0,     0,   137,   138,   139,   140,     0,     0,
     130,   141,   142,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,   140,   133,   134,     0,
     141,   142,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   129,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   470,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,   140,   133,   134,     0,
     141,   142,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   129,
       0,    47,     0,     0,     0,     0,   473,     0,     0,     0,
     130,     0,     0,     0,   131,   132,   127,   128,   129,     0,
      47,     0,   480,   137,   138,   139,   140,   133,   134,   130,
     141,   142,     0,   131,   132,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,   133,   134,   127,   128,
     129,     0,    47,     0,     0,     0,   135,   136,     0,     0,
       0,   130,   501,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   137,   138,   139,   140,     0,   133,   134,
     141,   142,     0,     0,     0,     0,     0,     0,   135,   136,
       0,     0,   137,   138,   139,   140,     0,     0,     0,   141,
     142,     0,     0,   127,   128,   129,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   503,     0,     0,
     131,   132,     0,     0,   137,   138,   139,   140,     0,     0,
       0,   141,   142,   133,   134,   127,   128,   129,   516,    47,
       0,     0,     0,   135,   136,     0,     0,     0,   130,     0,
       0,     0,   131,   132,   127,   128,   129,     0,    47,     0,
       0,     0,     0,     0,     0,   133,   134,   130,   526,     0,
       0,   131,   132,     0,     0,   135,   136,     0,     0,   137,
     138,   139,   140,     0,   133,   134,   141,   142,     0,    83,
      84,    85,    86,    87,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   129,     0,    47,     0,
       0,   137,   138,   139,   140,     0,     0,   130,   141,   142,
       0,   131,   132,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   133,   134,     0,   141,   142,    83,
      84,    85,    86,    87,   135,   136,    89,    90,    91,    92,
      93,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,     0,     0,     0,   141,   142,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,     0,     0,     0,    95,    96,    97,    98,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
       1,     2,    29,    29,     0,   115,   102,    29,   102,   285,
     398,   287,     0,     0,     0,    86,   130,    75,    99,    65,
     101,    81,    82,    85,    81,     0,   120,    28,    74,   435,
      87,   112,   113,     0,    30,     0,    75,    99,     0,   110,
      81,    81,    30,    30,    30,   159,   160,   161,    60,    61,
      62,    63,    64,    65,   116,    30,    68,    69,    70,    71,
      72,    73,    74,    30,    76,    30,   472,   473,    30,   110,
     110,    84,    86,    85,    82,   102,    77,    89,    90,    76,
      88,    86,    86,    75,    83,    91,    92,    88,    19,   115,
     102,   103,    98,    87,   120,    99,   110,   101,   486,   505,
     112,   113,    82,   161,   380,   110,    86,   165,   112,   113,
     111,   110,   170,   114,    85,    76,    77,   113,   214,    82,
     214,    87,   180,   237,   238,    88,    75,   241,    82,    82,
     226,    95,    96,    97,    88,    88,   148,   149,   150,   151,
     104,   105,   238,   155,   156,   146,    82,    75,    82,    72,
      73,    74,    88,    76,    88,   269,    82,   433,   272,   116,
      86,   437,    85,   164,   191,   191,    89,    90,    85,   191,
      85,    82,   173,    82,   288,    86,    99,    86,   292,   102,
     103,   208,   208,   184,   252,   253,   254,   255,   256,   112,
     113,    82,    76,    77,   195,    86,   116,   311,   116,   226,
      72,    73,    74,    75,    76,    82,   264,     8,   318,    89,
      90,   116,   213,    85,   116,    87,    85,    89,    90,   315,
      76,    77,   280,    93,    94,   148,   149,   150,   151,    65,
     102,   103,   155,   156,    81,    82,   106,   107,   108,   109,
     112,   113,   238,   239,    85,    74,   360,    75,    72,    73,
      74,   173,    76,    72,   257,   258,   259,   260,   261,   262,
      75,    85,    75,    75,   322,    75,   111,   325,   250,   251,
      86,    85,   111,   195,    85,    81,   148,   149,   150,   151,
      85,    85,    85,   155,   156,   130,    85,    85,   315,    78,
      85,    85,   318,   294,    85,   322,   297,   411,   299,   413,
      80,   415,    81,    85,   400,   150,    84,    81,   422,    85,
     368,    84,    81,   100,   159,   160,   161,   413,    82,   415,
      82,   435,    77,    86,   438,    86,    86,    86,   173,    82,
     114,    12,    86,    72,   392,    86,   394,    86,    86,   184,
     398,    86,    86,    81,    84,    81,    74,    99,   406,    86,
     195,     3,     4,     5,     6,     7,    85,    82,   472,   473,
      86,   419,    82,    86,    82,    86,    82,   100,   100,    84,
     100,   398,   294,   400,    91,   297,    86,   299,    91,    86,
     494,    85,    91,    91,   385,    91,   444,    86,    86,    85,
      85,   505,   237,   238,   452,    81,   241,    91,   494,    91,
      82,    86,   247,   248,   249,    10,    86,    86,    60,    61,
      62,    63,    64,    86,    85,   116,    68,    69,    70,    71,
      86,    86,    86,    86,   269,    86,   484,   272,    86,    86,
     488,   432,   490,   434,    86,    81,    86,    86,   439,   116,
     116,   116,   116,   288,   116,   114,   114,   292,   265,   294,
     235,    77,   297,   360,   299,   114,   415,   213,   114,   486,
     114,   114,   422,   385,   161,   184,   311,   263,    30,   470,
     528,   529,   318,   323,   532,   533,   320,   478,   479,   126,
      -1,   482,   483,    -1,   542,   543,    -1,    -1,    -1,   547,
     548,    -1,    -1,   551,   552,    -1,   497,   555,   556,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,   508,   509,    -1,
     432,    -1,   434,    -1,    -1,   360,    -1,   439,    -1,    -1,
      -1,    -1,   523,    -1,   525,   526,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    -1,   539,    -1,
     385,    -1,    -1,    -1,    -1,    85,    -1,    87,   470,    89,
      90,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   102,   103,    -1,    -1,   411,    -1,   413,    -1,
     415,    -1,   112,   113,    -1,   497,    -1,   422,   500,   501,
      -1,   503,    -1,    -1,    -1,    -1,    -1,   432,    -1,   434,
     435,    -1,    -1,   438,   439,    -1,    -1,    -1,    -1,    -1,
      -1,   523,    -1,   525,   526,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   539,     0,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,   472,   473,    -1,
       3,     4,     5,     6,     7,    -1,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,   497,    -1,    -1,   500,   501,    -1,   503,    -1,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,   523,    -1,
     525,   526,    -1,    65,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    -1,   539,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,     3,     4,     5,     6,     7,    -1,    -1,    -1,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,   148,   149,   150,   151,    -1,
      -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
     102,   103,    -1,    68,    69,    70,    71,    -1,    -1,    -1,
     112,   113,     9,    -1,    11,    12,    13,    14,    15,    16,
      85,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    71,    -1,   148,   149,   150,   151,
      77,    -1,    -1,   155,   156,    -1,    -1,    -1,    85,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    76,
      -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,     9,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,     9,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    76,
      -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,     9,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,     9,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    76,
      18,    -1,    79,    -1,    81,    23,    24,    -1,    85,    -1,
      87,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,     3,     4,     5,
       6,     7,     8,    -1,    -1,   112,   113,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,
      -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      90,    72,    73,    74,    -1,    76,    -1,    78,    79,    -1,
      -1,    -1,   102,   103,    85,    -1,    -1,    -1,    89,    90,
      -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,    72,    73,    74,    -1,    76,    -1,    78,
      -1,   112,   113,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,   102,   103,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,    -1,    -1,    72,    73,
      74,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    90,    -1,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,   102,   103,
      -1,    72,    73,    74,    -1,    76,    -1,    -1,   112,   113,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,    -1,    -1,    -1,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    90,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   102,   103,    72,    73,
      74,    -1,    76,    -1,    78,    -1,   112,   113,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    90,    72,    73,    74,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,   102,   103,
      85,    -1,    -1,    -1,    89,    90,    -1,    -1,   112,   113,
      -1,    -1,   148,   149,   150,   151,    -1,   102,   103,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      85,   155,   156,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   102,   103,    -1,
     155,   156,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   102,   103,    -1,
     155,   156,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    90,    72,    73,    74,    -1,
      76,    -1,    78,   148,   149,   150,   151,   102,   103,    85,
     155,   156,    -1,    89,    90,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    72,    73,
      74,    -1,    76,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,   102,   103,
     155,   156,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,    -1,    -1,    72,    73,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      89,    90,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,   102,   103,    72,    73,    74,    75,    76,
      -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    89,    90,    72,    73,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    85,    86,    -1,
      -1,    89,    90,    -1,    -1,   112,   113,    -1,    -1,   148,
     149,   150,   151,    -1,   102,   103,   155,   156,    -1,     3,
       4,     5,     6,     7,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    76,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,    85,   155,   156,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   102,   103,    -1,   155,   156,     3,
       4,     5,     6,     7,   112,   113,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    23,    24,    56,    57,    58,    59,    65,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   182,   183,   184,   189,
     209,   210,   211,   212,   213,   214,   215,   222,   223,   226,
     227,   228,   229,   230,   231,   240,   241,    76,   163,   163,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   224,
     225,    75,    75,    75,    75,    85,    81,    82,   163,   193,
     197,   198,   199,     3,     4,     5,     6,     7,     8,    60,
      61,    62,    63,    64,    67,    68,    69,    70,    71,    77,
     185,   186,   187,   188,   190,   191,   192,   216,     0,   210,
      81,    87,   219,    84,    19,    85,    87,   232,    87,   242,
      85,   116,   116,   116,   116,   116,    82,    72,    73,    74,
      85,    89,    90,   102,   103,   112,   113,   148,   149,   150,
     151,   155,   156,   162,   163,   164,   165,   166,   167,   168,
     170,   171,   172,   173,   174,   175,   176,   177,   193,    85,
      99,   116,    77,   163,     8,    85,   188,   190,   191,   192,
      85,    85,     9,    11,    12,    13,    14,    15,    16,    20,
      21,    22,    79,    81,    87,    88,   163,   166,   177,   178,
     182,   189,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   222,   223,   226,   227,   228,   229,   248,   189,   217,
     218,    77,   163,   185,   187,   191,   220,   221,    74,   233,
     234,   235,    75,   243,   244,   245,   187,   190,    72,    75,
      75,    75,    75,   225,   178,    85,    85,    85,    85,    85,
      85,    99,   101,   112,   113,   163,   166,    91,    92,    98,
      89,    90,    95,    96,    97,   104,   105,    93,    94,   106,
     107,   108,   109,   111,    83,   110,    86,   178,   181,    99,
     178,    75,    87,   177,   178,   194,    77,   163,    78,   177,
      85,    78,    79,   177,    78,    85,   204,    85,    85,    80,
      81,    81,    85,   177,    84,    85,    88,   203,    81,    84,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   179,    81,    88,   204,   187,   191,   197,    82,    86,
      82,    88,    82,    82,    88,    82,    86,   191,    86,    86,
     164,    77,   178,   169,   178,   188,   189,    74,   189,    86,
     178,   166,   166,   166,   171,   171,   172,   172,   172,   172,
     172,   173,   173,   173,   173,   173,   173,   174,   177,   175,
      82,    86,   178,   100,   178,   194,   195,   196,   114,    86,
      86,    78,   177,    86,    86,    86,    86,   176,    12,   176,
      81,   178,   180,    81,   178,    84,   204,    72,    88,   204,
     178,    81,    85,   191,    85,   221,   234,    75,    87,   177,
     187,   191,   237,   239,   244,    75,    87,   177,   246,    86,
      86,    82,    86,    82,    86,    82,    86,    82,   100,    84,
     181,   100,    82,    88,   177,    91,    91,    86,    86,    91,
      91,    91,    86,    85,    86,    81,   176,    81,    82,    86,
     204,    86,    78,   177,    85,    78,   177,   177,   236,   237,
     238,   191,    85,    75,   177,   247,   178,   178,   188,   169,
     178,    74,   177,   100,   196,    91,    91,   204,   176,   204,
      86,   180,    81,    81,   176,   178,   204,    81,    86,    86,
      78,   177,    86,    86,    82,    88,    82,    88,    85,   177,
      82,    88,    86,    86,    82,    86,    86,    10,    86,   204,
      86,    86,   180,    86,   180,    81,   163,   163,    86,    86,
     163,   163,   177,   237,   177,    86,    75,   177,   178,   204,
      81,   204,   204,    86,   204,    86,    86,   180,   116,   116,
     163,   163,   116,   116,    86,    86,   204,   204,   204,    86,
     177,   177,   116,   116,   177,   177,   204,   114,   114,   177,
     177,   114,   114,   177,   177,   114,   114,   177,   177,   177,
     177
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { (yyval.np) = eval_ident((yyvsp[(1) - (1)].sp)); ;}
    break;

  case 3:

    { (yyval.np) = leafi(INT_LITERAL, (yyvsp[(1) - (1)].ival)); ;}
    break;

  case 4:

    { (yyval.np) = leafd(DOUBLE_LITERAL, (yyvsp[(1) - (1)].dval)); ;}
    break;

  case 5:

    { (yyval.np) = leafi(INT_LITERAL, (yyvsp[(1) - (1)].bit)->val); free_memt((yyvsp[(1) - (1)].bit)); ;}
    break;

  case 6:

    { (yyval.np) = (yyvsp[(2) - (3)].np); (yyval.np)->paren = 1; ;}
    break;

  case 9:

    { (yyval.np) = eval_subarray((yyvsp[(1) - (4)].np), (yyvsp[(3) - (4)].np)); ;}
    break;

  case 10:

    { 
        (yyval.np) = eval_scoped((yyvsp[(1) - (2)].np), (yyvsp[(2) - (2)].sp));

        /* remove two temporary contexts */
        s_remcontext();
        s_remcontext();
    ;}
    break;

  case 11:

    { (yyval.np) = eval_incdec((yyvsp[(2) - (2)].ival), (yyvsp[(1) - (2)].np)); ;}
    break;

  case 12:

    { (yyval.np) = eval_incdec((yyvsp[(2) - (2)].ival), (yyvsp[(1) - (2)].np)); ;}
    break;

  case 13:

    {
        /* activate the context of the class; if not available, eval_scoped above will catch it */
        if ((yyvsp[(1) - (2)].np)->ptype!=NULL && (yyvsp[(1) - (2)].np)->ptype->cxt!=NULL) s_inscontext((yyvsp[(1) - (2)].np)->ptype->cxt);
        /* add another context to protect the class members */
        s_newcontext(0);
        (yyval.np) = (yyvsp[(1) - (2)].np);
    ;}
    break;

  case 15:

    { (yyval.np) = eval_array((yyvsp[(1) - (1)].np)); ;}
    break;

  case 16:

    { (yyval.np) = eval_unary((yyvsp[(1) - (2)].ival), (yyvsp[(2) - (2)].np)); ;}
    break;

  case 17:

    { (yyval.np) = eval_lengthof(eval_array((yyvsp[(3) - (4)].np))); ;}
    break;

  case 18:

    { (yyval.np) = eval_isidof((yyvsp[(3) - (6)].sp), (yyvsp[(5) - (6)].np)); ;}
    break;

  case 19:

    { (yyval.np) = eval_skipbits((yyvsp[(3) - (4)].np)); ;}
    break;

  case 21:

    { 
        (yyval.np) = node(NEXTCODE, leafb(BIT_LITERAL, (yyvsp[(3) - (4)].bit)), NULL);
        (yyval.np)->type=INT; (yyval.np)->ptype = s_lookup("int"); 
    ;}
    break;

  case 22:

    { 
        (yyval.np)=node(NEXTCODE, leafb(BIT_LITERAL, (yyvsp[(5) - (6)].bit)), (yyvsp[(3) - (6)].np));
        (yyval.np)->type = INT; (yyval.np)->ptype = s_lookup("int"); 
    ;}
    break;

  case 23:

    { (yyval.np) = leaf(NUMBITS); (yyval.np)->type = INT; (yyval.np)->ptype = s_lookup("int"); ;}
    break;

  case 24:

    { (yyval.np) = eval_nextbits((yyvsp[(3) - (4)].np), 0, NULL); ;}
    break;

  case 25:

    { (yyval.np) = eval_nextbits((yyvsp[(5) - (6)].np), (yyvsp[(3) - (6)].ival), NULL); ;}
    break;

  case 26:

    { (yyval.np) = eval_nextbits((yyvsp[(5) - (6)].np), 0, (yyvsp[(3) - (6)].np)); ;}
    break;

  case 27:

    { (yyval.np) = eval_nextbits((yyvsp[(7) - (8)].np), (yyvsp[(5) - (8)].ival), (yyvsp[(3) - (8)].np)); ;}
    break;

  case 28:

    { (yyval.ival) = s_tok2mod((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 29:

    { (yyval.ival) = check_mod((yyvsp[(1) - (3)].ival), s_tok2mod((yyvsp[(3) - (3)].ival))); ;}
    break;

  case 37:

    { (yyval.np) = eval_mult((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 38:

    { (yyval.np) = eval_mult((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 39:

    { (yyval.np) = eval_mult((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 41:

    { (yyval.np) = eval_add((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 42:

    { (yyval.np) = eval_add((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 44:

    { (yyval.np) = eval_shift((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 45:

    { (yyval.np) = eval_shift((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 46:

    { (yyval.np) = eval_shift((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 47:

    { (yyval.np) = eval_shift((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 48:

    { (yyval.np) = eval_shift((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 50:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 51:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 52:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 53:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 54:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 55:

    { (yyval.np) = eval_rel((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 57:

    { (yyval.np) = eval_logic((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 58:

    { (yyval.np) = check_unassigned((yyvsp[(1) - (1)].np), (yyvsp[(1) - (1)].np)); ;}
    break;

  case 59:

    { (yyval.np) = eval_logic((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 61:

    { (yyval.np) = eval_cond((yyvsp[(2) - (5)].ival), (yyvsp[(1) - (5)].np), (yyvsp[(3) - (5)].np), (yyvsp[(5) - (5)].np)); ;}
    break;

  case 63:

    { (yyval.np) = check_assign((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 76:

    { (yyval.np) = node((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 78:

    { (yyval.np) = node((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); ;}
    break;

  case 80:

    {
        (yyval.lp) = (yyvsp[(2) - (2)].lp);

        /* copy parse, align, and usenext */
        (yyval.lp)->e2 = check_parse((yyvsp[(1) - (2)].lp)->sp, (yyvsp[(1) - (2)].lp)->type, (yyvsp[(1) - (2)].lp)->e1);
        
        /* also check for lookahead parsing of escaped maps */
        if ((yyvsp[(1) - (2)].lp)->usenext && (yyvsp[(1) - (2)].lp)->e1->op == MAP_TYPE && (yyvsp[(1) - (2)].lp)->e1->left.sp->escape)
            yyerror("Map with escape (%s) cannot be used in lookahead parsing", (yyvsp[(1) - (2)].lp)->e1->left.sp->name);

        /* check that for a bac, the declarator must be accompanied with param types */
        if ((yyvsp[(1) - (2)].lp)->e1 && (yyvsp[(1) - (2)].lp)->e1->op == BAC_TYPE) 
            if ((yyvsp[(2) - (2)].lp) == NULL || (yyvsp[(2) - (2)].lp)->e3 == NULL)
                yyerror("BAC (%s) must be accompanied with corresponding parameters", (yyvsp[(1) - (2)].lp)->e1->left.sp->name);
        
        (yyval.lp)->align = (yyvsp[(1) - (2)].lp)->align;
        (yyval.lp)->usenext = (yyvsp[(1) - (2)].lp)->usenext;
        
        /* if BIT type, treat as unsigned */
        if ((yyvsp[(1) - (2)].lp)->sp->ident == BIT) (yyvsp[(1) - (2)].lp)->type |= M_UNSIGNED;
        
        /* set type, mods, parse, init, check param, check alignment, dims and dim values */
        (yyval.lp)->sp = set_var((yyval.lp)->sp, (yyvsp[(1) - (2)].lp)->sp, (yyvsp[(1) - (2)].lp)->type, (yyvsp[(2) - (2)].lp)->e2, (yyvsp[(2) - (2)].lp)->e1, (yyvsp[(2) - (2)].lp)->e3, (yyvsp[(1) - (2)].lp)->align, (yyvsp[(2) - (2)].lp)->dims, (yyvsp[(2) - (2)].lp)->dim, 0, (yyval.lp)->sp->range);
        
        /* if we have a static array declaration of a non-global variable, unroll it */
        if ((yyvsp[(2) - (2)].lp)->e1 != NULL && (yyvsp[(2) - (2)].lp)->e1->op == ARRAY && (yyvsp[(2) - (2)].lp)->sp->cxt_level > 0)
            (yyval.lp) = c_array_unroll((yyval.lp)); 
    ;}
    break;

  case 81:

    {
        /* copy parse, align, and usenext */
        (yyvsp[(3) - (3)].lp)->e2 = (yyvsp[(1) - (3)].lp)->e2;
        (yyvsp[(3) - (3)].lp)->align = (yyvsp[(1) - (3)].lp)->align;
        (yyvsp[(3) - (3)].lp)->usenext = (yyvsp[(1) - (3)].lp)->usenext;
 
        /* set type, mods, parse, init, check param, check alignment, dims and dim values */
        (yyvsp[(3) - (3)].lp)->sp = set_var((yyvsp[(3) - (3)].lp)->sp, (yyvsp[(1) - (3)].lp)->sp->ptype, (yyvsp[(1) - (3)].lp)->sp->modifiers, (yyvsp[(3) - (3)].lp)->e2, (yyvsp[(3) - (3)].lp)->e1, (yyvsp[(3) - (3)].lp)->e3, (yyvsp[(1) - (3)].lp)->align, (yyvsp[(3) - (3)].lp)->dims, (yyvsp[(3) - (3)].lp)->dim, 0, (yyvsp[(3) - (3)].lp)->sp->range);
 
        /* if we have a static array declaration of a non-global variable, unroll it */
        if ((yyvsp[(3) - (3)].lp)->e1 != NULL && (yyvsp[(3) - (3)].lp)->e1->op == ARRAY && (yyvsp[(3) - (3)].lp)->sp->cxt_level > 0)
            (yyval.lp) = app((yyvsp[(1) - (3)].lp), c_array_unroll((yyvsp[(3) - (3)].lp))); 
        else
            (yyval.lp) = app((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp));
    ;}
    break;

  case 82:

    { (yyvsp[(2) - (2)].lp)->align = (yyvsp[(1) - (2)].np); (yyval.lp) = (yyvsp[(2) - (2)].lp); ;}
    break;

  case 83:

    { (yyvsp[(2) - (2)].lp)->align = (yyvsp[(1) - (2)].np); (yyval.lp) = (yyvsp[(2) - (2)].lp); ;}
    break;

  case 84:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (1)].sp), NULL, 0); ;}
    break;

  case 85:

    {
        if (!((yyvsp[(1) - (1)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified");
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (1)].ival), s_lookup("int")), s_lookup("int"), NULL, 0);
    ;}
    break;

  case 86:

    {
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (2)].ival), (yyvsp[(2) - (2)].sp)), (yyvsp[(2) - (2)].sp), NULL, 0);
    ;}
    break;

  case 87:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (4)].sp), (yyvsp[(3) - (4)].np), 0); ;}
    break;

  case 88:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (4)].sp), leafs(MAP_TYPE, (yyvsp[(3) - (4)].sp)), 0); ;}
    break;

  case 89:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (4)].sp), leafs(MAP_TYPE, (yyvsp[(3) - (4)].sp)), 0); ;}
    break;

  case 90:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (5)].sp), (yyvsp[(3) - (5)].np), 1); ;}
    break;

  case 91:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (5)].sp), leafs(MAP_TYPE, (yyvsp[(3) - (5)].sp)), 1); ;}
    break;

  case 92:

    { (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (5)].sp), leafs(MAP_TYPE, (yyvsp[(3) - (5)].sp)), 1); ;}
    break;

  case 93:

    {
        if (!((yyvsp[(1) - (4)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified");
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (4)].ival), s_lookup("int")), s_lookup("int"), (yyvsp[(3) - (4)].np), 0);
    ;}
    break;

  case 94:

    {
        if (!((yyvsp[(1) - (4)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified");
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (4)].ival), s_lookup("int")), s_lookup("int"), leafs(MAP_TYPE, (yyvsp[(3) - (4)].sp)), 0);
    ;}
    break;

  case 95:

    {
        if (!((yyvsp[(1) - (5)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified");
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (5)].ival), s_lookup("int")), s_lookup("int"), (yyvsp[(3) - (5)].np), 1);
    ;}
    break;

  case 96:

    {
        if (!((yyvsp[(1) - (5)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified");
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (5)].ival), s_lookup("int")), s_lookup("int"), leafs(MAP_TYPE, (yyvsp[(3) - (5)].sp)), 1);
    ;}
    break;

  case 97:

    {
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (5)].ival), (yyvsp[(2) - (5)].sp)), (yyvsp[(2) - (5)].sp), (yyvsp[(4) - (5)].np), 0);
    ;}
    break;

  case 98:

    {
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (5)].ival), (yyvsp[(2) - (5)].sp)), (yyvsp[(2) - (5)].sp), leafs(MAP_TYPE, (yyvsp[(4) - (5)].sp)), 0);
    ;}
    break;

  case 99:

    {
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (6)].ival), (yyvsp[(2) - (6)].sp)), (yyvsp[(2) - (6)].sp), (yyvsp[(4) - (6)].np), 1);
    ;}
    break;

  case 100:

    {
        (yyval.lp) = lnew_type(check_modtype((yyvsp[(1) - (6)].ival), (yyvsp[(2) - (6)].sp)), (yyvsp[(2) - (6)].sp), leafs(MAP_TYPE, (yyvsp[(4) - (6)].sp)), 1);
    ;}
    break;

  case 101:

    {
        (yyval.lp) = lnew_type(M_NONE, (yyvsp[(1) - (4)].sp), leafs(BAC_TYPE, (yyvsp[(3) - (4)].sp)), 0);
    ;}
    break;

  case 102:

    { (yyval.ival) = s_tok2mod((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 103:

    { (yyval.ival) = check_mod((yyvsp[(1) - (2)].ival), s_tok2mod((yyvsp[(2) - (2)].ival))); ;}
    break;

  case 113:

    { (yyval.np) = NULL; ;}
    break;

  case 114:

    { (yyval.np) = leafi(INT_LITERAL, 8); ;}
    break;

  case 115:

    { (yyval.np) = check_align_arg((yyvsp[(3) - (4)].np)); ;}
    break;

  case 123:

    {
        if (w_cyclic && s_get_cur_class() == (yyvsp[(1) - (1)].sp)) 
            yyerror("Declaration creates cyclic reference in class '%s'", (yyvsp[(1) - (1)].sp)->name);
        (yyval.sp) = (yyvsp[(1) - (1)].sp);
    ;}
    break;

  case 125:

    {   
        (yyvsp[(1) - (3)].lp)->sp->assigned = 1;
        (yyvsp[(1) - (3)].lp)->e1 = (yyvsp[(3) - (3)].np);
        (yyval.lp) = (yyvsp[(1) - (3)].lp);
    ;}
    break;

  case 126:

    {
        (yyvsp[(1) - (3)].lp)->sp->assigned = 1;
        (yyvsp[(1) - (3)].lp)->e1 = (yyvsp[(3) - (3)].np);
        (yyval.lp) = (yyvsp[(1) - (3)].lp);
    ;}
    break;

  case 129:

    { 
        (yyval.np) = node(ARRAY, (yyvsp[(2) - (3)].np), NULL); 
        (yyval.np)->ptype = (yyvsp[(2) - (3)].np)->ptype;
        (yyval.np)->type = (yyvsp[(2) - (3)].np)->type;
    ;}
    break;

  case 130:

    {
        (yyval.np) = node(ARRAY, eval_array_string((yyvsp[(1) - (1)].string)), NULL);
        (yyval.np)->ptype = s_lookup("char");
        (yyval.np)->type = CHAR;
    ;}
    break;

  case 132:

    { 
        (yyval.np) = node((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].np), (yyvsp[(3) - (3)].np)); 
        (yyval.np)->ptype = check_type_promote((yyvsp[(1) - (3)].np)->ptype, (yyvsp[(3) - (3)].np)->ptype);
        (yyval.np)->type = (yyval.np)->ptype->ident;
    ;}
    break;

  case 135:

    { (yyval.lp) = lnew_sp(DECL, (yyvsp[(1) - (1)].sp)); ;}
    break;

  case 136:

    {
        /* TBD: If the array is not parsable and not initialized, then the dimx_end variable is useless */
        s_cur_class_dimx_nonpartial((yyvsp[(1) - (4)].lp)->dims, 1);
        (yyvsp[(1) - (4)].lp)->dims++;
        (yyvsp[(1) - (4)].lp)->dim = (node_t **)buildarray((void **)(yyvsp[(1) - (4)].lp)->dim, node((yyvsp[(2) - (4)].ival), check_array_size((yyvsp[(3) - (4)].np)), NULL));
        (yyval.lp) = (yyvsp[(1) - (4)].lp);
    ;}
    break;

  case 137:

    {
        s_cur_class_dimx_nonpartial((yyvsp[(1) - (6)].lp)->dims, 0);
        (yyvsp[(1) - (6)].lp)->dims++;
        (yyvsp[(1) - (6)].lp)->dim = (node_t **)buildarray((void **)(yyvsp[(1) - (6)].lp)->dim, node(DBL_BRACE_L, check_array_index((yyvsp[(4) - (6)].np)), NULL));
        (yyval.lp) = (yyvsp[(1) - (6)].lp);
    ;}
    break;

  case 138:

    {
        /* add argument expression list to declaration */
        (yyvsp[(1) - (4)].lp)->e3 = (yyvsp[(3) - (4)].np);
        (yyval.lp) = (yyvsp[(1) - (4)].lp);
    ;}
    break;

  case 139:

    {
        (yyvsp[(1) - (5)].lp)->sp->range = 1;
        (yyvsp[(1) - (5)].lp)->sp->assigned = 1;
        (yyvsp[(1) - (5)].lp)->e1 = idrange((yyvsp[(3) - (5)].np), (yyvsp[(5) - (5)].np));
        (yyval.lp) = (yyvsp[(1) - (5)].lp);   
    ;}
    break;

  case 147:

    { 
        if ((yyvsp[(1) - (3)].sp)->ptype != NULL) yyerror("Use of variable '%s' as a label is illegal", (yyvsp[(1) - (3)].sp)->name);
        (yyvsp[(1) - (3)].sp)->ident = LABEL;
        (yyval.lp) = prep((yyvsp[(3) - (3)].lp), lnew_sp(LABEL, (yyvsp[(1) - (3)].sp)));
    ;}
    break;

  case 148:

    {
        if ((yyvsp[(2) - (4)].np)->type > INT) yyerror("The 'case' expression must be of integral type");
        if (!is_literal((yyvsp[(2) - (4)].np)->op) || ((yyvsp[(2) - (4)].np)->op == VARIABLE && !((yyvsp[(2) - (4)].np)->left.sp->modifiers & M_CONST))) yyerror("The 'case' expression must be a constant");
        (yyval.lp) = lnews1((yyvsp[(1) - (4)].ival), (yyvsp[(2) - (4)].np), (yyvsp[(4) - (4)].lp));
    ;}
    break;

  case 149:

    { (yyval.lp) = lnews0((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].lp)); ;}
    break;

  case 150:

    { (yyval.lp) = lnew0((yyvsp[(1) - (2)].ival)); ;}
    break;

  case 151:

    { (yyval.lp) = lnews0((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].lp)); ;}
    break;

  case 153:

    { (yyval.lp) = app((yyvsp[(1) - (2)].lp), (yyvsp[(2) - (2)].lp)); ;}
    break;

  case 162:

    { (yyval.lp) = lnew0(EXPR); ;}
    break;

  case 163:

    { (yyval.lp) = lnew1(EXPR, (yyvsp[(1) - (2)].np)); ;}
    break;

  case 164:

    { (yyval.lp) = lnew_ifelse((yyvsp[(3) - (5)].np), (yyvsp[(5) - (5)].lp), NULL); ;}
    break;

  case 165:

    { (yyval.lp) = lnew_ifelse((yyvsp[(3) - (7)].np), (yyvsp[(5) - (7)].lp), (yyvsp[(7) - (7)].lp)); ;}
    break;

  case 166:

    {
        if ((yyvsp[(3) - (5)].np)->type>INT) yyerror("'switch' expression must be of integral type");
        (yyval.lp) = lnews1((yyvsp[(1) - (5)].ival), (yyvsp[(3) - (5)].np), (yyvsp[(5) - (5)].lp));
    ;}
    break;

  case 167:

    { (yyval.lp) = lnews1((yyvsp[(1) - (5)].ival), (yyvsp[(3) - (5)].np), (yyvsp[(5) - (5)].lp)); ;}
    break;

  case 168:

    { (yyval.lp) = lnews1((yyvsp[(1) - (7)].ival), (yyvsp[(5) - (7)].np), (yyvsp[(2) - (7)].lp)); ;}
    break;

  case 169:

    { (yyval.lp) = lnews3((yyvsp[(1) - (6)].ival), NULL, NULL, NULL, (yyvsp[(6) - (6)].lp)); ;}
    break;

  case 170:

    { (yyval.lp) = lnews3((yyvsp[(1) - (7)].ival), NULL, NULL, (yyvsp[(5) - (7)].np),   (yyvsp[(7) - (7)].lp)); ;}
    break;

  case 171:

    { (yyval.lp) = lnews3((yyvsp[(1) - (7)].ival), NULL, (yyvsp[(4) - (7)].np),   NULL, (yyvsp[(7) - (7)].lp)); ;}
    break;

  case 172:

    { (yyval.lp) = lnews3((yyvsp[(1) - (8)].ival), NULL, (yyvsp[(4) - (8)].np),   (yyvsp[(6) - (8)].np),   (yyvsp[(8) - (8)].lp)); ;}
    break;

  case 173:

    { (yyval.lp) = lnews3((yyvsp[(1) - (7)].ival), (yyvsp[(3) - (7)].np),   NULL, NULL, (yyvsp[(7) - (7)].lp)); ;}
    break;

  case 174:

    { (yyval.lp) = lnews3((yyvsp[(1) - (8)].ival), (yyvsp[(3) - (8)].np),   NULL, (yyvsp[(6) - (8)].np),   (yyvsp[(8) - (8)].lp)); ;}
    break;

  case 175:

    { (yyval.lp) = lnews3((yyvsp[(1) - (8)].ival), (yyvsp[(3) - (8)].np),   (yyvsp[(5) - (8)].np),   NULL, (yyvsp[(8) - (8)].lp)); ;}
    break;

  case 176:

    { (yyval.lp) = lnews3((yyvsp[(1) - (9)].ival), (yyvsp[(3) - (9)].np),   (yyvsp[(5) - (9)].np),   (yyvsp[(7) - (9)].np),   (yyvsp[(9) - (9)].lp)); ;}
    break;

  case 177:

    { (yyval.lp) = lnew_sp((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].sp)); ;}
    break;

  case 178:

    { (yyval.lp) = lnew0((yyvsp[(1) - (2)].ival)); ;}
    break;

  case 179:

    { (yyval.lp) = lnew0((yyvsp[(1) - (2)].ival)); ;}
    break;

  case 180:

    { 
        /* 'program' may be called multiple times (when we do includes) */
        (yyval.lp) = parsed_code=app(parsed_code, (yyvsp[(1) - (1)].lp));
    ;}
    break;

  case 181:

    { (yyval.lp) = app((yyvsp[(1) - (2)].lp), (yyvsp[(2) - (2)].lp)); ;}
    break;

  case 192:

    {
        if ((yyvsp[(1) - (2)].sp)->forward == 1) {
            (yyvsp[(1) - (2)].sp)->forward = 2; 
            /* check for cyclic references in contained members, if requested */
            if (w_cyclic) check_cyclic_decl_contained((yyvsp[(1) - (2)].sp), (yyvsp[(1) - (2)].sp)->forwardref);
        }
        /* if it has align spec, then it is considered parsable */
        if ((yyvsp[(1) - (2)].sp)->align != NULL) (yyvsp[(1) - (2)].sp)->parsable = 1;

        s_remcontext();         /* exit param type scope */
        s_remcontext();         /* exit class scope (will not be deleted) */
        s_set_cur_class(NULL);  /* exiting class decl */
        (yyval.lp) = lnews_sp(CLASS, (yyvsp[(1) - (2)].sp), (yyvsp[(2) - (2)].lp)); 
    ;}
    break;

  case 193:

    {
        (yyvsp[(1) - (2)].sp)->forward = 1;        /* mark as a forward declaration */
        (yyvsp[(1) - (2)].sp)->parsable = 1;       /* all forwards are parsable */
        (yyvsp[(1) - (2)].sp)->accessed--;         /* don't count forward decl as access */
        /* forward declarations shouldn't use 'extends' */
        if ((yyvsp[(1) - (2)].sp)->ptype != NULL) {
            yyerror("Forward declaration of a class cannot use 'extends'");
            fatal("Translation aborted");
        }
        /* they should also not use IDs */
        if ((yyvsp[(1) - (2)].sp)->id != NULL) {
            yyerror("Forward declaration of a class cannot use an ID declaration");
            fatal("Translation aborted");
        }
        /* they cannot use the abstract keyword (although it wouldn't do harm) */
        if ((yyvsp[(1) - (2)].sp)->abstract == 1) {
            yyerror("Forward declaration of a class should not use 'abstract'");
            (yyvsp[(1) - (2)].sp)->abstract = 0;
        }
        /* finally, they cannot use align() */
        if ((yyvsp[(1) - (2)].sp)->align != NULL) {
            yyerror("Forward declaration of a class should not use 'align'");
            (yyvsp[(1) - (2)].sp)->align = NULL;
        }
        s_remcontext();         /* exit param type scope */
        s_remcontext();         /* exit class scope (will not be deleted) */
        s_set_cur_class(NULL);  /* exiting class decl */
        (yyval.lp) = lnews_sp(CLASS, (yyvsp[(1) - (2)].sp), NULL); 
    ;}
    break;

  case 194:

    {
        if ((yyvsp[(1) - (1)].sp)->abstract && (yyvsp[(1) - (1)].sp)->id==NULL) {
            yyerror("Abstract class '%s' requires an ID", (yyvsp[(1) - (1)].sp)->name);
            (yyvsp[(1) - (1)].sp)->abstract=0;
        }
        (yyval.sp) = (yyvsp[(1) - (1)].sp);
    ;}
    break;

  case 195:

    { 
        (yyvsp[(1) - (3)].sp)->id = (yyvsp[(3) - (3)].sp);
        s_transfer((yyvsp[(3) - (3)].sp), (yyvsp[(1) - (3)].sp)->cxt);
        if (!(yyvsp[(1) - (3)].sp)->abstract) check_id((yyvsp[(1) - (3)].sp));
        (yyval.sp) = (yyvsp[(1) - (3)].sp);
    ;}
    break;

  case 196:

    { 
        (yyvsp[(1) - (3)].sp)->id = (yyvsp[(3) - (3)].sp);
        s_transfer((yyvsp[(3) - (3)].sp), (yyvsp[(1) - (3)].sp)->cxt);
        if (!(yyvsp[(1) - (3)].sp)->abstract) check_id((yyvsp[(1) - (3)].sp));
        (yyval.sp) = (yyvsp[(1) - (3)].sp);
    ;}
    break;

  case 198:

    { 
        /* forward declarations *cannot* be used as base classes */
        if ((yyvsp[(3) - (3)].sp)->forward == 1) {
            yyerror("Forward-declared class '%s' cannot be used as a base class", (yyvsp[(3) - (3)].sp)->name);
            (yyvsp[(3) - (3)].sp)->accessed--; /* don't count this as an access */
        }
        else {
            /* check for cyclic refs, if requested */
            if (w_cyclic) check_cyclic_decl_derived((yyvsp[(1) - (3)].sp), (yyvsp[(3) - (3)].sp), (yyvsp[(1) - (3)].sp)->forwardref);
            /* derived class, mark base type */
            (yyvsp[(1) - (3)].sp)->ptype = (yyvsp[(3) - (3)].sp);
            /* mark derivation on base class as well */
            (yyvsp[(3) - (3)].sp)->derived = (symbol_t **)buildarray((void **)(yyvsp[(3) - (3)].sp)->derived, (yyvsp[(1) - (3)].sp));
            /* if base is parsable, so is derived */
            (yyvsp[(1) - (3)].sp)->parsable = (yyvsp[(3) - (3)].sp)->parsable;
            /* if no alignment info, copy from base */
            if ((yyvsp[(1) - (3)].sp)->align == NULL) (yyvsp[(1) - (3)].sp)->align = (yyvsp[(3) - (3)].sp)->align;
            /* copy symbol table to derived class (derived table is *empty* at this point) */
            s_copy_st((yyvsp[(3) - (3)].sp)->cxt, (yyvsp[(1) - (3)].sp)->cxt);
            /* check that parameter types match exactly */
            check_formal_params((yyvsp[(1) - (3)].sp), (yyvsp[(1) - (3)].sp)->param, (yyvsp[(3) - (3)].sp)->param);
        }
        (yyval.sp) = (yyvsp[(1) - (3)].sp);
    ;}
    break;

  case 199:

    {
        yyerror("Incorrect base class '%s'", (yyvsp[(3) - (3)].sp)->name);
        (yyval.sp) = (yyvsp[(1) - (3)].sp);
    ;}
    break;

  case 200:

    {
        /* if we had a forward declaration, it should also not have params */
        if ((yyvsp[(1) - (1)].sp)->forward == 1 && (yyvsp[(1) - (1)].sp)->param != NULL) {
            yyerror("Class '%s' definition/declaration has no parameters but previous declaration did", (yyvsp[(1) - (1)].sp)->name);
            (yyvsp[(1) - (1)].sp)->param = NULL;
        }
        (yyval.sp)=(yyvsp[(1) - (1)].sp);
    ;}
    break;

  case 201:

    {
        /* if we had a forward declaration, params must match */
        if ((yyvsp[(1) - (4)].sp)->forward == 1) check_forward_params((yyvsp[(1) - (4)].sp), (yyvsp[(3) - (4)].lp), (yyvsp[(1) - (4)].sp)->param);
        (yyvsp[(1) - (4)].sp)->param = (yyvsp[(3) - (4)].lp); /* we always trust the last declaration or the definition */
        (yyval.sp) = (yyvsp[(1) - (4)].sp); 
    ;}
    break;

  case 202:

    {
        (yyvsp[(2) - (2)].sp)->align = (yyvsp[(1) - (2)].np);
        (yyval.sp) = (yyvsp[(2) - (2)].sp);
    ;}
    break;

  case 203:

    {
        /* set current class; used for tracking recursive decls */
        s_set_cur_class((yyvsp[(2) - (2)].sp));
        /* new context for class members */
        (yyvsp[(2) - (2)].sp)->cxt = s_newcontext(CLASS);
        /* yet another context for parameter list, if any */
        s_newcontext(0);
        (yyvsp[(2) - (2)].sp)->ident = CLASS_TYPE;
        (yyval.sp) = (yyvsp[(2) - (2)].sp);
    ;}
    break;

  case 204:

    {
        /* set current class; used for tracking recursive decls */
        s_set_cur_class((yyvsp[(3) - (3)].sp));
        /* new context for class members */
        (yyvsp[(3) - (3)].sp)->cxt = s_newcontext(CLASS);
        /* yet another context for parameter list, if any */
        s_newcontext(0);
        (yyvsp[(3) - (3)].sp)->ident = CLASS_TYPE;
        (yyvsp[(3) - (3)].sp)->abstract = 1;
        (yyval.sp) = (yyvsp[(3) - (3)].sp);
    ;}
    break;

  case 205:

    {
        if ((yyvsp[(2) - (2)].sp)->forward != 1) yyerror("Duplicate definition of class '%s'", (yyvsp[(2) - (2)].sp)->name);
        /* set current class; used for tracking recursive decls */
        s_set_cur_class((yyvsp[(2) - (2)].sp));
        /* new context for class members */
        (yyvsp[(2) - (2)].sp)->cxt = s_newcontext(CLASS);
        /* yet another context for parameter list, if any */
        s_newcontext(0);
        (yyval.sp) = (yyvsp[(2) - (2)].sp);
    ;}
    break;

  case 206:

    {
        if ((yyvsp[(3) - (3)].sp)->forward != 1) yyerror("Duplicate definition of class '%s'", (yyvsp[(3) - (3)].sp)->name);
        /* set current class; used for tracking recursive decls */
        s_set_cur_class((yyvsp[(3) - (3)].sp));
        /* new context for class members */
        (yyvsp[(3) - (3)].sp)->cxt = s_newcontext(CLASS);
        /* yet another context for parameter list, if any */
        s_newcontext(0);
        (yyvsp[(3) - (3)].sp)->abstract = 1;
        (yyval.sp) = (yyvsp[(3) - (3)].sp);
    ;}
    break;

  case 207:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (8)].sp)), (yyvsp[(2) - (8)].sp), M_CONST, check_parse((yyvsp[(2) - (8)].sp), M_CONST, (yyvsp[(4) - (8)].np)), (yyvsp[(8) - (8)].np), NULL, (yyvsp[(1) - (8)].np), 0, NULL, 0, 0);
        (yyval.sp)->align = (yyvsp[(1) - (8)].np);
    ;}
    break;

  case 208:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(7) - (9)].sp)), (yyvsp[(3) - (9)].sp), check_modtype(((yyvsp[(2) - (9)].ival)|M_CONST), (yyvsp[(3) - (9)].sp)), check_parse((yyvsp[(3) - (9)].sp), ((yyvsp[(2) - (9)].ival)|M_CONST), (yyvsp[(5) - (9)].np)), (yyvsp[(9) - (9)].np), NULL, (yyvsp[(1) - (9)].np), 0, NULL, 0, 0);	
        (yyval.sp)->align = (yyvsp[(1) - (9)].np);
    ;}
    break;

  case 209:

    {
        if (!((yyvsp[(2) - (8)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified for ID variable '%s'", (yyvsp[(6) - (8)].sp)->name);
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (8)].sp)), s_lookup("int"), check_modtype(((yyvsp[(2) - (8)].ival)|M_CONST), s_lookup("int")), check_parse(s_lookup("int"), ((yyvsp[(2) - (8)].ival)|M_CONST), (yyvsp[(4) - (8)].np)), (yyvsp[(8) - (8)].np), NULL, (yyvsp[(1) - (8)].np), 0, NULL, 0, 0);	
        (yyval.sp)->align = (yyvsp[(1) - (8)].np);
    ;}
    break;

  case 210:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (8)].sp)), (yyvsp[(2) - (8)].sp), M_CONST, check_parse((yyvsp[(2) - (8)].sp), M_CONST, leafs(MAP_TYPE, (yyvsp[(4) - (8)].sp))), (yyvsp[(8) - (8)].np), NULL, (yyvsp[(1) - (8)].np), 0, NULL, 0, 0);
        (yyval.sp)->align = (yyvsp[(1) - (8)].np);
    ;}
    break;

  case 211:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(7) - (9)].sp)), (yyvsp[(3) - (9)].sp), check_modtype(((yyvsp[(2) - (9)].ival)|M_CONST), (yyvsp[(3) - (9)].sp)), check_parse((yyvsp[(3) - (9)].sp), ((yyvsp[(2) - (9)].ival)|M_CONST), leafs(MAP_TYPE, (yyvsp[(5) - (9)].sp))), (yyvsp[(9) - (9)].np), NULL, (yyvsp[(1) - (9)].np), 0, NULL, 0, 0);	
        (yyval.sp)->align = (yyvsp[(1) - (9)].np);
    ;}
    break;

  case 212:

    {
        if (!((yyvsp[(2) - (8)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified for ID variable '%s'", (yyvsp[(6) - (8)].sp)->name);
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (8)].sp)), s_lookup("int"), check_modtype(((yyvsp[(2) - (8)].ival)|M_CONST), s_lookup("int")), check_parse(s_lookup("int"), ((yyvsp[(2) - (8)].ival)|M_CONST), leafs(MAP_TYPE, (yyvsp[(4) - (8)].sp))), (yyvsp[(8) - (8)].np), NULL, (yyvsp[(1) - (8)].np), 0, NULL, 0, 0);	
        (yyval.sp)->align = (yyvsp[(1) - (8)].np);
    ;}
    break;

  case 213:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (10)].sp)), (yyvsp[(2) - (10)].sp), M_NONE, check_parse((yyvsp[(2) - (10)].sp), M_CONST, (yyvsp[(4) - (10)].np)), idrange((yyvsp[(8) - (10)].np), (yyvsp[(10) - (10)].np)), NULL, (yyvsp[(1) - (10)].np), 0, NULL, 0, 1);
        (yyval.sp)->align = (yyvsp[(1) - (10)].np);
    ;}
    break;

  case 214:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(7) - (11)].sp)), (yyvsp[(3) - (11)].sp), check_modtype((yyvsp[(2) - (11)].ival), (yyvsp[(3) - (11)].sp)), check_parse((yyvsp[(3) - (11)].sp), ((yyvsp[(2) - (11)].ival)|M_CONST), (yyvsp[(5) - (11)].np)), idrange((yyvsp[(9) - (11)].np), (yyvsp[(11) - (11)].np)), NULL, (yyvsp[(1) - (11)].np), 0, NULL, 0, 1);	
        (yyval.sp)->align = (yyvsp[(1) - (11)].np);
    ;}
    break;

  case 215:

    {
        if (!((yyvsp[(2) - (10)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified for ID variable '%s'", (yyvsp[(6) - (10)].sp)->name);
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (10)].sp)), s_lookup("int"), check_modtype((yyvsp[(2) - (10)].ival), s_lookup("int")), check_parse(s_lookup("int"), ((yyvsp[(2) - (10)].ival)|M_CONST), (yyvsp[(4) - (10)].np)), idrange((yyvsp[(8) - (10)].np), (yyvsp[(10) - (10)].np)), NULL, (yyvsp[(1) - (10)].np), 0, NULL, 0, 1);	
        (yyval.sp)->align = (yyvsp[(1) - (10)].np);
    ;}
    break;

  case 216:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (10)].sp)), (yyvsp[(2) - (10)].sp), M_CONST, check_parse((yyvsp[(2) - (10)].sp), M_NONE, leafs(MAP_TYPE, (yyvsp[(4) - (10)].sp))), idrange((yyvsp[(8) - (10)].np), (yyvsp[(10) - (10)].np)), NULL, (yyvsp[(1) - (10)].np), 0, NULL, 0, 1);
        (yyval.sp)->align = (yyvsp[(1) - (10)].np);
    ;}
    break;

  case 217:

    {
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(7) - (11)].sp)), (yyvsp[(3) - (11)].sp), check_modtype((yyvsp[(2) - (11)].ival), (yyvsp[(3) - (11)].sp)), check_parse((yyvsp[(3) - (11)].sp), ((yyvsp[(2) - (11)].ival)|M_CONST), leafs(MAP_TYPE, (yyvsp[(5) - (11)].sp))), idrange((yyvsp[(9) - (11)].np), (yyvsp[(11) - (11)].np)), NULL, (yyvsp[(1) - (11)].np), 0, NULL, 0, 1);	
        (yyval.sp)->align = (yyvsp[(1) - (11)].np);
    ;}
    break;

  case 218:

    {
        if (!((yyvsp[(2) - (10)].ival) & (M_SHORT | M_LONG))) yyerror("No storage class specified for ID variable '%s'", (yyvsp[(6) - (10)].sp)->name);
        (yyval.sp) = set_var(check_rescope_id((yyvsp[(6) - (10)].sp)), s_lookup("int"), check_modtype((yyvsp[(2) - (10)].ival), s_lookup("int")), check_parse(s_lookup("int"), ((yyvsp[(2) - (10)].ival)|M_CONST), leafs(MAP_TYPE, (yyvsp[(4) - (10)].sp))), idrange((yyvsp[(8) - (10)].np), (yyvsp[(10) - (10)].np)), NULL, (yyvsp[(1) - (10)].np), 0, NULL, 0, 1);	
        (yyval.sp)->align = (yyvsp[(1) - (10)].np);
    ;}
    break;

  case 219:

    { (yyval.lp) = (yyvsp[(2) - (3)].lp); ;}
    break;

  case 220:

    { (yyval.lp) = (yyvsp[(2) - (4)].lp); ;}
    break;

  case 221:

    { (yyval.lp) = NULL; ;}
    break;

  case 222:

    { (yyval.lp) = NULL; ;}
    break;

  case 224:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp)); ;}
    break;

  case 225:

    {
        /* set type and mods; no parse, init, params, or alignment here */
        set_var((yyvsp[(2) - (2)].lp)->sp, (yyvsp[(1) - (2)].lp)->sp, (yyvsp[(1) - (2)].lp)->type, NULL, NULL, NULL, NULL, (yyvsp[(2) - (2)].lp)->dims, (yyvsp[(2) - (2)].lp)->dim, 1, (yyvsp[(2) - (2)].lp)->sp->range);
	
        /* formal parameters are considered assigned */
        (yyvsp[(2) - (2)].lp)->sp->assigned = 1;
        (yyvsp[(2) - (2)].lp)->sp->isparam =1 ;
        (yyval.lp) = (yyvsp[(2) - (2)].lp);
    ;}
    break;

  case 226:

    { (yyval.lp) = lnew_vp(VERBATIM, (yyvsp[(1) - (1)].vp)); ;}
    break;

  case 227:

    { 
        if (!s_in_class()) yyerror("Verbatim get() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_GET, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 228:

    {
        if (!s_in_class()) yyerror("Verbatim put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_PUT, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 229:

    {
        if (!s_in_class()) yyerror("Verbatim get()/put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_BOTH, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 230:

    { (yyval.lp) = lnew_vp(VERBATIM_C, (yyvsp[(1) - (1)].vp)); ;}
    break;

  case 231:

    {
        if (!s_in_class()) yyerror("Verbatim C++ get() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_GET_C, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 232:

    {
        if (!s_in_class()) yyerror("Verbatim C++ put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_PUT_C, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 233:

    {
        if (!s_in_class()) yyerror("Verbatim C++ get()/put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_BOTH_C, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 234:

    {
        if (s_in_class()) yyerror("Verbatim C++ code for .cpp file can not be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_C_CPP, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 235:

    { (yyval.lp) = lnew_vp(VERBATIM_J, (yyvsp[(1) - (1)].vp)); ;}
    break;

  case 236:

    {
        if (!s_in_class()) yyerror("Verbatim Java get() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_GET_J, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 237:

    {
        if (!s_in_class()) yyerror("Verbatim Java put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_PUT_J, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 238:

    {
        if (!s_in_class()) yyerror("Verbatim Java get()/put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_BOTH_J, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 239:

    { (yyval.lp) = lnew_vp(VERBATIM_A, (yyvsp[(1) - (1)].vp)); ;}
    break;

  case 240:

    {
        if (!s_in_class()) yyerror("Verbatim Angelscript get() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_GET_A, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 241:

    {
        if (!s_in_class()) yyerror("Verbatim Angelscript put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_PUT_A, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 242:

    {
        if (!s_in_class()) yyerror("Verbatim Angelscript get()/put() code can only be included within a class");
        (yyval.lp) = lnew_vp(VERBATIM_BOTH_A, (yyvsp[(1) - (1)].vp));
    ;}
    break;

  case 243:

    { (yyval.lp) = lnew0(PRAGMA); ;}
    break;

  case 244:

    { (yyval.lp) = lnews0(PRAGMA, (yyvsp[(2) - (2)].lp)); ;}
    break;

  case 246:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp)); ;}
    break;

  case 247:

    { 
        if ((yyvsp[(3) - (3)].ival) <= 0) yyerror("Negative or zero size for 'array' pragma: %d", (yyvsp[(3) - (3)].ival));
        else max_array_size = (yyvsp[(3) - (3)].ival);
        (yyval.lp) = lnew1((yyvsp[(1) - (3)].ival), leafi(INT_LITERAL, max_array_size));
    ;}
    break;

  case 248:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 249:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 250:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 251:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 252:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 253:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 254:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); if (!(yyval.lp)->included) decl_trace = 1; ;}
    break;

  case 255:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 256:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 257:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 258:

    { null_strings = 1; (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 259:

    { null_strings = 0; (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 260:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); if (!(yyval.lp)->included) gen_includes = 1; ;}
    break;

  case 261:

    { (yyval.lp) = lnew0((yyvsp[(1) - (1)].ival)); if (!(yyval.lp)->included) gen_includes = 0; ;}
    break;

  case 262:

    { (yyval.lp) = lnew1((yyvsp[(1) - (3)].ival), leafstr(STRING_LITERAL, (yyvsp[(3) - (3)].string))); ;}
    break;

  case 263:

    { (yyval.lp) = lnew1((yyvsp[(1) - (3)].ival), leafstr(STRING_LITERAL, (yyvsp[(3) - (3)].string))); ;}
    break;

  case 264:

    { (yyval.lp) = lnew1((yyvsp[(1) - (3)].ival), leafstr(STRING_LITERAL, (yyvsp[(3) - (3)].string))); ;}
    break;

  case 265:

    { (yyval.lp) = lnew1((yyvsp[(1) - (3)].ival), leafstr(STRING_LITERAL, (yyvsp[(3) - (3)].string))); ;}
    break;

  case 266:

    {
        (yyval.lp) = lnew1(IMPORT, leafstr(STRING_LITERAL, (yyvsp[(2) - (2)].string)));
        if (!include((yyvsp[(2) - (2)].string), 1)) {
            /* loop would occur; don't issue include statement */
            if (w_includes) yyerror("Importing file '%s' would create an infinite loop", (yyvsp[(2) - (2)].string));
            (yyval.lp) = NULL;
        }
    ;}
    break;

  case 267:

    {
        (yyval.lp) = lnew1((yyvsp[(1) - (2)].ival), leafstr(STRING_LITERAL, gethname((yyvsp[(2) - (2)].string))));
        if (!include((yyvsp[(2) - (2)].string), 0)) {
            /* loop would occur; don't issue include statement */
            if (w_includes) yyerror("Including file '%s' would create an infinite loop", (yyvsp[(2) - (2)].string));
            (yyval.lp) = NULL;
        }
    ;}
    break;

  case 268:

    {
        (yyval.lp) = lnew1((yyvsp[(1) - (2)].ival), leafstr(STRING_LITERAL, gethname((yyvsp[(2) - (2)].string))));
        if (!pushinclude((yyvsp[(2) - (2)].string))) {
            yyerror("Push including file '%s' mismatch", (yyvsp[(2) - (2)].string));
            (yyval.lp) = NULL;
        }
    ;}
    break;

  case 269:

    {
        (yyval.lp) = lnew1((yyvsp[(1) - (2)].ival), leafstr(STRING_LITERAL, gethname((yyvsp[(2) - (2)].string))));
        if (!popinclude((yyvsp[(2) - (2)].string))) {
            yyerror("Pop including file '%s' mismatch", (yyvsp[(2) - (2)].string));
            (yyval.lp) = NULL;
        }
    ;}
    break;

  case 270:

    {
        s_set_cur_class(NULL);  /* no current class or map */
        (yyval.lp) = lnews_sp(MAP, (yyvsp[(1) - (2)].sp), (yyvsp[(2) - (2)].lp));
    ;}
    break;

  case 271:

    {
        (yyvsp[(2) - (5)].sp)->ident = MAP_TYPE;
        (yyvsp[(2) - (5)].sp)->modifiers = M_NONE;
        (yyvsp[(2) - (5)].sp)->ptype = (yyvsp[(4) - (5)].sp);
        if ((yyvsp[(4) - (5)].sp)->ident == CLASS_TYPE) check_map_class((yyvsp[(4) - (5)].sp));
        (yyval.sp) = s_set_cur_class((yyvsp[(2) - (5)].sp)); /* mark current map */
    ;}
    break;

  case 272:

    {
        (yyvsp[(2) - (5)].sp)->ident = MAP_TYPE;
        (yyvsp[(2) - (5)].sp)->modifiers = (yyvsp[(4) - (5)].ival);
        (yyvsp[(2) - (5)].sp)->ptype = s_lookup("int");
        (yyval.sp) = s_set_cur_class((yyvsp[(2) - (5)].sp));
    ;}
    break;

  case 273:

    {
        (yyvsp[(2) - (6)].sp)->ident = MAP_TYPE;
        (yyvsp[(2) - (6)].sp)->modifiers = (yyvsp[(4) - (6)].ival);
        (yyvsp[(2) - (6)].sp)->ptype = (yyvsp[(5) - (6)].sp);
        (yyval.sp) = s_set_cur_class((yyvsp[(2) - (6)].sp));
    ;}
    break;

  case 274:

    { (yyval.lp) = (yyvsp[(2) - (3)].lp); ;}
    break;

  case 276:

    { 
        /* check for unique decodability and unique value */
        if (check_map(s_get_cur_class(), (yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp))) (yyval.lp) = app_map((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp)); 
        else (yyval.lp) = (yyvsp[(1) - (3)].lp);
    ;}
    break;

  case 277:

    { (yyval.lp) = (yyvsp[(1) - (3)].lp); (yyval.lp)->sub1 = (yyvsp[(3) - (3)].lp); ;}
    break;

  case 278:

    { (yyval.lp) = lnew1(BIT_LITERAL, leafb(BIT_LITERAL, (yyvsp[(1) - (1)].bit))); ;}
    break;

  case 279:

    { (yyval.lp) = lnew1(EXPR, (yyvsp[(1) - (1)].np)); ;}
    break;

  case 280:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), lnew1(EXPR, (yyvsp[(3) - (3)].np))); ;}
    break;

  case 281:

    { 
        (yyval.lp) = lnew3(ESC_FTYPE, leafi(EXPR, M_NONE), leafbs(EXPR, (yyvsp[(1) - (4)].sp)), (yyvsp[(3) - (4)].np)); 
    ;}
    break;

  case 282:

    { 
        (yyval.lp) = lnew3(ESC_FTYPE, leafi(EXPR, check_modtype((yyvsp[(1) - (5)].ival), (yyvsp[(2) - (5)].sp))), leafbs(EXPR, (yyvsp[(2) - (5)].sp)), (yyvsp[(4) - (5)].np));       
    ;}
    break;

  case 283:

    { (yyval.lp) = (yyvsp[(1) - (1)].lp); ;}
    break;

  case 284:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp)); ;}
    break;

  case 285:

    { (yyval.lp) = check_map_simple_value(s_get_cur_class(), lnew1(EXPR, (yyvsp[(1) - (1)].np))); ;}
    break;

  case 286:

    { (yyval.lp) = check_map_class_value(s_get_cur_class(), lnews0((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].lp))); ;}
    break;

  case 287:

    {
        check_map_esc_simple_value(s_get_cur_class(), (yyvsp[(1) - (1)].lp));
        if (s_get_cur_class()->escape == 1) {
            yyerror("Escape code is allowed only once in a map");
            exit(1);
        }
        s_get_cur_class()->escape = 1;
        (yyval.lp) = (yyvsp[(1) - (1)].lp);
    ;}
    break;

  case 288:

    { 
        check_map_esc_class_value(s_get_cur_class(), (yyvsp[(2) - (3)].lp)); 
        if (s_get_cur_class()->escape == 1) {
            yyerror("Escape code is allowed only once in a map");
            exit(1);
        }
        s_get_cur_class()->escape = 1;
        (yyval.lp) = (yyvsp[(2) - (3)].lp);
    ;}
    break;

  case 289:

    {
        /* must expand string to a list_t (*not* a node_t as with regular arrays...) */
        (yyval.lp) = NULL;
    ;}
    break;

  case 290:

    {
        s_set_cur_class(NULL);  
        (yyval.lp) = lnews_sp(BAC, (yyvsp[(1) - (2)].sp), (yyvsp[(2) - (2)].lp));
    ;}
    break;

  case 291:

    {
        (yyvsp[(2) - (2)].sp)->ident = BAC_TYPE;
        (yyvsp[(2) - (2)].sp)->modifiers = M_NONE;
        (yyval.sp) = s_set_cur_class((yyvsp[(2) - (2)].sp)); 
    ;}
    break;

  case 292:

    { (yyval.lp) = (yyvsp[(2) - (3)].lp); ;}
    break;

  case 294:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), (yyvsp[(3) - (3)].lp)); ;}
    break;

  case 295:

    { (yyval.lp)=(yyvsp[(1) - (3)].lp); (yyval.lp)->sub1=(yyvsp[(3) - (3)].lp); check_bac_val((yyval.lp)); ;}
    break;

  case 296:

    { (yyval.lp) = lnew1(INT_LITERAL, leafi(INT_LITERAL, check_bac_param((yyvsp[(1) - (1)].string)))); ;}
    break;

  case 297:

    { (yyval.lp) = lnew1(EXPR, (yyvsp[(1) - (1)].np)); ;}
    break;

  case 298:

    { (yyval.lp) = lnew1(STRING_LITERAL, leafstr(STRING_LITERAL, (yyvsp[(1) - (1)].string))); ;}
    break;

  case 299:

    { (yyval.lp) = lnews0((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].lp)); ;}
    break;

  case 300:

    { (yyval.lp) = lnew1(EXPR, (yyvsp[(1) - (1)].np)); ;}
    break;

  case 301:

    { (yyval.lp) = lnew1(STRING_LITERAL, leafstr(STRING_LITERAL, (yyvsp[(1) - (1)].string))); ;}
    break;

  case 302:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), lnew1(EXPR, (yyvsp[(3) - (3)].np))); ;}
    break;

  case 303:

    { (yyval.lp) = app((yyvsp[(1) - (3)].lp), lnew1(STRING_LITERAL, leafstr(STRING_LITERAL, (yyvsp[(3) - (3)].string)))); ;}
    break;

  case 304:

    { (yyval.lp) = lnew2(BAC_TYPE, leafs(BAC_TYPE, (yyvsp[(1) - (5)].sp)), leafi(INT_LITERAL, (yyvsp[(3) - (5)].ival))); ;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}






