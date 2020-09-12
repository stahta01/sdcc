/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 24 "../../sdcc-svn/src/SDCC.y"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "SDCCglobl.h"
#include "SDCCsymt.h"
#include "SDCChasht.h"
#include "SDCCval.h"
#include "SDCCmem.h"
#include "SDCCast.h"
#include "port.h"
#include "newalloc.h"
#include "SDCCerr.h"
#include "SDCCutil.h"
#include "SDCCbtree.h"
#include "SDCCopt.h"

extern int yyerror (char *);
extern FILE     *yyin;
long NestLevel = 0;     /* current NestLevel       */
int stackPtr  = 1;      /* stack pointer           */
int xstackPtr = 0;      /* xstack pointer          */
int reentrant = 0;
int blockNo   = 0;      /* sequential block number  */
int currBlockno=0;
int inCriticalFunction = 0;
int inCriticalBlock = 0;
int seqPointNo= 1;      /* sequence point number */
int ignoreTypedefType=0;
extern int yylex();
int yyparse(void);
extern int noLineno;
char lbuff[1024];       /* local buffer */
char function_name[256] = {0};

/* break & continue stacks */
STACK_DCL(continueStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(breakStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(forStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(swStk   ,ast   *,MAX_NEST_LEVEL)
STACK_DCL(blockNum,int,MAX_NEST_LEVEL*3)

value *cenum = NULL;        /* current enumeration  type chain*/
bool uselessDecl = TRUE;

#define YYDEBUG 1


#line 120 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPE_NAME = 259,               /* TYPE_NAME  */
    ADDRSPACE_NAME = 260,          /* ADDRSPACE_NAME  */
    CONSTANT = 261,                /* CONSTANT  */
    SIZEOF = 262,                  /* SIZEOF  */
    ALIGNOF = 263,                 /* ALIGNOF  */
    TYPEOF = 264,                  /* TYPEOF  */
    OFFSETOF = 265,                /* OFFSETOF  */
    PTR_OP = 266,                  /* PTR_OP  */
    INC_OP = 267,                  /* INC_OP  */
    DEC_OP = 268,                  /* DEC_OP  */
    LEFT_OP = 269,                 /* LEFT_OP  */
    RIGHT_OP = 270,                /* RIGHT_OP  */
    LE_OP = 271,                   /* LE_OP  */
    GE_OP = 272,                   /* GE_OP  */
    EQ_OP = 273,                   /* EQ_OP  */
    NE_OP = 274,                   /* NE_OP  */
    AND_OP = 275,                  /* AND_OP  */
    OR_OP = 276,                   /* OR_OP  */
    ATTRIBCOLON = 277,             /* ATTRIBCOLON  */
    MUL_ASSIGN = 278,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 279,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 280,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 281,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 282,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 283,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 284,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 285,              /* AND_ASSIGN  */
    XOR_ASSIGN = 286,              /* XOR_ASSIGN  */
    OR_ASSIGN = 287,               /* OR_ASSIGN  */
    TYPEDEF = 288,                 /* TYPEDEF  */
    EXTERN = 289,                  /* EXTERN  */
    STATIC = 290,                  /* STATIC  */
    THREAD_LOCAL = 291,            /* THREAD_LOCAL  */
    AUTO = 292,                    /* AUTO  */
    REGISTER = 293,                /* REGISTER  */
    CODE = 294,                    /* CODE  */
    EEPROM = 295,                  /* EEPROM  */
    INTERRUPT = 296,               /* INTERRUPT  */
    SFR = 297,                     /* SFR  */
    SFR16 = 298,                   /* SFR16  */
    SFR32 = 299,                   /* SFR32  */
    ADDRESSMOD = 300,              /* ADDRESSMOD  */
    STATIC_ASSERT = 301,           /* STATIC_ASSERT  */
    AT = 302,                      /* AT  */
    SBIT = 303,                    /* SBIT  */
    REENTRANT = 304,               /* REENTRANT  */
    USING = 305,                   /* USING  */
    XDATA = 306,                   /* XDATA  */
    DATA = 307,                    /* DATA  */
    IDATA = 308,                   /* IDATA  */
    PDATA = 309,                   /* PDATA  */
    VAR_ARGS = 310,                /* VAR_ARGS  */
    CRITICAL = 311,                /* CRITICAL  */
    NONBANKED = 312,               /* NONBANKED  */
    BANKED = 313,                  /* BANKED  */
    SHADOWREGS = 314,              /* SHADOWREGS  */
    SD_WPARAM = 315,               /* SD_WPARAM  */
    SD_BOOL = 316,                 /* SD_BOOL  */
    SD_CHAR = 317,                 /* SD_CHAR  */
    SD_SHORT = 318,                /* SD_SHORT  */
    SD_INT = 319,                  /* SD_INT  */
    SD_LONG = 320,                 /* SD_LONG  */
    SIGNED = 321,                  /* SIGNED  */
    UNSIGNED = 322,                /* UNSIGNED  */
    SD_FLOAT = 323,                /* SD_FLOAT  */
    DOUBLE = 324,                  /* DOUBLE  */
    FIXED16X16 = 325,              /* FIXED16X16  */
    SD_CONST = 326,                /* SD_CONST  */
    VOLATILE = 327,                /* VOLATILE  */
    SD_VOID = 328,                 /* SD_VOID  */
    BIT = 329,                     /* BIT  */
    STRUCT = 330,                  /* STRUCT  */
    UNION = 331,                   /* UNION  */
    ENUM = 332,                    /* ENUM  */
    RANGE = 333,                   /* RANGE  */
    SD_FAR = 334,                  /* SD_FAR  */
    CASE = 335,                    /* CASE  */
    DEFAULT = 336,                 /* DEFAULT  */
    IF = 337,                      /* IF  */
    ELSE = 338,                    /* ELSE  */
    SWITCH = 339,                  /* SWITCH  */
    WHILE = 340,                   /* WHILE  */
    DO = 341,                      /* DO  */
    FOR = 342,                     /* FOR  */
    GOTO = 343,                    /* GOTO  */
    CONTINUE = 344,                /* CONTINUE  */
    BREAK = 345,                   /* BREAK  */
    RETURN = 346,                  /* RETURN  */
    NAKED = 347,                   /* NAKED  */
    JAVANATIVE = 348,              /* JAVANATIVE  */
    OVERLAY = 349,                 /* OVERLAY  */
    TRAP = 350,                    /* TRAP  */
    STRING_LITERAL = 351,          /* STRING_LITERAL  */
    INLINEASM = 352,               /* INLINEASM  */
    IFX = 353,                     /* IFX  */
    ADDRESS_OF = 354,              /* ADDRESS_OF  */
    GET_VALUE_AT_ADDRESS = 355,    /* GET_VALUE_AT_ADDRESS  */
    SET_VALUE_AT_ADDRESS = 356,    /* SET_VALUE_AT_ADDRESS  */
    SPIL = 357,                    /* SPIL  */
    UNSPIL = 358,                  /* UNSPIL  */
    GETHBIT = 359,                 /* GETHBIT  */
    GETABIT = 360,                 /* GETABIT  */
    GETBYTE = 361,                 /* GETBYTE  */
    GETWORD = 362,                 /* GETWORD  */
    BITWISEAND = 363,              /* BITWISEAND  */
    UNARYMINUS = 364,              /* UNARYMINUS  */
    IPUSH = 365,                   /* IPUSH  */
    IPOP = 366,                    /* IPOP  */
    PCALL = 367,                   /* PCALL  */
    ENDFUNCTION = 368,             /* ENDFUNCTION  */
    JUMPTABLE = 369,               /* JUMPTABLE  */
    RRC = 370,                     /* RRC  */
    RLC = 371,                     /* RLC  */
    CAST = 372,                    /* CAST  */
    CALL = 373,                    /* CALL  */
    PARAM = 374,                   /* PARAM  */
    NULLOP = 375,                  /* NULLOP  */
    BLOCK = 376,                   /* BLOCK  */
    LABEL = 377,                   /* LABEL  */
    RECEIVE = 378,                 /* RECEIVE  */
    SEND = 379,                    /* SEND  */
    ARRAYINIT = 380,               /* ARRAYINIT  */
    DUMMY_READ_VOLATILE = 381,     /* DUMMY_READ_VOLATILE  */
    ENDCRITICAL = 382,             /* ENDCRITICAL  */
    SWAP = 383,                    /* SWAP  */
    INLINE = 384,                  /* INLINE  */
    NORETURN = 385,                /* NORETURN  */
    RESTRICT = 386,                /* RESTRICT  */
    SMALLC = 387,                  /* SMALLC  */
    PRESERVES_REGS = 388,          /* PRESERVES_REGS  */
    Z88DK_FASTCALL = 389,          /* Z88DK_FASTCALL  */
    Z88DK_CALLEE = 390,            /* Z88DK_CALLEE  */
    ALIGNAS = 391,                 /* ALIGNAS  */
    Z88DK_SHORTCALL = 392,         /* Z88DK_SHORTCALL  */
    Z88DK_PARAMS_OFFSET = 393,     /* Z88DK_PARAMS_OFFSET  */
    GENERIC = 394,                 /* GENERIC  */
    GENERIC_ASSOC_LIST = 395,      /* GENERIC_ASSOC_LIST  */
    GENERIC_ASSOCIATION = 396,     /* GENERIC_ASSOCIATION  */
    ASM = 397                      /* ASM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define TYPE_NAME 259
#define ADDRSPACE_NAME 260
#define CONSTANT 261
#define SIZEOF 262
#define ALIGNOF 263
#define TYPEOF 264
#define OFFSETOF 265
#define PTR_OP 266
#define INC_OP 267
#define DEC_OP 268
#define LEFT_OP 269
#define RIGHT_OP 270
#define LE_OP 271
#define GE_OP 272
#define EQ_OP 273
#define NE_OP 274
#define AND_OP 275
#define OR_OP 276
#define ATTRIBCOLON 277
#define MUL_ASSIGN 278
#define DIV_ASSIGN 279
#define MOD_ASSIGN 280
#define ADD_ASSIGN 281
#define SUB_ASSIGN 282
#define LEFT_ASSIGN 283
#define RIGHT_ASSIGN 284
#define AND_ASSIGN 285
#define XOR_ASSIGN 286
#define OR_ASSIGN 287
#define TYPEDEF 288
#define EXTERN 289
#define STATIC 290
#define THREAD_LOCAL 291
#define AUTO 292
#define REGISTER 293
#define CODE 294
#define EEPROM 295
#define INTERRUPT 296
#define SFR 297
#define SFR16 298
#define SFR32 299
#define ADDRESSMOD 300
#define STATIC_ASSERT 301
#define AT 302
#define SBIT 303
#define REENTRANT 304
#define USING 305
#define XDATA 306
#define DATA 307
#define IDATA 308
#define PDATA 309
#define VAR_ARGS 310
#define CRITICAL 311
#define NONBANKED 312
#define BANKED 313
#define SHADOWREGS 314
#define SD_WPARAM 315
#define SD_BOOL 316
#define SD_CHAR 317
#define SD_SHORT 318
#define SD_INT 319
#define SD_LONG 320
#define SIGNED 321
#define UNSIGNED 322
#define SD_FLOAT 323
#define DOUBLE 324
#define FIXED16X16 325
#define SD_CONST 326
#define VOLATILE 327
#define SD_VOID 328
#define BIT 329
#define STRUCT 330
#define UNION 331
#define ENUM 332
#define RANGE 333
#define SD_FAR 334
#define CASE 335
#define DEFAULT 336
#define IF 337
#define ELSE 338
#define SWITCH 339
#define WHILE 340
#define DO 341
#define FOR 342
#define GOTO 343
#define CONTINUE 344
#define BREAK 345
#define RETURN 346
#define NAKED 347
#define JAVANATIVE 348
#define OVERLAY 349
#define TRAP 350
#define STRING_LITERAL 351
#define INLINEASM 352
#define IFX 353
#define ADDRESS_OF 354
#define GET_VALUE_AT_ADDRESS 355
#define SET_VALUE_AT_ADDRESS 356
#define SPIL 357
#define UNSPIL 358
#define GETHBIT 359
#define GETABIT 360
#define GETBYTE 361
#define GETWORD 362
#define BITWISEAND 363
#define UNARYMINUS 364
#define IPUSH 365
#define IPOP 366
#define PCALL 367
#define ENDFUNCTION 368
#define JUMPTABLE 369
#define RRC 370
#define RLC 371
#define CAST 372
#define CALL 373
#define PARAM 374
#define NULLOP 375
#define BLOCK 376
#define LABEL 377
#define RECEIVE 378
#define SEND 379
#define ARRAYINIT 380
#define DUMMY_READ_VOLATILE 381
#define ENDCRITICAL 382
#define SWAP 383
#define INLINE 384
#define NORETURN 385
#define RESTRICT 386
#define SMALLC 387
#define PRESERVES_REGS 388
#define Z88DK_FASTCALL 389
#define Z88DK_CALLEE 390
#define ALIGNAS 391
#define Z88DK_SHORTCALL 392
#define Z88DK_PARAMS_OFFSET 393
#define GENERIC 394
#define GENERIC_ASSOC_LIST 395
#define GENERIC_ASSOCIATION 396
#define ASM 397

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 74 "../../sdcc-svn/src/SDCC.y"

    symbol     *sym;        /* symbol table pointer                   */
    structdef  *sdef;       /* structure definition                   */
    char       yychar[SDCC_NAME_MAX+1];
    sym_link   *lnk;        /* declarator  or specifier               */
    int        yyint;       /* integer value returned                 */
    value      *val;        /* for integer constant                   */
    initList   *ilist;      /* initial list                           */
    designation*dsgn;       /* designator                             */
    const char *yystr;      /* pointer to dynamicaly allocated string */
    ast        *asts;       /* expression tree                        */

#line 469 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_NAME = 4,                  /* TYPE_NAME  */
  YYSYMBOL_ADDRSPACE_NAME = 5,             /* ADDRSPACE_NAME  */
  YYSYMBOL_CONSTANT = 6,                   /* CONSTANT  */
  YYSYMBOL_SIZEOF = 7,                     /* SIZEOF  */
  YYSYMBOL_ALIGNOF = 8,                    /* ALIGNOF  */
  YYSYMBOL_TYPEOF = 9,                     /* TYPEOF  */
  YYSYMBOL_OFFSETOF = 10,                  /* OFFSETOF  */
  YYSYMBOL_PTR_OP = 11,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 12,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 13,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 14,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 15,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 16,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 17,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 18,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 19,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 20,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 21,                     /* OR_OP  */
  YYSYMBOL_ATTRIBCOLON = 22,               /* ATTRIBCOLON  */
  YYSYMBOL_MUL_ASSIGN = 23,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 24,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 25,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 26,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 27,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 28,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 29,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 30,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 31,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 32,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF = 33,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 34,                    /* EXTERN  */
  YYSYMBOL_STATIC = 35,                    /* STATIC  */
  YYSYMBOL_THREAD_LOCAL = 36,              /* THREAD_LOCAL  */
  YYSYMBOL_AUTO = 37,                      /* AUTO  */
  YYSYMBOL_REGISTER = 38,                  /* REGISTER  */
  YYSYMBOL_CODE = 39,                      /* CODE  */
  YYSYMBOL_EEPROM = 40,                    /* EEPROM  */
  YYSYMBOL_INTERRUPT = 41,                 /* INTERRUPT  */
  YYSYMBOL_SFR = 42,                       /* SFR  */
  YYSYMBOL_SFR16 = 43,                     /* SFR16  */
  YYSYMBOL_SFR32 = 44,                     /* SFR32  */
  YYSYMBOL_ADDRESSMOD = 45,                /* ADDRESSMOD  */
  YYSYMBOL_STATIC_ASSERT = 46,             /* STATIC_ASSERT  */
  YYSYMBOL_AT = 47,                        /* AT  */
  YYSYMBOL_SBIT = 48,                      /* SBIT  */
  YYSYMBOL_REENTRANT = 49,                 /* REENTRANT  */
  YYSYMBOL_USING = 50,                     /* USING  */
  YYSYMBOL_XDATA = 51,                     /* XDATA  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_IDATA = 53,                     /* IDATA  */
  YYSYMBOL_PDATA = 54,                     /* PDATA  */
  YYSYMBOL_VAR_ARGS = 55,                  /* VAR_ARGS  */
  YYSYMBOL_CRITICAL = 56,                  /* CRITICAL  */
  YYSYMBOL_NONBANKED = 57,                 /* NONBANKED  */
  YYSYMBOL_BANKED = 58,                    /* BANKED  */
  YYSYMBOL_SHADOWREGS = 59,                /* SHADOWREGS  */
  YYSYMBOL_SD_WPARAM = 60,                 /* SD_WPARAM  */
  YYSYMBOL_SD_BOOL = 61,                   /* SD_BOOL  */
  YYSYMBOL_SD_CHAR = 62,                   /* SD_CHAR  */
  YYSYMBOL_SD_SHORT = 63,                  /* SD_SHORT  */
  YYSYMBOL_SD_INT = 64,                    /* SD_INT  */
  YYSYMBOL_SD_LONG = 65,                   /* SD_LONG  */
  YYSYMBOL_SIGNED = 66,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 67,                  /* UNSIGNED  */
  YYSYMBOL_SD_FLOAT = 68,                  /* SD_FLOAT  */
  YYSYMBOL_DOUBLE = 69,                    /* DOUBLE  */
  YYSYMBOL_FIXED16X16 = 70,                /* FIXED16X16  */
  YYSYMBOL_SD_CONST = 71,                  /* SD_CONST  */
  YYSYMBOL_VOLATILE = 72,                  /* VOLATILE  */
  YYSYMBOL_SD_VOID = 73,                   /* SD_VOID  */
  YYSYMBOL_BIT = 74,                       /* BIT  */
  YYSYMBOL_STRUCT = 75,                    /* STRUCT  */
  YYSYMBOL_UNION = 76,                     /* UNION  */
  YYSYMBOL_ENUM = 77,                      /* ENUM  */
  YYSYMBOL_RANGE = 78,                     /* RANGE  */
  YYSYMBOL_SD_FAR = 79,                    /* SD_FAR  */
  YYSYMBOL_CASE = 80,                      /* CASE  */
  YYSYMBOL_DEFAULT = 81,                   /* DEFAULT  */
  YYSYMBOL_IF = 82,                        /* IF  */
  YYSYMBOL_ELSE = 83,                      /* ELSE  */
  YYSYMBOL_SWITCH = 84,                    /* SWITCH  */
  YYSYMBOL_WHILE = 85,                     /* WHILE  */
  YYSYMBOL_DO = 86,                        /* DO  */
  YYSYMBOL_FOR = 87,                       /* FOR  */
  YYSYMBOL_GOTO = 88,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 89,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 90,                     /* BREAK  */
  YYSYMBOL_RETURN = 91,                    /* RETURN  */
  YYSYMBOL_NAKED = 92,                     /* NAKED  */
  YYSYMBOL_JAVANATIVE = 93,                /* JAVANATIVE  */
  YYSYMBOL_OVERLAY = 94,                   /* OVERLAY  */
  YYSYMBOL_TRAP = 95,                      /* TRAP  */
  YYSYMBOL_STRING_LITERAL = 96,            /* STRING_LITERAL  */
  YYSYMBOL_INLINEASM = 97,                 /* INLINEASM  */
  YYSYMBOL_IFX = 98,                       /* IFX  */
  YYSYMBOL_ADDRESS_OF = 99,                /* ADDRESS_OF  */
  YYSYMBOL_GET_VALUE_AT_ADDRESS = 100,     /* GET_VALUE_AT_ADDRESS  */
  YYSYMBOL_SET_VALUE_AT_ADDRESS = 101,     /* SET_VALUE_AT_ADDRESS  */
  YYSYMBOL_SPIL = 102,                     /* SPIL  */
  YYSYMBOL_UNSPIL = 103,                   /* UNSPIL  */
  YYSYMBOL_GETHBIT = 104,                  /* GETHBIT  */
  YYSYMBOL_GETABIT = 105,                  /* GETABIT  */
  YYSYMBOL_GETBYTE = 106,                  /* GETBYTE  */
  YYSYMBOL_GETWORD = 107,                  /* GETWORD  */
  YYSYMBOL_BITWISEAND = 108,               /* BITWISEAND  */
  YYSYMBOL_UNARYMINUS = 109,               /* UNARYMINUS  */
  YYSYMBOL_IPUSH = 110,                    /* IPUSH  */
  YYSYMBOL_IPOP = 111,                     /* IPOP  */
  YYSYMBOL_PCALL = 112,                    /* PCALL  */
  YYSYMBOL_ENDFUNCTION = 113,              /* ENDFUNCTION  */
  YYSYMBOL_JUMPTABLE = 114,                /* JUMPTABLE  */
  YYSYMBOL_RRC = 115,                      /* RRC  */
  YYSYMBOL_RLC = 116,                      /* RLC  */
  YYSYMBOL_CAST = 117,                     /* CAST  */
  YYSYMBOL_CALL = 118,                     /* CALL  */
  YYSYMBOL_PARAM = 119,                    /* PARAM  */
  YYSYMBOL_NULLOP = 120,                   /* NULLOP  */
  YYSYMBOL_BLOCK = 121,                    /* BLOCK  */
  YYSYMBOL_LABEL = 122,                    /* LABEL  */
  YYSYMBOL_RECEIVE = 123,                  /* RECEIVE  */
  YYSYMBOL_SEND = 124,                     /* SEND  */
  YYSYMBOL_ARRAYINIT = 125,                /* ARRAYINIT  */
  YYSYMBOL_DUMMY_READ_VOLATILE = 126,      /* DUMMY_READ_VOLATILE  */
  YYSYMBOL_ENDCRITICAL = 127,              /* ENDCRITICAL  */
  YYSYMBOL_SWAP = 128,                     /* SWAP  */
  YYSYMBOL_INLINE = 129,                   /* INLINE  */
  YYSYMBOL_NORETURN = 130,                 /* NORETURN  */
  YYSYMBOL_RESTRICT = 131,                 /* RESTRICT  */
  YYSYMBOL_SMALLC = 132,                   /* SMALLC  */
  YYSYMBOL_PRESERVES_REGS = 133,           /* PRESERVES_REGS  */
  YYSYMBOL_Z88DK_FASTCALL = 134,           /* Z88DK_FASTCALL  */
  YYSYMBOL_Z88DK_CALLEE = 135,             /* Z88DK_CALLEE  */
  YYSYMBOL_ALIGNAS = 136,                  /* ALIGNAS  */
  YYSYMBOL_Z88DK_SHORTCALL = 137,          /* Z88DK_SHORTCALL  */
  YYSYMBOL_Z88DK_PARAMS_OFFSET = 138,      /* Z88DK_PARAMS_OFFSET  */
  YYSYMBOL_GENERIC = 139,                  /* GENERIC  */
  YYSYMBOL_GENERIC_ASSOC_LIST = 140,       /* GENERIC_ASSOC_LIST  */
  YYSYMBOL_GENERIC_ASSOCIATION = 141,      /* GENERIC_ASSOCIATION  */
  YYSYMBOL_ASM = 142,                      /* ASM  */
  YYSYMBOL_143_ = 143,                     /* '('  */
  YYSYMBOL_144_ = 144,                     /* ')'  */
  YYSYMBOL_145_ = 145,                     /* ','  */
  YYSYMBOL_146_ = 146,                     /* ':'  */
  YYSYMBOL_147_ = 147,                     /* '['  */
  YYSYMBOL_148_ = 148,                     /* ']'  */
  YYSYMBOL_149_ = 149,                     /* '.'  */
  YYSYMBOL_150_ = 150,                     /* '{'  */
  YYSYMBOL_151_ = 151,                     /* '}'  */
  YYSYMBOL_152_ = 152,                     /* '&'  */
  YYSYMBOL_153_ = 153,                     /* '*'  */
  YYSYMBOL_154_ = 154,                     /* '+'  */
  YYSYMBOL_155_ = 155,                     /* '-'  */
  YYSYMBOL_156_ = 156,                     /* '~'  */
  YYSYMBOL_157_ = 157,                     /* '!'  */
  YYSYMBOL_158_ = 158,                     /* '/'  */
  YYSYMBOL_159_ = 159,                     /* '%'  */
  YYSYMBOL_160_ = 160,                     /* '<'  */
  YYSYMBOL_161_ = 161,                     /* '>'  */
  YYSYMBOL_162_ = 162,                     /* '^'  */
  YYSYMBOL_163_ = 163,                     /* '|'  */
  YYSYMBOL_164_ = 164,                     /* '?'  */
  YYSYMBOL_165_ = 165,                     /* '='  */
  YYSYMBOL_166_ = 166,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 167,                 /* $accept  */
  YYSYMBOL_primary_expr = 168,             /* primary_expr  */
  YYSYMBOL_generic_selection = 169,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 170,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 171,      /* generic_association  */
  YYSYMBOL_postfix_expr = 172,             /* postfix_expr  */
  YYSYMBOL_173_1 = 173,                    /* $@1  */
  YYSYMBOL_174_2 = 174,                    /* $@2  */
  YYSYMBOL_argument_expr_list = 175,       /* argument_expr_list  */
  YYSYMBOL_unary_expr = 176,               /* unary_expr  */
  YYSYMBOL_unary_operator = 177,           /* unary_operator  */
  YYSYMBOL_cast_expr = 178,                /* cast_expr  */
  YYSYMBOL_multiplicative_expr = 179,      /* multiplicative_expr  */
  YYSYMBOL_additive_expr = 180,            /* additive_expr  */
  YYSYMBOL_shift_expr = 181,               /* shift_expr  */
  YYSYMBOL_relational_expr = 182,          /* relational_expr  */
  YYSYMBOL_equality_expr = 183,            /* equality_expr  */
  YYSYMBOL_and_expr = 184,                 /* and_expr  */
  YYSYMBOL_exclusive_or_expr = 185,        /* exclusive_or_expr  */
  YYSYMBOL_inclusive_or_expr = 186,        /* inclusive_or_expr  */
  YYSYMBOL_logical_and_expr = 187,         /* logical_and_expr  */
  YYSYMBOL_188_3 = 188,                    /* $@3  */
  YYSYMBOL_logical_or_expr = 189,          /* logical_or_expr  */
  YYSYMBOL_190_4 = 190,                    /* $@4  */
  YYSYMBOL_conditional_expr = 191,         /* conditional_expr  */
  YYSYMBOL_192_5 = 192,                    /* $@5  */
  YYSYMBOL_assignment_expr = 193,          /* assignment_expr  */
  YYSYMBOL_assignment_operator = 194,      /* assignment_operator  */
  YYSYMBOL_expr = 195,                     /* expr  */
  YYSYMBOL_196_6 = 196,                    /* $@6  */
  YYSYMBOL_expr_opt = 197,                 /* expr_opt  */
  YYSYMBOL_constant_expr = 198,            /* constant_expr  */
  YYSYMBOL_declaration = 199,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 200,   /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_ = 201,  /* declaration_specifiers_  */
  YYSYMBOL_init_declarator_list = 202,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 203,          /* init_declarator  */
  YYSYMBOL_attribute_declaration = 204,    /* attribute_declaration  */
  YYSYMBOL_storage_class_specifier = 205,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 206,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 207, /* struct_or_union_specifier  */
  YYSYMBOL_208_7 = 208,                    /* $@7  */
  YYSYMBOL_struct_or_union = 209,          /* struct_or_union  */
  YYSYMBOL_member_declaration_list = 210,  /* member_declaration_list  */
  YYSYMBOL_member_declaration = 211,       /* member_declaration  */
  YYSYMBOL_type_specifier_qualifier = 212, /* type_specifier_qualifier  */
  YYSYMBOL_member_declarator_list = 213,   /* member_declarator_list  */
  YYSYMBOL_member_declarator = 214,        /* member_declarator  */
  YYSYMBOL_enum_specifier = 215,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 216,          /* enumerator_list  */
  YYSYMBOL_enumerator = 217,               /* enumerator  */
  YYSYMBOL_type_qualifier = 218,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 219,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 220,      /* alignment_specifier  */
  YYSYMBOL_declarator = 221,               /* declarator  */
  YYSYMBOL_direct_declarator = 222,        /* direct_declarator  */
  YYSYMBOL_declarator2 = 223,              /* declarator2  */
  YYSYMBOL_array_declarator = 224,         /* array_declarator  */
  YYSYMBOL_declarator2_function_attributes = 225, /* declarator2_function_attributes  */
  YYSYMBOL_function_declarator = 226,      /* function_declarator  */
  YYSYMBOL_227_8 = 227,                    /* $@8  */
  YYSYMBOL_pointer = 228,                  /* pointer  */
  YYSYMBOL_unqualified_pointer = 229,      /* unqualified_pointer  */
  YYSYMBOL_type_qualifier_list = 230,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 231,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 232,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 233,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator = 234,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 235, /* direct_abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator_opt = 236, /* direct_abstract_declarator_opt  */
  YYSYMBOL_array_abstract_declarator = 237, /* array_abstract_declarator  */
  YYSYMBOL_function_abstract_declarator = 238, /* function_abstract_declarator  */
  YYSYMBOL_239_9 = 239,                    /* $@9  */
  YYSYMBOL_initializer = 240,              /* initializer  */
  YYSYMBOL_initializer_list = 241,         /* initializer_list  */
  YYSYMBOL_designation_opt = 242,          /* designation_opt  */
  YYSYMBOL_designation = 243,              /* designation  */
  YYSYMBOL_designator_list = 244,          /* designator_list  */
  YYSYMBOL_designator = 245,               /* designator  */
  YYSYMBOL_static_assert_declaration = 246, /* static_assert_declaration  */
  YYSYMBOL_attribute_specifier_sequence = 247, /* attribute_specifier_sequence  */
  YYSYMBOL_attribute_specifier_sequence_opt = 248, /* attribute_specifier_sequence_opt  */
  YYSYMBOL_attribute_specifier = 249,      /* attribute_specifier  */
  YYSYMBOL_attribute_list = 250,           /* attribute_list  */
  YYSYMBOL_attribute = 251,                /* attribute  */
  YYSYMBOL_attribute_token = 252,          /* attribute_token  */
  YYSYMBOL_attribute_argument_clause = 253, /* attribute_argument_clause  */
  YYSYMBOL_balanced_token_sequence = 254,  /* balanced_token_sequence  */
  YYSYMBOL_balanced_token = 255,           /* balanced_token  */
  YYSYMBOL_statement = 256,                /* statement  */
  YYSYMBOL_labeled_statement = 257,        /* labeled_statement  */
  YYSYMBOL_label = 258,                    /* label  */
  YYSYMBOL_259_10 = 259,                   /* @10  */
  YYSYMBOL_start_block = 260,              /* start_block  */
  YYSYMBOL_end_block = 261,                /* end_block  */
  YYSYMBOL_compound_statement = 262,       /* compound_statement  */
  YYSYMBOL_block_item_list = 263,          /* block_item_list  */
  YYSYMBOL_expression_statement = 264,     /* expression_statement  */
  YYSYMBOL_selection_statement = 265,      /* selection_statement  */
  YYSYMBOL_266_11 = 266,                   /* $@11  */
  YYSYMBOL_267_12 = 267,                   /* @12  */
  YYSYMBOL_iteration_statement = 268,      /* iteration_statement  */
  YYSYMBOL_269_13 = 269,                   /* $@13  */
  YYSYMBOL_270_14 = 270,                   /* $@14  */
  YYSYMBOL_jump_statement = 271,           /* jump_statement  */
  YYSYMBOL_translation_unit = 272,         /* translation_unit  */
  YYSYMBOL_external_declaration = 273,     /* external_declaration  */
  YYSYMBOL_function_definition = 274,      /* function_definition  */
  YYSYMBOL_275_15 = 275,                   /* $@15  */
  YYSYMBOL_276_16 = 276,                   /* $@16  */
  YYSYMBOL_function_body = 277,            /* function_body  */
  YYSYMBOL_file = 278,                     /* file  */
  YYSYMBOL_function_attribute = 279,       /* function_attribute  */
  YYSYMBOL_function_attributes = 280,      /* function_attributes  */
  YYSYMBOL_offsetof_member_designator = 281, /* offsetof_member_designator  */
  YYSYMBOL_282_17 = 282,                   /* $@17  */
  YYSYMBOL_string_literal_val = 283,       /* string_literal_val  */
  YYSYMBOL_Interrupt_storage = 284,        /* Interrupt_storage  */
  YYSYMBOL_sfr_reg_bit = 285,              /* sfr_reg_bit  */
  YYSYMBOL_sfr_attributes = 286,           /* sfr_attributes  */
  YYSYMBOL_opt_stag = 287,                 /* opt_stag  */
  YYSYMBOL_stag = 288,                     /* stag  */
  YYSYMBOL_opt_assign_expr = 289,          /* opt_assign_expr  */
  YYSYMBOL_specifier_qualifier_list = 290, /* specifier_qualifier_list  */
  YYSYMBOL_type_specifier_list_ = 291,     /* type_specifier_list_  */
  YYSYMBOL_identifier_list = 292,          /* identifier_list  */
  YYSYMBOL_type_name = 293,                /* type_name  */
  YYSYMBOL_critical = 294,                 /* critical  */
  YYSYMBOL_critical_statement = 295,       /* critical_statement  */
  YYSYMBOL_statements_and_implicit = 296,  /* statements_and_implicit  */
  YYSYMBOL_declaration_after_statement = 297, /* declaration_after_statement  */
  YYSYMBOL_298_18 = 298,                   /* $@18  */
  YYSYMBOL_implicit_block = 299,           /* implicit_block  */
  YYSYMBOL_declaration_list = 300,         /* declaration_list  */
  YYSYMBOL_statement_list = 301,           /* statement_list  */
  YYSYMBOL_else_statement = 302,           /* else_statement  */
  YYSYMBOL_while = 303,                    /* while  */
  YYSYMBOL_do = 304,                       /* do  */
  YYSYMBOL_for = 305,                      /* for  */
  YYSYMBOL_asm_string_literal = 306,       /* asm_string_literal  */
  YYSYMBOL_asm_statement = 307,            /* asm_statement  */
  YYSYMBOL_addressmod = 308,               /* addressmod  */
  YYSYMBOL_identifier = 309                /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  163
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  377
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  599

#define YYMAXUTOK   397


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   157,     2,     2,     2,   159,   152,     2,
     143,   144,   153,   154,   145,   155,   149,   158,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   146,   166,
     160,   165,   161,   164,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   147,     2,   148,   162,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   150,   163,   151,   156,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   154,   155,   156,   157,   161,   165,   166,
     170,   171,   175,   176,   177,   179,   183,   183,   190,   190,
     197,   199,   201,   209,   220,   221,   225,   226,   227,   228,
     237,   238,   239,   240,   241,   245,   246,   247,   248,   249,
     250,   254,   255,   259,   260,   261,   262,   266,   267,   268,
     272,   273,   274,   278,   279,   280,   281,   282,   286,   287,
     288,   292,   293,   297,   298,   302,   303,   307,   308,   308,
     313,   314,   314,   319,   320,   320,   328,   329,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   388,
     389,   389,   393,   394,   398,   404,   428,   463,   467,   473,
     476,   477,   482,   483,   488,   489,   497,   498,   502,   503,
     507,   511,   515,   519,   523,   528,   532,   539,   544,   549,
     554,   559,   564,   569,   574,   579,   584,   589,   595,   604,
     609,   617,   626,   630,   629,   722,   752,   753,   757,   758,
     771,   796,   797,   798,   802,   803,   811,   812,   822,   836,
     840,   845,   852,   873,   896,   912,   913,   921,   941,   945,
     949,   953,   957,   961,   965,   969,   973,   977,   984,   988,
     995,  1001,  1016,  1017,  1025,  1026,  1027,  1028,  1032,  1033,
    1034,  1038,  1047,  1066,  1095,  1130,  1169,  1211,  1256,  1257,
    1289,  1294,  1293,  1327,  1338,  1339,  1349,  1362,  1382,  1388,
    1428,  1436,  1437,  1444,  1445,  1449,  1450,  1458,  1475,  1485,
    1486,  1487,  1494,  1495,  1496,  1500,  1501,  1505,  1512,  1524,
    1525,  1537,  1539,  1538,  1569,  1570,  1571,  1575,  1576,  1585,
    1586,  1590,  1594,  1595,  1599,  1621,  1625,  1633,  1646,  1647,
    1651,  1652,  1656,  1664,  1665,  1666,  1667,  1671,  1672,  1676,
    1677,  1681,  1682,  1686,  1687,  1691,  1692,  1698,  1699,  1700,
    1704,  1708,  1712,  1716,  1717,  1721,  1722,  1723,  1736,  1738,
    1745,  1745,  1755,  1766,  1774,  1775,  1780,  1784,  1785,  1786,
    1790,  1791,  1795,  1795,  1803,  1803,  1829,  1829,  1838,  1848,
    1874,  1873,  1913,  1923,  1936,  1946,  1955,  1969,  1970,  1974,
    1978,  1999,  2007,  2006,  2026,  2025,  2054,  2055,  2066,  2069,
    2076,  2077,  2081,  2085,  2088,  2091,  2094,  2097,  2100,  2106,
    2109,  2112,  2118,  2124,  2130,  2133,  2136,  2139,  2148,  2172,
    2190,  2191,  2191,  2198,  2205,  2232,  2233,  2248,  2256,  2260,
    2268,  2279,  2290,  2302,  2303,  2314,  2333,  2351,  2364,  2367,
    2369,  2377,  2378,  2386,  2394,  2420,  2431,  2440,  2441,  2450,
    2450,  2461,  2468,  2478,  2491,  2517,  2518,  2522,  2523,  2528,
    2542,  2557,  2582,  2586,  2596,  2609,  2620,  2638
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_NAME", "ADDRSPACE_NAME", "CONSTANT", "SIZEOF", "ALIGNOF", "TYPEOF",
  "OFFSETOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "ATTRIBCOLON",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF", "EXTERN", "STATIC", "THREAD_LOCAL", "AUTO", "REGISTER",
  "CODE", "EEPROM", "INTERRUPT", "SFR", "SFR16", "SFR32", "ADDRESSMOD",
  "STATIC_ASSERT", "AT", "SBIT", "REENTRANT", "USING", "XDATA", "DATA",
  "IDATA", "PDATA", "VAR_ARGS", "CRITICAL", "NONBANKED", "BANKED",
  "SHADOWREGS", "SD_WPARAM", "SD_BOOL", "SD_CHAR", "SD_SHORT", "SD_INT",
  "SD_LONG", "SIGNED", "UNSIGNED", "SD_FLOAT", "DOUBLE", "FIXED16X16",
  "SD_CONST", "VOLATILE", "SD_VOID", "BIT", "STRUCT", "UNION", "ENUM",
  "RANGE", "SD_FAR", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "NAKED",
  "JAVANATIVE", "OVERLAY", "TRAP", "STRING_LITERAL", "INLINEASM", "IFX",
  "ADDRESS_OF", "GET_VALUE_AT_ADDRESS", "SET_VALUE_AT_ADDRESS", "SPIL",
  "UNSPIL", "GETHBIT", "GETABIT", "GETBYTE", "GETWORD", "BITWISEAND",
  "UNARYMINUS", "IPUSH", "IPOP", "PCALL", "ENDFUNCTION", "JUMPTABLE",
  "RRC", "RLC", "CAST", "CALL", "PARAM", "NULLOP", "BLOCK", "LABEL",
  "RECEIVE", "SEND", "ARRAYINIT", "DUMMY_READ_VOLATILE", "ENDCRITICAL",
  "SWAP", "INLINE", "NORETURN", "RESTRICT", "SMALLC", "PRESERVES_REGS",
  "Z88DK_FASTCALL", "Z88DK_CALLEE", "ALIGNAS", "Z88DK_SHORTCALL",
  "Z88DK_PARAMS_OFFSET", "GENERIC", "GENERIC_ASSOC_LIST",
  "GENERIC_ASSOCIATION", "ASM", "'('", "')'", "','", "':'", "'['", "']'",
  "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expr", "generic_selection", "generic_assoc_list",
  "generic_association", "postfix_expr", "$@1", "$@2",
  "argument_expr_list", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "and_expr", "exclusive_or_expr", "inclusive_or_expr",
  "logical_and_expr", "$@3", "logical_or_expr", "$@4", "conditional_expr",
  "$@5", "assignment_expr", "assignment_operator", "expr", "$@6",
  "expr_opt", "constant_expr", "declaration", "declaration_specifiers",
  "declaration_specifiers_", "init_declarator_list", "init_declarator",
  "attribute_declaration", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "$@7", "struct_or_union",
  "member_declaration_list", "member_declaration",
  "type_specifier_qualifier", "member_declarator_list",
  "member_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "declarator2", "array_declarator",
  "declarator2_function_attributes", "function_declarator", "$@8",
  "pointer", "unqualified_pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "abstract_declarator", "direct_abstract_declarator",
  "direct_abstract_declarator_opt", "array_abstract_declarator",
  "function_abstract_declarator", "$@9", "initializer", "initializer_list",
  "designation_opt", "designation", "designator_list", "designator",
  "static_assert_declaration", "attribute_specifier_sequence",
  "attribute_specifier_sequence_opt", "attribute_specifier",
  "attribute_list", "attribute", "attribute_token",
  "attribute_argument_clause", "balanced_token_sequence", "balanced_token",
  "statement", "labeled_statement", "label", "@10", "start_block",
  "end_block", "compound_statement", "block_item_list",
  "expression_statement", "selection_statement", "$@11", "@12",
  "iteration_statement", "$@13", "$@14", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "$@15", "$@16", "function_body", "file", "function_attribute",
  "function_attributes", "offsetof_member_designator", "$@17",
  "string_literal_val", "Interrupt_storage", "sfr_reg_bit",
  "sfr_attributes", "opt_stag", "stag", "opt_assign_expr",
  "specifier_qualifier_list", "type_specifier_list_", "identifier_list",
  "type_name", "critical", "critical_statement", "statements_and_implicit",
  "declaration_after_statement", "$@18", "implicit_block",
  "declaration_list", "statement_list", "else_statement", "while", "do",
  "for", "asm_string_literal", "asm_statement", "addressmod", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,    40,    41,    44,    58,    91,    93,    46,
     123,   125,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    61,    59
};
#endif

#define YYPACT_NINF (-458)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-363)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1936,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,
    -458,  -458,    -9,  -458,  -458,   112,   -46,  1780,  -458,  -458,
    -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,
    -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,    24,  -458,
    -458,  -458,   -12,    43,    36,  -458,  -458,    14,  -458,  -458,
    2416,  -458,  -458,    60,  2416,  -458,  -458,  2416,  -458,  -458,
      62,    11,    23,  -458,  2456,    39,   690,  -458,  -103,  -458,
    1936,  -458,  -458,   199,  -458,  -458,  -458,    42,  -458,    47,
    1780,  -458,  1799,    71,  1807,    75,  1807,  1807,  -458,    84,
    1411,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,   257,
    -458,  1780,  -458,   -67,   -66,   258,    41,   293,    79,    81,
      74,   225,     5,  -458,  -458,  -458,  -458,   112,   102,  1411,
     111,   112,  -458,   -97,  -458,  -105,  -458,    60,   112,  -458,
    -458,  2102,  1518,    21,  1780,  -458,  1780,  -458,  -458,  -458,
    -458,  -458,  -458,  -458,  -458,  -458,  -458,   114,  -458,  -458,
     120,   146,  -458,  2456,  -458,    62,  1780,  -458,  -458,   794,
    -458,  -458,  -458,  -458,   112,   135,   176,  1411,  -458,  2416,
    1411,  -458,  2416,  -458,  -458,  1780,   556,  -458,  -458,   178,
     -71,   153,  -458,  -458,  -458,   496,  1780,  -458,  -458,  1780,
    1780,  1780,  1780,  1780,  1780,  1780,  1780,  1780,  1780,  1780,
    1780,  1780,  1780,  1780,  1780,  -458,  -458,  -458,   -26,  -458,
      60,   112,   159,   161,   170,   -81,  -458,   182,   309,    43,
    -458,  1356,  2102,  -458,   198,  -458,   172,  -458,  -458,    14,
     742,  -458,  -458,  2102,  1625,  -458,   194,  1571,  -458,  2416,
     183,  -458,  -458,  -458,   112,  1780,  1780,  -458,  -458,  1780,
    -458,  -458,   186,  -458,   190,   264,   210,   229,   230,   232,
     234,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,  -458,
    -458,  -458,  1780,  -458,  -458,  2220,   -39,  -458,    -4,   236,
    -458,  -458,  1590,   112,  -458,   237,   239,   -70,   112,  -458,
    -458,  -458,   -67,   -67,   -66,   -66,   258,   258,   258,   258,
      41,    41,   293,    79,    81,  1780,  1780,  1780,    17,  -458,
     221,    52,  -458,  -458,   112,   241,    28,  -458,   112,  -458,
     222,   -27,  -458,  -458,  -458,   240,  -458,  -458,  1780,  -458,
     226,   248,  -458,   249,   231,  1101,   467,  -458,  -458,   976,
    -458,   244,  -458,  1081,  -458,  -458,   897,   617,  -458,   252,
    -458,  -458,   254,  1625,  -458,  1780,  -458,   255,     9,   263,
     266,  -458,  -458,  -458,   112,   185,   271,   265,  -458,  -458,
    -458,   273,   268,  -458,   268,   112,  1791,  -458,  1780,  -458,
     276,   277,    -4,   278,  1745,   -27,  -458,  -458,  -458,  1780,
    -458,  -458,    74,   225,   188,  -458,  -458,  1780,  -458,    19,
    -458,  -458,  -458,  -458,  -458,    33,  -458,  -458,  -458,  1780,
     112,    55,  1356,  -458,   -94,  -458,    60,   262,   279,  -458,
     331,  -458,   -86,  1081,   287,   288,  -458,  -458,  -458,   112,
     274,   282,   138,  -458,  -458,  -458,  -458,   291,  1081,   294,
    -458,  1201,  -458,  -458,  -458,  -458,  -458,  1002,  2265,  -458,
    -458,  -458,   296,   305,  -458,  2057,  -458,    51,  -458,  2371,
    -458,  -458,  1780,  -458,   290,    77,  -458,   308,   192,  -458,
     312,  -458,  -458,  -458,  -458,  2416,  -458,   311,    59,  -458,
    1780,  -458,  -458,  -458,  -458,   313,  -458,   131,  -458,  -458,
    -458,  -458,     8,  -458,  1981,  -458,  -458,  -458,   295,  -458,
    -458,  1780,  1780,   297,  -458,  -458,  -458,   -83,  1780,   357,
    1256,  -458,  2265,  -458,  -458,  -458,  -458,   316,  -458,  -458,
    1780,  -458,  1780,  -458,  1791,  1780,   318,  -458,   149,  -458,
    -458,  -458,  -458,  1356,  -458,  -458,  -458,    38,  1981,   299,
     196,   200,  -458,  -458,   206,   326,   304,  1780,  -458,    94,
     112,  -458,  -458,  -458,  -458,  -458,  -458,  1780,   -79,  -458,
     325,  -458,  -458,  -458,  -458,  -458,  1780,  1780,   306,  -458,
    -458,  -458,    38,  -458,  1780,  1081,  1081,  1081,   218,   307,
    1780,  -458,  -458,   391,  -458,  -458,   310,  1780,   333,  1081,
    -458,  -458,   335,  -458,  -458,  1081,  1081,  -458,  -458
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     308,   377,   128,   161,   111,   112,   113,   114,   115,   116,
     163,   164,   339,   341,   342,     0,     0,     0,   337,   162,
     165,   166,   167,   125,   118,   119,   120,   121,   123,   124,
     122,   129,   158,   160,   117,   130,   136,   137,     0,   168,
     169,   159,     0,     0,     0,   200,   300,     0,    99,    98,
     100,   141,   126,   240,   102,   127,   142,   104,   143,   302,
     172,     0,   176,   177,   188,     0,   194,    97,     0,   239,
     309,   297,   299,     0,   132,   338,   301,   174,   340,     0,
       0,     3,     0,     0,     0,     0,     0,     0,   334,     0,
       0,    35,    36,    37,    38,    39,    40,    12,     6,    26,
      41,     0,    43,    47,    50,    53,    58,    61,    63,    65,
      67,    70,    73,    94,   131,     4,     2,     0,   154,     0,
       0,   243,    95,     0,   106,   304,   101,   241,   344,   103,
     105,     0,     0,   191,   335,   313,     0,   314,   318,   321,
     319,   320,   315,   316,   317,   323,   324,     0,   325,   326,
       0,     0,   189,   310,   322,   173,     0,   201,   198,   196,
     110,   238,   298,     1,     0,     0,     0,     0,    30,     0,
       0,    33,     0,    27,    28,     0,    41,    76,    89,     0,
     353,     0,    18,    20,    21,     0,     0,    16,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    71,    74,     0,   155,
     240,     0,     0,     0,   175,     0,   244,   247,   249,     0,
      96,     0,     0,   133,   135,   345,     0,   272,   363,     0,
     240,   306,   303,     0,     0,   181,     0,     0,   190,     0,
       0,   351,   336,   312,     0,     0,     0,   311,   195,     0,
     202,   199,     0,   375,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    78,     0,     5,    90,   215,   209,   354,   210,     0,
     213,   214,     0,     0,    14,     0,    24,     0,     0,    44,
      45,    46,    48,    49,    51,    52,    56,    57,    54,    55,
      59,    60,    62,    64,    66,     0,     0,     0,     0,   150,
     347,     0,   171,   170,   245,     0,     0,   248,     0,   107,
     108,   229,   224,   109,   305,     0,   276,   355,     0,   270,
       0,     0,   273,    93,     0,   241,     0,   365,   257,   240,
     274,     0,   258,   240,   263,   277,   240,   359,   264,     2,
     364,   307,     0,     0,   183,     0,   182,     0,   353,     0,
     203,   205,   208,   193,     0,     0,     0,     0,   197,   376,
     237,     0,    31,    32,     0,     0,     0,    77,     0,   219,
       0,     0,   211,   222,     0,   229,    42,    19,    15,     0,
      13,    17,    69,    72,     0,   151,   156,     0,   157,     0,
     152,   246,   242,   256,   251,     0,   253,   255,   250,     0,
       0,     0,     0,   230,     0,   232,   240,     0,     0,   374,
       0,   280,     0,   240,     0,     0,   369,   370,   371,     0,
       0,     0,     0,   259,   260,   261,   262,     0,   240,     0,
     267,   241,   265,   275,   356,   279,   366,   240,     0,   358,
     268,   184,     0,     0,   185,   215,   207,   209,   192,     0,
     352,   329,     0,   327,     0,     0,   330,     0,     0,     8,
       0,    91,   221,   212,   220,     0,   217,     0,     0,    25,
       0,   346,   153,   252,   254,     0,   235,   229,   225,   227,
     231,   233,   240,   138,     0,   269,   271,   372,     0,   281,
     266,     0,     0,     0,   293,   294,   295,     0,     0,     0,
      92,   361,   360,   186,   187,   204,   206,     0,   236,    34,
       0,   331,     0,     7,     0,     0,     0,   218,   229,    22,
      75,   234,   226,     0,   134,   139,   349,   149,   348,     0,
       0,     0,   292,   296,     0,     0,     0,    92,   328,     0,
       0,    11,     9,    10,   223,    23,   228,     0,     0,   144,
     146,   350,   373,   282,   284,   286,     0,    92,     0,   333,
     332,   147,   149,   140,     0,   240,   240,   240,     0,     0,
      92,   145,   148,   368,   285,   287,     0,    92,     0,   240,
     283,   288,     0,   290,   367,   240,   240,   289,   291
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -458,  -458,  -458,  -458,   -42,  -458,  -458,  -458,    86,    89,
    -458,   -90,   173,   175,    88,   171,   281,   283,   284,   180,
     184,  -458,  -458,  -458,     4,  -458,    37,  -458,   -56,  -458,
    -352,   -29,     7,    32,    56,  -458,   270,  -458,  -458,  -458,
    -458,  -458,  -458,  -458,   -11,  -457,  -458,   -80,  -458,   286,
    -273,   -47,  -458,  -458,   -41,   -64,  -458,  -458,  -458,  -458,
    -458,   -43,  -458,  -102,  -214,  -458,    34,  -262,  -268,  -458,
    -458,  -458,  -458,  -384,   109,  -454,  -458,  -458,    97,  -458,
       3,   -49,   -59,  -458,   202,  -458,  -458,  -458,    93,  -329,
    -458,  -306,  -458,  -458,   177,  -194,  -458,  -458,  -458,  -458,
    -458,  -458,  -458,  -458,  -458,  -458,   430,  -458,  -458,  -458,
     292,  -458,   367,  -458,  -458,  -458,  -458,  -458,  -458,  -458,
    -458,  -458,  -458,  -458,  -458,   280,   -74,  -458,  -458,  -294,
    -458,  -458,  -458,  -225,  -458,  -458,  -458,  -458,  -458,  -458,
    -458,  -458,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    97,    98,   468,   469,    99,   288,   283,   285,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   305,   112,   306,   177,   307,   178,   272,   333,   378,
     334,   114,   228,   180,    48,   123,   124,    49,    50,    51,
      52,   325,    53,   492,   493,    54,   558,   559,    55,   208,
     209,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     239,    65,    66,   159,   380,   360,   361,   277,   278,   279,
     280,   281,   475,   323,   411,   412,   413,   414,   415,    67,
     441,   336,    69,   215,   216,   217,   317,   405,   406,   337,
     338,   339,   418,   230,   340,   231,   341,   342,   434,   575,
     576,   435,   577,   596,   436,    70,    71,    72,   131,   222,
     232,    73,   152,   153,   465,   550,   115,   154,    74,    75,
     223,   224,   398,   537,   538,   240,   362,   343,   344,   345,
     447,   448,   449,   233,   347,   590,   437,   438,   439,   498,
     348,    76,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,   155,   120,    68,   128,   346,   125,    46,   382,   161,
     442,   188,     1,   381,   444,    79,   181,     1,   446,   157,
       1,   113,     1,   158,     1,   359,   206,     1,   489,   423,
     237,     1,    47,   533,   179,   396,     1,   536,   118,   351,
    -108,     1,     1,    77,    44,   213,     1,    77,   219,    78,
       1,   166,   445,   409,     1,   410,   127,   196,   197,   274,
     221,  -108,   274,   160,   314,    77,   572,   315,   161,   220,
      77,   490,   275,    68,   533,   274,  -215,    46,   390,   165,
     499,   561,    45,   543,   113,   157,   189,   573,   192,   193,
     212,   190,   191,   256,   500,   257,   258,    80,   259,   289,
     290,   291,    47,   236,   275,   242,   126,   243,  -215,   509,
     129,   179,   250,   130,   179,     1,   251,   210,   164,   308,
     409,   218,   410,   113,   403,   309,   396,   248,   225,   403,
     287,   119,   353,   241,    68,   423,   113,   276,   113,   383,
     113,     1,   433,  -216,    81,    82,    83,    84,    85,   556,
      86,    87,   455,   511,   133,    44,  -215,    43,   546,   534,
     113,   310,    45,   229,   252,   238,  -180,    45,   395,   207,
     482,   168,   404,   171,   117,   173,   174,   483,   320,   176,
     122,    43,    43,   121,   557,  -178,    43,   157,   320,   382,
     250,    45,   386,   381,   455,   568,    45,   399,  -215,   163,
     487,   198,   199,   400,   528,   352,   488,    44,   357,   132,
     529,   210,   260,   127,   169,   579,   366,   367,   172,    77,
     368,   519,   286,   512,   520,    68,   521,   175,   588,    77,
     349,   202,   276,   335,    88,   592,    68,   204,   113,   274,
     350,   113,   569,   203,   241,   205,   583,   584,   585,   113,
     113,   394,   211,   113,   229,   214,   176,   244,   322,   176,
     594,   526,   229,   245,   176,   229,   597,   598,   182,   183,
     184,   358,   194,   195,   176,   176,   161,    89,   409,   422,
     410,    90,   532,   387,   296,   297,   298,   299,   391,   246,
      91,    92,    93,    94,    95,    96,   409,   282,   410,   417,
     555,   253,   470,   312,   506,   313,   250,   358,   210,   377,
     176,   200,   201,  -179,   218,   457,   407,   456,   408,   176,
     254,   255,   273,   274,   452,   316,   453,   363,   364,   461,
     364,   318,   113,   274,   480,   349,   523,   524,   326,   349,
     563,   274,   354,   349,   564,   274,   349,   349,  -343,   335,
     565,   274,   369,   350,   372,   477,   370,   113,    77,   113,
     371,   176,   586,   274,   460,   292,   293,   494,   481,   294,
     295,   300,   301,   373,   374,   466,   507,   375,   229,   376,
     485,   388,   161,   384,   389,   422,   397,   221,   113,   402,
     416,   420,   419,   155,   274,   332,   176,   421,   450,   210,
     185,   113,   451,   454,   186,   407,   187,   458,   495,   463,
     486,   459,   457,   113,   120,   471,   462,   464,   385,   127,
     472,   473,   474,   349,   176,   496,   286,   497,   176,   503,
     501,   502,   176,   517,   508,   176,   176,   510,   349,   539,
     504,   349,   545,   494,   513,   540,   541,   349,   505,   322,
     470,    68,   544,   514,   522,    77,   518,    77,   525,   527,
     548,   531,   554,   542,   549,   562,   113,   176,   226,   566,
     567,   574,   580,   587,   589,   479,   591,   593,   176,   595,
     229,   535,   552,   302,   530,   392,   303,   358,   304,   319,
     393,   358,   581,   516,   478,   127,   560,   311,   484,     1,
     162,   176,    81,    82,    83,    84,    85,   358,    86,    87,
     578,   491,   176,    68,   324,    68,   401,   547,   443,   350,
     247,   176,     0,     0,   365,     0,     0,   176,   571,     0,
     176,   560,     0,     0,     0,     0,   176,    77,     0,     0,
       0,     0,   229,     0,   229,   582,     0,     0,     0,   424,
     570,   425,   426,   427,   428,   429,   430,   431,   432,   551,
       0,   113,   553,     0,     0,     0,     0,     0,     0,     0,
     322,     0,    77,     0,     0,   349,   349,   349,   113,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   349,
     176,   176,    88,     0,     0,   349,   349,   176,     0,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,   176,     0,     0,   176,     0,     0,   227,  -240,     0,
       1,     0,   176,    81,    82,    83,    84,    85,     0,    86,
      87,     0,     0,     0,     0,    89,   176,     0,     0,    90,
     284,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,     0,   176,   176,     0,     0,     0,
       0,     0,     0,     0,   176,   176,   176,     0,     0,   176,
       0,     0,     0,   327,     0,     0,   176,     0,   176,     0,
       0,     0,     0,     0,   176,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,   328,   329,  -240,
       0,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,     0,
       0,     0,     0,    88,   330,     0,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,    19,    20,    21,    22,     1,     2,     3,    81,    82,
      83,    84,    85,     0,    86,    87,    89,     0,     0,   331,
      90,    32,    33,     0,    44,     0,     0,  -240,  -357,    91,
      92,    93,    94,    95,    96,     4,     5,     6,     7,     8,
       9,    10,    11,   -92,    12,    13,    14,     0,    16,    17,
      18,     0,     0,    19,    20,    21,    22,     0,   327,     3,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
       0,    41,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,    88,   330,
       0,   249,     0,    45,     0,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,     0,
       0,    39,    40,    41,     0,     0,     0,     0,    42,     0,
       0,    89,     0,     0,   331,    90,     0,     0,     0,    44,
       0,     0,     0,   332,    91,    92,    93,    94,    95,    96,
       1,     2,     3,    81,    82,    83,    84,    85,   -92,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
      13,    14,     0,    16,    17,    18,     0,    45,    19,    20,
      21,    22,     0,   327,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,     0,     0,   328,   329,     1,
       0,     0,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,     0,    88,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,    81,    82,
      83,    84,    85,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,    41,     0,
       0,     0,   327,    42,     0,     0,    89,     0,     0,   331,
      90,     0,     0,     0,    44,     0,     0,     0,  -278,    91,
      92,    93,    94,    95,    96,     0,   328,   329,   327,     0,
       0,     0,     0,   -92,     0,     0,     0,     0,     0,     0,
       0,     0,    88,   330,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   329,     1,     0,     0,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,    88,   330,
       0,     0,     0,     0,     1,     0,     0,    81,    82,    83,
      84,    85,     0,    86,    87,    89,     0,     0,   331,    90,
       0,     0,     0,    44,     0,     0,     0,   440,    91,    92,
      93,    94,    95,    96,     0,     0,     0,   327,     0,     0,
       0,    89,   -92,     0,   331,    90,     0,     0,     0,    44,
       0,     0,     0,  -362,    91,    92,    93,    94,    95,    96,
       0,   328,   329,     0,     0,     0,     0,     0,   -92,     0,
       0,     0,     0,     0,     0,     0,     0,    88,   330,     0,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     1,     0,     0,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,     0,
      89,     0,     0,   331,    90,     0,     0,     0,    44,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
      89,     0,     0,     0,    90,     0,     0,   -92,    44,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     1,
       2,     3,    81,    82,    83,    84,    85,   160,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    88,    12,    13,
      14,     0,    16,    17,    18,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    90,     0,     0,     0,    44,     0,
       0,     0,    88,    91,    92,    93,    94,    95,    96,     1,
       0,     0,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,     0,     0,
       0,     0,    42,     0,     0,    89,     0,     0,     0,    90,
       0,     0,     0,    44,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,     1,     2,     3,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    88,    12,    13,    14,     0,     0,    17,    18,
       0,     0,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,   321,    88,    91,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     3,    81,    82,    83,    84,    85,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,     0,     0,    42,     0,     0,
      89,     0,     0,   234,    90,     0,     0,    10,    11,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    19,
      20,    21,    22,     0,     1,     0,     3,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,    32,
      33,     0,     0,     1,     0,     0,    81,    82,    83,    84,
      85,     0,    86,    87,     0,     0,   355,     0,     0,     0,
      10,    11,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,    22,     0,     0,     1,     0,
       3,    81,    82,    83,    84,    85,     0,    86,    87,     0,
       0,     0,    32,    33,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,    90,     0,     0,    10,    11,   235,    88,     0,     0,
      91,    92,    93,    94,    95,    96,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    90,     0,     0,     0,     0,   356,
       0,    88,     0,    91,    92,    93,    94,    95,    96,    89,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
     385,     0,    91,    92,    93,    94,    95,    96,     1,     0,
       0,    81,    82,    83,    84,    85,    41,    86,    87,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,     1,     0,     0,    81,    82,    83,    84,
      85,     0,    86,    87,     0,     2,     3,     0,     0,     0,
       0,     0,     1,     0,     0,    81,    82,    83,    84,    85,
       1,    86,    87,    81,    82,    83,    84,    85,     0,    86,
      87,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,    13,    14,     0,     0,    17,    18,
       0,    88,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,     0,
       0,     0,   467,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    90,     0,
       0,     0,     0,   476,     0,    88,     0,    91,    92,    93,
      94,    95,    96,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      39,    40,    41,    90,     0,     0,     0,    42,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    89,     1,
       2,     3,   167,     0,     0,     0,    89,     0,     0,     0,
     170,    91,    92,    93,    94,    95,    96,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,     2,     3,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
      10,    11,     0,    12,    13,    14,     0,     0,    17,    18,
       0,     0,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,     0,
       1,     2,     3,     0,     0,    39,    40,    41,     0,     0,
       0,     0,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    45,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
      13,    14,     0,   226,    17,    18,     2,     3,    19,    20,
      21,    22,    41,     0,     0,     0,     0,    42,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,    13,    14,     0,    16,    17,
      18,     0,     0,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,     0,    39,    40,    41,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
     455,   379,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,   227,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,    13,    14,     0,     0,    17,    18,     2,
       3,    19,    20,    21,    22,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,    14,
       0,    16,    17,    18,     0,     0,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,    39,
      40,    41,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,   275,   379,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,    41,     0,     0,     0,
       0,    42,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    44,    12,    13,    14,     0,     0,    17,    18,
       2,     3,    19,    20,    21,    22,   515,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,    13,
      14,     0,     0,    17,    18,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,   134,     0,     0,
      39,    40,    41,     0,     0,   135,   136,    42,     0,     0,
       0,     0,   137,   138,   139,   140,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,   142,   143,
     144,   145,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,     0,   150,   151
};

static const yytype_int16 yycheck[] =
{
       0,    65,    43,     0,    53,   230,    47,     0,   276,    68,
     339,   101,     3,   275,   343,    15,    90,     3,   347,    66,
       3,    17,     3,    66,     3,   239,    21,     3,   412,   335,
     132,     3,     0,   487,    90,   308,     3,   494,    38,   233,
     145,     3,     3,    43,   147,   119,     3,    47,   145,    58,
       3,    80,   346,   147,     3,   149,    53,    16,    17,   145,
     165,   166,   145,   166,   145,    65,   145,   148,   127,   166,
      70,   165,   143,    70,   528,   145,   147,    70,   148,    79,
     166,   538,   153,   166,    80,   132,   153,   166,   154,   155,
     119,   158,   159,   167,   423,   169,   170,   143,   172,   189,
     190,   191,    70,   132,   143,   134,    50,   136,   147,   438,
      54,   167,   159,    57,   170,     3,   159,   117,    71,   145,
     147,   121,   149,   119,    96,   151,   399,   156,   128,    96,
     186,   143,   234,   133,   131,   441,   132,   180,   134,   143,
     136,     3,   336,   147,     6,     7,     8,     9,    10,   533,
      12,    13,   143,   447,   143,   147,   147,   143,   510,   151,
     156,   210,   153,   131,   164,   144,   143,   153,   151,   164,
     151,    82,   144,    84,   150,    86,    87,   144,   219,    90,
     166,   143,   143,   147,   146,   143,   143,   234,   229,   457,
     237,   153,   282,   455,   143,   547,   153,   145,   147,     0,
     145,   160,   161,   151,   145,   234,   151,   147,   237,   147,
     151,   211,   175,   210,   143,   567,   245,   246,   143,   219,
     249,   144,   185,   448,   147,   222,   149,   143,   580,   229,
     230,   152,   275,   230,    96,   587,   233,   163,   234,   145,
     233,   237,   148,   162,   244,    20,   575,   576,   577,   245,
     246,   307,   150,   249,   222,   144,   167,   143,   221,   170,
     589,   475,   230,   143,   175,   233,   595,   596,    11,    12,
      13,   239,    14,    15,   185,   186,   335,   139,   147,   335,
     149,   143,   151,   283,   196,   197,   198,   199,   288,   143,
     152,   153,   154,   155,   156,   157,   147,   144,   149,   328,
     151,   166,   376,   144,   166,   144,   353,   275,   308,   272,
     221,    18,    19,   143,   314,   358,   316,   358,   318,   230,
     144,   145,   144,   145,   353,   143,   355,   144,   145,   144,
     145,    22,   328,   145,   146,   335,   144,   145,   166,   339,
     144,   145,   148,   343,   144,   145,   346,   347,   150,   346,
     144,   145,   166,   346,   144,   384,   166,   353,   358,   355,
      96,   272,   144,   145,   364,   192,   193,   416,   397,   194,
     195,   200,   201,   144,   144,   375,   432,   145,   346,   145,
     409,   144,   441,   147,   145,   441,   165,   165,   384,   148,
     150,   143,   166,   457,   145,   151,   307,   166,   146,   399,
     143,   397,   148,   148,   147,   405,   149,   144,   146,   144,
     410,   145,   455,   409,   455,   378,   145,   144,   150,   416,
     144,   144,   144,   423,   335,   146,   389,    96,   339,   429,
     143,   143,   343,   462,   143,   346,   347,   143,   438,   144,
     166,   441,    85,   492,   148,   501,   502,   447,   166,   412,
     524,   448,   508,   148,   146,   455,   166,   457,   146,   148,
     144,   148,   144,   166,   520,   166,   462,   378,     1,   143,
     166,   146,   166,   166,    83,   389,   166,   144,   389,   144,
     448,   492,   524,   202,   480,   305,   203,   455,   204,   219,
     306,   459,   572,   459,   385,   492,   537,   211,   405,     3,
      70,   412,     6,     7,     8,     9,    10,   475,    12,    13,
     566,   414,   423,   510,   222,   512,   314,   510,   341,   512,
     153,   432,    -1,    -1,   244,    -1,    -1,   438,   557,    -1,
     441,   572,    -1,    -1,    -1,    -1,   447,   537,    -1,    -1,
      -1,    -1,   510,    -1,   512,   574,    -1,    -1,    -1,    82,
     550,    84,    85,    86,    87,    88,    89,    90,    91,   522,
      -1,   557,   525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     533,    -1,   572,    -1,    -1,   575,   576,   577,   574,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   589,
     501,   502,    96,    -1,    -1,   595,   596,   508,    -1,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
      -1,   522,    -1,    -1,   525,    -1,    -1,   150,     1,    -1,
       3,    -1,   533,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,   139,   547,    -1,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,    -1,   566,   567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   575,   576,   577,    -1,    -1,   580,
      -1,    -1,    -1,    56,    -1,    -1,   587,    -1,   589,    -1,
      -1,    -1,    -1,    -1,   595,   596,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    80,    81,    82,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    54,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,   139,    -1,    -1,   142,
     143,    71,    72,    -1,   147,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,    33,    34,    35,    36,    37,
      38,    39,    40,   166,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    52,    53,    54,    -1,    56,     5,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   131,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    96,    97,
      -1,    47,    -1,   153,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,   139,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
       3,     4,     5,     6,     7,     8,     9,    10,   166,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    -1,    46,    47,    48,    -1,   153,    51,    52,
      53,    54,    -1,    56,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,     3,
      -1,    -1,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    56,   136,    -1,    -1,   139,    -1,    -1,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,   156,   157,    -1,    80,    81,    56,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,     3,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    96,    97,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,   139,    -1,    -1,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    56,    -1,    -1,
      -1,   139,   166,    -1,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,    -1,
     139,    -1,    -1,    -1,   143,    -1,    -1,   166,   147,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,     3,
       4,     5,     6,     7,     8,     9,    10,   166,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    96,    42,    43,
      44,    -1,    46,    47,    48,    -1,    -1,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    96,   152,   153,   154,   155,   156,   157,     3,
      -1,    -1,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    96,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    96,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,    -1,    -1,    35,   143,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,    51,
      52,    53,    54,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,     3,    -1,    -1,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,    -1,    -1,    39,    40,   148,    96,    -1,    -1,
     152,   153,   154,   155,   156,   157,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
      -1,    96,    -1,   152,   153,   154,   155,   156,   157,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    -1,   152,   153,   154,   155,   156,   157,     3,    -1,
      -1,     6,     7,     8,     9,    10,   131,    12,    13,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,
     155,   156,   157,     3,    -1,    -1,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,     8,     9,    10,
       3,    12,    13,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    96,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,    -1,    96,    -1,   152,   153,   154,
     155,   156,   157,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     129,   130,   131,   143,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,   139,     3,
       4,     5,   143,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   152,   153,   154,   155,   156,   157,    -1,    -1,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,     4,     5,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
       3,     4,     5,    -1,    -1,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,   153,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    -1,     1,    47,    48,     4,     5,    51,    52,
      53,    54,   131,    -1,    -1,    -1,    -1,   136,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,   150,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    -1,    -1,    47,    48,     4,
       5,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      -1,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,   147,    42,    43,    44,    -1,    -1,    47,    48,
       4,     5,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    -1,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    41,    -1,    -1,
     129,   130,   131,    -1,    -1,    49,    50,   136,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,    92,    93,
      94,    95,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,    -1,   137,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,     4,     5,    33,    34,    35,    36,    37,    38,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    51,
      52,    53,    54,    61,    62,    63,    64,    65,    66,    67,
      68,    70,    71,    72,    73,    74,    75,    76,    77,   129,
     130,   131,   136,   143,   147,   153,   199,   200,   201,   204,
     205,   206,   207,   209,   212,   215,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   228,   229,   246,   247,   249,
     272,   273,   274,   278,   285,   286,   308,   309,    58,   309,
     143,     6,     7,     8,     9,    10,    12,    13,    96,   139,
     143,   152,   153,   154,   155,   156,   157,   168,   169,   172,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   189,   191,   198,   283,   309,   150,   309,   143,
     221,   147,   166,   202,   203,   221,   201,   247,   248,   201,
     201,   275,   147,   143,    41,    49,    50,    56,    57,    58,
      59,    60,    92,    93,    94,    95,   132,   133,   134,   135,
     137,   138,   279,   280,   284,   222,    47,   218,   228,   230,
     166,   249,   273,     0,    71,   309,   198,   143,   176,   143,
     143,   176,   143,   176,   176,   143,   176,   191,   193,   195,
     200,   293,    11,    12,    13,   143,   147,   149,   178,   153,
     158,   159,   154,   155,    14,    15,    16,    17,   160,   161,
      18,    19,   152,   162,   163,    20,    21,   164,   216,   217,
     309,   150,   198,   293,   144,   250,   251,   252,   309,   145,
     166,   165,   276,   287,   288,   309,     1,   150,   199,   200,
     260,   262,   277,   300,    35,   148,   198,   230,   144,   227,
     292,   309,   198,   198,   143,   143,   143,   279,   198,    47,
     218,   228,   309,   166,   144,   145,   293,   293,   293,   293,
     193,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   165,   194,   144,   145,   143,   228,   234,   235,   236,
     237,   238,   144,   174,   144,   175,   193,   195,   173,   178,
     178,   178,   179,   179,   180,   180,   181,   181,   181,   181,
     182,   182,   183,   184,   185,   188,   190,   192,   145,   151,
     248,   216,   144,   144,   145,   148,   143,   253,    22,   203,
     221,   150,   193,   240,   277,   208,   166,    56,    80,    81,
      97,   142,   151,   195,   197,   247,   248,   256,   257,   258,
     261,   263,   264,   294,   295,   296,   300,   301,   307,   309,
     199,   262,   198,   230,   148,    35,   148,   198,   200,   231,
     232,   233,   293,   144,   145,   292,   198,   198,   198,   166,
     166,    96,   144,   144,   144,   145,   145,   193,   196,   144,
     231,   234,   235,   143,   147,   150,   178,   309,   144,   145,
     148,   309,   186,   187,   195,   151,   217,   165,   289,   145,
     151,   251,   148,    96,   144,   254,   255,   309,   309,   147,
     149,   241,   242,   243,   244,   245,   150,   198,   259,   166,
     143,   166,   195,   258,    82,    84,    85,    86,    87,    88,
      89,    90,    91,   262,   265,   268,   271,   303,   304,   305,
     151,   247,   256,   261,   256,   296,   256,   297,   298,   299,
     146,   148,   198,   198,   148,   143,   221,   228,   144,   145,
     309,   144,   145,   144,   144,   281,   309,    81,   170,   171,
     293,   193,   144,   144,   144,   239,   148,   198,   241,   175,
     146,   198,   151,   144,   255,   198,   309,   145,   151,   240,
     165,   245,   210,   211,   248,   146,   146,    96,   306,   166,
     256,   143,   143,   309,   166,   166,   166,   195,   143,   256,
     143,   296,   300,   148,   148,    55,   233,   198,   166,   144,
     147,   149,   146,   144,   145,   146,   231,   148,   145,   151,
     191,   148,   151,   242,   151,   211,   212,   290,   291,   144,
     195,   195,   166,   166,   195,    85,   197,   199,   144,   195,
     282,   193,   171,   193,   144,   151,   240,   146,   213,   214,
     221,   212,   166,   144,   144,   144,   143,   166,   197,   148,
     309,   198,   145,   166,   146,   266,   267,   269,   195,   197,
     166,   214,   198,   256,   256,   256,   144,   166,   197,    83,
     302,   166,   197,   144,   256,   144,   270,   256,   256
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   167,   168,   168,   168,   168,   168,   169,   170,   170,
     171,   171,   172,   172,   172,   172,   173,   172,   174,   172,
     172,   172,   172,   172,   175,   175,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   177,
     177,   178,   178,   179,   179,   179,   179,   180,   180,   180,
     181,   181,   181,   182,   182,   182,   182,   182,   183,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   188,   187,
     189,   190,   189,   191,   192,   191,   193,   193,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   195,
     196,   195,   197,   197,   198,   199,   199,   199,   199,   200,
     201,   201,   201,   201,   201,   201,   202,   202,   203,   203,
     204,   205,   205,   205,   205,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   208,   207,   207,   209,   209,   210,   210,
     211,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     215,   215,   215,   215,   215,   216,   216,   217,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   219,   219,
     220,   220,   221,   221,   222,   222,   222,   222,   223,   223,
     223,   224,   224,   224,   224,   224,   224,   224,   225,   225,
     226,   227,   226,   226,   228,   228,   228,   228,   228,   228,
     229,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   234,   235,   235,   235,   236,   236,   237,   237,   238,
     238,   238,   239,   238,   240,   240,   240,   241,   241,   242,
     242,   243,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   250,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   254,   254,   255,   255,   256,   256,   256,
     256,   256,   256,   256,   256,   257,   257,   257,   258,   258,
     259,   258,   260,   261,   262,   262,   262,   263,   263,   263,
     264,   264,   266,   265,   267,   265,   269,   268,   268,   268,
     270,   268,   271,   271,   271,   271,   271,   272,   272,   273,
     273,   273,   275,   274,   276,   274,   277,   277,   278,   278,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     281,   282,   281,   281,   283,   284,   284,   285,   285,   286,
     286,   286,   286,   287,   287,   288,   289,   289,   290,   291,
     291,   292,   292,   293,   293,   294,   295,   296,   296,   298,
     297,   299,   299,   300,   300,   301,   301,   302,   302,   303,
     304,   305,   306,   307,   307,   308,   308,   309
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     6,     1,     3,
       3,     3,     1,     4,     3,     4,     0,     4,     0,     4,
       2,     2,     6,     7,     1,     3,     1,     2,     2,     2,
       2,     4,     4,     2,     6,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     0,     4,
       1,     0,     4,     1,     0,     6,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     1,     2,     3,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     7,     3,     1,     1,     1,     2,
       4,     1,     1,     1,     1,     3,     1,     2,     3,     0,
       4,     5,     5,     6,     2,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     1,     3,     1,     1,     1,     3,
       1,     3,     4,     4,     5,     5,     6,     6,     1,     2,
       3,     0,     5,     4,     1,     3,     2,     4,     2,     3,
       1,     1,     2,     1,     3,     1,     3,     2,     1,     1,
       1,     2,     3,     1,     1,     0,     1,     3,     4,     2,
       3,     3,     0,     5,     1,     3,     4,     2,     4,     0,
       1,     2,     1,     2,     3,     2,     7,     5,     2,     1,
       0,     1,     5,     0,     1,     2,     3,     1,     2,     1,
       3,     2,     3,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     3,     2,     2,     3,
       0,     3,     1,     1,     2,     3,     2,     1,     1,     2,
       2,     3,     0,     7,     0,     6,     0,     6,     7,     9,
       0,     9,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     0,     3,     0,     4,     1,     2,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     4,
       1,     0,     4,     4,     1,     1,     2,     1,     1,     1,
       2,     1,     1,     1,     0,     1,     2,     0,     1,     1,
       2,     1,     3,     1,     2,     1,     2,     1,     2,     0,
       2,     2,     1,     1,     2,     1,     2,     2,     0,     1,
       1,     1,     1,     5,     2,     4,     5,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 153 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[0].sym))); }
#line 2678 "y.tab.c"
    break;

  case 3:
#line 154 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE ((yyvsp[0].val)); }
#line 2684 "y.tab.c"
    break;

  case 5:
#line 156 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = (yyvsp[-1].asts); }
#line 2690 "y.tab.c"
    break;

  case 7:
#line 161 "../../sdcc-svn/src/SDCC.y"
                                                            { (yyval.asts) = newNode (GENERIC, (yyvsp[-3].asts), (yyvsp[-1].asts)); }
#line 2696 "y.tab.c"
    break;

  case 8:
#line 165 "../../sdcc-svn/src/SDCC.y"
                         { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, NULL, (yyvsp[0].asts)); }
#line 2702 "y.tab.c"
    break;

  case 9:
#line 166 "../../sdcc-svn/src/SDCC.y"
                                                { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, (yyvsp[-2].asts), (yyvsp[0].asts)); }
#line 2708 "y.tab.c"
    break;

  case 10:
#line 170 "../../sdcc-svn/src/SDCC.y"
                                   { (yyval.asts) = newNode  (GENERIC_ASSOCIATION, newAst_LINK((yyvsp[-2].lnk)), (yyvsp[0].asts)); }
#line 2714 "y.tab.c"
    break;

  case 11:
#line 171 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.asts) = newNode  (GENERIC_ASSOCIATION,NULL,(yyvsp[0].asts)); }
#line 2720 "y.tab.c"
    break;

  case 13:
#line 176 "../../sdcc-svn/src/SDCC.y"
                                        { (yyval.asts) = newNode  ('[', (yyvsp[-3].asts), (yyvsp[-1].asts)); }
#line 2726 "y.tab.c"
    break;

  case 14:
#line 177 "../../sdcc-svn/src/SDCC.y"
                                        { (yyval.asts) = newNode  (CALL,(yyvsp[-2].asts),NULL);
                                          (yyval.asts)->left->funcName = 1;}
#line 2733 "y.tab.c"
    break;

  case 15:
#line 180 "../../sdcc-svn/src/SDCC.y"
          {
            (yyval.asts) = newNode  (CALL,(yyvsp[-3].asts),(yyvsp[-1].asts)); (yyval.asts)->left->funcName = 1;
          }
#line 2741 "y.tab.c"
    break;

  case 16:
#line 183 "../../sdcc-svn/src/SDCC.y"
                      { ignoreTypedefType = 1; }
#line 2747 "y.tab.c"
    break;

  case 17:
#line 184 "../../sdcc-svn/src/SDCC.y"
                      {
                        ignoreTypedefType = 0;
                        (yyvsp[0].sym) = newSymbol((yyvsp[0].sym)->name,NestLevel);
                        (yyvsp[0].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,newNode('&',(yyvsp[-3].asts),NULL),newAst_VALUE(symbolVal((yyvsp[0].sym))));
                      }
#line 2758 "y.tab.c"
    break;

  case 18:
#line 190 "../../sdcc-svn/src/SDCC.y"
                         { ignoreTypedefType = 1; }
#line 2764 "y.tab.c"
    break;

  case 19:
#line 191 "../../sdcc-svn/src/SDCC.y"
                      {
                        ignoreTypedefType = 0;
                        (yyvsp[0].sym) = newSymbol((yyvsp[0].sym)->name,NestLevel);
                        (yyvsp[0].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,(yyvsp[-3].asts),newAst_VALUE(symbolVal((yyvsp[0].sym))));
                      }
#line 2775 "y.tab.c"
    break;

  case 20:
#line 198 "../../sdcc-svn/src/SDCC.y"
                      { (yyval.asts) = newNode(INC_OP,(yyvsp[-1].asts),NULL);}
#line 2781 "y.tab.c"
    break;

  case 21:
#line 200 "../../sdcc-svn/src/SDCC.y"
                      { (yyval.asts) = newNode(DEC_OP,(yyvsp[-1].asts),NULL); }
#line 2787 "y.tab.c"
    break;

  case 22:
#line 202 "../../sdcc-svn/src/SDCC.y"
                      {
                        /* if (!options.std_c99) */
                          werror(E_COMPOUND_LITERALS_C99);

                        /* TODO: implement compound literals (C99) */
                        (yyval.asts) = newAst_VALUE (valueFromLit (0));
                      }
#line 2799 "y.tab.c"
    break;

  case 23:
#line 210 "../../sdcc-svn/src/SDCC.y"
                      {
                        /* if (!options.std_c99) */
                          werror(E_COMPOUND_LITERALS_C99);

                        /* TODO: implement compound literals (C99) */
                        (yyval.asts) = newAst_VALUE (valueFromLit (0));
                      }
#line 2811 "y.tab.c"
    break;

  case 25:
#line 221 "../../sdcc-svn/src/SDCC.y"
                                            { (yyval.asts) = newNode(PARAM,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2817 "y.tab.c"
    break;

  case 27:
#line 226 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newNode (INC_OP, NULL, (yyvsp[0].asts)); }
#line 2823 "y.tab.c"
    break;

  case 28:
#line 227 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newNode (DEC_OP, NULL, (yyvsp[0].asts)); }
#line 2829 "y.tab.c"
    break;

  case 29:
#line 229 "../../sdcc-svn/src/SDCC.y"
       {
         if ((yyvsp[-1].yyint) == '&' && IS_AST_OP ((yyvsp[0].asts)) && (yyvsp[0].asts)->opval.op == '*' && (yyvsp[0].asts)->right == NULL)
           (yyval.asts) = (yyvsp[0].asts)->left;
         else if ((yyvsp[-1].yyint) == '*' && IS_AST_OP ((yyvsp[0].asts)) && (yyvsp[0].asts)->opval.op == '&' && (yyvsp[0].asts)->right == NULL)
           (yyval.asts) = (yyvsp[0].asts)->left;
         else
           (yyval.asts) = newNode ((yyvsp[-1].yyint), (yyvsp[0].asts), NULL);
       }
#line 2842 "y.tab.c"
    break;

  case 30:
#line 237 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newNode (SIZEOF, NULL, (yyvsp[0].asts)); }
#line 2848 "y.tab.c"
    break;

  case 31:
#line 238 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newAst_VALUE (sizeofOp ((yyvsp[-1].lnk))); }
#line 2854 "y.tab.c"
    break;

  case 32:
#line 239 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newAst_VALUE (alignofOp ((yyvsp[-1].lnk))); }
#line 2860 "y.tab.c"
    break;

  case 33:
#line 240 "../../sdcc-svn/src/SDCC.y"
                              { (yyval.asts) = newNode (TYPEOF, NULL, (yyvsp[0].asts)); }
#line 2866 "y.tab.c"
    break;

  case 34:
#line 241 "../../sdcc-svn/src/SDCC.y"
                                                               { (yyval.asts) = offsetofOp((yyvsp[-3].lnk), (yyvsp[-1].asts)); }
#line 2872 "y.tab.c"
    break;

  case 35:
#line 245 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '&';}
#line 2878 "y.tab.c"
    break;

  case 36:
#line 246 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '*';}
#line 2884 "y.tab.c"
    break;

  case 37:
#line 247 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '+';}
#line 2890 "y.tab.c"
    break;

  case 38:
#line 248 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '-';}
#line 2896 "y.tab.c"
    break;

  case 39:
#line 249 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '~';}
#line 2902 "y.tab.c"
    break;

  case 40:
#line 250 "../../sdcc-svn/src/SDCC.y"
            { (yyval.yyint) = '!';}
#line 2908 "y.tab.c"
    break;

  case 42:
#line 255 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.asts) = newNode(CAST,newAst_LINK((yyvsp[-2].lnk)),(yyvsp[0].asts)); }
#line 2914 "y.tab.c"
    break;

  case 44:
#line 260 "../../sdcc-svn/src/SDCC.y"
                                       { (yyval.asts) = newNode('*',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2920 "y.tab.c"
    break;

  case 45:
#line 261 "../../sdcc-svn/src/SDCC.y"
                                       { (yyval.asts) = newNode('/',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2926 "y.tab.c"
    break;

  case 46:
#line 262 "../../sdcc-svn/src/SDCC.y"
                                       { (yyval.asts) = newNode('%',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2932 "y.tab.c"
    break;

  case 48:
#line 267 "../../sdcc-svn/src/SDCC.y"
                                           { (yyval.asts)=newNode('+',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2938 "y.tab.c"
    break;

  case 49:
#line 268 "../../sdcc-svn/src/SDCC.y"
                                           { (yyval.asts)=newNode('-',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2944 "y.tab.c"
    break;

  case 51:
#line 273 "../../sdcc-svn/src/SDCC.y"
                                       { (yyval.asts) = newNode(LEFT_OP,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2950 "y.tab.c"
    break;

  case 52:
#line 274 "../../sdcc-svn/src/SDCC.y"
                                       { (yyval.asts) = newNode(RIGHT_OP,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2956 "y.tab.c"
    break;

  case 54:
#line 279 "../../sdcc-svn/src/SDCC.y"
                                      { (yyval.asts) = newNode('<',  (yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2962 "y.tab.c"
    break;

  case 55:
#line 280 "../../sdcc-svn/src/SDCC.y"
                                      { (yyval.asts) = newNode('>',  (yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2968 "y.tab.c"
    break;

  case 56:
#line 281 "../../sdcc-svn/src/SDCC.y"
                                      { (yyval.asts) = newNode(LE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2974 "y.tab.c"
    break;

  case 57:
#line 282 "../../sdcc-svn/src/SDCC.y"
                                      { (yyval.asts) = newNode(GE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2980 "y.tab.c"
    break;

  case 59:
#line 287 "../../sdcc-svn/src/SDCC.y"
                                         { (yyval.asts) = newNode(EQ_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2986 "y.tab.c"
    break;

  case 60:
#line 288 "../../sdcc-svn/src/SDCC.y"
                                         { (yyval.asts) = newNode(NE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2992 "y.tab.c"
    break;

  case 62:
#line 293 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.asts) = newNode('&',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2998 "y.tab.c"
    break;

  case 64:
#line 298 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.asts) = newNode('^',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 3004 "y.tab.c"
    break;

  case 66:
#line 303 "../../sdcc-svn/src/SDCC.y"
                                             { (yyval.asts) = newNode('|',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 3010 "y.tab.c"
    break;

  case 68:
#line 308 "../../sdcc-svn/src/SDCC.y"
                             { seqPointNo++;}
#line 3016 "y.tab.c"
    break;

  case 69:
#line 309 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.asts) = newNode(AND_OP,(yyvsp[-3].asts),(yyvsp[0].asts));}
#line 3022 "y.tab.c"
    break;

  case 71:
#line 314 "../../sdcc-svn/src/SDCC.y"
                           { seqPointNo++;}
#line 3028 "y.tab.c"
    break;

  case 72:
#line 315 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.asts) = newNode(OR_OP,(yyvsp[-3].asts),(yyvsp[0].asts)); }
#line 3034 "y.tab.c"
    break;

  case 74:
#line 320 "../../sdcc-svn/src/SDCC.y"
                         { seqPointNo++;}
#line 3040 "y.tab.c"
    break;

  case 75:
#line 321 "../../sdcc-svn/src/SDCC.y"
                     {
                        (yyval.asts) = newNode(':',(yyvsp[-2].asts),(yyvsp[0].asts));
                        (yyval.asts) = newNode('?',(yyvsp[-5].asts),(yyval.asts));
                     }
#line 3049 "y.tab.c"
    break;

  case 77:
#line 330 "../../sdcc-svn/src/SDCC.y"
                     {

                             switch ((yyvsp[-1].yyint)) {
                             case '=':
                                     (yyval.asts) = newNode((yyvsp[-1].yyint),(yyvsp[-2].asts),(yyvsp[0].asts));
                                     break;
                             case MUL_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '*', (yyvsp[0].asts));
                                     break;
                             case DIV_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '/', (yyvsp[0].asts));
                                     break;
                             case MOD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '%', (yyvsp[0].asts));
                                     break;
                             case ADD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '+', (yyvsp[0].asts));
                                     break;
                             case SUB_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '-', (yyvsp[0].asts));
                                     break;
                             case LEFT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), LEFT_OP, (yyvsp[0].asts));
                                     break;
                             case RIGHT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), RIGHT_OP, (yyvsp[0].asts));
                                     break;
                             case AND_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '&', (yyvsp[0].asts));
                                     break;
                             case XOR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '^', (yyvsp[0].asts));
                                     break;
                             case OR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '|', (yyvsp[0].asts));
                                     break;
                             default :
                                     (yyval.asts) = NULL;
                             }

                     }
#line 3095 "y.tab.c"
    break;

  case 78:
#line 374 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.yyint) = '=';}
#line 3101 "y.tab.c"
    break;

  case 90:
#line 389 "../../sdcc-svn/src/SDCC.y"
              { seqPointNo++;}
#line 3107 "y.tab.c"
    break;

  case 91:
#line 389 "../../sdcc-svn/src/SDCC.y"
                                               { (yyval.asts) = newNode(',',(yyvsp[-3].asts),(yyvsp[0].asts));}
#line 3113 "y.tab.c"
    break;

  case 92:
#line 393 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = NULL; seqPointNo++; }
#line 3119 "y.tab.c"
    break;

  case 93:
#line 394 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = (yyvsp[0].asts); seqPointNo++; }
#line 3125 "y.tab.c"
    break;

  case 95:
#line 405 "../../sdcc-svn/src/SDCC.y"
      {
         /* Special case: if incomplete struct/union declared without name, */
         /* make sure an incomplete type for it exists in the current scope */
         if (IS_STRUCT((yyvsp[-1].lnk)))
           {
             structdef *sdef = SPEC_STRUCT((yyvsp[-1].lnk));
             structdef *osdef;
             osdef = findSymWithBlock (StructTab, sdef->tagsym, currBlockno, NestLevel);
             if (osdef && osdef->block != currBlockno)
               {
                 sdef = newStruct(osdef->tagsym->name);
                 sdef->level = NestLevel;
                 sdef->block = currBlockno;
                 sdef->tagsym = newSymbol (osdef->tagsym->name, NestLevel);
                 addSym (StructTab, sdef, sdef->tag, sdef->level, currBlockno, 0);
                 uselessDecl = FALSE;
               }
           }
         if (uselessDecl)
           werror(W_USELESS_DECL);
         uselessDecl = TRUE;
         (yyval.sym) = NULL;
      }
#line 3153 "y.tab.c"
    break;

  case 96:
#line 429 "../../sdcc-svn/src/SDCC.y"
      {
         /* add the specifier list to the id */
         symbol *sym , *sym1;

         for (sym1 = sym = reverseSyms((yyvsp[-1].sym));sym != NULL;sym = sym->next) {
             sym_link *lnk = copyLinkChain((yyvsp[-2].lnk));
             sym_link *l0 = NULL, *l1 = NULL, *l2 = NULL;
             /* check illegal declaration */
             for (l0 = sym->type; l0 != NULL; l0 = l0->next)
               if (IS_PTR (l0))
                 break;
             /* check if creating intances of structs with flexible arrays */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_STRUCT (l1) && SPEC_STRUCT (l1)->b_flexArrayMember)
                 break;
             if (!options.std_c99 && l0 == NULL && l1 != NULL && SPEC_EXTR((yyvsp[-2].lnk)) != 1)
               werror (W_FLEXARRAY_INSTRUCT, sym->name);
             /* check if creating intances of function type */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_FUNC (l1))
                 break;
             for (l2 = lnk; l2 != NULL; l2 = l2->next)
               if (IS_PTR (l2))
                 break;
             if (l0 == NULL && l2 == NULL && l1 != NULL)
               werrorfl(sym->fileDef, sym->lineDef, E_TYPE_IS_FUNCTION, sym->name);
             /* do the pointer stuff */
             pointerTypes(sym->type,lnk);
             addDecl (sym,0,lnk);
         }

         uselessDecl = TRUE;
         (yyval.sym) = sym1;
      }
#line 3192 "y.tab.c"
    break;

  case 97:
#line 464 "../../sdcc-svn/src/SDCC.y"
      {
         (yyval.sym) = NULL;
      }
#line 3200 "y.tab.c"
    break;

  case 98:
#line 468 "../../sdcc-svn/src/SDCC.y"
      {
         (yyval.sym) = NULL;
      }
#line 3208 "y.tab.c"
    break;

  case 99:
#line 473 "../../sdcc-svn/src/SDCC.y"
                                                 { (yyval.lnk) = finalizeSpec((yyvsp[0].lnk)); }
#line 3214 "y.tab.c"
    break;

  case 100:
#line 476 "../../sdcc-svn/src/SDCC.y"
                                                     { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3220 "y.tab.c"
    break;

  case 101:
#line 477 "../../sdcc-svn/src/SDCC.y"
                                                     {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "storage_class_specifier declaration_specifiers - skipped");
   }
#line 3230 "y.tab.c"
    break;

  case 102:
#line 482 "../../sdcc-svn/src/SDCC.y"
                                                    { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3236 "y.tab.c"
    break;

  case 103:
#line 483 "../../sdcc-svn/src/SDCC.y"
                                                      {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_specifier_qualifier declaration_specifiers - skipped");
   }
#line 3246 "y.tab.c"
    break;

  case 104:
#line 488 "../../sdcc-svn/src/SDCC.y"
                                                    { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3252 "y.tab.c"
    break;

  case 105:
#line 489 "../../sdcc-svn/src/SDCC.y"
                                                    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "function_specifier declaration_specifiers - skipped");
   }
#line 3262 "y.tab.c"
    break;

  case 107:
#line 498 "../../sdcc-svn/src/SDCC.y"
                                                   { (yyvsp[0].sym)->next = (yyvsp[-2].sym); (yyval.sym) = (yyvsp[0].sym);}
#line 3268 "y.tab.c"
    break;

  case 108:
#line 502 "../../sdcc-svn/src/SDCC.y"
                                 { (yyvsp[0].sym)->ival = NULL; }
#line 3274 "y.tab.c"
    break;

  case 109:
#line 503 "../../sdcc-svn/src/SDCC.y"
                                 { (yyvsp[-2].sym)->ival = (yyvsp[0].ilist); seqPointNo++; }
#line 3280 "y.tab.c"
    break;

  case 111:
#line 511 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_TYPEDEF((yyval.lnk)) = 1;
               }
#line 3289 "y.tab.c"
    break;

  case 112:
#line 515 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink(SPECIFIER);
                  SPEC_EXTR((yyval.lnk)) = 1;
               }
#line 3298 "y.tab.c"
    break;

  case 113:
#line 519 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_STAT((yyval.lnk)) = 1;
               }
#line 3307 "y.tab.c"
    break;

  case 114:
#line 524 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = 0;
                  werror(E_THREAD_LOCAL);
               }
#line 3316 "y.tab.c"
    break;

  case 115:
#line 528 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_AUTO;
               }
#line 3325 "y.tab.c"
    break;

  case 116:
#line 532 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_REGISTER;
               }
#line 3334 "y.tab.c"
    break;

  case 117:
#line 539 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_VOID;
                  ignoreTypedefType = 1;
               }
#line 3344 "y.tab.c"
    break;

  case 118:
#line 544 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_CHAR;
                  ignoreTypedefType = 1;
               }
#line 3354 "y.tab.c"
    break;

  case 119:
#line 549 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_SHORT((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3364 "y.tab.c"
    break;

  case 120:
#line 554 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_INT;
                  ignoreTypedefType = 1;
               }
#line 3374 "y.tab.c"
    break;

  case 121:
#line 559 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_LONG((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3384 "y.tab.c"
    break;

  case 122:
#line 564 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FLOAT;
                  ignoreTypedefType = 1;
               }
#line 3394 "y.tab.c"
    break;

  case 123:
#line 569 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  (yyval.lnk)->select.s.b_signed = 1;
                  ignoreTypedefType = 1;
               }
#line 3404 "y.tab.c"
    break;

  case 124:
#line 574 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_USIGN((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3414 "y.tab.c"
    break;

  case 125:
#line 579 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BOOL;
                  ignoreTypedefType = 1;
               }
#line 3424 "y.tab.c"
    break;

  case 126:
#line 584 "../../sdcc-svn/src/SDCC.y"
                                {
                                   uselessDecl = FALSE;
                                   (yyval.lnk) = (yyvsp[0].lnk);
                                   ignoreTypedefType = 1;
                                }
#line 3434 "y.tab.c"
    break;

  case 127:
#line 589 "../../sdcc-svn/src/SDCC.y"
                        {
                           cenum = NULL;
                           uselessDecl = FALSE;
                           ignoreTypedefType = 1;
                           (yyval.lnk) = (yyvsp[0].lnk);
                        }
#line 3445 "y.tab.c"
    break;

  case 128:
#line 596 "../../sdcc-svn/src/SDCC.y"
         {
            symbol *sym;
            sym_link *p;
            sym = findSym(TypedefTab,NULL,(yyvsp[0].yychar));
            (yyval.lnk) = p = copyLinkChain(sym ? sym->type : NULL);
            SPEC_TYPEDEF(getSpec(p)) = 0;
            ignoreTypedefType = 1;
         }
#line 3458 "y.tab.c"
    break;

  case 129:
#line 604 "../../sdcc-svn/src/SDCC.y"
                {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FIXED16X16;
                  ignoreTypedefType = 1;
               }
#line 3468 "y.tab.c"
    break;

  case 130:
#line 609 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BIT;
                  SPEC_SCLS((yyval.lnk)) = S_BIT;
                  SPEC_BLEN((yyval.lnk)) = 1;
                  SPEC_BSTR((yyval.lnk)) = 0;
                  ignoreTypedefType = 1;
               }
#line 3481 "y.tab.c"
    break;

  case 131:
#line 617 "../../sdcc-svn/src/SDCC.y"
                      {
                  (yyval.lnk)=newLink(SPECIFIER);
                  /* add this to the storage class specifier  */
                  SPEC_ABSA((yyval.lnk)) = 1;   /* set the absolute addr flag */
                  /* now get the abs addr from value */
                  SPEC_ADDR((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts),TRUE));
               }
#line 3493 "y.tab.c"
    break;

  case 133:
#line 630 "../../sdcc-svn/src/SDCC.y"
        {
          structdef *sdef;

          if (! (yyvsp[0].sdef)->tagsym)
            {
              /* no tag given, so new struct def for current scope */
              addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
            }
          else
            {
              sdef = findSymWithBlock (StructTab, (yyvsp[0].sdef)->tagsym, currBlockno, NestLevel);
              if (sdef)
                {
                  /* Error if a complete type already defined in this scope */
                  if (sdef->block == currBlockno)
                    {
                      if (sdef->fields)
                        {
                          werror(E_STRUCT_REDEF, (yyvsp[0].sdef)->tag);
                          werrorfl(sdef->tagsym->fileDef, sdef->tagsym->lineDef, E_PREVIOUS_DEF);
                        }
                      else
                        {
                          (yyvsp[0].sdef) = sdef; /* We are completing an incomplete type */
                        }
                    }
                  else
                    {
                      /* There is an existing struct def in an outer scope. */
                      /* Create new struct def for current scope */
                      addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
                    }
                }
              else
               {
                 /* There is no existing struct def at all. */
                 /* Create new struct def for current scope */
                 addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
               }
            }

          if (!(yyvsp[0].sdef)->type)
            {
              (yyvsp[0].sdef)->type = (yyvsp[-2].yyint);
            }
          else
            {
              if ((yyvsp[0].sdef)->type != (yyvsp[-2].yyint))
                  werror(E_BAD_TAG, (yyvsp[0].sdef)->tag, (yyvsp[-2].yyint)==STRUCT ? "struct" : "union");
            }
        }
#line 3549 "y.tab.c"
    break;

  case 134:
#line 682 "../../sdcc-svn/src/SDCC.y"
        {
          structdef *sdef;
          symbol *sym, *dsym;

          // check for errors in structure members
          for (sym=(yyvsp[-1].sym); sym; sym=sym->next)
            {
              if (IS_ABSOLUTE(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "'at'");
                  SPEC_ABSA(sym->etype) = 0;
                }
              if (IS_SPEC(sym->etype) && SPEC_SCLS(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "storage class");
                  printTypeChainRaw (sym->type, NULL);
                  SPEC_SCLS(sym->etype) = 0;
                }
              for (dsym=sym->next; dsym; dsym=dsym->next)
                {
                  if (*dsym->name && strcmp(sym->name, dsym->name)==0)
                    {
                      werrorfl(sym->fileDef, sym->lineDef, E_DUPLICATE_MEMBER,
                               (yyvsp[-6].yyint)==STRUCT ? "struct" : "union", sym->name);
                      werrorfl(dsym->fileDef, dsym->lineDef, E_PREVIOUS_DEF);
                    }
                }
            }

          /* Create a structdef   */
          sdef = (yyvsp[-4].sdef);
          sdef->fields = reverseSyms((yyvsp[-1].sym));        /* link the fields */
          sdef->size = compStructSize((yyvsp[-6].yyint), sdef); /* update size of  */
          promoteAnonStructs ((yyvsp[-6].yyint), sdef);

          /* Create the specifier */
          (yyval.lnk) = newLink (SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk))= sdef;
        }
#line 3594 "y.tab.c"
    break;

  case 135:
#line 723 "../../sdcc-svn/src/SDCC.y"
        {
          structdef *sdef;

          sdef = findSymWithBlock (StructTab, (yyvsp[0].sdef)->tagsym, currBlockno, NestLevel);

          if (sdef)
            (yyvsp[0].sdef) = sdef;
          else
            {
              /* new struct def for current scope */
              addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
            }
          (yyval.lnk) = newLink(SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk)) = (yyvsp[0].sdef);

          if (!(yyvsp[0].sdef)->type)
            {
              (yyvsp[0].sdef)->type = (yyvsp[-2].yyint);
            }
          else
            {
              if ((yyvsp[0].sdef)->type != (yyvsp[-2].yyint))
                  werror(E_BAD_TAG, (yyvsp[0].sdef)->tag, (yyvsp[-2].yyint)==STRUCT ? "struct" : "union");
            }
        }
#line 3625 "y.tab.c"
    break;

  case 136:
#line 752 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.yyint) = STRUCT; ignoreTypedefType = 1; }
#line 3631 "y.tab.c"
    break;

  case 137:
#line 753 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.yyint) = UNION; ignoreTypedefType = 1; }
#line 3637 "y.tab.c"
    break;

  case 139:
#line 759 "../../sdcc-svn/src/SDCC.y"
        {
          symbol *sym = (yyvsp[0].sym);

          /* go to the end of the chain */
          while (sym->next) sym = sym->next;
          sym->next = (yyvsp[-1].sym);

           (yyval.sym) = (yyvsp[0].sym);
        }
#line 3651 "y.tab.c"
    break;

  case 140:
#line 772 "../../sdcc-svn/src/SDCC.y"
        {
          /* add this type to all the symbols */
          symbol *sym;
          for ( sym = (yyvsp[-1].sym); sym != NULL; sym = sym->next )
            {
              sym_link *btype = copyLinkChain((yyvsp[-2].lnk));

              pointerTypes(sym->type, btype);
              if (!sym->type)
                {
                  sym->type = btype;
                  sym->etype = getSpec(sym->type);
                }
              else
                  addDecl (sym, 0, btype);
              /* make sure the type is complete and sane */
              checkTypeSanity(sym->etype, sym->name);
            }
          ignoreTypedefType = 0;
          (yyval.sym) = (yyvsp[-1].sym);
        }
#line 3677 "y.tab.c"
    break;

  case 141:
#line 796 "../../sdcc-svn/src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3683 "y.tab.c"
    break;

  case 142:
#line 797 "../../sdcc-svn/src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3689 "y.tab.c"
    break;

  case 143:
#line 798 "../../sdcc-svn/src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3695 "y.tab.c"
    break;

  case 145:
#line 804 "../../sdcc-svn/src/SDCC.y"
        {
          (yyvsp[0].sym)->next  = (yyvsp[-2].sym);
          (yyval.sym) = (yyvsp[0].sym);
        }
#line 3704 "y.tab.c"
    break;

  case 147:
#line 813 "../../sdcc-svn/src/SDCC.y"
        {
          unsigned int bitsize;
          (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts), TRUE));
          if (!bitsize)
              bitsize = BITVAR_PAD;
          (yyval.sym)->bitVar = bitsize;
          (yyval.sym)->bitUnnamed = 1;
        }
#line 3718 "y.tab.c"
    break;

  case 148:
#line 823 "../../sdcc-svn/src/SDCC.y"
        {
          unsigned int bitsize;
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts), TRUE));

          if (!bitsize)
            {
              (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
              (yyval.sym)->bitVar = BITVAR_PAD;
              werror(W_BITFLD_NAMED);
            }
          else
              (yyvsp[-2].sym)->bitVar = bitsize;
        }
#line 3736 "y.tab.c"
    break;

  case 149:
#line 836 "../../sdcc-svn/src/SDCC.y"
     { (yyval.sym) = newSymbol ("", NestLevel); }
#line 3742 "y.tab.c"
    break;

  case 150:
#line 841 "../../sdcc-svn/src/SDCC.y"
        {
          (yyval.lnk) = newEnumType ((yyvsp[-1].sym));
          SPEC_SCLS(getSpec((yyval.lnk))) = 0;
        }
#line 3751 "y.tab.c"
    break;

  case 151:
#line 846 "../../sdcc-svn/src/SDCC.y"
        {
          if (!options.std_c99)
            werror (E_ENUM_COMMA_C99);
          (yyval.lnk) = newEnumType ((yyvsp[-2].sym));
          SPEC_SCLS(getSpec((yyval.lnk))) = 0;
        }
#line 3762 "y.tab.c"
    break;

  case 152:
#line 853 "../../sdcc-svn/src/SDCC.y"
        {
          symbol *csym;
          sym_link *enumtype;

          csym = findSymWithLevel(enumTab, (yyvsp[-3].sym));
          if ((csym && csym->level == (yyvsp[-3].sym)->level))
            {
              werrorfl((yyvsp[-3].sym)->fileDef, (yyvsp[-3].sym)->lineDef, E_DUPLICATE_TYPEDEF, csym->name);
              werrorfl(csym->fileDef, csym->lineDef, E_PREVIOUS_DEF);
            }

          enumtype = newEnumType ((yyvsp[-1].sym));
          SPEC_SCLS(getSpec(enumtype)) = 0;
          (yyvsp[-3].sym)->type = enumtype;

          /* add this to the enumerator table */
          if (!csym)
              addSym (enumTab, (yyvsp[-3].sym), (yyvsp[-3].sym)->name, (yyvsp[-3].sym)->level, (yyvsp[-3].sym)->block, 0);
          (yyval.lnk) = copyLinkChain(enumtype);
        }
#line 3787 "y.tab.c"
    break;

  case 153:
#line 874 "../../sdcc-svn/src/SDCC.y"
        {
          if (!options.std_c99)
            werror (E_ENUM_COMMA_C99);
          symbol *csym;
          sym_link *enumtype;

          csym = findSymWithLevel(enumTab, (yyvsp[-4].sym));
          if ((csym && csym->level == (yyvsp[-4].sym)->level))
            {
              werrorfl((yyvsp[-4].sym)->fileDef, (yyvsp[-4].sym)->lineDef, E_DUPLICATE_TYPEDEF, csym->name);
              werrorfl(csym->fileDef, csym->lineDef, E_PREVIOUS_DEF);
            }

          enumtype = newEnumType ((yyvsp[-2].sym));
          SPEC_SCLS(getSpec(enumtype)) = 0;
          (yyvsp[-4].sym)->type = enumtype;

          /* add this to the enumerator table */
          if (!csym)
              addSym (enumTab, (yyvsp[-4].sym), (yyvsp[-4].sym)->name, (yyvsp[-4].sym)->level, (yyvsp[-4].sym)->block, 0);
          (yyval.lnk) = copyLinkChain(enumtype);
        }
#line 3814 "y.tab.c"
    break;

  case 154:
#line 897 "../../sdcc-svn/src/SDCC.y"
        {
          symbol *csym;

          /* check the enumerator table */
          if ((csym = findSymWithLevel(enumTab, (yyvsp[0].sym))))
              (yyval.lnk) = copyLinkChain(csym->type);
          else
            {
              (yyval.lnk) = newLink(SPECIFIER);
              SPEC_NOUN((yyval.lnk)) = V_INT;
            }
        }
#line 3831 "y.tab.c"
    break;

  case 156:
#line 914 "../../sdcc-svn/src/SDCC.y"
        {
          (yyvsp[0].sym)->next = (yyvsp[-2].sym);
          (yyval.sym) = (yyvsp[0].sym);
        }
#line 3840 "y.tab.c"
    break;

  case 157:
#line 922 "../../sdcc-svn/src/SDCC.y"
        {
          symbol *sym;

          // check if the symbol at the same level already exists
          if ((sym = findSymWithLevel (SymbolTab, (yyvsp[-2].sym))) && sym->level == (yyvsp[-2].sym)->level)
            {
              werrorfl ((yyvsp[-2].sym)->fileDef, (yyvsp[-2].sym)->lineDef, E_DUPLICATE_MEMBER, "enum", (yyvsp[-2].sym)->name);
              werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
            }
          (yyvsp[-2].sym)->type = copyLinkChain ((yyvsp[0].val)->type);
          (yyvsp[-2].sym)->etype = getSpec ((yyvsp[-2].sym)->type);
          SPEC_ENUM ((yyvsp[-2].sym)->etype) = 1;
          (yyval.sym) = (yyvsp[-2].sym);
          // do this now, so we can use it for the next enums in the list
          addSymChain (&(yyvsp[-2].sym));
        }
#line 3861 "y.tab.c"
    break;

  case 158:
#line 941 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_CONST((yyval.lnk)) = 1;
               }
#line 3870 "y.tab.c"
    break;

  case 159:
#line 945 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_RESTRICT((yyval.lnk)) = 1;
               }
#line 3879 "y.tab.c"
    break;

  case 160:
#line 949 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_VOLATILE((yyval.lnk)) = 1;
               }
#line 3888 "y.tab.c"
    break;

  case 161:
#line 953 "../../sdcc-svn/src/SDCC.y"
                    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_ADDRSPACE((yyval.lnk)) = findSym (AddrspaceTab, 0, (yyvsp[0].yychar));
               }
#line 3897 "y.tab.c"
    break;

  case 162:
#line 957 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_XDATA;
               }
#line 3906 "y.tab.c"
    break;

  case 163:
#line 961 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_CODE;
               }
#line 3915 "y.tab.c"
    break;

  case 164:
#line 965 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_EEPROM;
               }
#line 3924 "y.tab.c"
    break;

  case 165:
#line 969 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_DATA;
               }
#line 3933 "y.tab.c"
    break;

  case 166:
#line 973 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_IDATA;
               }
#line 3942 "y.tab.c"
    break;

  case 167:
#line 977 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_PDATA;
               }
#line 3951 "y.tab.c"
    break;

  case 168:
#line 984 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_INLINE((yyval.lnk)) = 1;
               }
#line 3960 "y.tab.c"
    break;

  case 169:
#line 988 "../../sdcc-svn/src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_NORETURN((yyval.lnk)) = 1;
               }
#line 3969 "y.tab.c"
    break;

  case 170:
#line 996 "../../sdcc-svn/src/SDCC.y"
              {
                 checkTypeSanity ((yyvsp[-1].lnk), "(_Alignas)");
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 1;
              }
#line 3979 "y.tab.c"
    break;

  case 171:
#line 1002 "../../sdcc-svn/src/SDCC.y"
              {
                 value *val = constExprValue ((yyvsp[-1].asts), TRUE);
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 0;
                 if (!val)
                   werror (E_CONST_EXPECTED);
                 else if (ulFromVal (val) == 0 || isPowerOf2 (ulFromVal (val)) && ulFromVal (val) <= port->mem.maxextalign)
                   SPEC_ALIGNAS((yyval.lnk)) = ulFromVal(val);
                 else
                   werror (E_ALIGNAS, ulFromVal(val));
              }
#line 3995 "y.tab.c"
    break;

  case 172:
#line 1016 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.sym) = (yyvsp[0].sym); }
#line 4001 "y.tab.c"
    break;

  case 173:
#line 1018 "../../sdcc-svn/src/SDCC.y"
         {
             addDecl ((yyvsp[0].sym),0,reverseLink((yyvsp[-1].lnk)));
             (yyval.sym) = (yyvsp[0].sym);
         }
#line 4010 "y.tab.c"
    break;

  case 175:
#line 1026 "../../sdcc-svn/src/SDCC.y"
                            { (yyval.sym) = (yyvsp[-1].sym); }
#line 4016 "y.tab.c"
    break;

  case 179:
#line 1033 "../../sdcc-svn/src/SDCC.y"
                            { (yyval.sym) = (yyvsp[-1].sym); }
#line 4022 "y.tab.c"
    break;

  case 181:
#line 1039 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link   *p;

            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;
            DCL_ELEM(p) = 0;
            addDecl((yyvsp[-2].sym),0,p);
         }
#line 4035 "y.tab.c"
    break;

  case 182:
#line 1048 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p, *n;

            if (!options.std_c99)
              werror (E_QUALIFIED_ARRAY_PARAM_C99);

            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;
            DCL_ELEM(p) = 0;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-1].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-1].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-1].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-1].lnk));
            addDecl((yyvsp[-3].sym),0,p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[-3].sym),0,n);
         }
#line 4058 "y.tab.c"
    break;

  case 183:
#line 1067 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p;
            value *tval;
            int size;

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[-3].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            addDecl((yyvsp[-3].sym), 0, p);
         }
#line 4091 "y.tab.c"
    break;

  case 184:
#line 1096 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              werror (E_STATIC_ARRAY_PARAM_C99);

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[-4].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            addDecl((yyvsp[-4].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[-4].sym),0,n);
         }
#line 4130 "y.tab.c"
    break;

  case 185:
#line 1131 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              werror (E_QUALIFIED_ARRAY_PARAM_C99);

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[-4].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-2].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-2].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-2].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-2].lnk));
            addDecl((yyvsp[-4].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[-4].sym),0,n);
         }
#line 4173 "y.tab.c"
    break;

  case 186:
#line 1170 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              {
                werror (E_STATIC_ARRAY_PARAM_C99);
                werror (E_QUALIFIED_ARRAY_PARAM_C99);
              }

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[-5].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-2].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-2].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-2].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-2].lnk));
            addDecl((yyvsp[-5].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[-5].sym),0,n);
         }
#line 4219 "y.tab.c"
    break;

  case 187:
#line 1212 "../../sdcc-svn/src/SDCC.y"
         {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              {
                werror (E_QUALIFIED_ARRAY_PARAM_C99);
                werror (E_STATIC_ARRAY_PARAM_C99);
              }

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[-5].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-3].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-3].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-3].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-3].lnk));
            addDecl((yyvsp[-5].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[-5].sym),0,n);
         }
#line 4265 "y.tab.c"
    break;

  case 188:
#line 1256 "../../sdcc-svn/src/SDCC.y"
                                         { (yyval.sym) = (yyvsp[0].sym); }
#line 4271 "y.tab.c"
    break;

  case 189:
#line 1257 "../../sdcc-svn/src/SDCC.y"
                                             {
           // copy the functionAttributes (not the args and hasVargs !!)
           struct value *args;
           unsigned hasVargs;
           sym_link *funcType=(yyvsp[-1].sym)->type;

           while (funcType && !IS_FUNC(funcType))
             funcType = funcType->next;

           if (!funcType)
             werror (E_FUNC_ATTR);
           else
             {
               args=FUNC_ARGS(funcType);
               hasVargs=FUNC_HASVARARGS(funcType);

               memcpy (&funcType->funcAttrs, &(yyvsp[0].lnk)->funcAttrs,
                   sizeof((yyvsp[0].lnk)->funcAttrs));

               FUNC_ARGS(funcType)=args;
               FUNC_HASVARARGS(funcType)=hasVargs;

               // just to be sure
               memset (&(yyvsp[0].lnk)->funcAttrs, 0,
                   sizeof((yyvsp[0].lnk)->funcAttrs));

               addDecl ((yyvsp[-1].sym),0,(yyvsp[0].lnk));
             }
   }
#line 4305 "y.tab.c"
    break;

  case 190:
#line 1290 "../../sdcc-svn/src/SDCC.y"
        {
          addDecl ((yyvsp[-2].sym), FUNCTION, NULL);
        }
#line 4313 "y.tab.c"
    break;

  case 191:
#line 1294 "../../sdcc-svn/src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          seqPointNo++; /* not a true sequence point, but helps resolve scope */
        }
#line 4325 "y.tab.c"
    break;

  case 192:
#line 1302 "../../sdcc-svn/src/SDCC.y"
        {
          sym_link *funcType;

          addDecl ((yyvsp[-4].sym), FUNCTION, NULL);

          funcType = (yyvsp[-4].sym)->type;
          while (funcType && !IS_FUNC(funcType))
              funcType = funcType->next;

          assert (funcType);

          FUNC_HASVARARGS(funcType) = IS_VARG((yyvsp[-1].val));
          FUNC_ARGS(funcType) = reverseVal((yyvsp[-1].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          seqPointNo++; /* not a true sequence point, but helps resolve scope */

          // if this was a pointer (to a function)
          if (!IS_FUNC((yyvsp[-4].sym)->type))
              cleanUpLevel(SymbolTab, NestLevel + LEVEL_UNIT);

          (yyval.sym) = (yyvsp[-4].sym);
        }
#line 4355 "y.tab.c"
    break;

  case 193:
#line 1328 "../../sdcc-svn/src/SDCC.y"
        {
          werror(E_OLD_STYLE,(yyvsp[-3].sym)->name);
          
          addDecl ((yyvsp[-3].sym), FUNCTION, NULL);
          
          (yyval.sym) = (yyvsp[-3].sym);
        }
#line 4367 "y.tab.c"
    break;

  case 194:
#line 1338 "../../sdcc-svn/src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk);}
#line 4373 "y.tab.c"
    break;

  case 195:
#line 1340 "../../sdcc-svn/src/SDCC.y"
         {
             sym_link *n = newLink(SPECIFIER);
             /* add this to the storage class specifier  */
             SPEC_ABSA(n) = 1;   /* set the absolute addr flag */
             /* now get the abs addr from value */
             SPEC_ADDR(n) = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts),TRUE));
             n->next = (yyvsp[-2].lnk);
             (yyval.lnk) = n;
         }
#line 4387 "y.tab.c"
    break;

  case 196:
#line 1350 "../../sdcc-svn/src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-1].lnk);
             if (IS_SPEC((yyvsp[0].lnk))) {
                 DCL_TSPEC((yyvsp[-1].lnk)) = (yyvsp[0].lnk);
                 DCL_PTR_CONST((yyvsp[-1].lnk)) = SPEC_CONST((yyvsp[0].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-1].lnk)) = SPEC_VOLATILE((yyvsp[0].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-1].lnk)) = SPEC_RESTRICT((yyvsp[0].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-1].lnk)) = SPEC_ADDRSPACE((yyvsp[0].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);
         }
#line 4404 "y.tab.c"
    break;

  case 197:
#line 1363 "../../sdcc-svn/src/SDCC.y"
         {
             if (IS_SPEC((yyvsp[-2].lnk))) {
                 DCL_TSPEC((yyvsp[-3].lnk)) = (yyvsp[-2].lnk);
                 DCL_PTR_CONST((yyvsp[-3].lnk)) = SPEC_CONST((yyvsp[-2].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-3].lnk)) = SPEC_VOLATILE((yyvsp[-2].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-3].lnk)) = SPEC_RESTRICT((yyvsp[-2].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-3].lnk)) = SPEC_ADDRSPACE((yyvsp[-2].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);

             sym_link *n = newLink(SPECIFIER);
             /* add this to the storage class specifier  */
             SPEC_ABSA(n) = 1;   /* set the absolute addr flag */
             /* now get the abs addr from value */
             SPEC_ADDR(n) = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts),TRUE));
             n->next = (yyvsp[-3].lnk);
             (yyval.lnk) = n;
         }
#line 4428 "y.tab.c"
    break;

  case 198:
#line 1383 "../../sdcc-svn/src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-1].lnk);
             (yyval.lnk)->next = (yyvsp[0].lnk);
             DCL_TYPE((yyvsp[0].lnk))=port->unqualified_pointer;
         }
#line 4438 "y.tab.c"
    break;

  case 199:
#line 1389 "../../sdcc-svn/src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-2].lnk);
             if (IS_SPEC((yyvsp[-1].lnk)) && DCL_TYPE((yyvsp[0].lnk)) == UPOINTER) {
                 DCL_PTR_CONST((yyvsp[-2].lnk)) = SPEC_CONST((yyvsp[-1].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-2].lnk)) = SPEC_VOLATILE((yyvsp[-1].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-2].lnk)) = SPEC_RESTRICT((yyvsp[-1].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-2].lnk)) = SPEC_ADDRSPACE((yyvsp[-1].lnk));
                 switch (SPEC_SCLS((yyvsp[-1].lnk))) {
                 case S_XDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = FPOINTER;
                     break;
                 case S_IDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = IPOINTER;
                     break;
                 case S_PDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = PPOINTER;
                     break;
                 case S_DATA:
                     DCL_TYPE((yyvsp[0].lnk)) = POINTER;
                     break;
                 case S_CODE:
                     DCL_TYPE((yyvsp[0].lnk)) = CPOINTER;
                     break;
                 case S_EEPROM:
                     DCL_TYPE((yyvsp[0].lnk)) = EEPPOINTER;
                     break;
                 default:
                   // this could be just "constant"
                   // werror(W_PTR_TYPE_INVALID);
                     ;
                 }
             }
             else
                 werror (W_PTR_TYPE_INVALID);
             (yyval.lnk)->next = (yyvsp[0].lnk);
         }
#line 4479 "y.tab.c"
    break;

  case 200:
#line 1429 "../../sdcc-svn/src/SDCC.y"
      {
        (yyval.lnk) = newLink(DECLARATOR);
        DCL_TYPE((yyval.lnk))=UPOINTER;
      }
#line 4488 "y.tab.c"
    break;

  case 202:
#line 1438 "../../sdcc-svn/src/SDCC.y"
               {
                 (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_qualifier_list type_qualifier skipped");
               }
#line 4496 "y.tab.c"
    break;

  case 204:
#line 1445 "../../sdcc-svn/src/SDCC.y"
                                      { (yyvsp[-2].val)->vArgs = 1;}
#line 4502 "y.tab.c"
    break;

  case 206:
#line 1451 "../../sdcc-svn/src/SDCC.y"
         {
            (yyvsp[0].val)->next = (yyvsp[-2].val);
            (yyval.val) = (yyvsp[0].val);
         }
#line 4511 "y.tab.c"
    break;

  case 207:
#line 1459 "../../sdcc-svn/src/SDCC.y"
        {
          symbol *loop;

          if (IS_SPEC ((yyvsp[-1].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[-1].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, (yyvsp[0].sym)->name);
            }
          pointerTypes ((yyvsp[0].sym)->type, (yyvsp[-1].lnk));
          if (IS_SPEC ((yyvsp[0].sym)->etype))
            SPEC_NEEDSPAR((yyvsp[0].sym)->etype) = 0;
          addDecl ((yyvsp[0].sym), 0, (yyvsp[-1].lnk));
          for (loop = (yyvsp[0].sym); loop; loop->_isparm = 1, loop = loop->next)
            ;
          (yyval.val) = symbolVal ((yyvsp[0].sym));
          ignoreTypedefType = 0;
        }
#line 4532 "y.tab.c"
    break;

  case 208:
#line 1476 "../../sdcc-svn/src/SDCC.y"
        {
          (yyval.val) = newValue ();
          (yyval.val)->type = (yyvsp[0].lnk);
          (yyval.val)->etype = getSpec ((yyval.val)->type);
          ignoreTypedefType = 0;
         }
#line 4543 "y.tab.c"
    break;

  case 209:
#line 1485 "../../sdcc-svn/src/SDCC.y"
             { (yyval.lnk) = reverseLink((yyvsp[0].lnk)); }
#line 4549 "y.tab.c"
    break;

  case 211:
#line 1487 "../../sdcc-svn/src/SDCC.y"
                                          { (yyvsp[-1].lnk) = reverseLink((yyvsp[-1].lnk)); (yyvsp[0].lnk)->next = (yyvsp[-1].lnk); (yyval.lnk) = (yyvsp[0].lnk);
          if (IS_PTR((yyvsp[-1].lnk)) && IS_FUNC((yyvsp[0].lnk)))
            DCL_TYPE((yyvsp[-1].lnk)) = CPOINTER;
        }
#line 4558 "y.tab.c"
    break;

  case 212:
#line 1494 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.lnk) = (yyvsp[-1].lnk); }
#line 4564 "y.tab.c"
    break;

  case 215:
#line 1500 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.lnk) = NULL; }
#line 4570 "y.tab.c"
    break;

  case 217:
#line 1505 "../../sdcc-svn/src/SDCC.y"
                                              {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                       if((yyvsp[-2].lnk))
                                         (yyval.lnk)->next = (yyvsp[-2].lnk);
                                    }
#line 4582 "y.tab.c"
    break;

  case 218:
#line 1513 "../../sdcc-svn/src/SDCC.y"
                                    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[-1].asts),TRUE));
                                       if((yyvsp[-3].lnk))
                                         (yyval.lnk)->next = (yyvsp[-3].lnk);
                                    }
#line 4595 "y.tab.c"
    break;

  case 219:
#line 1524 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.lnk) = NULL;}
#line 4601 "y.tab.c"
    break;

  case 220:
#line 1525 "../../sdcc-svn/src/SDCC.y"
                                        {
     // $1 must be a pointer to a function
     sym_link *p=newLink(DECLARATOR);
     DCL_TYPE(p) = FUNCTION;
     if (!(yyvsp[-2].lnk)) {
       // ((void (code *) ()) 0) ()
       (yyvsp[-2].lnk)=newLink(DECLARATOR);
       DCL_TYPE((yyvsp[-2].lnk))=CPOINTER;
       (yyval.lnk) = (yyvsp[-2].lnk);
     }
     (yyvsp[-2].lnk)->next=p;
   }
#line 4618 "y.tab.c"
    break;

  case 221:
#line 1537 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.lnk) = NULL;}
#line 4624 "y.tab.c"
    break;

  case 222:
#line 1539 "../../sdcc-svn/src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
        }
#line 4635 "y.tab.c"
    break;

  case 223:
#line 1546 "../../sdcc-svn/src/SDCC.y"
        {
          sym_link *p = newLink(DECLARATOR), *q;
          DCL_TYPE(p) = FUNCTION;

          FUNC_HASVARARGS(p) = IS_VARG((yyvsp[-1].val));
          FUNC_ARGS(p) = reverseVal((yyvsp[-1].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          if (!(yyvsp[-4].lnk))
            {
              /* ((void (code *) (void)) 0) () */
              (yyvsp[-4].lnk) = newLink(DECLARATOR);
              DCL_TYPE((yyvsp[-4].lnk)) = CPOINTER;
              (yyval.lnk) = (yyvsp[-4].lnk);
            }
          for (q = (yyvsp[-4].lnk); q && q->next; q = q->next);
          q->next = p;
        }
#line 4660 "y.tab.c"
    break;

  case 224:
#line 1569 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_NODE,(yyvsp[0].asts)); }
#line 4666 "y.tab.c"
    break;

  case 225:
#line 1570 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[-1].ilist))); }
#line 4672 "y.tab.c"
    break;

  case 226:
#line 1571 "../../sdcc-svn/src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[-2].ilist))); }
#line 4678 "y.tab.c"
    break;

  case 227:
#line 1575 "../../sdcc-svn/src/SDCC.y"
                                    { (yyvsp[0].ilist)->designation = (yyvsp[-1].dsgn); (yyval.ilist) = (yyvsp[0].ilist); }
#line 4684 "y.tab.c"
    break;

  case 228:
#line 1577 "../../sdcc-svn/src/SDCC.y"
                                    {
                                       (yyvsp[0].ilist)->designation = (yyvsp[-1].dsgn);
                                       (yyvsp[0].ilist)->next = (yyvsp[-3].ilist);
                                       (yyval.ilist) = (yyvsp[0].ilist);
                                    }
#line 4694 "y.tab.c"
    break;

  case 229:
#line 1585 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.dsgn) = NULL; }
#line 4700 "y.tab.c"
    break;

  case 231:
#line 1590 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.dsgn) = revDesignation((yyvsp[-1].dsgn)); }
#line 4706 "y.tab.c"
    break;

  case 233:
#line 1595 "../../sdcc-svn/src/SDCC.y"
                                 { (yyvsp[0].dsgn)->next = (yyvsp[-1].dsgn); (yyval.dsgn) = (yyvsp[0].dsgn); }
#line 4712 "y.tab.c"
    break;

  case 234:
#line 1600 "../../sdcc-svn/src/SDCC.y"
         {
            value *tval;
            int elemno;

            tval = constExprValue((yyvsp[-1].asts), TRUE);
            /* if it is not a constant then Error  */
            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror (E_CONST_EXPECTED);
                elemno = 0; /* arbitrary fixup */
              }
            else
              {
                if ((elemno = (int) ulFromVal(tval)) < 0)
                  {
                    werror (E_BAD_DESIGNATOR);
                    elemno = 0; /* arbitrary fixup */
                  }
              }
            (yyval.dsgn) = newDesignation(DESIGNATOR_ARRAY, &elemno);
         }
#line 4738 "y.tab.c"
    break;

  case 235:
#line 1621 "../../sdcc-svn/src/SDCC.y"
                                 { (yyval.dsgn) = newDesignation(DESIGNATOR_STRUCT,(yyvsp[0].sym)); }
#line 4744 "y.tab.c"
    break;

  case 236:
#line 1626 "../../sdcc-svn/src/SDCC.y"
                                    {
                                       value *val = constExprValue ((yyvsp[-4].asts), TRUE);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ulFromVal(val))
                                         werror (W_STATIC_ASSERTION, (yyvsp[-2].yystr));
                                    }
#line 4756 "y.tab.c"
    break;

  case 237:
#line 1634 "../../sdcc-svn/src/SDCC.y"
                                    {
                                       value *val = constExprValue ((yyvsp[-2].asts), TRUE);
                                       if (!options.std_c2x)
                                         werror (E_STATIC_ASSERTION_C2X);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ulFromVal(val))
                                         werror (W_STATIC_ASSERTION_2);
                                    }
#line 4770 "y.tab.c"
    break;

  case 242:
#line 1657 "../../sdcc-svn/src/SDCC.y"
     {
       if (!options.std_c2x)
         werror(E_ATTRIBUTE_C2X);
     }
#line 4779 "y.tab.c"
    break;

  case 259:
#line 1701 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4787 "y.tab.c"
    break;

  case 260:
#line 1705 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4795 "y.tab.c"
    break;

  case 261:
#line 1709 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4803 "y.tab.c"
    break;

  case 262:
#line 1713 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4811 "y.tab.c"
    break;

  case 265:
#line 1721 "../../sdcc-svn/src/SDCC.y"
                      { if ((yyvsp[-1].asts)) {(yyval.asts) = (yyvsp[-1].asts); (yyvsp[-1].asts)->right = (yyvsp[0].asts);} else (yyval.asts) = newNode (BLOCK, NULL, NULL); }
#line 4817 "y.tab.c"
    break;

  case 266:
#line 1722 "../../sdcc-svn/src/SDCC.y"
                                                   { if ((yyvsp[-1].asts)) {(yyval.asts) = (yyvsp[-1].asts); (yyvsp[-1].asts)->right = (yyvsp[0].asts);} else (yyval.asts) = newNode (BLOCK, NULL, NULL); }
#line 4823 "y.tab.c"
    break;

  case 267:
#line 1724 "../../sdcc-svn/src/SDCC.y"
     { /* Support a label without a statement at the end of a */
       /* compound statement as a SDCC extension. Include the */
       /* closing brace as part of the rule to avoid an */
       /* unacceptably large number of shift/reduce conflicts */
       /* and then reinsert it to be parsed a second time. */
       werror(W_LABEL_WITHOUT_STATEMENT);
       (yyval.asts) = (yyvsp[-1].asts);
       yychar = '}';
     }
#line 4837 "y.tab.c"
    break;

  case 268:
#line 1736 "../../sdcc-svn/src/SDCC.y"
                                       {  (yyval.asts) = createLabel((yyvsp[-1].sym),NULL);
                                          (yyvsp[-1].sym)->isitmp = 0;  }
#line 4844 "y.tab.c"
    break;

  case 269:
#line 1739 "../../sdcc-svn/src/SDCC.y"
     {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createCase(NULL,(yyvsp[-1].asts),NULL);
       else
         (yyval.asts) = createCase(STACK_PEEK(swStk),(yyvsp[-1].asts),NULL);
     }
#line 4855 "y.tab.c"
    break;

  case 270:
#line 1745 "../../sdcc-svn/src/SDCC.y"
             { (yyval.asts) = newNode(DEFAULT,NULL,NULL); }
#line 4861 "y.tab.c"
    break;

  case 271:
#line 1746 "../../sdcc-svn/src/SDCC.y"
     {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createDefault(NULL,(yyvsp[-1].asts),NULL);
       else
         (yyval.asts) = createDefault(STACK_PEEK(swStk),(yyvsp[-1].asts),NULL);
     }
#line 4872 "y.tab.c"
    break;

  case 272:
#line 1756 "../../sdcc-svn/src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          ignoreTypedefType = 0;
        }
#line 4884 "y.tab.c"
    break;

  case 273:
#line 1767 "../../sdcc-svn/src/SDCC.y"
        {
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
        }
#line 4893 "y.tab.c"
    break;

  case 274:
#line 1774 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.asts) = createBlock(NULL, NULL); }
#line 4899 "y.tab.c"
    break;

  case 275:
#line 1776 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[-1].asts);
       cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
     }
#line 4908 "y.tab.c"
    break;

  case 276:
#line 1780 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.asts) = NULL; }
#line 4914 "y.tab.c"
    break;

  case 277:
#line 1784 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.asts) = createBlock(NULL, (yyvsp[0].asts)); }
#line 4920 "y.tab.c"
    break;

  case 278:
#line 1785 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.asts) = createBlock((yyvsp[0].sym), NULL); }
#line 4926 "y.tab.c"
    break;

  case 279:
#line 1786 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.asts) = createBlock((yyvsp[-1].sym), (yyvsp[0].asts)); }
#line 4932 "y.tab.c"
    break;

  case 281:
#line 1791 "../../sdcc-svn/src/SDCC.y"
                                                     { (yyval.asts) = (yyvsp[-1].asts); seqPointNo++;}
#line 4938 "y.tab.c"
    break;

  case 282:
#line 1795 "../../sdcc-svn/src/SDCC.y"
                     { seqPointNo++;}
#line 4944 "y.tab.c"
    break;

  case 283:
#line 1796 "../../sdcc-svn/src/SDCC.y"
                           {
                              noLineno++;
                              (yyval.asts) = createIf ((yyvsp[-4].asts), (yyvsp[-1].asts), (yyvsp[0].asts) );
                              (yyval.asts)->lineno = (yyvsp[-4].asts)->lineno;
                              (yyval.asts)->filename = (yyvsp[-4].asts)->filename;
                              noLineno--;
                           }
#line 4956 "y.tab.c"
    break;

  case 284:
#line 1803 "../../sdcc-svn/src/SDCC.y"
                           {
                              ast *ex;
                              static   int swLabel = 0;

                              seqPointNo++;
                              /* create a node for expression  */
                              ex = newNode(SWITCH,(yyvsp[-1].asts),NULL);
                              STACK_PUSH(swStk,ex);   /* save it in the stack */
                              ex->values.switchVals.swNum = swLabel;

                              /* now create the label */
                              SNPRINTF(lbuff, sizeof(lbuff),
                                       "_swBrk_%d",swLabel++);
                              (yyval.sym)  =  newSymbol(lbuff,NestLevel);
                              /* put label in the break stack  */
                              STACK_PUSH(breakStack,(yyval.sym));
                           }
#line 4978 "y.tab.c"
    break;

  case 285:
#line 1820 "../../sdcc-svn/src/SDCC.y"
                           {
                              /* get back the switch form the stack  */
                              (yyval.asts) = STACK_POP(swStk);
                              (yyval.asts)->right = newNode (NULLOP,(yyvsp[0].asts),createLabel((yyvsp[-1].sym),NULL));
                              STACK_POP(breakStack);
                           }
#line 4989 "y.tab.c"
    break;

  case 286:
#line 1829 "../../sdcc-svn/src/SDCC.y"
                        { seqPointNo++;}
#line 4995 "y.tab.c"
    break;

  case 287:
#line 1830 "../../sdcc-svn/src/SDCC.y"
                         {
                           noLineno++;
                           (yyval.asts) = createWhile ( (yyvsp[-5].sym), STACK_POP(continueStack),
                                              STACK_POP(breakStack), (yyvsp[-3].asts), (yyvsp[0].asts) );
                           (yyval.asts)->lineno = (yyvsp[-5].sym)->lineDef;
                           (yyval.asts)->filename = (yyvsp[-5].sym)->fileDef;
                           noLineno--;
                         }
#line 5008 "y.tab.c"
    break;

  case 288:
#line 1839 "../../sdcc-svn/src/SDCC.y"
                        {
                          seqPointNo++;
                          noLineno++;
                          (yyval.asts) = createDo ( (yyvsp[-6].sym) , STACK_POP(continueStack),
                                          STACK_POP(breakStack), (yyvsp[-2].asts), (yyvsp[-5].asts));
                          (yyval.asts)->lineno = (yyvsp[-6].sym)->lineDef;
                          (yyval.asts)->filename = (yyvsp[-6].sym)->fileDef;
                          noLineno--;
                        }
#line 5022 "y.tab.c"
    break;

  case 289:
#line 1849 "../../sdcc-svn/src/SDCC.y"
                        {
                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[0].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[-8].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = (yyvsp[-6].asts);
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[-4].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[-2].asts);
                          
                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL));
                          noLineno--;

                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
#line 5051 "y.tab.c"
    break;

  case 290:
#line 1874 "../../sdcc-svn/src/SDCC.y"
                        {
                          if (!options.std_c99)
                            werror (E_FOR_INITAL_DECLARATION_C99);

                          if ( (yyvsp[-4].sym) && IS_TYPEDEF((yyvsp[-4].sym)->etype))
                            allocVariables ((yyvsp[-4].sym));
                          ignoreTypedefType = 0;
                          addSymChain(&(yyvsp[-4].sym));
                        }
#line 5065 "y.tab.c"
    break;

  case 291:
#line 1884 "../../sdcc-svn/src/SDCC.y"
                        {

                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[0].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[-8].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = 0;
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[-5].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[-3].asts);

                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = createBlock((yyvsp[-6].sym), newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL)));
                          cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
                          noLineno--;

                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
#line 5096 "y.tab.c"
    break;

  case 292:
#line 1913 "../../sdcc-svn/src/SDCC.y"
                           {
                              if (inCriticalBlock) {
                                werror(E_INVALID_CRITICAL);
                                (yyval.asts) = NULL;
                              } else {
                                (yyvsp[-1].sym)->islbl = 1;
                                (yyval.asts) = newAst_VALUE(symbolVal((yyvsp[-1].sym)));
                                (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
                              }
                           }
#line 5111 "y.tab.c"
    break;

  case 293:
#line 1923 "../../sdcc-svn/src/SDCC.y"
                           {
       /* make sure continue is in context */
       if (STACK_EMPTY(continueStack) || STACK_PEEK(continueStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       }
       else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(continueStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           /* mark the continue label as referenced */
           STACK_PEEK(continueStack)->isref = 1;
       }
   }
#line 5129 "y.tab.c"
    break;

  case 294:
#line 1936 "../../sdcc-svn/src/SDCC.y"
                           {
       if (STACK_EMPTY(breakStack) || STACK_PEEK(breakStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(breakStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           STACK_PEEK(breakStack)->isref = 1;
       }
   }
#line 5144 "y.tab.c"
    break;

  case 295:
#line 1946 "../../sdcc-svn/src/SDCC.y"
                           {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,NULL);
       }
   }
#line 5158 "y.tab.c"
    break;

  case 296:
#line 1955 "../../sdcc-svn/src/SDCC.y"
                           {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,(yyvsp[-1].asts));
       }
   }
#line 5172 "y.tab.c"
    break;

  case 299:
#line 1975 "../../sdcc-svn/src/SDCC.y"
        {
          // blockNo = 0;
        }
#line 5180 "y.tab.c"
    break;

  case 300:
#line 1979 "../../sdcc-svn/src/SDCC.y"
        {
          ignoreTypedefType = 0;
          if ((yyvsp[0].sym) && (yyvsp[0].sym)->type && IS_FUNC((yyvsp[0].sym)->type))
            {
              /* The only legal storage classes for
               * a function prototype (declaration)
               * are extern and static. extern is the
               * default. Thus, if this function isn't
               * explicitly marked static, mark it
               * extern.
               */
              if ((yyvsp[0].sym)->etype && IS_SPEC((yyvsp[0].sym)->etype) && !SPEC_STAT((yyvsp[0].sym)->etype))
                {
                  SPEC_EXTR((yyvsp[0].sym)->etype) = 1;
                }
            }
          addSymChain (&(yyvsp[0].sym));
          allocVariables ((yyvsp[0].sym));
          cleanUpLevel (SymbolTab, 1);
        }
#line 5205 "y.tab.c"
    break;

  case 301:
#line 2000 "../../sdcc-svn/src/SDCC.y"
        {
          /* These empty braces here are apparently required by some version of GNU bison on MS Windows. See bug #2858. */
        }
#line 5213 "y.tab.c"
    break;

  case 302:
#line 2007 "../../sdcc-svn/src/SDCC.y"
        {   /* function type not specified */
            /* assume it to be 'int'       */
            addDecl((yyvsp[0].sym),0,newIntLink());
            (yyvsp[0].sym) = createFunctionDecl((yyvsp[0].sym));
            if ((yyvsp[0].sym))
                {
                    if (FUNC_ISCRITICAL ((yyvsp[0].sym)->type))
                        inCriticalFunction = 1;
                    strncpy (function_name, (yyvsp[0].sym)->name, sizeof (function_name) - 4);
                    memset (function_name + sizeof (function_name) - 4, 0x00, 4);
                }
        }
#line 5230 "y.tab.c"
    break;

  case 303:
#line 2020 "../../sdcc-svn/src/SDCC.y"
        {
            (yyval.asts) = createFunction((yyvsp[-2].sym),(yyvsp[0].asts));
            if ((yyvsp[-2].sym) && FUNC_ISCRITICAL ((yyvsp[-2].sym)->type))
                inCriticalFunction = 0;
        }
#line 5240 "y.tab.c"
    break;

  case 304:
#line 2026 "../../sdcc-svn/src/SDCC.y"
        {
            sym_link *p = copyLinkChain((yyvsp[-1].lnk));
            pointerTypes((yyvsp[0].sym)->type,p);
            addDecl((yyvsp[0].sym),0,p);
            (yyvsp[0].sym) = createFunctionDecl((yyvsp[0].sym));
            if ((yyvsp[0].sym))
                {
                    if (FUNC_ISCRITICAL ((yyvsp[0].sym)->type))
                        inCriticalFunction = 1;
                    // warn for loss of calling convention for inlined functions.
                    if (FUNC_ISINLINE ((yyvsp[0].sym)->type) &&
                        ( FUNC_ISZ88DK_CALLEE ((yyvsp[0].sym)->type) || FUNC_ISZ88DK_FASTCALL ((yyvsp[0].sym)->type) ||
                          FUNC_BANKED ((yyvsp[0].sym)->type)         || FUNC_REGBANK ((yyvsp[0].sym)->type)          ||
                          FUNC_ISOVERLAY ((yyvsp[0].sym)->type)      || FUNC_ISISR ((yyvsp[0].sym)->type) ))
                        werror (W_INLINE_FUNCATTR, (yyvsp[0].sym)->name);
                    strncpy (function_name, (yyvsp[0].sym)->name, sizeof (function_name) - 4);
                    memset (function_name + sizeof (function_name) - 4, 0x00, 4);
                }
        }
#line 5264 "y.tab.c"
    break;

  case 305:
#line 2046 "../../sdcc-svn/src/SDCC.y"
        {
            (yyval.asts) = createFunction((yyvsp[-2].sym),(yyvsp[0].asts));
            if ((yyvsp[-2].sym) && FUNC_ISCRITICAL ((yyvsp[-2].sym)->type))
                inCriticalFunction = 0;
        }
#line 5274 "y.tab.c"
    break;

  case 307:
#line 2056 "../../sdcc-svn/src/SDCC.y"
                     {
                       werror (E_OLD_STYLE, ((yyvsp[-1].sym) ? (yyvsp[-1].sym)->name: ""));
                       exit (1);
                     }
#line 5283 "y.tab.c"
    break;

  case 308:
#line 2066 "../../sdcc-svn/src/SDCC.y"
        {
          werror(W_EMPTY_SOURCE_FILE);
        }
#line 5291 "y.tab.c"
    break;

  case 311:
#line 2077 "../../sdcc-svn/src/SDCC.y"
                                            { (yyval.lnk) = mergeSpec((yyvsp[-1].lnk),(yyvsp[0].lnk),"function_attribute"); }
#line 5297 "y.tab.c"
    break;

  case 312:
#line 2081 "../../sdcc-svn/src/SDCC.y"
                          {
                        (yyval.lnk) = newLink(SPECIFIER);
                        FUNC_REGBANK((yyval.lnk)) = (int) ulFromVal(constExprValue((yyvsp[0].asts),TRUE));
                     }
#line 5306 "y.tab.c"
    break;

  case 313:
#line 2085 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISREENT((yyval.lnk))=1;
                     }
#line 5314 "y.tab.c"
    break;

  case 314:
#line 2088 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISCRITICAL((yyval.lnk)) = 1;
                     }
#line 5322 "y.tab.c"
    break;

  case 315:
#line 2091 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISNAKED((yyval.lnk))=1;
                     }
#line 5330 "y.tab.c"
    break;

  case 316:
#line 2094 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISJAVANATIVE((yyval.lnk))=1;
                     }
#line 5338 "y.tab.c"
    break;

  case 317:
#line 2097 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISOVERLAY((yyval.lnk))=1;
                     }
#line 5346 "y.tab.c"
    break;

  case 318:
#line 2100 "../../sdcc-svn/src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_NONBANKED((yyval.lnk)) = 1;
                        if (FUNC_BANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
#line 5357 "y.tab.c"
    break;

  case 319:
#line 2106 "../../sdcc-svn/src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSHADOWREGS((yyval.lnk)) = 1;
                     }
#line 5365 "y.tab.c"
    break;

  case 320:
#line 2109 "../../sdcc-svn/src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISWPARAM((yyval.lnk)) = 1;
                     }
#line 5373 "y.tab.c"
    break;

  case 321:
#line 2112 "../../sdcc-svn/src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_BANKED((yyval.lnk)) = 1;
                        if (FUNC_NONBANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
#line 5384 "y.tab.c"
    break;

  case 322:
#line 2119 "../../sdcc-svn/src/SDCC.y"
                     {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = (yyvsp[0].yyint);
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
#line 5394 "y.tab.c"
    break;

  case 323:
#line 2125 "../../sdcc-svn/src/SDCC.y"
                     {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = INTNO_TRAP;
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
#line 5404 "y.tab.c"
    break;

  case 324:
#line 2130 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSMALLC((yyval.lnk)) = 1;
                     }
#line 5412 "y.tab.c"
    break;

  case 325:
#line 2133 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_FASTCALL((yyval.lnk)) = 1;
                     }
#line 5420 "y.tab.c"
    break;

  case 326:
#line 2136 "../../sdcc-svn/src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_CALLEE((yyval.lnk)) = 1;
                     }
#line 5428 "y.tab.c"
    break;

  case 327:
#line 2140 "../../sdcc-svn/src/SDCC.y"
                     {
                        value *offset_v = constExprValue ((yyvsp[-1].asts), TRUE);
                        int    offset = 0;
                        (yyval.lnk) = newLink(SPECIFIER);
                        if  ( offset_v ) 
                          offset = ulFromVal(offset_v);
                        (yyval.lnk)->funcAttrs.z88dk_params_offset = offset;
                     }
#line 5441 "y.tab.c"
    break;

  case 328:
#line 2149 "../../sdcc-svn/src/SDCC.y"
                     {
                        value *rst_v = constExprValue ((yyvsp[-3].asts), TRUE);
                        value *value_v = constExprValue ((yyvsp[-1].asts), TRUE);
                        int rst = -1, value = -1;
                        (yyval.lnk) = newLink(SPECIFIER);

                        if  ( rst_v ) 
                          rst = ulFromVal(rst_v);
                        if  ( value_v ) 
                          value = ulFromVal(value_v);
          
                        if ( rst < 0 || rst > 56 || ( rst % 8 ) )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "rst", rst);
                          }
                        if ( value < 0 || value > 0xfff )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "value", value);
                          }
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_rst = rst;
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_val = value;
                        FUNC_ISZ88DK_SHORTCALL((yyval.lnk)) = 1;
                     }
#line 5469 "y.tab.c"
    break;

  case 329:
#line 2173 "../../sdcc-svn/src/SDCC.y"
                     {
                        const struct symbol *regsym;
                        (yyval.lnk) = newLink (SPECIFIER);

                        for(regsym = (yyvsp[-1].sym); regsym; regsym = regsym->next)
                          {
                            int regnum;

                            if (!port->getRegByName || ((regnum = port->getRegByName(regsym->name)) < 0))
                              werror (W_UNKNOWN_REG, regsym->name);
                            else
                              (yyval.lnk)->funcAttrs.preserved_regs[regnum] = TRUE;
                          }
                     }
#line 5488 "y.tab.c"
    break;

  case 330:
#line 2190 "../../sdcc-svn/src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[0].sym))); }
#line 5494 "y.tab.c"
    break;

  case 331:
#line 2191 "../../sdcc-svn/src/SDCC.y"
                                    { ignoreTypedefType = 1; }
#line 5500 "y.tab.c"
    break;

  case 332:
#line 2192 "../../sdcc-svn/src/SDCC.y"
                     {
                       ignoreTypedefType = 0;
                       (yyvsp[0].sym) = newSymbol ((yyvsp[0].sym)->name, NestLevel);
                       (yyvsp[0].sym)->implicit = 1;
                       (yyval.asts) = newNode ('.', (yyvsp[-3].asts), newAst_VALUE (symbolVal ((yyvsp[0].sym))));
                     }
#line 5511 "y.tab.c"
    break;

  case 333:
#line 2199 "../../sdcc-svn/src/SDCC.y"
                     {
                       (yyval.asts) = newNode ('[', (yyvsp[-3].asts), (yyvsp[-1].asts));
                     }
#line 5519 "y.tab.c"
    break;

  case 334:
#line 2205 "../../sdcc-svn/src/SDCC.y"
                    {
                       int cnt = 1;
                       int max = 253, min = 1;
                       char fb[256];
                       /* refer to support/cpp/libcpp/macro.c for details */
                       while ((((int) ((yyvsp[0].yystr)[cnt] & 0xff)) & 0xff) == 0xff)
                         cnt++;

                       if (cnt <= max)
                         {
                           (yyval.asts) = newAst_VALUE (strVal ((yyvsp[0].yystr)));
                         }
                       else
                         {
                           memset (fb, 0x00, sizeof (fb));
                           fb[0] = '"';
                           strncpy (fb + 1, function_name, max - min + 1);
                           fb[max + 1] = '"';
                           fb[max + 2] = 0;
                           fb[strlen (fb)] = '"';
                           fb[strlen (fb) + 1] = 0;
                           (yyval.asts) = newAst_VALUE (strVal (fb));
                         }
                     }
#line 5548 "y.tab.c"
    break;

  case 335:
#line 2232 "../../sdcc-svn/src/SDCC.y"
               { (yyval.yyint) = INTNO_UNSPEC; }
#line 5554 "y.tab.c"
    break;

  case 336:
#line 2234 "../../sdcc-svn/src/SDCC.y"
        { 
          value *val = constExprValue((yyvsp[0].asts),TRUE);
          int intno = (int) ulFromVal(val);
          if (val && (intno >= 0) && (intno <= INTNO_MAX))
            (yyval.yyint) = intno;
          else
            {
              werror(E_INT_BAD_INTNO, intno);
              (yyval.yyint) = INTNO_UNSPEC;
            }
        }
#line 5570 "y.tab.c"
    break;

  case 337:
#line 2248 "../../sdcc-svn/src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               SPEC_NOUN((yyval.lnk)) = V_SBIT;
               SPEC_SCLS((yyval.lnk)) = S_SBIT;
               SPEC_BLEN((yyval.lnk)) = 1;
               SPEC_BSTR((yyval.lnk)) = 0;
               ignoreTypedefType = 1;
            }
#line 5583 "y.tab.c"
    break;

  case 339:
#line 2260 "../../sdcc-svn/src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5596 "y.tab.c"
    break;

  case 340:
#line 2268 "../../sdcc-svn/src/SDCC.y"
                {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 1;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5609 "y.tab.c"
    break;

  case 341:
#line 2279 "../../sdcc-svn/src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5622 "y.tab.c"
    break;

  case 342:
#line 2290 "../../sdcc-svn/src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_LONG((yyval.lnk))    = 1;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5636 "y.tab.c"
    break;

  case 344:
#line 2303 "../../sdcc-svn/src/SDCC.y"
        {  /* synthesize a name add to structtable */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct(genSymName(NestLevel));
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = NULL;
          //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
        }
#line 5649 "y.tab.c"
    break;

  case 345:
#line 2315 "../../sdcc-svn/src/SDCC.y"
        {  /* add name to structure table */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct((yyvsp[0].sym)->name);
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = (yyvsp[0].sym);
          //$$ = findSymWithBlock (StructTab, $1, currBlockno);
          //if (! $$ )
          //  {
          //    $$ = newStruct($1->name);
          //    $$->level = NestLevel;
          //    $$->tagsym = $1;
          //    //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
          //  }
        }
#line 5669 "y.tab.c"
    break;

  case 346:
#line 2334 "../../sdcc-svn/src/SDCC.y"
        {
          value *val;

          val = constExprValue((yyvsp[0].asts), TRUE);
          if (!val) // Not a constant expression
            {
              werror (E_CONST_EXPECTED);
              val = constIntVal("0");
            }
          else if (!IS_INT(val->type) && !IS_CHAR(val->type) && !IS_BOOL(val->type))
            {
              werror(E_ENUM_NON_INTEGER);
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(val));
              val = constVal(lbuff);
            }
          (yyval.val) = cenum = val;
        }
#line 5691 "y.tab.c"
    break;

  case 347:
#line 2351 "../../sdcc-svn/src/SDCC.y"
        {
          if (cenum)
            {
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(cenum)+1);
              (yyval.val) = cenum = constVal(lbuff);
            }
          else
            {
              (yyval.val) = cenum = constCharVal(0);
            }
        }
#line 5707 "y.tab.c"
    break;

  case 348:
#line 2364 "../../sdcc-svn/src/SDCC.y"
                                                { (yyval.lnk) = finalizeSpec((yyvsp[0].lnk)); }
#line 5713 "y.tab.c"
    break;

  case 350:
#line 2369 "../../sdcc-svn/src/SDCC.y"
                                                   {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_specifier_list type_specifier skipped");
   }
#line 5723 "y.tab.c"
    break;

  case 352:
#line 2379 "../../sdcc-svn/src/SDCC.y"
         {
           (yyvsp[0].sym)->next = (yyvsp[-2].sym);
           (yyval.sym) = (yyvsp[0].sym);
         }
#line 5732 "y.tab.c"
    break;

  case 353:
#line 2387 "../../sdcc-svn/src/SDCC.y"
        {
          if (IS_SPEC ((yyvsp[0].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[0].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          (yyval.lnk) = (yyvsp[0].lnk); ignoreTypedefType = 0;
        }
#line 5744 "y.tab.c"
    break;

  case 354:
#line 2395 "../../sdcc-svn/src/SDCC.y"
        {
          /* go to the end of the list */
          sym_link *p;

          if (IS_SPEC ((yyvsp[-1].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[-1].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          pointerTypes ((yyvsp[0].lnk),(yyvsp[-1].lnk));
          for (p = (yyvsp[0].lnk); p && p->next; p = p->next)
            ;
          if (!p)
            {
              werror(E_SYNTAX_ERROR, yytext);
            }
          else
            {
              p->next = (yyvsp[-1].lnk);
            }
          (yyval.lnk) = (yyvsp[0].lnk);
          ignoreTypedefType = 0;
        }
#line 5771 "y.tab.c"
    break;

  case 355:
#line 2420 "../../sdcc-svn/src/SDCC.y"
                {
                   if (inCriticalFunction || inCriticalBlock)
                     werror(E_INVALID_CRITICAL);
                   inCriticalBlock = 1;
                   STACK_PUSH(continueStack,NULL);
                   STACK_PUSH(breakStack,NULL);
                   (yyval.sym) = NULL;
                }
#line 5784 "y.tab.c"
    break;

  case 356:
#line 2431 "../../sdcc-svn/src/SDCC.y"
                         {
                   STACK_POP(breakStack);
                   STACK_POP(continueStack);
                   (yyval.asts) = newNode(CRITICAL,(yyvsp[0].asts),NULL);
                   inCriticalBlock = 0;
                }
#line 5795 "y.tab.c"
    break;

  case 358:
#line 2442 "../../sdcc-svn/src/SDCC.y"
     {
       (yyval.asts) = newNode(NULLOP, (yyvsp[-1].asts), (yyvsp[0].asts));
       if (!options.std_c99)
         werror(E_DECL_AFTER_STATEMENT_C99);
     }
#line 5805 "y.tab.c"
    break;

  case 359:
#line 2450 "../../sdcc-svn/src/SDCC.y"
     {
       NestLevel += SUBLEVEL_UNIT;
       STACK_PUSH(blockNum, currBlockno);
       btree_add_child(currBlockno, ++blockNo);
       currBlockno = blockNo;
       ignoreTypedefType = 0;
     }
#line 5817 "y.tab.c"
    break;

  case 360:
#line 2457 "../../sdcc-svn/src/SDCC.y"
                                              { (yyval.sym) = (yyvsp[0].sym); }
#line 5823 "y.tab.c"
    break;

  case 361:
#line 2462 "../../sdcc-svn/src/SDCC.y"
     {
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[-1].sym), (yyvsp[0].asts));
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
#line 5834 "y.tab.c"
    break;

  case 362:
#line 2469 "../../sdcc-svn/src/SDCC.y"
     {
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[0].sym), NULL);
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
#line 5845 "y.tab.c"
    break;

  case 363:
#line 2479 "../../sdcc-svn/src/SDCC.y"
     {
       /* if this is typedef declare it immediately */
       if ( (yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = NULL;
       }
       else
         (yyval.sym) = (yyvsp[0].sym);
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[0].sym));
     }
#line 5861 "y.tab.c"
    break;

  case 364:
#line 2492 "../../sdcc-svn/src/SDCC.y"
     {
       symbol   *sym;

       /* if this is a typedef */
       if ((yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = (yyvsp[-1].sym);
       }
       else {
         /* get to the end of the previous decl */
         if ( (yyvsp[-1].sym) ) {
           (yyval.sym) = sym = (yyvsp[-1].sym);
           while (sym->next)
             sym = sym->next;
           sym->next = (yyvsp[0].sym);
         }
         else
           (yyval.sym) = (yyvsp[0].sym);
       }
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[0].sym));
     }
#line 5888 "y.tab.c"
    break;

  case 366:
#line 2518 "../../sdcc-svn/src/SDCC.y"
                                       {  (yyval.asts) = newNode(NULLOP,(yyvsp[-1].asts),(yyvsp[0].asts));}
#line 5894 "y.tab.c"
    break;

  case 367:
#line 2522 "../../sdcc-svn/src/SDCC.y"
                        { (yyval.asts) = (yyvsp[0].asts); }
#line 5900 "y.tab.c"
    break;

  case 368:
#line 2523 "../../sdcc-svn/src/SDCC.y"
                        { (yyval.asts) = NULL; }
#line 5906 "y.tab.c"
    break;

  case 369:
#line 2528 "../../sdcc-svn/src/SDCC.y"
               {  /* create and push the continue , break & body labels */
                  static int Lblnum = 0;
                  /* continue */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilecontinue_%d",Lblnum);
                  STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
                  /* break */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebreak_%d",Lblnum);
                  STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
                  /* body */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebody_%d",Lblnum++);
                  (yyval.sym) = newSymbol(lbuff,NestLevel);
               }
#line 5923 "y.tab.c"
    break;

  case 370:
#line 2542 "../../sdcc-svn/src/SDCC.y"
        {  /* create and push the continue , break & body Labels */
           static int Lblnum = 0;

           /* continue */
           SNPRINTF(lbuff, sizeof(lbuff), "_docontinue_%d",Lblnum);
           STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
           /* break */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobreak_%d",Lblnum);
           STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
           /* do body */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobody_%d",Lblnum++);
           (yyval.sym) = newSymbol (lbuff,NestLevel);
        }
#line 5941 "y.tab.c"
    break;

  case 371:
#line 2557 "../../sdcc-svn/src/SDCC.y"
          { /* create & push continue, break & body labels */
            static int Lblnum = 0;

           NestLevel += LEVEL_UNIT;
           STACK_PUSH(blockNum, currBlockno);
           btree_add_child(currBlockno, ++blockNo);
           currBlockno = blockNo;
           ignoreTypedefType = 0;

            /* continue */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcontinue_%d",Lblnum);
            STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
            /* break    */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbreak_%d",Lblnum);
            STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
            /* body */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbody_%d",Lblnum);
            (yyval.sym) = newSymbol(lbuff,NestLevel);
            /* condition */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcond_%d",Lblnum++);
            STACK_PUSH(forStack,newSymbol(lbuff,NestLevel));
          }
#line 5968 "y.tab.c"
    break;

  case 373:
#line 2587 "../../sdcc-svn/src/SDCC.y"
      {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup(copyStr ((yyvsp[-2].yystr), NULL));
        seqPointNo++;
        (yyval.asts) = ex;
     }
#line 5982 "y.tab.c"
    break;

  case 374:
#line 2597 "../../sdcc-svn/src/SDCC.y"
      {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup((yyvsp[-1].yystr));
        seqPointNo++;
        (yyval.asts) = ex;
      }
#line 5996 "y.tab.c"
    break;

  case 375:
#line 2609 "../../sdcc-svn/src/SDCC.y"
                                          {
     symbol *sym;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym))) && sym->level == (yyvsp[-1].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[-2].sym)))
       werror (E_ID_UNDEF, (yyvsp[-2].sym)->name);
     addSym (AddrspaceTab, (yyvsp[-1].sym), (yyvsp[-1].sym)->name, (yyvsp[-1].sym)->level, (yyvsp[-1].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[-2].sym));
     sym->addressmod[1] = 0;
   }
#line 6012 "y.tab.c"
    break;

  case 376:
#line 2620 "../../sdcc-svn/src/SDCC.y"
                                                   {
     symbol *sym;
     sym_link *type;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym))) && sym->level == (yyvsp[-1].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[-3].sym)))
       werror (E_ID_UNDEF, (yyvsp[-3].sym)->name);
     addSym (AddrspaceTab, (yyvsp[-1].sym), (yyvsp[-1].sym)->name, (yyvsp[-1].sym)->level, (yyvsp[-1].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[-3].sym));
     sym->addressmod[1] = 0;
     type = newLink (SPECIFIER);
     SPEC_CONST(type) = 1;
     sym->type = sym->etype = type;
   }
#line 6032 "y.tab.c"
    break;

  case 377:
#line 2638 "../../sdcc-svn/src/SDCC.y"
                  { (yyval.sym) = newSymbol ((yyvsp[0].yychar), NestLevel); }
#line 6038 "y.tab.c"
    break;


#line 6042 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2640 "../../sdcc-svn/src/SDCC.y"

