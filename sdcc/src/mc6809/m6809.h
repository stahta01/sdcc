typedef enum
  {
    SUB_MC6809,
    SUB_HD6309
  }
MC6809_SUB_PORT;

typedef struct
  {
    MC6809_SUB_PORT sub;
  }
MC6809_OPTS;

extern MC6809_OPTS mc6809_opts;

#define IS_MC6809 (mc6809_opts.sub == SUB_MC6809)
#define IS_HD6309 (mc6809_opts.sub == SUB_HD6309)

