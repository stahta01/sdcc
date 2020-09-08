/*-------------------------------------------------------------------------

  m6809/reg_index.h - header file register index

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
#ifndef M6809_REG_INDEX_H
#define M6809_REG_INDEX_H 1

enum
{
  MIN_IDX=0,
  A_IDX = MIN_IDX,    /* Accumulator A */
  B_IDX,              /* Accumulator B */

  XL_IDX,             /* Lower byte of X */
  XH_IDX,             /* Upper byte of X */
  YL_IDX,             /* Lower byte of Y */
  YH_IDX,             /* Upper byte of Y */
  UL_IDX,             /* Lower byte of U */
  UH_IDX,             /* Upper byte of U */

  MAX_TREE_DECOMP_IDX=UH_IDX,

  CND_IDX,            /* Condition Register */

  DP_IDX,             /* Direct page */

  SP_IDX,             /* Stack Pointer */

  PC_IDX,             /* Program Counter */

  X_IDX,              /* Index X */
  Y_IDX,              /* Index Y */
  U_IDX,              /* User Stack Pointer */
  D_IDX,              /* Registers A and B combined */

  MAX_IDX=D_IDX
};

#endif
