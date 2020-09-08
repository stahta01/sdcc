/*-------------------------------------------------------------------------
  gen.c - code generator for MC6809 / HD6309.

  Over all logic from "z80/gen.c" with parts of logic copied from 
  "stm8/gen.c" or "hc08/gen.c".

  Copyright (C) 1998, Sandeep Dutta . sandeep.dutta@usa.net
  Copyright (C) 1999, Jean-Louis VERN.jlvern@writeme.com
  Copyright (C) 2000, Michael Hope <michaelh@juju.net.nz>
  Copyright (C) 2011-2018, Philipp Klaus Krause pkk@spth.de, philipp@informatik.uni-frankfurt.de)
  Copyright (C) 2020, Tim Stahlhut stahta01@gmail.com

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "m6809.h"
#include "gen.h"
#include "dbuf_string.h"

/* This is the down and dirty file with all kinds of kludgy & hacky
   stuff. This is what it is all about CODE GENERATION for a specific MCU.
   Some of the routines may be reusable, will have to see */

/* MC6809 calling convention description.
?   Parameters are passed right to left.  As the stack grows downwards,
?   the parameters are arranged in left to right in memory.

   Everything is caller saves. i.e. the caller must save any registers
?   that it wants to preserve over the call.
?   va args functions do not use register parameters.  All arguments
?   are passed on the stack.
*/

enum
{
  /* Set to enable debugging trace statements in the output assembly code. */
  DISABLE_DEBUG = 0
};

// #define DEBUG_DRY_COST

extern struct dbuf_s *codeOutBuf;

enum
{
  INT8MIN = -128,
  INT8MAX = 127
};

enum
{
  LSB,
  MSB16,
  MSB24,
  MSB32
};

enum asminst
{
  A_ABX,
  A_ADC8,
  A_ADD8,
  A_ADD16,
  A_AND8,
  A_ANDCC,
  A_ASL,
  A_ASL8,
  A_ASR,
  A_ASR8,
  A_BCC,
  A_BCS,
  A_BEQ,
  A_BGE,
  A_BGT,
  A_BHI,
  A_BHS,
  A_BIT8,
  A_BLE,
  A_BLO,
  A_BLS,
  A_BLT,
  A_BMI,
  A_BNE,
  A_BPL,
  A_BRA,
  A_BRN,
  A_BSR,
  A_BVC,
  A_BVS,
  A_CLR,
  A_CLR8,
  A_CMP8,
  A_CMP16,
  A_COM,
  A_COM8,
  A_CWAI,
  A_DAA,
  A_DEC,
  A_DEC8,
  A_EOR8,
  A_EXG,
  A_INC,
  A_INC8,
  A_JMP,
  A_JSR,
  A_LBCC,
  A_LBCS,
  A_LBEQ,
  A_LBGE,
  A_LBGT,
  A_LBHI,
  A_LBHS,
  A_LBLE,
  A_LBLO,
  A_LBLS,
  A_LBLT,
  A_LBMI,
  A_LBNE,
  A_LBPL,
  A_LBRA,
  A_LBRN,
  A_LBSR,
  A_LBVC,
  A_LBVS,
  A_LD8,
  A_LD16,
  A_LEA16,
  A_LSL,
  A_LSL8,
  A_LSR,
  A_LSR8,
  A_MUL,
  A_NEG,
  A_NEG8,
  A_NOP,
  A_OR8,
  A_ORCC,
  A_PSHS,
  A_PSHU,
  A_PULS,
  A_PULU,
  A_ROL,
  A_ROL8,
  A_ROR,
  A_ROR8,
  A_RTI,
  A_RTS,
  A_SBC8,
  A_SEX,
  A_ST8,
  A_ST16,
  A_SUB8,
  A_SUB16,
  A_SWI,
  A_SWI2,
  A_SWI3,
  A_SYNC,
  A_TFR,
  A_TST,
  A_TST8,
  A_MAX=A_TST8
};

static const char *asminstnames[] =
{
  "abx",
  "adc",
  "add",
  "add",
  "and",
  "andcc",
  "asl",
  "asl",
  "asr",
  "asr",
  "bcc",
  "bcs",
  "beq",
  "bge",
  "bgt",
  "bhi",
  "bhs",
  "bit",
  "ble",
  "blo",
  "bls",
  "blt",
  "bmi",
  "bne",
  "bpl",
  "bra",
  "brn",
  "bsr",
  "bvc",
  "bvs",
  "clr",
  "clr",
  "cmp",
  "cmp",
  "com",
  "com",
  "cwai",
  "daa",
  "dec",
  "dec",
  "eor",
  "exg",
  "inc",
  "inc",
  "jmp",
  "jsr",
  "lbcc",
  "lbcs",
  "lbeq",
  "lbge",
  "lbgt",
  "lbhi",
  "lbhs",
  "lble",
  "lblo",
  "lbls",
  "lblt",
  "lbmi",
  "lbne",
  "lbpl",
  "lbra",
  "lbrn",
  "lbsr",
  "lbvc",
  "lbvs",
  "ld",
  "ld",
  "lea",
  "lsl",
  "lsl",
  "lsr",
  "lsr",
  "mul",
  "neg",
  "neg",
  "nop",
  "or",
  "orcc",
  "pshs",
  "pshu",
  "puls",
  "pulu",
  "rol",
  "rol",
  "ror",
  "ror",
  "rti",
  "rts",
  "sbc",
  "sex",
  "st",
  "st",
  "sub",
  "sub",
  "swi",
  "swi2",
  "swi3",
  "sync",
  "tfr",
  "tst",
  "tst"
};

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

/** Code generator persistent data.
 */
static struct
{
  struct
  {
//    int last;
    int pushed;
    int param_offset;
    int offset;
  } stack;

/*
  struct
  {
  } calleeSaves;
*/

  bool omitFramePtr;
  int frameId;
  int receiveOffset;
  bool flushStatics;
  bool in_home;
  const char *lastFunctionName;
  iCode *current_iCode;
  bool preserveCarry;

  set *sendSet;

  struct
  {
    /** TRUE if the registers have already been saved. */
    bool saved;
  } saves;

  struct
  {
    allocTrace trace;
  } lines;

  struct
  {
    allocTrace aops;
  } trace;
} _G;

bool mc6809_regs_used_as_parms_in_calls_from_current_function[MAX_IDX + 1];
bool mc6809_symmParm_in_calls_from_current_function;
bool mc6809_regs_preserved_in_calls_from_current_function[MAX_IDX + 1];

static const char *aopGet (asmop *aop, int offset, bool bit16);

static struct asmop asmop_a, asmop_b, asmop_d, asmop_x, asmop_y, asmop_u;
static struct asmop *const ASMOP_A = &asmop_a;
static struct asmop *const ASMOP_B = &asmop_b;
static struct asmop *const ASMOP_D = &asmop_d;
static struct asmop *const ASMOP_X = &asmop_x;
static struct asmop *const ASMOP_Y = &asmop_y;
static struct asmop *const ASMOP_U = &asmop_u;

static asmop *asmopregs[] = { &asmop_a, &asmop_b, &asmop_d, &asmop_x, &asmop_y, &asmop_u };

void
mc6809_init_asmops (void)
{
  asmop_a.type = AOP_REG;
  asmop_a.size = 1;
  asmop_a.aopu.aop_reg[0] = regsMC6809 + A_IDX;
  memset (asmop_a.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_a.regs[A_IDX] = 0;

  asmop_b.type = AOP_REG;
  asmop_b.size = 1;
  asmop_b.aopu.aop_reg[0] = regsMC6809 + B_IDX;
  memset (asmop_b.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_b.regs[B_IDX] = 0;

  asmop_d.type = AOP_REG;
  asmop_d.size = 2;
  asmop_d.aopu.aop_reg[0] = regsMC6809 + D_IDX;
  memset (asmop_d.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_d.regs[B_IDX] = 0;
  asmop_d.regs[A_IDX] = 1;

  asmop_x.type = AOP_REG;
  asmop_x.size = 2;
  asmop_x.aopu.aop_reg[0] = regsMC6809 + X_IDX;
  memset (asmop_x.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_x.regs[XL_IDX] = 0;
  asmop_x.regs[XH_IDX] = 1;

  asmop_y.type = AOP_REG;
  asmop_y.size = 2;
  asmop_y.aopu.aop_reg[0] = regsMC6809 + Y_IDX;
  memset (asmop_y.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_y.regs[YL_IDX] = 0;
  asmop_y.regs[YH_IDX] = 1;

  asmop_u.type = AOP_REG;
  asmop_u.size = 2;
  asmop_u.aopu.aop_reg[0] = regsMC6809 + U_IDX;
  memset (asmop_u.regs, -1, MAX_ASMOP_IDX + 1);
  asmop_u.regs[UL_IDX] = 0;
  asmop_u.regs[UH_IDX] = 1;
}

static bool regalloc_dry_run;
static unsigned int regalloc_dry_run_cost;

static void
cost(unsigned int bytes, unsigned int cycles)
{
  regalloc_dry_run_cost += bytes;
}

static void
cost2(unsigned int bytes, unsigned int cycles_mc6809)
{
  regalloc_dry_run_cost += bytes;
}

/*-----------------------------------------------------------------*/
/* aopRS - asmop in register or on stack                           */
/*-----------------------------------------------------------------*/
static bool
aopRS (const asmop *aop)
{
  return (aop->type == AOP_REG || aop->type == AOP_STK);
}

/*-----------------------------------------------------------------*/
/* aopIsLitVal - asmop from offset is val                          */
/*-----------------------------------------------------------------*/
static bool
aopIsLitVal (const asmop *aop, int offset, int size, unsigned long long int val)
{
  wassert (size <= sizeof (unsigned long long int)); // Make sure we are not testing outside of argument val.

  for(; size; size--, offset++)
    {
      unsigned char b = val & 0xff;
      val >>= 8;

      // Leading zeroes
      if (aop->size <= offset && !b && aop->type != AOP_LIT)
        continue;

      if (aop->type != AOP_LIT)
        return (false);

      if (byteOfVal (aop->aopu.aop_lit, offset) != b)
        return (false);
    }

  return (true);
}

/*-----------------------------------------------------------------*/
/* aopInReg - asmop from offset in the register                    */
/*-----------------------------------------------------------------*/
static inline bool
aopInReg (const asmop *aop, int offset, short rIdx)
{}

/*-----------------------------------------------------------------*/
/* aopOnStack - asmop from offset on stack in consecutive memory   */
/*-----------------------------------------------------------------*/
static bool
aopOnStack (const asmop *aop, int offset, int size)
{
  if (!(aop->type == AOP_STK))
    return (false);

  if (offset + size > aop->size)
    return (false);

  return (true);
}

/* WARNING: This function is dangerous to use. It works literally:
   It will return true if ic the the last use of op, even if ic might
   be executed again, e.g. due to a loop. Most of the time you will want
   to use isPairDead(), or ic->rSurv instead of this function. */
static bool
isLastUse (const iCode * ic, operand * op)
{
  bitVect *uses = bitVectCopy (OP_USES (op));

  while (!bitVectIsZero (uses))
    {
      if (bitVectFirstBit (uses) == ic->key)
        {
          if (bitVectnBitsOn (uses) == 1)
            {
              return TRUE;
            }
          else
            {
              return FALSE;
            }
        }
      bitVectUnSetBit (uses, bitVectFirstBit (uses));
    }

  return FALSE;
}

static void
_tidyUp (char *buf)
{
  /* Clean up the line so that it is 'prettier' */
  /* If it is a label - can't do anything */
  if (!strchr (buf, ':'))
    {
      /* Change the first (and probably only) ' ' to a tab so
         everything lines up.
       */
      while (*buf)
        {
          if (*buf == ' ')
            {
              *buf = '\t';
              break;
            }
          buf++;
        }
    }
}

static void
_vemit2 (const char *szFormat, va_list ap)
{
  struct dbuf_s dbuf;
  char *buffer, *p, *nextp;

  dbuf_init (&dbuf, INITIAL_INLINEASM);

  dbuf_tvprintf (&dbuf, szFormat, ap);

  buffer = p = dbuf_detach_c_str (&dbuf);

  _tidyUp (p);

  /* Decompose multiline macros */
  while ((nextp = strchr (p, '\n')))
    {
      *nextp = '\0';
      emit_raw (p);
      p = nextp + 1;
    }

  emit_raw (p);

  dbuf_free (buffer);
}

static void
emitDebug (const char *szFormat, ...)
{
  if (!DISABLE_DEBUG && !regalloc_dry_run && options.verboseAsm)
    {
      va_list ap;

      va_start (ap, szFormat);
      _vemit2 (szFormat, ap);
      va_end (ap);
    }
}

static void
emit2 (const char *szFormat, ...)
{
  if (!regalloc_dry_run)
    {
      va_list ap;

      va_start (ap, szFormat);
      _vemit2 (szFormat, ap);
      va_end (ap);
    }
}


/*-----------------------------------------------------------------*/
/* mc6809_emitDebuggerSymbol - associate the current code location    */
/*   with a debugger symbol                                        */
/*-----------------------------------------------------------------*/
void
mc6809_emitDebuggerSymbol (const char *debugSym)
{
  genLine.lineElement.isDebug = 1;
  emit2 ("%s !equ .", debugSym);
  emit2 ("!global", debugSym);
  genLine.lineElement.isDebug = 0;
}

// Todo: Handle IY correctly.
static unsigned char
ld_cost (const asmop *op1, const asmop *op2)
{
  AOP_TYPE op1type = op1->type;
  AOP_TYPE op2type = op2->type;

  /* Costs are symmetric */
  if (op2type == AOP_REG || op2type == AOP_DUMMY)
    {
      const asmop *tmp = op1;
      op1 = op2;
      op2 = tmp;
      op1type = op1->type;
      op2type = op2->type;
    }

  switch (op1type)
    {
    case AOP_REG:
    case AOP_DUMMY:
      switch (op2type)
        {
        case AOP_REG:
        case AOP_DUMMY:
          return (1);
        case AOP_IMMD:
        case AOP_LIT:
          return (2);
        case AOP_STK:
          return (3);
        case AOP_IY:
        default:
          printf ("ld_cost op1: AOP_REG, op2: %d\n", (int) (op2type));
          wassert (0);
        }
    case AOP_IY:
      switch (op2type)
        {
        case AOP_IMMD:
        case AOP_LIT:
          return (8);
        case AOP_STK:
          return (10);
        case AOP_IY:
          return (16);
        default:
          printf ("ld_cost op1: AOP_IY, op2: %d\n", (int) (op2type));
          wassert (0);
        }
    case AOP_STK:
      switch (op2type)
        {
        case AOP_IMMD:
        case AOP_LIT:
          return (4);
        case AOP_STK:
          return (6);
        case AOP_IY:
          return (10);
        default:
          printf ("ld_cost op1: AOP_STK, op2: %d\n", (int) (op2type));
          wassert (0);
        }
    case AOP_LIT:
    case AOP_IMMD:
      wassertl (0, "Trying to assign a value to a literal");
      break;
    default:
      printf ("ld_cost op1: %d\n", (int) (op1type));
      wassert (0);
    }
  return (8);                   // Fallback
}

static unsigned char
op8_cost (const asmop * op2)
{
  switch (op2->type)
    {
    case AOP_REG:
    case AOP_DUMMY:
      return (1);
    case AOP_IMMD:
    case AOP_LIT:
      return (2);
    case AOP_STK:
      return (3);
    case AOP_IY:
      return (7);
    default:
      printf ("op8_cost op2: %d\n", (int) (op2->type));
      wassert (0);
    }
  return (8);                   // Fallback
}

static unsigned char
bit8_cost (const asmop * op1)
{
  switch (op1->type)
    {
    case AOP_REG:
    case AOP_DUMMY:
      return (2);
    case AOP_STK:
      return (4);
    case AOP_IY:
      return (8);
    default:
      printf ("bit8_cost op1: %d\n", (int) (op1->type));
      wassert (0);
    }
  return (8);                   //Fallback
}

static unsigned char
emit3Cost (enum asminst inst, const asmop *op1, int offset1, const asmop *op2, int offset2)
{}

static void
emit3_o (enum asminst inst, asmop *op1, int offset1, asmop *op2, int offset2)
{
  BUILD_BUG_ON((A_MAX+1)-(sizeof(asminstnames)/sizeof(asminstnames[0])));

  unsigned char cost;

  regalloc_dry_run_cost += emit3Cost (inst, op1, offset1, op2, offset2);
  if (regalloc_dry_run)
    return;

  cost = regalloc_dry_run_cost;
  if (!op1)
    emit2 ("%s", asminstnames[inst]);
  else if (!op2)
    emit2 ("%s %s", asminstnames[inst], aopGet (op1, offset1, FALSE));
  else
    {
      char *l = Safe_strdup (aopGet (op1, offset1, FALSE));
      //emit2("%s %s, %s", asminstnames[inst], aopGet(op1, offset1, FALSE), aopGet(op2, offset2, FALSE));
      emit2 ("%s %s, %s", asminstnames[inst], l, aopGet (op2, offset2, FALSE));
      Safe_free (l);
    }

  regalloc_dry_run_cost = cost;
  //emitDebug(";emit3_o cost: %d total so far: %d", (int)emit3Cost(inst, op1, offset1, op2, offset2), (int)cost);
}

static void
emit3 (enum asminst inst, asmop *op1, asmop *op2)
{
  emit3_o (inst, op1, 0, op2, 0);
}

static void
_emitMove (const char *to, const char *from)
{
}

static void
_emitMove3 (asmop *to, int to_offset, asmop *from, int from_offset)
{}

static void
_moveA (const char *moveFrom)
{
  _emitMove ("a", moveFrom);
}

/* Load aop into A */
static void
_moveA3 (asmop * from, int offset)
{
  _emitMove3 (ASMOP_A, 0, from, offset);
}

/*-----------------------------------------------------------------*/
/* newAsmop - creates a new asmOp                                  */
/*-----------------------------------------------------------------*/
static asmop *
newAsmop (short type)
{
  asmop *aop;

  aop = traceAlloc (&_G.trace.aops, Safe_alloc (sizeof (asmop)));
  aop->type = type;
  memset (aop->regs, -1, MAX_ASMOP_IDX + 1);
  return aop;
}

/*-----------------------------------------------------------------*/
/* aopForSym - for a true symbol                                   */
/*-----------------------------------------------------------------*/
static asmop *
aopForSym (const iCode * ic, symbol * sym, bool requires_a)
{
  asmop *aop;
  memmap *space;

  wassert (ic);
  wassert (sym);
  wassert (sym->etype);

  space = SPEC_OCLS (sym->etype);

  /* if already has one */
  if (sym->aop)
    {
      return sym->aop;
    }

  /* Assign depending on the storage class */
  if (sym->onStack || sym->iaccess)
    {
        {
          emitDebug ("; AOP_STK for %s", sym->rname);
          sym->aop = aop = newAsmop (AOP_STK);
        }

      aop->size = getSize (sym->type);
      aop->aopu.aop_stk = sym->stack;
      return aop;
    }

  /* special case for a function */
  if (IS_FUNC (sym->type))
    {
      sym->aop = aop = newAsmop (AOP_IMMD);
      aop->aopu.aop_immd = traceAlloc (&_G.trace.aops, Safe_strdup (sym->rname));
      aop->size = 2;
      return aop;
    }

  /* only remaining is far space */
  /* in which case DPTR gets the address */
  if (IY_RESERVED)
    {
    }
  else
    sym->aop = aop = newAsmop (AOP_IY);

  aop->size = getSize (sym->type);
  aop->aopu.aop_dir = sym->rname;

  /* if it is in code space */
  if (IN_CODESPACE (space))
    aop->code = 1;

  return aop;
}

/*-----------------------------------------------------------------*/
/* aopForRemat - rematerializes an object                          */
/*-----------------------------------------------------------------*/
static asmop *
aopForRemat (symbol *sym)
{
  iCode *ic = sym->rematiCode;
  asmop *aop = newAsmop (AOP_IMMD);
  int val = 0;
  struct dbuf_s dbuf;

  wassert(ic);

  for (;;)
    {
      if (ic->op == '+')
        {
          if (isOperandLiteral (IC_RIGHT (ic)))
            {
              val += (int) operandLitValue (IC_RIGHT (ic));
              ic = OP_SYMBOL (IC_LEFT (ic))->rematiCode;
            }
          else
            {
              val += (int) operandLitValue (IC_LEFT (ic));
              ic = OP_SYMBOL (IC_RIGHT (ic))->rematiCode;
            }
        }
      else if (ic->op == '-')
        {
          val -= (int) operandLitValue (IC_RIGHT (ic));
          ic = OP_SYMBOL (IC_LEFT (ic))->rematiCode;
        }
      else if (IS_CAST_ICODE (ic))
        {
          ic = OP_SYMBOL (IC_RIGHT (ic))->rematiCode;
        }
      else if (ic->op == ADDRESS_OF)
        {
          val += (int) operandLitValue (IC_RIGHT (ic));
          break;
        }
      else
        break;
    }

  dbuf_init (&dbuf, 128);
  if (val)
    {
      dbuf_printf (&dbuf, "(%s %c 0x%04x)", OP_SYMBOL (IC_LEFT (ic))->rname, val >= 0 ? '+' : '-', abs (val) & 0xffff);
    }
  else
    {
      dbuf_append_str (&dbuf, OP_SYMBOL (IC_LEFT (ic))->rname);
    }

  aop->aopu.aop_immd = traceAlloc (&_G.trace.aops, dbuf_detach_c_str (&dbuf));
  return aop;
}

/*-----------------------------------------------------------------*/
/* regsInCommon - two operands have some registers in common       */
/*-----------------------------------------------------------------*/
static bool
regsInCommon (operand * op1, operand * op2)
{
  symbol *sym1, *sym2;
  int i;

  /* if they have registers in common */
  if (!IS_SYMOP (op1) || !IS_SYMOP (op2))
    return FALSE;

  sym1 = OP_SYMBOL (op1);
  sym2 = OP_SYMBOL (op2);

  if (sym1->nRegs == 0 || sym2->nRegs == 0)
    return FALSE;

  for (i = 0; i < sym1->nRegs; i++)
    {
      int j;
      if (!sym1->regs[i])
        continue;

      for (j = 0; j < sym2->nRegs; j++)
        {
          if (!sym2->regs[j])
            continue;

          if (sym2->regs[j] == sym1->regs[i])
            return TRUE;
        }
    }

  return FALSE;
}

/*-----------------------------------------------------------------*/
/* operandsEqu - equivalent                                        */
/*-----------------------------------------------------------------*/
static bool
operandsEqu (operand * op1, operand * op2)
{
  symbol *sym1, *sym2;

  /* if they not symbols */
  if (!IS_SYMOP (op1) || !IS_SYMOP (op2))
    return FALSE;

  sym1 = OP_SYMBOL (op1);
  sym2 = OP_SYMBOL (op2);

  /* if both are itemps & one is spilt
     and the other is not then false */
  if (IS_ITEMP (op1) && IS_ITEMP (op2) && sym1->isspilt != sym2->isspilt)
    return FALSE;

  /* if they are the same */
  if (sym1 == sym2)
    return 1;

  if (sym1->rname[0] && sym2->rname[0] && strcmp (sym1->rname, sym2->rname) == 0)
    return 2;

  /* if left is a tmp & right is not */
  if (IS_ITEMP (op1) && !IS_ITEMP (op2) && sym1->isspilt && (sym1->usl.spillLoc == sym2))
    return 3;

  if (IS_ITEMP (op2) && !IS_ITEMP (op1) && sym2->isspilt && sym1->level > 0 && (sym2->usl.spillLoc == sym1))
    return 4;

  return FALSE;
}

/*-----------------------------------------------------------------*/
/* sameRegs - two asmops have the same registers                   */
/*-----------------------------------------------------------------*/
static bool
sameRegs (asmop * aop1, asmop * aop2)
{}

/*-----------------------------------------------------------------*/
/* aopOp - allocates an asmop for an operand  :                    */
/*-----------------------------------------------------------------*/
static void
aopOp (operand *op, const iCode *ic, bool result, bool requires_a)
{}

/*-----------------------------------------------------------------*/
/* freeAsmop - free up the asmop given to an operand               */
/*----------------------------------------------------------------*/
static void
freeAsmop (operand * op, asmop *aaop)
{
  asmop *aop;

  if (!op)
    aop = aaop;
  else
    aop = op->aop;

  if (!aop)
    return;

  if (aop->freed)
    goto dealloc;

  aop->freed = 1;

dealloc:
  /* all other cases just dealloc */
  if (op)
    {
      op->aop = NULL;
      if (IS_SYMOP (op))
        {
          OP_SYMBOL (op)->aop = NULL;
          /* if the symbol has a spill */
          if (SPIL_LOC (op))
            SPIL_LOC (op)->aop = NULL;
        }
    }

}

static bool
isLitWord (const asmop *aop)
{
  switch (aop->type)
    {
    case AOP_IMMD:
    case AOP_LIT:
      return TRUE;
    default:
      return FALSE;
    }
}

static const char *
aopGetLitWordLong (const asmop *aop, int offset, bool with_hash)
{
  static struct dbuf_s dbuf = { 0 };

  if (dbuf_is_initialized (&dbuf))
    {
      dbuf_set_length (&dbuf, 0);
    }
  else
    {
      dbuf_init (&dbuf, 128);
    }

  /* depending on type */
  switch (aop->type)
    {
    case AOP_IY:
    case AOP_IMMD:
      /* PENDING: for re-target */
      if (with_hash)
        {
          dbuf_tprintf (&dbuf, "!hashedstr + %d", aop->aopu.aop_immd, offset);
        }
      else if (offset == 0)
        {
          dbuf_tprintf (&dbuf, "%s", aop->aopu.aop_immd);
        }
      else
        {
          dbuf_tprintf (&dbuf, "%s + %d", aop->aopu.aop_immd, offset);
        }
      break;

    case AOP_LIT:
    {
      value *val = aop->aopu.aop_lit;
      /* if it is a float then it gets tricky */
      /* otherwise it is fairly simple */
      if (!IS_FLOAT (val->type))
        {
          unsigned long long v = ullFromVal (val);

          v >>= (offset * 8);

          dbuf_tprintf (&dbuf, with_hash ? "!immedword" : "!constword", (unsigned long) (v & 0xffffull));
        }
      else
        {
          union
          {
            float f;
            unsigned char c[4];
          }
          fl;
          unsigned int i;

          /* it is type float */
          fl.f = (float) floatFromVal (val);

#ifdef WORDS_BIGENDIAN
          i = fl.c[3 - offset] | (fl.c[3 - offset - 1] << 8);
#else
          i = fl.c[offset] | (fl.c[offset + 1] << 8);
#endif
          dbuf_tprintf (&dbuf, with_hash ? "!immedword" : "!constword", i);
        }
    }
    break;

    case AOP_REG:
    case AOP_STK:
    case AOP_DIR:
    case AOP_STR:
    case AOP_COND:
    case AOP_DUMMY:
      break;

    default:
      dbuf_destroy (&dbuf);
      fprintf (stderr, "aop->type: %d\n", aop->type);
      wassertl (0, "aopGetLitWordLong got unsupported aop->type");
      exit (0);
    }
  return dbuf_c_str (&dbuf);
}

static bool
isPtr (const char *s)
{
  if (!strcmp (s, "x"))
    return TRUE;
  if (!strcmp (s, "y"))
    return TRUE;
  if (!strcmp (s, "u"))
    return TRUE;
  return FALSE;
}

static void
spillCached (void)
{
}

/*----------------------------------------------------------*/
/* strtoul_asm: a wrapper to strtoul, which can also handle */
/* hex numbers with a $ prefix.                             */
/*----------------------------------------------------------*/
static unsigned long int
strtoul_asm (const char *nptr, char **endptr, int base)
{
  char *p = NULL;
  int i, flag = 0, len;
  unsigned long ret;

  if (nptr != NULL && (p = malloc ((len = strlen (nptr)) + 1 + 1)) != NULL)
    {
      memset (p, 0, len + 2);
      for (i = 0; i < len; i++)
        {
          if (!flag)
            if (isspace (nptr[i]))
              p[i] = nptr[i];
            else if (nptr[i] == '$')
              {
                p[i] = '0';
                p[i + 1] = 'x';
                flag = 1;
              }
            else
              break;
          else
            p[i + 1] = nptr[i];
        }
    }

  if (flag)
    ret = strtoul (p, endptr, base);
  else
    ret = strtoul (nptr, endptr, base);

  if (p)
    free (p);
  return ret;
}

static void
emitLabelSpill (symbol *tlbl)
{
  emitLabel (tlbl);
  spillCached ();
}

/*-----------------------------------------------------------------*/
/* aopGet - for fetching value of the aop                          */
/*-----------------------------------------------------------------*/
static const char *
aopGet (asmop *aop, int offset, bool bit16)
{
  static struct dbuf_s dbuf = { 0 };

  wassert_bt (!regalloc_dry_run);

  if (dbuf_is_initialized (&dbuf))
    {
      /* reuse the dynamically allocated buffer */
      dbuf_set_length (&dbuf, 0);
    }
  else
    {
      /* first time: initialize the dynamically allocated buffer */
      dbuf_init (&dbuf, 128);
    }

  /* offset is greater than size then zero */
  /* PENDING: this seems a bit screwed in some pointer cases. */
  if (offset > (aop->size - 1) && aop->type != AOP_LIT)
    {
      dbuf_tprintf (&dbuf, "!zero");
    }
  else
    {
      /* depending on type */
      switch (aop->type)
        {
        case AOP_DUMMY:
          dbuf_append_char (&dbuf, 'a');
          break;

        case AOP_IMMD:
          /* PENDING: re-target */
          if (bit16)
            dbuf_tprintf (&dbuf, "!immedword", aop->aopu.aop_immd);
          else
            {
              switch (offset)
                {
                case 2:
                  // dbuf_tprintf (&dbuf, "!bankimmeds", aop->aopu.aop_immd); Bank support not fully implemented yet.
                  dbuf_tprintf (&dbuf, "#0x00");
                  break;

                case 1:
                  dbuf_tprintf (&dbuf, "!msbimmeds", aop->aopu.aop_immd);
                  break;

                case 0:
                  dbuf_tprintf (&dbuf, "!lsbimmeds", aop->aopu.aop_immd);
                  break;

                default:
                  dbuf_tprintf (&dbuf, "#0x00");
                }
            }
          break;

        case AOP_DIR:
          break;

        case AOP_REG:
          break;

        case AOP_IY:
          dbuf_tprintf (&dbuf, "!*iyx", offset);
          break;

        case AOP_STK:
          if (_G.omitFramePtr)
            {
              if (aop->aopu.aop_stk >= 0)
                offset += _G.stack.param_offset;
              dbuf_tprintf (&dbuf, "!*ixx", offset);
            }
          else
            {
              if (aop->aopu.aop_stk >= 0)
                offset += _G.stack.param_offset;
              dbuf_tprintf (&dbuf, "!*ixx", aop->aopu.aop_stk + offset);
            }
          break;

        case AOP_COND:
          wassertl (0, "Tried to fetch from a bit variable");
          break;

        case AOP_LIT:
          dbuf_append_str (&dbuf, aopLiteral (aop->aopu.aop_lit, offset));
          break;

        case AOP_STR:
          aop->coff = offset;
          dbuf_append_str (&dbuf, aop->aopu.aop_str[offset]);
          break;

        default:
          dbuf_destroy (&dbuf);
          fprintf (stderr, "aop->type: %d\n", aop->type);
          wassertl (0, "aopGet got unsupported aop->type");
          exit (0);
        }
    }
  return dbuf_c_str (&dbuf);
}

static bool
isRegString (const char *s)
{
  if (!strcmp (s, "a") || !strcmp (s, "b") || !strcmp (s, "d"))
    return TRUE;
  return FALSE;
}

static bool
isConstantString (const char *s)
{
  /* This is a bit of a hack... */
  return (*s == '#' || *s == '$');
}

#define AOP(op) op->aop
#define AOP_TYPE(op) AOP(op)->type
#define AOP_SIZE(op) AOP(op)->size

static bool
canAssignToPtr (const char *s)
{
  if (isRegString (s))
    return TRUE;
  if (isConstantString (s))
    return TRUE;
  return FALSE;
}

static bool
canAssignToPtr3 (const asmop *aop)
{
  if (aop->type == AOP_REG)
    return (TRUE);
  if (aop->type == AOP_IMMD || aop->type == AOP_LIT)
    return (TRUE);
  return (FALSE);
}

/*-----------------------------------------------------------------*/
/* aopPut - puts a string for a aop                                */
/*-----------------------------------------------------------------*/
static void
aopPut (asmop *aop, const char *s, int offset)
{
  struct dbuf_s dbuf;

  wassert (!regalloc_dry_run);

  if (aop->size && offset > (aop->size - 1))
    {
      werror_bt (E_INTERNAL_ERROR, __FILE__, __LINE__, "aopPut got offset > aop->size");
      exit (0);
    }

  // PENDING
  dbuf_init (&dbuf, 128);
  dbuf_tprintf (&dbuf, s);
  s = dbuf_c_str (&dbuf);

  /* will assign value to value */
  /* depending on where it is of course */
  switch (aop->type)
    {
    case AOP_DUMMY:
      _moveA (s);               /* in case s is volatile */
      break;

    case AOP_DIR:
      break;

    case AOP_REG:
      break;

    case AOP_IY:
      break;

    case AOP_STK:
      break;

    case AOP_COND:
      /* if bit variable */
        {
          /* In bit space but not in C - cant happen */
          wassertl (0, "Tried to write into a bit variable");
        }
      break;

    case AOP_STR:
      break;

    default:
      dbuf_destroy (&dbuf); fprintf (stderr, "AOP_DIR: %d\n",AOP_DIR);
      fprintf (stderr, "aop->type: %d\n", aop->type);
      werror (E_INTERNAL_ERROR, __FILE__, __LINE__, "aopPut got unsupported aop->type");
      exit (0);
    }
  dbuf_destroy (&dbuf);
}

// Move, but try not to. Cannot use xor to zero, since xor resets the carry flag.
static void
cheapMove (asmop *to, int to_offset, asmop *from, int from_offset, bool a_dead)
{}

/*-----------------------------------------------------------------*/
/* genCopyStack - Copy the value - stack to stack only             */
/*-----------------------------------------------------------------*/
static void
genCopyStack (asmop *result, int roffset, asmop *source, int soffset, int n, bool *assigned, int *size, bool a_free, bool hl_free, bool really_do_it_now)
{
  for (int i = 0; i < n;)
    {
      if (assigned[i])
        {
          i++;
          continue;
        }

      if (!aopOnStack (result, roffset + i, 1) || !aopOnStack (source, soffset + i, 1))
        {
          i++;
          continue;
        }

      if (a_free || really_do_it_now)
        {
          cheapMove (result, roffset + i, source, soffset + i, a_free);
          assigned[i] = true;
          (*size)--;
          i++;
          continue;
        }

       i++;
    }

  wassertl_bt (*size >= 0, "genCopyStack() copied more than there is to be copied.");
}

/*-----------------------------------------------------------------*/
/* genCopy - Copy the value from one reg/stk asmop to another      */
/*-----------------------------------------------------------------*/
static void
genCopy (asmop *result, int roffset, asmop *source, int soffset, int sizex, bool a_dead, bool hl_dead)
{}

/*-----------------------------------------------------------------*/
/* genMove_o - Copy part of one asmop to another                   */
/*-----------------------------------------------------------------*/
static void
genMove_o (asmop *result, int roffset, asmop *source, int soffset, int size, bool a_dead_global, bool hl_dead_global)
{}

/*-----------------------------------------------------------------*/
/* genMove - Copy the value from one asmop to another              */
/*-----------------------------------------------------------------*/
static void
genMove (asmop *result, asmop *source, bool a_dead, bool hl_dead)
{
  genMove_o (result, 0, source, 0, result->size, a_dead, hl_dead);
}

/*-----------------------------------------------------------------*/
/* getDataSize - get the operand data size                         */
/*-----------------------------------------------------------------*/
static int
getDataSize (operand * op)
{
  int size;
  size = AOP_SIZE (op);
  if (size == 3)
    {
      /* pointer */
      wassertl (0, "Somehow got a three byte data pointer");
    }
  return size;
}

/*--------------------------------------------------------------------------*/
/* adjustStack - Adjust the stack pointer by n bytes.                       */
/*--------------------------------------------------------------------------*/
static void
adjustStack (int n, bool af_free, bool bc_free, bool hl_free, bool iy_free)
{}

/*-----------------------------------------------------------------*/
/* movLeft2Result - move byte from left to result                  */
/*-----------------------------------------------------------------*/
static void
movLeft2Result (operand *left, int offl, operand *result, int offr, int sign)
{
  if (!sameRegs (AOP (left), AOP (result)) || (offl != offr))
    {
      if (!sign)
        cheapMove (AOP (result), offr, AOP (left), offl, true);
      else
        {
          if (getDataSize (left) == offl + 1)
            {
              cheapMove (ASMOP_A, 0, AOP (left), offl, true);
              cheapMove (AOP (result), offr, ASMOP_A, 0, true);
            }
        }
    }
}

/** Put Acc into a register set
 */
static void
outAcc (operand * result)
{}

/** Take the value in carry and put it into a register
 */
static void
outBitC (operand * result)
{}

/*-----------------------------------------------------------------*/
/* toBoolean - emit code for or a,operator(sizeop)                 */
/*-----------------------------------------------------------------*/
static void
_toBoolean (const operand *oper, bool needflag)
{}

/*-----------------------------------------------------------------*/
/* castBoolean - emit code for casting operand to boolean in a     */
/*-----------------------------------------------------------------*/
static void
_castBoolean (const operand *right)
{}

/* Shuffle src reg array into dst reg array. */
static void
regMove (const short *dst, const short *src, size_t n, bool preserve_a)
{}

/*-----------------------------------------------------------------*/
/* genNot - generate code for ! operation                          */
/*-----------------------------------------------------------------*/
static void
genNot (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genCpl - generate code for complement                           */
/*-----------------------------------------------------------------*/
static void
genCpl (const iCode *ic)
{}

static void
_mc6809_emitAddSubLongLong (const iCode * ic, asmop * left, asmop * right, bool isAdd)
{}

static void
_mc6809_emitAddSubLong (const iCode * ic, bool isAdd)
{
  _mc6809_emitAddSubLongLong (ic, AOP (IC_LEFT (ic)), AOP (IC_RIGHT (ic)), isAdd);
}

/*-----------------------------------------------------------------*/
/* assignResultValue -               */
/*-----------------------------------------------------------------*/
static void
assignResultValue (operand * oper)
{}

/* Pop saved regs from stack, taking care not to destroy result */
static void
restoreRegs (bool iy, bool de, bool bc, bool hl, const operand *result)
{}

static void
_saveRegsForCall (const iCode * ic, bool dontsaveIY)
{}

/*-----------------------------------------------------------------*/
/* genIpush - genrate code for pushing this gets a little complex  */
/*-----------------------------------------------------------------*/
static void
genIpush (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genIpop - recover the registers: can happen only for spilling   */
/*-----------------------------------------------------------------*/
static void
genIpop (const iCode * ic)
{}

/* This is quite unfortunate */
static void
setArea (int inHome)
{
  /*
     static int lastArea = 0;

     if (_G.in_home != inHome) {
     if (inHome) {
     const char *sz = port->mem.code_name;
     port->mem.code_name = "HOME";
     emit2("!area", CODE_NAME);
     port->mem.code_name = sz;
     }
     else
     emit2("!area", CODE_NAME); */
  _G.in_home = inHome;
  //    }
}

static bool
isInHome (void)
{
  return _G.in_home;
}

/** Emit the code for a register parameter
 */
static void genSend (const iCode *ic)
{}

/** Emit the code for a call statement
 */
static void
genCall (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* resultRemat - result  is rematerializable                       */
/*-----------------------------------------------------------------*/
static int
resultRemat (const iCode * ic)
{
  if (SKIP_IC (ic) || ic->op == IFX)
    return 0;

  if (IC_RESULT (ic) && IS_ITEMP (IC_RESULT (ic)))
    {
      const symbol *sym = OP_SYMBOL_CONST (IC_RESULT (ic));
      if (sym->remat && !POINTER_SET (ic) && sym->isspilt)
        return 1;
    }

  return 0;
}

/*-----------------------------------------------------------------*/
/* genFunction - generated code for function entry                 */
/*-----------------------------------------------------------------*/
static void
genFunction (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genEndFunction - generates epilogue for functions               */
/*-----------------------------------------------------------------*/
static void
genEndFunction (iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genRet - generate code for return statement                     */
/*-----------------------------------------------------------------*/
static void
genRet (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genLabel - generates a label                                    */
/*-----------------------------------------------------------------*/
static void
genLabel (const iCode * ic)
{
  /* special case never generate */
  if (IC_LABEL (ic) == entryLabel)
    return;

  emitLabelSpill (IC_LABEL (ic));
}

/*-----------------------------------------------------------------*/
/* genGoto - generates a ljmp                                      */
/*-----------------------------------------------------------------*/
static void
genGoto (const iCode * ic)
{}


/*-----------------------------------------------------------------*/
/* genPlusIncr :- does addition with increment if possible         */
/*-----------------------------------------------------------------*/
static bool
genPlusIncr (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* outBitAcc - output a bit in acc                                 */
/*-----------------------------------------------------------------*/
static void
outBitAcc (operand * result)
{
  symbol *tlbl = regalloc_dry_run ? 0 : newiTempLabel (0);
  /* if the result is a bit */
  if (AOP_TYPE (result) == AOP_COND)
    {
      wassertl (0, "Tried to write A into a bit");
    }
  else
    {
    }
}

static bool
couldDestroyCarry (const asmop *aop)
{
  if (aop)
    {
      if (aop->type == AOP_IY)
        {
          return TRUE;
        }
    }
  return FALSE;
}

static void
setupToPreserveCarry (asmop *result, asmop *left, asmop *right)
{
  wassert (left && right);

    {
      if (couldDestroyCarry (right) && couldDestroyCarry (result))
        {
          /* check result again, in case right == result */
          if (couldDestroyCarry (result))
            {
            }
        }
      else if (couldDestroyCarry (right))
        {
        }
      else if (couldDestroyCarry (result))
        {
        }
    }
}

/*-----------------------------------------------------------------*/
/* genPlus - generates code for addition                           */
/*-----------------------------------------------------------------*/
static void
genPlus (iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genSubDec :- does subtraction with decrement if possible        */
/*-----------------------------------------------------------------*/
static bool
genMinusDec (const iCode *ic, asmop *result, asmop *left, asmop *right)
{
  unsigned int icount;
  unsigned int size = getDataSize (IC_RESULT (ic));

  /* will try to generate a decrement */
  /* if the right side is not a literal we cannot */
  if (right->type != AOP_LIT)
    return false;

  /* if the literal value of the right hand side
     is greater than 4 then it is not worth it */
  if ((icount = (unsigned int) ulFromVal (right->aopu.aop_lit)) > 2)
    return false;

  size = getDataSize (IC_RESULT (ic));

  /* if the sizes are greater than 1 then we cannot */
  if (result->size > 1 || left->size > 1)
    return false;

  /* we can if the aops of the left & result match or if they are in
     registers and the registers are the same */
  if (sameRegs (left, result))
    {
      while (icount--)
        emit3 (A_DEC, result, 0);
      return true;
    }

  if (result->type == AOP_REG)
    {
      cheapMove (result, 0, left, 0, true);
      while (icount--)
        emit3 (A_DEC, result, 0);
      return true;
    }

  return false;
}

/*-----------------------------------------------------------------*/
/* genSub - generates code for subtraction                       */
/*-----------------------------------------------------------------*/
static void
genSub (const iCode *ic, asmop *result, asmop *left, asmop *right)
{}

/*-----------------------------------------------------------------*/
/* genMinus - generates code for subtraction                       */
/*-----------------------------------------------------------------*/
static void
genMinus (const iCode *ic)
{
  aopOp (IC_LEFT (ic), ic, FALSE, FALSE);
  aopOp (IC_RIGHT (ic), ic, FALSE, FALSE);
  aopOp (IC_RESULT (ic), ic, TRUE, FALSE);

  genSub (ic, AOP (IC_RESULT (ic)), AOP (IC_LEFT (ic)), AOP (IC_RIGHT (ic)));

  _G.preserveCarry = FALSE;
  freeAsmop (IC_LEFT (ic), NULL);
  freeAsmop (IC_RIGHT (ic), NULL);
  freeAsmop (IC_RESULT (ic), NULL);
}

/*-----------------------------------------------------------------*/
/* genUminusFloat - unary minus for floating points                */
/*-----------------------------------------------------------------*/
static void
genUminusFloat (operand *op, operand *result)
{}

/*-----------------------------------------------------------------*/
/* genUminus - unary minus code generation                         */
/*-----------------------------------------------------------------*/
static void
genUminus (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genMultOneChar - generates code for unsigned 8x8 multiplication */
/*-----------------------------------------------------------------*/
static void
genMultOneChar (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genMult - generates code for multiplication                     */
/*-----------------------------------------------------------------*/
static void
genMult (iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genDiv - generates code for division                            */
/*-----------------------------------------------------------------*/
static void
genDiv (const iCode * ic)
{
  /* Shouldn't occur - all done through function calls */
  wassertl (0, "Division is handled through support function calls");
}

/*-----------------------------------------------------------------*/
/* genMod - generates code for division                            */
/*-----------------------------------------------------------------*/
static void
genMod (const iCode * ic)
{
  /* Shouldn't occur - all done through function calls */
  wassert (0);
}

/*-----------------------------------------------------------------*/
/* genIfxJump :- will create a jump depending on the ifx           */
/*-----------------------------------------------------------------*/
static void
genIfxJump (iCode * ic, char *jval)
{}

/** Generic compare for > or <
 */
static void
genCmp (operand * left, operand * right, operand * result, iCode * ifx, int sign, const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genCmpGt :- greater than comparison                             */
/*-----------------------------------------------------------------*/
static void
genCmpGt (iCode * ic, iCode * ifx)
{}

/*-----------------------------------------------------------------*/
/* genCmpLt - less than comparisons                                */
/*-----------------------------------------------------------------*/
static void
genCmpLt (iCode * ic, iCode * ifx)
{}

/*-----------------------------------------------------------------*/
/* gencjne - compare and jump if not equal                         */
/*-----------------------------------------------------------------*/
static void
gencjne (operand * left, operand * right, symbol * lbl, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genCmpEq - generates code for equal to                          */
/*-----------------------------------------------------------------*/
static void
genCmpEq (iCode * ic, iCode * ifx)
{}

/*-----------------------------------------------------------------*/
/* genAndOp - for && operation                                     */
/*-----------------------------------------------------------------*/
static void
genAndOp (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genOrOp - for || operation                                      */
/*-----------------------------------------------------------------*/
static void
genOrOp (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* isLiteralBit - test if lit == 2^n                               */
/*-----------------------------------------------------------------*/
static int
isLiteralBit (unsigned long lit)
{
  unsigned long pw[32] =
  {
    1L, 2L, 4L, 8L, 16L, 32L, 64L, 128L,
    0x100L, 0x200L, 0x400L, 0x800L,
    0x1000L, 0x2000L, 0x4000L, 0x8000L,
    0x10000L, 0x20000L, 0x40000L, 0x80000L,
    0x100000L, 0x200000L, 0x400000L, 0x800000L,
    0x1000000L, 0x2000000L, 0x4000000L, 0x8000000L,
    0x10000000L, 0x20000000L, 0x40000000L, 0x80000000L
  };
  int idx;

  for (idx = 0; idx < 32; idx++)
    if (lit == pw[idx])
      return idx;
  return -1;
}

/*-----------------------------------------------------------------*/
/* jmpTrueOrFalse -                                                */
/*-----------------------------------------------------------------*/
static void
jmpTrueOrFalse (iCode * ic, symbol * tlbl)
{}

/*-----------------------------------------------------------------*/
/* genAnd  - code for and                                          */
/*-----------------------------------------------------------------*/
static void
genAnd (const iCode * ic, iCode * ifx)
{}

/*-----------------------------------------------------------------*/
/* genOr  - code for or                                            */
/*-----------------------------------------------------------------*/
static void
genOr (const iCode * ic, iCode * ifx)
{}

/*-----------------------------------------------------------------*/
/* genXor - code for xclusive or                                   */
/*-----------------------------------------------------------------*/
static void
genXor (const iCode *ic, iCode *ifx)
{}

/*-----------------------------------------------------------------*/
/* genRRC - rotate right with carry                                */
/*-----------------------------------------------------------------*/
static void
genRRC (const iCode * ic)
{
  wassert (0);
}

/*-----------------------------------------------------------------*/
/* genRLC - generate code for rotate left with carry               */
/*-----------------------------------------------------------------*/
static void
genRLC (const iCode * ic)
{
  wassert (0);
}

/*-----------------------------------------------------------------*/
/* genGetHbit - generates code get highest order bit               */
/*-----------------------------------------------------------------*/
static void
genGetHbit (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genGetAbit - generates code get a single bit                    */
/*-----------------------------------------------------------------*/
static void
genGetAbit (const iCode * ic)
{
  wassert (0);
}

static void
emitRsh2 (asmop * aop, int size, int is_signed)
{}

/*-----------------------------------------------------------------*/
/* shiftR2Left2Result - shift right two bytes from left to result  */
/*-----------------------------------------------------------------*/
static void
shiftR2Left2Result (const iCode *ic, operand *left, int offl, operand *result, int offr, int shCount, int is_signed)
{}

/*-----------------------------------------------------------------*/
/* shiftL2Left2Result - shift left two bytes from left to result   */
/*-----------------------------------------------------------------*/
static void
shiftL2Left2Result (operand *left, operand *result, int shCount, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* AccRol - rotate left accumulator by known count                 */
/*-----------------------------------------------------------------*/
static void
AccRol (int shCount)
{}

/*-----------------------------------------------------------------*/
/* AccLsh - left shift accumulator by known count                  */
/*-----------------------------------------------------------------*/
static void
AccLsh (unsigned int shCount)
{}

/*-----------------------------------------------------------------*/
/* shiftL1Left2Result - shift left one byte from left to result    */
/*-----------------------------------------------------------------*/
static void
shiftL1Left2Result (operand *left, int offl, operand *result, int offr, unsigned int shCount, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genlshTwo - left shift two bytes by known amount                */
/*-----------------------------------------------------------------*/
static void
genlshTwo (operand *result, operand *left, unsigned int shCount, const iCode *ic)
{}

/*------------------------------------------------------------------*/
/* genLeftShiftLiteral - left shifting by known count for size <= 2 */
/*------------------------------------------------------------------*/
static void
genLeftShiftLiteral (operand *left, operand *right, operand *result, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genLeftShift - generates code for left shifting                 */
/*-----------------------------------------------------------------*/
static void
genLeftShift (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* AccRsh - right shift accumulator by known count                 */
/*-----------------------------------------------------------------*/
static void
AccRsh (int shCount)
{}

/*-----------------------------------------------------------------*/
/* genrshOne - right shift one byte by known amount                */
/*-----------------------------------------------------------------*/
static void
genrshOne (operand *result, operand *left, int shCount, int is_signed, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* shiftR1Left2Result - shift right one byte from left to result   */
/*-----------------------------------------------------------------*/
static void
shiftR1Left2Result (operand *left, int offl, operand *result, int offr, int shCount, int sign)
{}

/*-----------------------------------------------------------------*/
/* genrshTwo - right shift two bytes by known amount               */
/*-----------------------------------------------------------------*/
static void
genrshTwo (const iCode * ic, operand * result, operand * left, int shCount, int sign)
{}

/*-----------------------------------------------------------------*/
/* genRightShiftLiteral - right shifting by known count              */
/*-----------------------------------------------------------------*/
static void
genRightShiftLiteral (operand * left, operand * right, operand * result, const iCode *ic, int sign)
{}

/*-----------------------------------------------------------------*/
/* genRightShift - generate code for right shifting                */
/*-----------------------------------------------------------------*/
static void
genRightShift (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* unpackMaskA - generate masking code for unpacking last byte     */
/* of bitfiled. And mask for unsigned, sign extension for signed.  */
/*-----------------------------------------------------------------*/
static void
unpackMaskA(sym_link *type, int len)
{}

/*-----------------------------------------------------------------*/
/* genUnpackBits - generates code for unpacking bits               */
/*-----------------------------------------------------------------*/
static void
genUnpackBits (operand * result, int pair, const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genPointerGet - generate code for pointer get                   */
/*-----------------------------------------------------------------*/
static void
genPointerGet (const iCode *ic)
{}

static bool
isRegOrLit (asmop * aop)
{
  if (aop->type == AOP_REG || aop->type == AOP_LIT || aop->type == AOP_IMMD)
    return true;
  return false;
}


/*-----------------------------------------------------------------*/
/* genPackBits - generates code for packed bit storage             */
/*-----------------------------------------------------------------*/
static void
genPackBits (sym_link * etype, operand * right, int pair, const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genPointerSet - stores the value into a pointer location        */
/*-----------------------------------------------------------------*/
static void
genPointerSet (iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genIfx - generate code for Ifx statement                        */
/*-----------------------------------------------------------------*/
static void
genIfx (iCode *ic, iCode *popIc)
{}

/*-----------------------------------------------------------------*/
/* genAddrOf - generates code for address of                       */
/*-----------------------------------------------------------------*/
static void
genAddrOf (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genAssign - generate code for assignment                        */
/*-----------------------------------------------------------------*/
static void
genAssign (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genJumpTab - generate code for jump table                       */
/*-----------------------------------------------------------------*/
static void
genJumpTab (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genCast - gen code for casting                                  */
/*-----------------------------------------------------------------*/
static void
genCast (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genReceive - generate code for a receive iCode                  */
/*-----------------------------------------------------------------*/
static void
genReceive (const iCode *ic)
{}

/*-----------------------------------------------------------------*/
/* genDummyRead - generate code for dummy read of volatiles        */
/*-----------------------------------------------------------------*/
static void
genDummyRead (const iCode * ic)
{
  operand *op;
  int size, offset;

  op = IC_RIGHT (ic);
  if (op && IS_SYMOP (op))
    {
      aopOp (op, ic, FALSE, FALSE);

      /* general case */
      size = AOP_SIZE (op);
      offset = 0;

      while (size--)
        {
          _moveA3 (AOP (op), offset);
          offset++;
        }

      freeAsmop (op, NULL);
    }

  op = IC_LEFT (ic);
  if (op && IS_SYMOP (op))
    {
      aopOp (op, ic, FALSE, FALSE);

      /* general case */
      size = AOP_SIZE (op);
      offset = 0;

      while (size--)
        {
          _moveA3 (AOP (op), offset);
          offset++;
        }

      freeAsmop (op, NULL);
    }
}

/*-----------------------------------------------------------------*/
/* genCritical - generate code for start of a critical sequence    */
/*-----------------------------------------------------------------*/
static void
genCritical (const iCode * ic)
{}

/*-----------------------------------------------------------------*/
/* genEndCritical - generate code for end of a critical sequence   */
/*-----------------------------------------------------------------*/
static void
genEndCritical (const iCode * ic)
{}

static void
setupForMemcpy (const iCode *ic, const operand *to, const operand *from, const operand *count)
{}

static void
setupForMemset (const iCode *ic, const operand *dst, const operand *c, bool direct_c)
{}


/*--------------------------------------------------------------------------------------------*/
/* genMC6809iCode - generate code for MC6809 based controllers for a single iCode instruction */
/*--------------------------------------------------------------------------------------------*/
static void
genMC6809iCode (iCode * ic)
{
  genLine.lineElement.ic = ic;

  /* if the result is marked as
     spilt and rematerializable or code for
     this has already been generated then
     do nothing */
  if (resultRemat (ic) || ic->generated)
    return;

  /* depending on the operation */
  switch (ic->op)
    {
    case '!':
      emitDebug ("; genNot");
      genNot (ic);
      break;

    case '~':
      emitDebug ("; genCpl");
      genCpl (ic);
      break;

    case UNARYMINUS:
      emitDebug ("; genUminus");
      genUminus (ic);
      break;

    case IPUSH:
      emitDebug ("; genIpush");
      genIpush (ic);
      break;

    case IPOP:
      /* IPOP happens only when trying to restore a
         spilt live range, if there is an ifx statement
         following this pop then the if statement might
         be using some of the registers being popped which
         would destroy the contents of the register so
         we need to check for this condition and handle it */
      if (ic->next && ic->next->op == IFX && regsInCommon (IC_LEFT (ic), IC_COND (ic->next)))
        {
          emitDebug ("; genIfx");
          genIfx (ic->next, ic);
        }
      else
        {
          emitDebug ("; genIpop");
          genIpop (ic);
        }
      break;

    case CALL:
    case PCALL:
      emitDebug ("; genCall");
      genCall (ic);
      break;

    case FUNCTION:
      emitDebug ("; genFunction");
      genFunction (ic);
      break;

    case ENDFUNCTION:
      emitDebug ("; genEndFunction");
      genEndFunction (ic);
      break;

    case RETURN:
      emitDebug ("; genRet");
      genRet (ic);
      break;

    case LABEL:
      emitDebug ("; genLabel");
      genLabel (ic);
      break;

    case GOTO:
      emitDebug ("; genGoto");
      genGoto (ic);
      break;

    case '+':
      emitDebug ("; genPlus");
      genPlus (ic);
      break;

    case '-':
      emitDebug ("; genMinus");
      genMinus (ic);
      break;

    case '*':
      emitDebug ("; genMult");
      genMult (ic);
      break;

    case '/':
      emitDebug ("; genDiv");
      genDiv (ic);
      break;

    case '%':
      emitDebug ("; genMod");
      genMod (ic);
      break;

    case '>':
      emitDebug ("; genCmpGt");
      genCmpGt (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case '<':
      emitDebug ("; genCmpLt");
      genCmpLt (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case LE_OP:
    case GE_OP:
    case NE_OP:

      /* note these two are xlated by algebraic equivalence
         during parsing SDCC.y */
      werror (E_INTERNAL_ERROR, __FILE__, __LINE__, "got '>=' or '<=' shouldn't have come here");
      break;

    case EQ_OP:
      emitDebug ("; genCmpEq");
      genCmpEq (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case AND_OP:
      emitDebug ("; genAndOp");
      genAndOp (ic);
      break;

    case OR_OP:
      emitDebug ("; genOrOp");
      genOrOp (ic);
      break;

    case '^':
      emitDebug ("; genXor");
      genXor (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case '|':
      emitDebug ("; genOr");
      genOr (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case BITWISEAND:
      emitDebug ("; genAnd");
      genAnd (ic, ifxForOp (IC_RESULT (ic), ic));
      break;

    case INLINEASM:
      emitDebug ("; genInline");
      genInline (ic);
      break;

    case RRC:
      emitDebug ("; genRRC");
      genRRC (ic);
      break;

    case RLC:
      emitDebug ("; genRLC");
      genRLC (ic);
      break;

    case GETHBIT:
      emitDebug ("; genGetHbit");
      genGetHbit (ic);
      break;

    case GETABIT:
      emitDebug ("; genGetAbit");
      genGetAbit (ic);
      break;

    case LEFT_OP:
      emitDebug ("; genLeftShift");
      genLeftShift (ic);
      break;

    case RIGHT_OP:
      emitDebug ("; genRightShift");
      genRightShift (ic);
      break;

    case GET_VALUE_AT_ADDRESS:
      emitDebug ("; genPointerGet");
      genPointerGet (ic);
      break;

    case '=':

      if (POINTER_SET (ic))
        {
          emitDebug ("; genAssign (pointer)");
          genPointerSet (ic);
        }
      else
        {
          emitDebug ("; genAssign");
          genAssign (ic);
        }
      break;

    case IFX:
      emitDebug ("; genIfx");
      genIfx (ic, NULL);
      break;

    case ADDRESS_OF:
      emitDebug ("; genAddrOf");
      genAddrOf (ic);
      break;

    case JUMPTABLE:
      emitDebug ("; genJumpTab");
      genJumpTab (ic);
      break;

    case CAST:
      emitDebug ("; genCast");
      genCast (ic);
      break;

    case RECEIVE:
      emitDebug ("; genReceive");
      genReceive (ic);
      break;

    case SEND:
        {
          emitDebug ("; genSend");
          genSend (ic);
        }
      break;

    case DUMMY_READ_VOLATILE:
      emitDebug ("; genDummyRead");
      genDummyRead (ic);
      break;

    case CRITICAL:
      emitDebug ("; genCritical");
      genCritical (ic);
      break;

    case ENDCRITICAL:
      emitDebug ("; genEndCritical");
      genEndCritical (ic);
      break;

    default:
      ;
    }
}

unsigned char
dryMC6809iCode (iCode * ic)
{}

#ifdef DEBUG_DRY_COST
static void
dryMC6809Code (iCode * lic)
{
  iCode *ic;

  for (ic = lic; ic; ic = ic->next)
    if (ic->op != FUNCTION && ic->op != ENDFUNCTION && ic->op != LABEL && ic->op != GOTO && ic->op != INLINEASM)
      printf ("; iCode %d total cost: %d\n", ic->key, (int) (dryMC6809iCode (ic)));
}
#endif

/*---------------------------------------------------------------------------------------*/
/* genMC6809Code - generate code for MC6809 based controllers for a block of intructions */
/*---------------------------------------------------------------------------------------*/
void
genMC6809Code (iCode * lic)
{}
