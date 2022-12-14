%{ 

/*
 * Copyright (c) 1997-2004 Alexandros Eleftheriadis, Danny Hong and 
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
 * Lexical analyzer for the Flavor translator
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "port.h"
#include "globals.h"
#include "symbol.h"
#include "ptree.h"
#include "util.h"
#include "error.h"
//#include "compile.h"

/* jl - changed YY_INPUT to use the qfilefacade */
#include "qfilefacade.h"

#include "y.tab.h"

/* symbol lookup */
static int getsymbol(void);

/* error reporting */
void yyerror(char *fmt, ...);

/* comment processing */
void yycomment(char *end);

/* transparent user-code processing */
verbatim_t *yyverbatim(char *end);

/* sometimes yywrap is defined as a macro */
#undef yywrap

/* disable 'unreferenced label' warning from Visual C++ */
#pragma warning(disable : 4102)

/* Set when processing pragma statements.
 * Suppresses regular symbol lookup -- see getsymbol() below.
 */
static int pragma_active = 0;

/* parser entry point */
int yyparse();

/* jl - redefine YY_INPUT to use qfilefacade instead */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
    { \
    errno=0; \
    if ( (result = qf_fread(buf, 1, max_size, yyin))==0 && qf_ferror(yyin) && !qf_feof(yyin)) \
        { \
            YY_FATAL_ERROR( "input in flex scanner failed" ); \
        } \
    }
%}

%option noyyalloc noyyrealloc noyyfree never-interactive

DIGIT           [0-9]
LETTER          [a-zA-Z]
ALPHANUM        {LETTER}|{DIGIT}
ALL             {ALPHANUM}|[\.\[\]\\,;:/=+!@#$%\^&*'~_]
LETTERS         {LETTER}+
EXP             [DEde][+-]?{DIGIT}+
SPACES          [ \t\v\f]
STRING          \"({ALL})*\"

%%

"/*"    yycomment("*/");
"//"    yycomment("\n");

"%{"    yylval.vp=yyverbatim("%}"); return VERBATIM;

"%g{"	yylval.vp=yyverbatim("%g}"); return VERBATIM_GET;

"%p{"	yylval.vp=yyverbatim("%p}"); return VERBATIM_PUT;

"%*{"	yylval.vp=yyverbatim("%*}"); return VERBATIM_BOTH;

"%.c{"  yylval.vp=yyverbatim("%.c}"); return VERBATIM_C;

"%.c.cpp{" yylval.vp=yyverbatim("%.c.cpp}"); return VERBATIM_C_CPP;

"%p.c{" yylval.vp=yyverbatim("%p.c}"); return VERBATIM_PUT_C;

"%g.c{" yylval.vp=yyverbatim("%g.c}"); return VERBATIM_GET_C;

"%*.c{" yylval.vp=yyverbatim("%*.c}"); return VERBATIM_BOTH_C;

"%.j{"  yylval.vp=yyverbatim("%.j}"); return VERBATIM_J;

"%p.j{" yylval.vp=yyverbatim("%p.j}"); return VERBATIM_PUT_J;

"%g.j{" yylval.vp=yyverbatim("%g.j}"); return VERBATIM_GET_J;

"%*.j{" yylval.vp=yyverbatim("%*.j}"); return VERBATIM_BOTH_J;

"%.a{"  yylval.vp=yyverbatim("%.a}"); return VERBATIM_A;

"%p.a{" yylval.vp=yyverbatim("%p.a}"); return VERBATIM_PUT_A;

"%g.a{" yylval.vp=yyverbatim("%g.a}"); return VERBATIM_GET_A;

"%*.a{" yylval.vp=yyverbatim("%*.a}"); return VERBATIM_BOTH_A;

"%pragma"  pragma_active=1; return yylval.ival=PRAGMA;

"%include" return yylval.ival=INCLUDE;

"%import"  return yylval.ival=IMPORT;

(_|{LETTER})({ALPHANUM}|_)* {
    int c = getsymbol();
    if (c) return c;
}

"++"      return yylval.ival=INC;
"--"      return yylval.ival=DEC;
"<<"      return yylval.ival=LS;
">>"      return yylval.ival=RS;
"<="      return yylval.ival=LE;
">="      return yylval.ival=GE;
"=="      return yylval.ival=EQ;
"!="      return yylval.ival=NE;
"&&"      return yylval.ival=AND;
"||"      return yylval.ival=OR;
"::"      return yylval.ival=CLCL;
".."      return yylval.ival=RANGE;

"->"|".*"|"->*" {
    yyerror("C++ operator '%s' not supported in Flavor", yytext);
}

"*="      return yylval.ival=MUL_ASSIGN;
"/="      return yylval.ival=DIV_ASSIGN;
"%="      return yylval.ival=MOD_ASSIGN;
"+="      return yylval.ival=ADD_ASSIGN;
"-="      return yylval.ival=SUB_ASSIGN;
"<<="     return yylval.ival=LS_ASSIGN;
">>="     return yylval.ival=RS_ASSIGN;
"&="      return yylval.ival=AND_ASSIGN;
"^="      return yylval.ival=XOR_ASSIGN;
"|="      return yylval.ival=OR_ASSIGN;

{DIGIT}+"."{DIGIT}*({EXP})? |
{DIGIT}*"."{DIGIT}+({EXP})? |
{DIGIT}+{EXP} {
    /* double number */
    char *stop;
    yylval.dval = strtod(yytext, &stop);
    if (strlen(stop) > 0) yyerror("Incorrect double number");
    return DOUBLE_LITERAL;
}

0(b|B)((0|1)(0|1)(0|1)(0|1)\.)*(0|1)+ {
    /* bitstring */ 
    int i;
    unsigned int shift;
    
    yylval.bit = (bit_t *)getmem(sizeof(bit_t));

    /* compute value */
    yylval.bit->len = 0;
    yylval.bit->val = 0;
    shift = 1;
    for (i=yyleng-1; i>=2; i--) {
        if (yytext[i] == '.') continue;
        if (yytext[i] == '1') yylval.bit->val|=shift;
        shift = shift<<1;
        /* we only accept up to 32 bits */
        if (yylval.bit->len == 32) {
            yyerror("Bitstring value longer than 32 bits");
            return BIT_LITERAL;
        } 
        else yylval.bit->len++;
    }
    return BIT_LITERAL;
}

0(x|X)[0-9a-fA-F]+ {
    /* hexadecimal - treated as bitstring */

    yylval.bit = (bit_t *)getmem(sizeof(bit_t));

    /* we only accept up to 32 bits */
    if (yyleng-2 > 8) {
        yyerror("Hexadecimal value longer than 32 bits");
        yylval.bit->len = 32;
        yylval.bit->val = strtol(yytext+yyleng-8, (char **)NULL, 16);
    }
    else {
        /* every hex digit is taken as 4 bits */
        yylval.bit->len = (yyleng-2)*4;
        yylval.bit->val = strtoul(yytext+2, (char **)NULL, 16);
    }
    return BIT_LITERAL;
}

0{DIGIT}({DIGIT})* {
    /* octal number - treated as bitstring */

    yylval.bit = (bit_t *)getmem(sizeof(bit_t));

    /* we only accept up to 32 bits */
    if (yyleng-2 > 10) {
        yyerror("Octal value longer than 32 bits");
        yylval.bit->len = 30;
        yylval.bit->val = strtol(yytext+yyleng-10, (char **)NULL, 8);
    }
    else {
        /* every octal digit is taken as 3 bits */
        yylval.bit->len = (yyleng-2)*3;
        yylval.bit->val = strtol(yytext+1, (char **)NULL, 8);
    }
    return BIT_LITERAL;
}

{DIGIT}+ {
    /* int number */
    char *stop;

    yylval.ival = strtol(yytext, &stop, 10);
    if (strlen(stop) > 0) yyerror("Incorrect integer number");
    return INT_LITERAL;
}

[-+*/<>|&^%~\[\]!=,();?:\.] return yylval.ival = *yytext;

\{   s_newcontext(0); return yylval.ival = *yytext;

\}   s_remcontext(); return yylval.ival = *yytext;

{STRING} {
    /* copy, trimming initial and final '"' */
    yylval.string = strdup(yytext+1);
    if (yylval.string == NULL) fatal("Could not allocate memory (%d bytes)", strlen(yytext)+1);
    yylval.string[strlen(yylval.string)-1] = '\0';
    return STRING_LITERAL;
}

'.'	yylval.ival=yytext[1]; return INT_LITERAL;
'\\a'	yylval.ival='\a'; return INT_LITERAL;
'\\b'	yylval.ival='\b'; return INT_LITERAL;
'\\f'	yylval.ival='\f'; return INT_LITERAL;
'\\n'	yylval.ival='\n'; return INT_LITERAL;
'\\r'	yylval.ival='\r'; return INT_LITERAL;
'\\t'	yylval.ival='\t'; return INT_LITERAL;
'\\v'	yylval.ival='\v'; return INT_LITERAL;
'\\?'	yylval.ival='?'; return INT_LITERAL;
'\\''	yylval.ival='\''; return INT_LITERAL;
'\\\"'	yylval.ival='\"'; return INT_LITERAL;
'\\\\'	yylval.ival='\\'; return INT_LITERAL;

'\\[0-7]+'	{
    /* ascii code in octal */
    char *stop;

    yylval.ival = strtol(yytext+2, &stop, 8);
    if (strlen(stop) != 1 || yylval.ival > 255)
        yyerror("Incorrect ASCII code in char constant: %d", yylval.ival);
    return INT_LITERAL;
}

'\\x[0-9a-fA-F]+'	{
    /* ascii code in hex */
    char *stop;

    yylval.ival = strtol(yytext+3, &stop, 16);
    if (strlen(stop) != 1 || yylval.ival > 255)
        yyerror("Incorrect ASCII code in char constant: %d", yylval.ival);
    return INT_LITERAL;
}

'\\.' yylval.ival=yytext[2]; return INT_LITERAL;

\n    { lineno++; pragma_active = 0; }

{SPACES} ;

. { return yytext[0]; };

%%

 /* Provide our own implementations. */
      void * yyalloc (size_t bytes) {
          return getmem (bytes);
      }

      void * yyrealloc (void * ptr, size_t bytes) {
          return regetmem (ptr, bytes);
      }

      void yyfree (void * ptr) {
          free_memt(ptr);
      }

/* lookup symbol */
static int getsymbol()
{
    symbol_t *sp;

    if (pragma_active) {
        sp = s_pragma_lookup(yytext);
        if (sp != NULL) {
            /* all pragma symbols are internal and not exported */
            yylval.ival = sp->ident;
            return sp->ident;
    	}
    	/* pragma lookup failed; disable and do a regular lookup */
    	pragma_active = 0;
    }
    sp = s_lookupadd(yytext, VARIABLE);

    if (sp->ident == 0) {
        yyerror("Reserved keyword '%s' cannot be used", yytext);
        return 0;
    }
    if (sp->internal && !sp->exported){
        yylval.ival = sp->ident;
    }
    else {
        yylval.sp = sp;
    }

    return sp->ident;
}

/* varargs version */
void yyerror(char *fmt, ...)
{
    va_list ap;
    char buf[256];

    /* keep track of how many errors we found */
    nerrors++;

    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);

    if (!msvc) {
        if (qf_feof(yyin)) {
            /* in MKS Lex, lineno and yytext are wrong after EOF */
            fprintf(stderr, "%s:%d: %s\n", filename, lineno-1, buf);
    	}
        else {
            /* print next token if just 'Syntax error' */
            if (strcmp(buf, "Syntax error")==0)
    	        fprintf(stderr, "%s:%d: %s: '%s'\n", filename, lineno, buf, yytext);
            else
    	        fprintf(stderr, "%s:%d: %s\n", filename, lineno, buf);
        }
    }
    else {
        if (qf_feof(yyin)) {
            /* in MKS Lex, lineno and yytext are wrong after EOF */
            fprintf(stderr, "%s(%d) : error: %s\n", filename, lineno-1, buf);
        }
        else {
	    /* print next token if just 'Syntax error' */
	    if (strcmp(buf, "Syntax error")==0)
	        fprintf(stderr, "%s(%d) : error: %s: '%s'\n", filename, lineno, buf, yytext);
	    else
	        fprintf(stderr, "%s(%d) : error: %s\n", filename, lineno, buf);
        }
    }
    return;
}

/* skip input until end of comment */
void yycomment(char *end)
{
    int c, startline;
    char *cp;

    startline = lineno;
    for (cp=end; *cp!='\0'; ) {
        c = input();
        if (c == EOF) {
            yyerror("End of file in comment started at line %d", startline);
            exit(1);
        }
        if (c == '\n') lineno++;
        if (c != *cp++) {
            cp = end;
            if (c == *cp) cp++;
        }
    }
}

/*
 * Transparently pass user to code to the output file.
 * Returns verbatim code.
 */
verbatim_t *yyverbatim(char *end)
{
    int c;
    char *cp, *sp;
    verbatim_t *vp;

    vp = (verbatim_t *)getmem(sizeof(verbatim_t));

    /* we need to hold off so that we don't print the 'end' characters */

    vp->lineno = lineno;
    vp->str = NULL;
    for (cp=end; *cp!='\0'; ) {
        c = input();
        if (c == EOF) {
            yyerror("End of file in verbatim section started at line %d", vp->lineno);
            exit(1);
        }
        if (c == '\n') lineno++;
        if (c != *cp++) {
            /* no match, output and restart */
            sp = end;
            while (sp < cp-1) vp->str = buildstr(vp->str, *sp++);
            cp = end;
            /* see if at least the first 'end' char matches */
            if (c == *cp) cp++;
            else vp->str = buildstr(vp->str, c);
        }
    }
    return vp;
}

/* state stack (reversed) for include file processing */
typedef struct _state_t {
    char filename[MAX_LEN];
    int lineno;
    void *yyin;
    int max_array_size;
    int null_strings;
    int import;     /* set to 1 if import, 0 if include */
    struct _state_t *next;
} state_t;

static state_t *state_top=NULL;

/* push; returns 0 if file with same base name has already been included */
static int state_push(char *newfname, FILE *newfp, int import)
{
    state_t *sp, *tp;

    /* sanity check: can't include ourselves */
    if (strcmp(basename(newfname), basename(filename)) == 0) return 0;

    sp = (state_t *)getmem(sizeof(state_t));

    /* add to stack */
    if (state_top == NULL) state_top = sp;
    else {
        tp = state_top;
        while (tp != NULL) {
            /* detect loops */
#if defined(WIN32) || defined(_WIN32_)
            if (stricmp(basename(newfname), basename(tp->filename))==0) {
#else
            if (strcmp(basename(newfname), basename(tp->filename))==0) {
#endif
                free_memt(sp);
                return 0;
            }
            if (tp->next == NULL) break;
            tp = tp->next;
        }
        tp->next = sp;
    }
    strcpy(sp->filename, filename);
    strcpy(filename, newfname);
    sp->import = import;
    sp->max_array_size = max_array_size;
    sp->null_strings = null_strings;
    sp->lineno = lineno;
    sp->yyin = yyin;
    yyin = newfp;
    lineno = 1;
    sp->next = NULL;

    return 1;
}

static void state_pop(void)
{
    state_t *sp, *prevsp;

    if (state_top == NULL) fatal("Internal error L%d: State stack is empty", __LINE__);
    
    /* find entry at the bottom of stack */
    prevsp = NULL;
    sp = state_top;
    while (sp->next != NULL) {
        if (prevsp == NULL) prevsp = sp;
        else prevsp = prevsp->next;
        sp = sp->next;
    }
    /* restore state */
    strcpy(filename, sp->filename);
    lineno = sp->lineno;
    yyin = sp->yyin;
    /* pop max_array_size and null_strings *only* if we are including */
    if (including()) {
        max_array_size = sp->max_array_size;
        null_strings = sp->null_strings;
    }

    /* unlink entry */
    if (prevsp == NULL) state_top = NULL;
    else prevsp->next = NULL;

    free_memt(sp);
}

/*
 * Are we currently processing an include file? 
 * An import is only treated as such if all previous includes where imports themselves.
 */
int including(void)
{
    state_t *sp;
   
    sp = state_top;
    while (sp != NULL) {
        if (!sp->import) return 1;
        sp = sp->next;
    }
    return 0;
}

/* file processing continuation (0 means there is more input) */
int yywrap(void) 
{
    if (state_top != NULL) {
        state_pop();
        return 0;
    }
    return 1;
}

/* process include/import file (returns 0 if a loop would occur) */
int include(char *file, int import)
{
    char path[MAX_LEN]; /* full path to included file */
    void *fp;

    /* input filename must end with .fl */
    if (strcmp(&file[ strlen(file) >= 3 ? strlen(file)-3 : 0 ], ".fl"))
        fatal("Included file does hot have '.fl' suffix: %s", file);

    if (!isabsolute(file)) {
        strcpy(path, dirname(filename));
        strcat(path, file);
    }
    else {
        strcpy(path, file);
    }

    // open input file
    if ((fp = qf_fopen(path, "r")) == NULL) {
        fatal("Cannot open included file: %s", path);
    }

    /* switch state */
    if (!state_push(path, fp, import)) {
        qf_fclose(fp);
        return 0;
    }

    /* let the parser continue */
    return 1;
}
