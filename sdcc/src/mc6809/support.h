/** @file mc6809/support.h
    Support functions for the mc6809 port.
*/
#ifndef MC6809_SUPPORT_INCLUDE
#define MC6809_SUPPORT_INCLUDE

typedef unsigned short WORD;
typedef unsigned char BYTE;

typedef struct
  {
    WORD w[2];
    BYTE b[4];
  }
MC6809_FLOAT;

/** Convert a native float into 'mc6809' format */
int convertFloat (MC6809_FLOAT * f, double native);

#endif
