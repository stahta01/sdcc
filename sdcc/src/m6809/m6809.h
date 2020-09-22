/** @file m6809/m6809.h
    Common definitions between the MC6809 and HD6309 ports.
*/
#include "common.h"
#include "ralloc.h"
#include "gen.h"
#include "peep.h"


typedef enum
  {
    SUB_M6809,
    SUB_H6309
  }
M6809_SUB_PORT;

typedef struct
  {
    M6809_SUB_PORT sub;
  }
M6809_OPTS;

extern M6809_OPTS M6809_opts;

#define IS_M6809 (M6809_opts.sub == SUB_M6809)
#define IS_H6309 (M6809_opts.sub == SUB_H6309)

