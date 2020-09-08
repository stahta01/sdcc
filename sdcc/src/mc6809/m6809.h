/** @file mc6809/m6809.h
    Common definitions between the MC6809 and HD6309 CPUs.
*/
#include "common.h"
#include "ralloc.h"
#include "gen.h"
#include "peep.h"
#include "support.h"

typedef enum
  {
    SUB_MC6809,
    SUB_HD6309
  }
MC6809_SUB_PORT;

typedef struct
  {
    MC6809_SUB_PORT sub;
    int port_mode;
    int port_back;
    int reserveIY;
    int noOmitFramePtr;
  }
MC6809_OPTS;

extern MC6809_OPTS mc6809_opts;

#define IS_MC6809 (mc6809_opts.sub == SUB_MC6809)

#define IY_RESERVED (mc6809_opts.reserveIY)

#define OPTRALLOC_IY !(IY_RESERVED)

enum
  {
    ACCUSE_A = 1,
    ACCUSE_SCRATCH,
    ACCUSE_IY
  };
