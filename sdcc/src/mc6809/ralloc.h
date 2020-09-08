/*-------------------------------------------------------------------------

  mc6809/ralloc.h - header file register allocation

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
   
   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!  
-------------------------------------------------------------------------*/
#ifndef MC6809_RALLOC_H
#define MC6809_RALLOC_H 1

#include "SDCCicode.h"
#include "SDCCBBlock.h"

#include "reg_index.h"

enum
{
  REG_PTR = 1,
  REG_GPR = 2,
  REG_CND = 4
};

/* definition for the registers */
typedef struct reg_info
{
  short type;                   /* can have value 
                                   REG_GPR, REG_PTR or REG_CND */
  short rIdx;                   /* index into register table */
  char *name;                   /* name */
  unsigned isFree:1;            /* is currently unassigned  */
} reg_info;

extern reg_info *regsMC6809;

void assignRegisters (eBBlock **, int);
reg_info *regWithIdx (int);

void mc6809_assignRegisters (ebbIndex *);
bitVect *mc6809_rUmaskForOp (const operand * op);

void mc6809SpillThis (symbol *);
iCode *mc6809_ralloc2_cc(ebbIndex *ebbi);

void MC6809RegFix (eBBlock ** ebbs, int count);
#endif
