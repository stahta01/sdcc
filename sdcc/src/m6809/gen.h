/*-------------------------------------------------------------------------
  gen.h - header file for code generation for M6809

  Primarily based on the stm8 port with other changes from z80 and hc08 ports.

             Written By -  Philipp Krause . pkk@spth.de (2012)
   M6809 conversion By  -  Tim Stahlhut . stahta01@gmail.com (2020)          

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

#ifndef M6809GEN_H
#define M6809GEN_H 1

#include "reg_index.h"

typedef enum
{
  AOP_INVALID,
  /* Is a literal */
  AOP_LIT = 1,
  /* Is in a register */
  AOP_REG,
  /* Should be placed on the stack can happen only for the result */
  AOP_STK,
  /* Is a stack location */
  AOP_STL,
  /* Is an immediate value */
  AOP_IMMD,
  /* Is in direct space */
  AOP_DIR,
  /* Is in the extended stack pointer (IU on the M6809) */
  AOP_EXSTK,
  /* Read undefined, discard writes */
  AOP_DUMMY,
  /* Bit value in the condition register */
  AOP_COND
}
AOP_TYPE;

/* asmop_byte: A type for the location a single byte
   of an operand can be in */
typedef struct asmop_byte
{
  bool in_reg;
  union
  {
    reg_info *reg;    /* Register this byte is in. */
    long int stk; /* Stack offset for this byte. */
  } byteu;
} asmop_byte;

/* asmop: A homogenised type for all the different
   spaces an operand can be in */
typedef struct asmop
{
  AOP_TYPE type;
  short size;
  union
  {
    value *aop_lit;
    reg_info *aop_reg[4];       /* array of registers */
    struct
      {
        char *immd;
        int immd_off;
      };
    int stk_off;
    char *aop_dir;
    asmop_byte bytes[8];
  } aopu;
  signed char regs[MAX_TREE_DECOMP_IDX + 1]; // Byte of this aop that is in the register. -1 if no byte of this aop is in the reg.
}
asmop;

void genM6809Code (iCode *);
void m6809_emitDebuggerSymbol (const char *);

extern bool m6809_assignment_optimal;
extern long int m6809_call_stack_size;
extern bool m6809_extend_stack;

#endif

