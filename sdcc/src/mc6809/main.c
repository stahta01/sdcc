/*-------------------------------------------------------------------------
  main.c - m6809 specific definitions.

  Michael Hope <michaelh@juju.net.nz> 2001

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

#include <sys/stat.h>
#include "m6809.h"
#include "SDCCsystem.h"
#include "SDCCutil.h"
#include "SDCCargs.h"
#include "dbuf_string.h"

static char _m6809_defaultRules[] = {
#include "peeph.rul"
};

#define OPTION_SMALL_MODEL          "--model-small"
#define OPTION_LARGE_MODEL          "--model-large"

static OPTION _mc6809_options[] =
  {
    {0, OPTION_SMALL_MODEL, NULL, "8-bit address space for data"},
    {0, OPTION_LARGE_MODEL, NULL, "16-bit address space for data (default)"},
    {0, "--out-fmt-elf", NULL, "Output executable in ELF format" },
    {0, NULL }
  };

MC6809_OPTS mc6809_opts;

typedef enum
{
  /* Must be first */
  ASM_TYPE_ASXXXX,
  ASM_TYPE_MC6809ASM,
}
ASM_TYPE;

static struct
{
  ASM_TYPE asmType;
  /* determine if we can register a parameter */
  int regParams;
}
_G;

static char *_keywords[] = {
  "sfr",
  "nonbanked",
  "banked",
  "at",
  "_naked",
  "critical",
  "interrupt",
  "smallc",
  NULL
};

extern PORT mc6809_port;

#include "mappings.i"

static void
_mc6809_init (void)
{
  mc6809_opts.sub = SUB_MC6809;
  switch (_G.asmType)
    {
    default:
      asm_addTree (&_asxxxx_mc6809);
      break;
    }
}

static void
_reset_regparm (struct sym_link *funcType)
{
  _G.regParams = 0;
}

static int
_reg_parm (sym_link *l, bool reentrant)
{
 return FALSE;
}

enum
{
  P_BANK = 1,
  P_PORTMODE,
  P_CODESEG,
  P_CONSTSEG,
};

static int
do_pragma (int id, const char *name, const char *cp)
{
  struct pragma_token_s token;
  int err = 0;
  int processed = 1;

  init_pragma_token (&token);

  switch (id)
    {
    case P_BANK:
      {
        struct dbuf_s buffer;

        dbuf_init (&buffer, 128);

        cp = get_pragma_token (cp, &token);

        switch (token.type)
          {
          case TOKEN_EOL:
            err = 1;
            break;

          case TOKEN_INT:
            switch (_G.asmType)
              {
              case ASM_TYPE_ASXXXX:
                dbuf_printf (&buffer, "CODE_%d", token.val.int_val);
                break;

              default:
                wassert (0);
              }
            break;

          default:
            {
              const char *str = get_pragma_string (&token);

              dbuf_append_str (&buffer, (0 == strcmp ("BASE", str)) ? "HOME" : str);
            }
            break;
          }

        cp = get_pragma_token (cp, &token);
        if (TOKEN_EOL != token.type)
          {
            err = 1;
            break;
          }

        dbuf_c_str (&buffer);
        options.code_seg = (char *) dbuf_detach (&buffer);
      }
      break;

    case P_PORTMODE:
      {                         
        const char *str;

        cp = get_pragma_token (cp, &token);

        if (TOKEN_EOL == token.type)
          {
            err = 1;
            break;
          }

        str = get_pragma_string (&token);

        cp = get_pragma_token (cp, &token);
        if (TOKEN_EOL != token.type)
          {
            err = 1;
            break;
          }

        if (!strcmp (str, "mc6809"))
          {
            mc6809_opts.port_mode = 6809;
          }
        else if (!strcmp (str, "hd6309"))
          {
            mc6809_opts.port_mode = 6309;
          }
        else if (!strcmp (str, "save"))
          {
            mc6809_opts.port_back = mc6809_opts.port_mode;
          }
        else if (!strcmp (str, "restore"))
          {
            mc6809_opts.port_mode = mc6809_opts.port_back;
          }
        else
          err = 1;
      }
      break;

    case P_CODESEG:
    case P_CONSTSEG:
      {
        char *segname;

        cp = get_pragma_token (cp, &token);
        if (token.type == TOKEN_EOL)
          {
            err = 1;
            break;
          }

        segname = Safe_strdup (get_pragma_string (&token));

        cp = get_pragma_token (cp, &token);
        if (token.type != TOKEN_EOL)
          {
            Safe_free (segname);
            err = 1;
            break;
          }

        if (id == P_CODESEG)
          {
            if (options.code_seg)
              Safe_free (options.code_seg);
            options.code_seg = segname;
          }
        else
          {
            if (options.const_seg)
              Safe_free (options.const_seg);
            options.const_seg = segname;
          }
      }
      break;

    default:
      processed = 0;
      break;
    }

  get_pragma_token (cp, &token);

  if (1 == err)
    werror (W_BAD_PRAGMA_ARGUMENTS, name);

  free_pragma_token (&token);
  return processed;
}

static struct pragma_s pragma_tbl[] = {
  {"bank", P_BANK, 0, do_pragma},
  {"portmode", P_PORTMODE, 0, do_pragma},
  {"codeseg", P_CODESEG, 0, do_pragma},
  {"constseg", P_CONSTSEG, 0, do_pragma},
  {NULL, 0, 0, NULL},
};

static int
_process_pragma (const char *s)
{
  return process_pragma_tbl (pragma_tbl, s);
}

static bool
_parseOptions (int *pargc, char **argv, int *i)
{
  if (argv[*i][0] == '-')
    {
    }
  return FALSE;
}

static void
_setValues (void)
{
  const char *s;
  struct dbuf_s dbuf;

  if (options.nostdlib == FALSE)
    {
      const char *s;
      char *path;
      struct dbuf_s dbuf;

      dbuf_init (&dbuf, PATH_MAX);

      for (s = setFirstItem (libDirsSet); s != NULL; s = setNextItem (libDirsSet))
        {
          path = buildCmdLine2 ("-k\"%s" DIR_SEPARATOR_STRING "{port}\" ", s);
          dbuf_append_str (&dbuf, path);
          Safe_free (path);
        }
      path = buildCmdLine2 ("-l\"{port}.lib\"", s);
      dbuf_append_str (&dbuf, path);
      Safe_free (path);

      setMainValue ("mc6809libspec", dbuf_c_str (&dbuf));
      dbuf_destroy (&dbuf);

      for (s = setFirstItem (libDirsSet); s != NULL; s = setNextItem (libDirsSet))
        {
          struct stat stat_buf;

          path = buildCmdLine2 ("%s" DIR_SEPARATOR_STRING "{port}" DIR_SEPARATOR_STRING "crt0{objext}", s);
          if (stat (path, &stat_buf) == 0)
            {
              Safe_free (path);
              break;
            }
          else
            Safe_free (path);
        }

      if (s == NULL)
        setMainValue ("mc6809crt0", "\"crt0{objext}\"");
      else
        {
          struct dbuf_s dbuf;

          dbuf_init (&dbuf, 128);
          dbuf_printf (&dbuf, "\"%s\"", path);
          setMainValue ("mc6809crt0", dbuf_c_str (&dbuf));
          dbuf_destroy (&dbuf);
        }
    }
  else
    {
      setMainValue ("mc6809libspec", "");
      setMainValue ("mc6809crt0", "");
    }

  setMainValue ("mc6809extralibfiles", (s = joinStrSet (libFilesSet)));
  Safe_free ((void *) s);
  setMainValue ("mc6809extralibpaths", (s = joinStrSet (libPathsSet)));
  Safe_free ((void *) s);

    {
      setMainValue ("mc6809outputtypeflag", "-i");
      setMainValue ("mc6809outext", ".ihx");
    }

  setMainValue ("stdobjdstfilename", "{dstfilename}{objext}");
  setMainValue ("stdlinkdstfilename", "{dstfilename}{mc6809outext}");

  setMainValue ("mc6809extraobj", (s = joinStrSet (relFilesSet)));
  Safe_free ((void *) s);

  dbuf_init (&dbuf, 128);
  dbuf_printf (&dbuf, "-b_CODE=0x%04X -b_DATA=0x%04X", options.code_loc, options.data_loc);
  setMainValue ("mc6809bases", dbuf_c_str (&dbuf));
  dbuf_destroy (&dbuf);

  /* For the old register allocator (with the new one we decide to omit the frame pointer for each function individually) */
  if (options.omitFramePtr)
    port->stack.call_overhead = 2;
}

static void
_finaliseOptions (void)
{
  port->mem.default_local_map = data;
  port->mem.default_globl_map = data;

  if (IY_RESERVED)
    port->num_regs -= 2;

  _setValues ();
}

static void
_setDefaultOptions (void)
{
  options.nopeep = 0;
  options.stackAuto = 1;
  /* first the options part */
  options.intlong_rent = 1;
  options.float_rent = 1;
  options.noRegParams = 0;
  /* Default code and data locations. */
  options.code_loc = 0x200;

  options.data_loc = 0x8000;
  options.out_fmt = 'i';        /* Default output format is ihx */
}

#if 0
/* Mangling format:
    _fun_policy_params
    where:
      policy is the function policy
      params is the parameter format

   policy format:
    rsp
    where:
      r is 'r' for reentrant, 's' for static functions
      s is 'c' for callee saves, 'r' for caller saves
      f is 'f' for profiling on, 'x' for profiling off
    examples:
      rr - reentrant, caller saves
   params format:
    A combination of register short names and s to signify stack variables.
    examples:
      bds - first two args appear in BC and DE, the rest on the stack
      s - all arguments are on the stack.
*/
static const char *
_mangleSupportFunctionName (const char *original)
{
  struct dbuf_s dbuf;

  if (strstr (original, "longlong"))
    return (original);

  dbuf_init (&dbuf, 128);
  dbuf_printf (&dbuf, "%s_rr%s_%s", original, options.profile ? "f" : "x", options.noRegParams ? "s" : "bds"    /* MB: but the library only has hds variants ??? */
    );

  return dbuf_detach_c_str (&dbuf);
}
#endif

static const char *
_getRegName (const struct reg_info *reg)
{
  if (reg)
    {
      return reg->name;
    }
  /*  assert (0); */
  return "err";
}

static int
_getRegByName (const char *name)
{
  if (!strcmp (name, "a"))
    return A_IDX;
  if (!strcmp (name, "b"))
    return B_IDX;
  if (!strcmp (name, "d"))
    return D_IDX;
  if (!strcmp (name, "x"))
    return X_IDX;
  if (!strcmp (name, "y"))
    return Y_IDX;
  if (!strcmp (name, "u"))
    return U_IDX;
  return -1;
}

static bool
_hasNativeMulFor (iCode *ic, sym_link *left, sym_link *right)
{
  sym_link *test = NULL;
  int result_size = IS_SYMOP (IC_RESULT(ic)) ? getSize (OP_SYM_TYPE (IC_RESULT(ic))) : 4;

  if (ic->op != '*')
    {
      return FALSE;
    }

  if (IS_LITERAL (left))
    test = left;
  else if (IS_LITERAL (right))
    test = right;
  /* 8x8 unsigned multiplication code is shorter than
     call overhead for the multiplication routine. */
  else if (IS_CHAR (right) && IS_UNSIGNED (right) && IS_CHAR (left) && IS_UNSIGNED (left))
    {
      return TRUE;
    }
  /* Same for any multiplication with 8 bit result. */
  else if (result_size == 1)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }

  if (getSize (test) <= 2)
    {
      return TRUE;
    }

  return FALSE;
}

/* Indicate which extended bit operations this port supports */
static bool
hasExtBitOp (int op, int size)
{
  if (op == GETHBIT)
    return TRUE;
  else
    return FALSE;
}

/* Indicate the expense of an access to an output storage class */
static int
oclsExpense (struct memmap *oclass)
{
  if (IN_FARSPACE (oclass))
    return 1;

  return 0;
}

static const char *_mc6809LinkCmd[] = {
  "sdld6809", "-nf", "$1", NULL
};

/* $3 is replaced by assembler.debug_opts resp. port->assembler.plain_opts */
static const char *_mc6809AsmCmd[] = {
  "sdas6809", "$l", "$3", "$2", "$1.asm", NULL
};

static const char *const _crt[] = { "crt0.rel", NULL, };
static const char *const _libs_mc6809[] = { "mc6809", NULL, };

/* Globals */
PORT mc6809_port =
{
  TARGET_ID_MC6809,
  "mc6809",
  "Motorola MC6809",            /* Target name */
  NULL,                         /* Processor name */
  {
    glue,
    FALSE,
    NO_MODEL,
    NO_MODEL,
    NULL,                       /* model == target */
  },
  {                             /* Assembler */
    _mc6809AsmCmd,
    NULL,
    "-plosgffwy",               /* Options with debug */
    "-plosgffw",                /* Options without debug */
    0,
    ".asm"
  },
  {                             /* Linker */
    _mc6809LinkCmd,                //NULL,
    NULL,                       //LINKCMD,
    NULL,
    ".rel",
    1,                          /* needLinkerScript */
    _crt,                       /* crt */
    _libs_mc6809,                  /* libs */
  },
  {                             /* Peephole optimizer */
    _m6809_defaultRules,
    mc6809instructionSize,
    NULL,
    NULL,
    NULL,
    mc6809notUsed,
    mc6809canAssign,
    mc6809notUsedFrom,
    NULL,
    NULL,
    NULL,
  },
  /* Sizes: char, short, int, long, long long, near ptr, far ptr, gptr, func ptr, banked func ptr, bit, float */
  { 1, 2, 2, 4, 8, 2, 2, 2, 2, 2, 1, 4 },
  /* tags for generic pointers */
  { 0x00, 0x40, 0x60, 0x80 },   /* far, near, xstack, code */
  {
    "XSEG",
    "STACK",
    "CODE",
    "DATA",
    NULL,                       /* idata */
    NULL,                       /* pdata */
    NULL,                       /* xdata */
    NULL,                       /* bit */
    "RSEG (ABS)",
    "GSINIT",                   /* static initialization */
    NULL,                       /* overlay */
    "GSFINAL",
    "HOME",
    NULL,                       /* xidata */
    NULL,                       /* xinit */
    NULL,                       /* const_name */
    "CABS (ABS)",               /* cabs_name */
    "DABS (ABS)",               /* xabs_name */
    NULL,                       /* iabs_name */
    "INITIALIZED",              /* name of segment for initialized variables */
    "INITIALIZER",              /* name of segment for copies of initialized variables in code space */
    NULL,
    NULL,
    1,                          /* CODE  is read-only */
    1                           /* No fancy alignments supported. */
  },
  { NULL, NULL },
  { -1, 0, 0, 4, 0, 3, 0 },
  { -1, FALSE },
  { mc6809_emitDebuggerSymbol },
  {
    256,                        /* maxCount */
    3,                          /* sizeofElement */
    {6, 7, 8},                  /* sizeofMatchJump[] - Assumes operand allocated to registers */
    {6, 9, 15},                 /* sizeofRangeCompare[] - Assumes operand allocated to registers*/
    1,                          /* sizeofSubtract - Assumes use of a single inc or dec */
    9,                          /* sizeofDispatch - Assumes operand allocated to register e or c*/
  },
  "_",
  _mc6809_init,
  _parseOptions,
  _mc6809_options,
  NULL,
  _finaliseOptions,
  _setDefaultOptions,
  mc6809_assignRegisters,
  _getRegName,
  _getRegByName,
  NULL,
  _keywords,
  0,                            /* no assembler preamble */
  NULL,                         /* no genAssemblerEnd */
  0,                            /* no local IVT generation code */
  0,                            /* no genXINIT code */
  NULL,                         /* genInitStartup */
  _reset_regparm,
  _reg_parm,
  _process_pragma,
  NULL,
  _hasNativeMulFor,
  hasExtBitOp,                  /* hasExtBitOp */
  oclsExpense,                  /* oclsExpense */
  TRUE,
  TRUE,                         /* little endian */
  0,                            /* leave lt */
  0,                            /* leave gt */
  1,                            /* transform <= to ! > */
  1,                            /* transform >= to ! < */
  1,                            /* transform != to !(a == b) */
  0,                            /* leave == */
  FALSE,                        /* Array initializer support. */
  0,                            /* no CSE cost estimation yet */
  NULL,                         /* no builtin functions */
  GPOINTER,                     /* treat unqualified pointers as "generic" pointers */
  1,                            /* reset labelKey to 1 */
  1,                            /* globals & local statics allowed */
  MAX_ASMOP_IDX + 1,            /* Number of registers handled in the tree-decomposition-based register allocator in SDCCralloc.hpp */
  PORT_MAGIC
};
