static const ASM_MAPPING _asxxxx_mc6809_mapping[] = {
    /* We want to prepend the _ */
    { "area", ".area _%s" },
    { "areacode", ".area _%s" },
    { "areadata", ".area _%s" },
    { "areahome", ".area _%s" },
    { "*ixx", "%d (ix)" },
    { "*iyx", "%d (iy)" },
    { "*hl", "(hl)" },
    { "jphl", "jp (hl)" },
    { "di", "di" },
    { "ei", "ei" },
    { "ldahli",
      "ld a, (hl)\n"
      "inc\thl" },
    { "ldahlsp",
      "ld hl, #%d\n"
      "add\thl, sp" },
    { "ldaspsp",
      "ld iy,#%d\n"
      "add\tiy,sp\n"
      "ld\tsp,iy" },
    { "*pair", "(%s)" },
    { "enter",
      "push\tix\n"
      "ld\tix,#0\n"
      "add\tix,sp" },
    { "enters",
      "call\t___sdcc_enter_ix\n" },
    { "pusha",
      "push af\n"
      "push\tbc\n"
      "push\tde\n"
      "push\thl\n"
      "push\tiy"
    },
    { "popa",
      "pop iy\n"
      "pop\thl\n"
      "pop\tde\n"
      "pop\tbc\n"
      "pop\taf"
    },
    { "adjustsp", "lda sp,-%d(sp)" },
    { "profileenter",
      "ld a,#3\n"
      "rst\t0x08"
    },
    { "profileexit",
      "ld a,#4\n"
      "rst\t0x08"
    },
    { NULL, NULL }
};

static const ASM_MAPPING _mc6809asm_mapping[] = {
    { "global", "XDEF %s" },
    { "extern", "XREF %s" },
    { "slabeldef", "\n.%s" },
    { "labeldef", "\n.%s" },
    { "tlabeldef", "\n.l%N%05d" },
    { "tlabel", "l%N%05d" },
    { "fileprelude",
      "; Generated using the z80asm/z88 tokens.\n"
      "\tXREF __muluchar_rrx_s\n"
      "\tXREF __mulschar_rrx_s\n"
      "\tXREF __mulint_rrx_s\n"
      "\tXREF __mullong_rrx_s\n"
      "\tXREF __divuchar_rrx_s\n"
      "\tXREF __divschar_rrx_s\n"
      "\tXREF __divsint_rrx_s\n"
      "\tXREF __divuint_rrx_s\n"
      "\tXREF __divulong_rrx_s\n"
      "\tXREF __divslong_rrx_s\n"
      "\tXREF __rrulong_rrx_s\n"
      "\tXREF __rrslong_rrx_s\n"
      "\tXREF __rlulong_rrx_s\n"
      "\tXREF __rlslong_rrx_s\n"
    },
    { "functionheader",
      "; ---------------------------------\n"
      "; Function %s\n"
      "; ---------------------------------"
    },
    { "functionlabeldef", ".%s" },
    { "globalfunctionlabeldef", ".%s" },
    { "zero", "$00" },
    { "one", "$01" },
    { "ascii", "DEFM \"%s\"" },
    { "ds", "DEFS %d" },
    { "db", "DEFB" },
    { "dbs", "DEFB %s" },
    { "dw", "DEFW" },
    { "dws", "DEFB %s" },
    { "immed", "" },
    { "constbyte", "$%02X" },
    { "constword", "$%04X" },
    { "immedword", "$%04X" },
    { "immedbyte", "$%02X" },
    { "hashedstr", "%s" },
    { "lsbimmeds", "%s ~ $FF" },
    { "msbimmeds", "%s / 256" },

    { "bankimmeds", "BANK(%s)" },
    { "hashedbankimmeds", "BANK(%s)" },
    { "module", "MODULE %s" },
    { "area", "; Area  %s" },
    { "areadata", "; Aread BSS" },
    { "areacode", "; Area CODE" },
    { "areahome", "; Area HOME" },
    { NULL, NULL }
};

static const ASM_MAPPING _mc6809asm_mc6809_mapping[] = {
    { "*ixx", "(ix%+d)" },
    { "*iyx", "(iy%+d)" },
    { "*hl", "(hl)" },
    { "jphl", "jp (hl)" },
    { "di", "di" },
    { "ei", "ei" },
    { "ldahli",
      "ld a, (hl)\n"
      "inc\thl" },
    { "ldahlsp",
      "ld hl, %d\n"
      "add\thl, sp" },
    { "ldaspsp",
      "ld iy, %d\n"
      "add\tiy, sp\n"
      "ld\tsp, iy" },
    { "*pair", "(%s)" },
    { "enter",
      "push\tix\n"
      "ld\tix,0\n"
      "add\tix,sp" },
    { "enters",
      "call\t___sdcc_enter_ix\n" },
    { "pusha",
      "push af\n"
      "push\tbc\n"
      "push\tde\n"
      "push\thl\n"
      "push\tiy"
    },
    { "popa",
      "pop\tiy\n"
      "pop\thl\n"
      "pop\tde\n"
      "pop\tbc\n"
      "pop\taf"
    },
    { "adjustsp", "lda sp, (sp%+d)" },
    { "profileenter",
      "ld a,3\n"
      "rst\t$08"
    },
    { "profileexit",
      "ld a,4\n"
      "rst\t$08"
    },
    { NULL, NULL }
};

const ASM_MAPPINGS _asxxxx_mc6809 = {
    &asm_asxxxx_mapping,
    _asxxxx_mc6809_mapping
};
