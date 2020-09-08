/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 363 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
