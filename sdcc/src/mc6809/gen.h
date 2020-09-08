/*-------------------------------------------------------------------------
  mc6809/gen.h - header file for code generation for MC6809

             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)

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

#ifndef MC6809GEN_H
#define MC6809GEN_H

typedef enum
{
  AOP_INVALID,
  /* Is a literal */
  AOP_LIT = 1,
  /* Is in a register */
  AOP_REG,
  /* Is in direct space */
  AOP_DIR,
  /* Is on the stack */
  AOP_STK,
  /* Is an immediate value */
  AOP_IMMD,
  /* Is a string (?) */
  AOP_STR,
  /* Is in the condition register */
  AOP_COND,
  /* Is pointed to by index register X */
  AOP_IX,
  /* Is pointed to by index register Y */
  AOP_IY,
  /* Is pointed to by index register U */
  AOP_IU,
  /* Read undefined, discard writes */
  AOP_DUMMY
}
AOP_TYPE;

/* type asmop : a homogenised type for 
   all the different spaces an operand can be
   in */
typedef struct asmop
{
  AOP_TYPE type;
  short coff;                   /* current offset */
  short size;                   /* total size */
  unsigned code:1;              /* is in Code space */
  unsigned paged:1;             /* in paged memory  */
  unsigned freed:1;             /* already freed    */
  union
  {
    value *aop_lit;             /* if literal */
    reg_info *aop_reg[4];       /* array of registers */
    char *aop_dir;              /* if direct  */
    char *aop_immd;             /* if immediate others are implied */
    int aop_stk;                /* stack offset when AOP_STK */
    const char *aop_str[4];     /* just a string array containing the location */
  }
  aopu;
  signed char regs[MAX_ASMOP_IDX + 1]; // Byte of this aop that is in the register. -1 if no byte of this aop is in the reg.
}
asmop;

void genMC6809Code (iCode *);
void mc6809_emitDebuggerSymbol (const char *);

extern bool mc6809_assignment_optimal;
extern bool mc6809_should_omit_frame_ptr;

#endif

