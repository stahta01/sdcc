//
// Register Declarations for Microchip 16F872 Processor
//
//
// This header file was automatically generated by:
//
//      inc2h.pl V4850
//
//      Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//      SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//      this license covers the code to the compiler and other executables,
//      but explicitly does not cover any code or objects generated by sdcc.
//
//      For pic device libraries and header files which are derived from
//      Microchip header (.inc) and linker script (.lkr) files Microchip
//      requires that "The header files should state that they are only to be
//      used with authentic Microchip devices" which makes them incompatible
//      with the GPL. Pic device libraries and header files are located at
//      non-free/lib and non-free/include directories respectively.
//      Sdcc should be run with the --use-non-free command line option in
//      order to include non-free header files and libraries.
//
//      See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
//
#ifndef P16F872_H
#define P16F872_H

//
// Register addresses.
//
#define INDF_ADDR       0x0000
#define TMR0_ADDR       0x0001
#define PCL_ADDR        0x0002
#define STATUS_ADDR     0x0003
#define FSR_ADDR        0x0004
#define PORTA_ADDR      0x0005
#define PORTB_ADDR      0x0006
#define PORTC_ADDR      0x0007
#define PCLATH_ADDR     0x000A
#define INTCON_ADDR     0x000B
#define PIR1_ADDR       0x000C
#define PIR2_ADDR       0x000D
#define TMR1L_ADDR      0x000E
#define TMR1H_ADDR      0x000F
#define T1CON_ADDR      0x0010
#define TMR2_ADDR       0x0011
#define T2CON_ADDR      0x0012
#define SSPBUF_ADDR     0x0013
#define SSPCON_ADDR     0x0014
#define CCPR1L_ADDR     0x0015
#define CCPR1H_ADDR     0x0016
#define CCP1CON_ADDR    0x0017
#define ADRESH_ADDR     0x001E
#define ADCON0_ADDR     0x001F
#define OPTION_REG_ADDR 0x0081
#define TRISA_ADDR      0x0085
#define TRISB_ADDR      0x0086
#define TRISC_ADDR      0x0087
#define PIE1_ADDR       0x008C
#define PIE2_ADDR       0x008D
#define PCON_ADDR       0x008E
#define SSPCON2_ADDR    0x0091
#define PR2_ADDR        0x0092
#define SSPADD_ADDR     0x0093
#define SSPSTAT_ADDR    0x0094
#define ADRESL_ADDR     0x009E
#define ADCON1_ADDR     0x009F
#define EEDATA_ADDR     0x010C
#define EEADR_ADDR      0x010D
#define EEDATH_ADDR     0x010E
#define EEADRH_ADDR     0x010F
#define EECON1_ADDR     0x018C
#define EECON2_ADDR     0x018D

//
// Memory organization.
//



//         LIST
// P16F872.INC  Standard Header File, Version 1.00    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F872 microcontroller.  These names are taken to match
// the data sheets as closely as possible.

// Note that the processor must be selected before this file is
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F872
//       2. LIST directive in the source file
//               LIST   P=PIC16F872
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================

//Rev:   Date:    Reason:

//1.01   11/17/05 Added the INTCON bits TMR0IE and TMR0IF
//1.00   01/25/98 Initial Release

//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F872
//            MESSG "Processor-header file mismatch.  Verify selected processor."
//         ENDIF

//==========================================================================
//
//       Register Definitions
//
//==========================================================================

#define W                    0x0000
#define F                    0x0001

//----- Register Files------------------------------------------------------

extern __sfr  __at (INDF_ADDR)                    INDF;
extern __sfr  __at (TMR0_ADDR)                    TMR0;
extern __sfr  __at (PCL_ADDR)                     PCL;
extern __sfr  __at (STATUS_ADDR)                  STATUS;
extern __sfr  __at (FSR_ADDR)                     FSR;
extern __sfr  __at (PORTA_ADDR)                   PORTA;
extern __sfr  __at (PORTB_ADDR)                   PORTB;
extern __sfr  __at (PORTC_ADDR)                   PORTC;
extern __sfr  __at (PCLATH_ADDR)                  PCLATH;
extern __sfr  __at (INTCON_ADDR)                  INTCON;
extern __sfr  __at (PIR1_ADDR)                    PIR1;
extern __sfr  __at (PIR2_ADDR)                    PIR2;
extern __sfr  __at (TMR1L_ADDR)                   TMR1L;
extern __sfr  __at (TMR1H_ADDR)                   TMR1H;
extern __sfr  __at (T1CON_ADDR)                   T1CON;
extern __sfr  __at (TMR2_ADDR)                    TMR2;
extern __sfr  __at (T2CON_ADDR)                   T2CON;
extern __sfr  __at (SSPBUF_ADDR)                  SSPBUF;
extern __sfr  __at (SSPCON_ADDR)                  SSPCON;
extern __sfr  __at (CCPR1L_ADDR)                  CCPR1L;
extern __sfr  __at (CCPR1H_ADDR)                  CCPR1H;
extern __sfr  __at (CCP1CON_ADDR)                 CCP1CON;
extern __sfr  __at (ADRESH_ADDR)                  ADRESH;
extern __sfr  __at (ADCON0_ADDR)                  ADCON0;

extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISB_ADDR)                   TRISB;
extern __sfr  __at (TRISC_ADDR)                   TRISC;
extern __sfr  __at (PIE1_ADDR)                    PIE1;
extern __sfr  __at (PIE2_ADDR)                    PIE2;
extern __sfr  __at (PCON_ADDR)                    PCON;
extern __sfr  __at (SSPCON2_ADDR)                 SSPCON2;
extern __sfr  __at (PR2_ADDR)                     PR2;
extern __sfr  __at (SSPADD_ADDR)                  SSPADD;
extern __sfr  __at (SSPSTAT_ADDR)                 SSPSTAT;
extern __sfr  __at (ADRESL_ADDR)                  ADRESL;
extern __sfr  __at (ADCON1_ADDR)                  ADCON1;

extern __sfr  __at (EEDATA_ADDR)                  EEDATA;
extern __sfr  __at (EEADR_ADDR)                   EEADR;
extern __sfr  __at (EEDATH_ADDR)                  EEDATH;
extern __sfr  __at (EEADRH_ADDR)                  EEADRH;

extern __sfr  __at (EECON1_ADDR)                  EECON1;
extern __sfr  __at (EECON2_ADDR)                  EECON2;

//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- PIR2 Bits ----------------------------------------------------------


//----- T1CON Bits ---------------------------------------------------------


//----- T2CON Bits ---------------------------------------------------------


//----- SSPCON Bits --------------------------------------------------------


//----- CCP1CON Bits -------------------------------------------------------


//----- ADCON0 Bits --------------------------------------------------------


//----- OPTION_REG Bits -----------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PIE2 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- SSPCON2 Bits --------------------------------------------------------


//----- SSPSTAT Bits -------------------------------------------------------


//----- ADCON1 Bits --------------------------------------------------------


//----- EECON1 Bits --------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'1FF'
//         __BADRAM H'008'-H'009', H'018'-H'01D', H'088'-H'089'
//         __BADRAM H'08F'-H'090', H'095'-H'09D', H'0C0'-H'0EF'
//         __BADRAM H'105', H'107'-H'109'
//         __BADRAM H'110'-H'11F', H'185'
//         __BADRAM H'185', H'187'-H'189', H'18E'-H'19F',H'1C0'-H'1EF'

//==========================================================================
//
//       Configuration Bits
//
// Code protection for the PIC16C872 is different than for other PIC16C87X devices.
// The CP_ALL and CP_OFF switches operate as expected.
// CP_HALF protects the lower half of program memory. The upper half is open.
// CP_UPPER_256 protects everything EXCEPT the top 256 words.
//==========================================================================

#define _CP_ALL              0x0FCF
#define _CP_HALF             0x1FDF
#define _CP_UPPER_256        0x2FEF
#define _CP_OFF              0x3FFF
#define _DEBUG_ON            0x37FF
#define _DEBUG_OFF           0x3FFF
#define _WRT_ENABLE_ON       0x3FFF
#define _WRT_ENABLE_OFF      0x3DFF
#define _CPD_ON              0x3EFF
#define _CPD_OFF             0x3FFF
#define _LVP_ON              0x3FFF
#define _LVP_OFF             0x3F7F
#define _BODEN_ON            0x3FFF
#define _BODEN_OFF           0x3FBF
#define _PWRTE_OFF           0x3FFF
#define _PWRTE_ON            0x3FF7
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FFB
#define _LP_OSC              0x3FFC
#define _XT_OSC              0x3FFD
#define _HS_OSC              0x3FFE
#define _RC_OSC              0x3FFF

//         LIST

// ----- ADCON0 bits --------------------
typedef union {
  struct {
    unsigned char ADON:1;
    unsigned char :1;
    unsigned char GO:1;
    unsigned char CHS0:1;
    unsigned char CHS1:1;
    unsigned char CHS2:1;
    unsigned char ADCS0:1;
    unsigned char ADCS1:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char GO_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __ADCON0bits_t;
extern volatile __ADCON0bits_t __at(ADCON0_ADDR) ADCON0bits;

// ----- ADCON1 bits --------------------
typedef union {
  struct {
    unsigned char PCFG0:1;
    unsigned char PCFG1:1;
    unsigned char PCFG2:1;
    unsigned char PCFG3:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char ADFM:1;
  };
} __ADCON1bits_t;
extern volatile __ADCON1bits_t __at(ADCON1_ADDR) ADCON1bits;

// ----- CCP1CON bits --------------------
typedef union {
  struct {
    unsigned char CCP1M0:1;
    unsigned char CCP1M1:1;
    unsigned char CCP1M2:1;
    unsigned char CCP1M3:1;
    unsigned char CCP1Y:1;
    unsigned char CCP1X:1;
    unsigned char :1;
    unsigned char :1;
  };
} __CCP1CONbits_t;
extern volatile __CCP1CONbits_t __at(CCP1CON_ADDR) CCP1CONbits;

// ----- EECON1 bits --------------------
typedef union {
  struct {
    unsigned char RD:1;
    unsigned char WR:1;
    unsigned char WREN:1;
    unsigned char WRERR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char EEPGD:1;
  };
} __EECON1bits_t;
extern volatile __EECON1bits_t __at(EECON1_ADDR) EECON1bits;

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RBIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RBIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char PEIE:1;
    unsigned char GIE:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char TMR0IF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char TMR0IE:1;
    unsigned char :1;
    unsigned char :1;
  };
} __INTCONbits_t;
extern volatile __INTCONbits_t __at(INTCON_ADDR) INTCONbits;

// ----- OPTION_REG bits --------------------
typedef union {
  struct {
    unsigned char PS0:1;
    unsigned char PS1:1;
    unsigned char PS2:1;
    unsigned char PSA:1;
    unsigned char T0SE:1;
    unsigned char T0CS:1;
    unsigned char INTEDG:1;
    unsigned char NOT_RBPU:1;
  };
} __OPTION_REGbits_t;
extern volatile __OPTION_REGbits_t __at(OPTION_REG_ADDR) OPTION_REGbits;

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BO:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCONbits_t;
extern volatile __PCONbits_t __at(PCON_ADDR) PCONbits;

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IE:1;
    unsigned char TMR2IE:1;
    unsigned char CCP1IE:1;
    unsigned char SSPIE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char ADIE:1;
    unsigned char :1;
  };
} __PIE1bits_t;
extern volatile __PIE1bits_t __at(PIE1_ADDR) PIE1bits;

// ----- PIE2 bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char BCLIE:1;
    unsigned char EEIE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIE2bits_t;
extern volatile __PIE2bits_t __at(PIE2_ADDR) PIE2bits;

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IF:1;
    unsigned char TMR2IF:1;
    unsigned char CCP1IF:1;
    unsigned char SSPIF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char ADIF:1;
    unsigned char :1;
  };
} __PIR1bits_t;
extern volatile __PIR1bits_t __at(PIR1_ADDR) PIR1bits;

// ----- PIR2 bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char BCLIF:1;
    unsigned char EEIF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIR2bits_t;
extern volatile __PIR2bits_t __at(PIR2_ADDR) PIR2bits;

// ----- PORTA bits --------------------
typedef union {
  struct {
    unsigned char RA0:1;
    unsigned char RA1:1;
    unsigned char RA2:1;
    unsigned char RA3:1;
    unsigned char RA4:1;
    unsigned char RA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __PORTAbits_t;
extern volatile __PORTAbits_t __at(PORTA_ADDR) PORTAbits;

// ----- PORTB bits --------------------
typedef union {
  struct {
    unsigned char RB0:1;
    unsigned char RB1:1;
    unsigned char RB2:1;
    unsigned char RB3:1;
    unsigned char RB4:1;
    unsigned char RB5:1;
    unsigned char RB6:1;
    unsigned char RB7:1;
  };
} __PORTBbits_t;
extern volatile __PORTBbits_t __at(PORTB_ADDR) PORTBbits;

// ----- PORTC bits --------------------
typedef union {
  struct {
    unsigned char RC0:1;
    unsigned char RC1:1;
    unsigned char RC2:1;
    unsigned char RC3:1;
    unsigned char RC4:1;
    unsigned char RC5:1;
    unsigned char RC6:1;
    unsigned char RC7:1;
  };
} __PORTCbits_t;
extern volatile __PORTCbits_t __at(PORTC_ADDR) PORTCbits;

// ----- SSPCON bits --------------------
typedef union {
  struct {
    unsigned char SSPM0:1;
    unsigned char SSPM1:1;
    unsigned char SSPM2:1;
    unsigned char SSPM3:1;
    unsigned char CKP:1;
    unsigned char SSPEN:1;
    unsigned char SSPOV:1;
    unsigned char WCOL:1;
  };
} __SSPCONbits_t;
extern volatile __SSPCONbits_t __at(SSPCON_ADDR) SSPCONbits;

// ----- SSPCON2 bits --------------------
typedef union {
  struct {
    unsigned char SEN:1;
    unsigned char RSEN:1;
    unsigned char PEN:1;
    unsigned char RCEN:1;
    unsigned char ACKEN:1;
    unsigned char ACKDT:1;
    unsigned char ACKSTAT:1;
    unsigned char GCEN:1;
  };
} __SSPCON2bits_t;
extern volatile __SSPCON2bits_t __at(SSPCON2_ADDR) SSPCON2bits;

// ----- SSPSTAT bits --------------------
typedef union {
  struct {
    unsigned char BF:1;
    unsigned char UA:1;
    unsigned char R:1;
    unsigned char S:1;
    unsigned char P:1;
    unsigned char D:1;
    unsigned char CKE:1;
    unsigned char SMP:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char I2C_READ:1;
    unsigned char I2C_START:1;
    unsigned char I2C_STOP:1;
    unsigned char I2C_DATA:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_W:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_A:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_WRITE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_ADDRESS:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char R_W:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char D_A:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char READ_WRITE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char DATA_ADDRESS:1;
    unsigned char :1;
    unsigned char :1;
  };
} __SSPSTATbits_t;
extern volatile __SSPSTATbits_t __at(SSPSTAT_ADDR) SSPSTATbits;

// ----- STATUS bits --------------------
typedef union {
  struct {
    unsigned char C:1;
    unsigned char DC:1;
    unsigned char Z:1;
    unsigned char NOT_PD:1;
    unsigned char NOT_TO:1;
    unsigned char RP0:1;
    unsigned char RP1:1;
    unsigned char IRP:1;
  };
} __STATUSbits_t;
extern volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;

// ----- T1CON bits --------------------
typedef union {
  struct {
    unsigned char TMR1ON:1;
    unsigned char TMR1CS:1;
    unsigned char NOT_T1SYNC:1;
    unsigned char T1OSCEN:1;
    unsigned char T1CKPS0:1;
    unsigned char T1CKPS1:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char T1INSYNC:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char T1SYNC:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __T1CONbits_t;
extern volatile __T1CONbits_t __at(T1CON_ADDR) T1CONbits;

// ----- T2CON bits --------------------
typedef union {
  struct {
    unsigned char T2CKPS0:1;
    unsigned char T2CKPS1:1;
    unsigned char TMR2ON:1;
    unsigned char TOUTPS0:1;
    unsigned char TOUTPS1:1;
    unsigned char TOUTPS2:1;
    unsigned char TOUTPS3:1;
    unsigned char :1;
  };
} __T2CONbits_t;
extern volatile __T2CONbits_t __at(T2CON_ADDR) T2CONbits;

// ----- TRISA bits --------------------
typedef union {
  struct {
    unsigned char TRISA0:1;
    unsigned char TRISA1:1;
    unsigned char TRISA2:1;
    unsigned char TRISA3:1;
    unsigned char TRISA4:1;
    unsigned char TRISA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __TRISAbits_t;
extern volatile __TRISAbits_t __at(TRISA_ADDR) TRISAbits;

// ----- TRISB bits --------------------
typedef union {
  struct {
    unsigned char TRISB0:1;
    unsigned char TRISB1:1;
    unsigned char TRISB2:1;
    unsigned char TRISB3:1;
    unsigned char TRISB4:1;
    unsigned char TRISB5:1;
    unsigned char TRISB6:1;
    unsigned char TRISB7:1;
  };
} __TRISBbits_t;
extern volatile __TRISBbits_t __at(TRISB_ADDR) TRISBbits;

// ----- TRISC bits --------------------
typedef union {
  struct {
    unsigned char TRISC0:1;
    unsigned char TRISC1:1;
    unsigned char TRISC2:1;
    unsigned char TRISC3:1;
    unsigned char TRISC4:1;
    unsigned char TRISC5:1;
    unsigned char TRISC6:1;
    unsigned char TRISC7:1;
  };
} __TRISCbits_t;
extern volatile __TRISCbits_t __at(TRISC_ADDR) TRISCbits;


#ifndef NO_BIT_DEFINES

#define ADON                 ADCON0bits.ADON                /* bit 0 */
#define GO                   ADCON0bits.GO                  /* bit 2 */
#define GO_DONE              ADCON0bits.GO_DONE             /* bit 2 */
#define NOT_DONE             ADCON0bits.NOT_DONE            /* bit 2 */
#define CHS0                 ADCON0bits.CHS0                /* bit 3 */
#define CHS1                 ADCON0bits.CHS1                /* bit 4 */
#define CHS2                 ADCON0bits.CHS2                /* bit 5 */
#define ADCS0                ADCON0bits.ADCS0               /* bit 6 */
#define ADCS1                ADCON0bits.ADCS1               /* bit 7 */

#define PCFG0                ADCON1bits.PCFG0               /* bit 0 */
#define PCFG1                ADCON1bits.PCFG1               /* bit 1 */
#define PCFG2                ADCON1bits.PCFG2               /* bit 2 */
#define PCFG3                ADCON1bits.PCFG3               /* bit 3 */
#define ADFM                 ADCON1bits.ADFM                /* bit 7 */

#define CCP1M0               CCP1CONbits.CCP1M0             /* bit 0 */
#define CCP1M1               CCP1CONbits.CCP1M1             /* bit 1 */
#define CCP1M2               CCP1CONbits.CCP1M2             /* bit 2 */
#define CCP1M3               CCP1CONbits.CCP1M3             /* bit 3 */
#define CCP1Y                CCP1CONbits.CCP1Y              /* bit 4 */
#define CCP1X                CCP1CONbits.CCP1X              /* bit 5 */

#define RD                   EECON1bits.RD                  /* bit 0 */
#define WR                   EECON1bits.WR                  /* bit 1 */
#define WREN                 EECON1bits.WREN                /* bit 2 */
#define WRERR                EECON1bits.WRERR               /* bit 3 */
#define EEPGD                EECON1bits.EEPGD               /* bit 7 */

#define RBIF                 INTCONbits.RBIF                /* bit 0 */
#define INTF                 INTCONbits.INTF                /* bit 1 */
#define T0IF                 INTCONbits.T0IF                /* bit 2 */
#define TMR0IF               INTCONbits.TMR0IF              /* bit 2 */
#define RBIE                 INTCONbits.RBIE                /* bit 3 */
#define INTE                 INTCONbits.INTE                /* bit 4 */
#define T0IE                 INTCONbits.T0IE                /* bit 5 */
#define TMR0IE               INTCONbits.TMR0IE              /* bit 5 */
#define PEIE                 INTCONbits.PEIE                /* bit 6 */
#define GIE                  INTCONbits.GIE                 /* bit 7 */

#define PS0                  OPTION_REGbits.PS0             /* bit 0 */
#define PS1                  OPTION_REGbits.PS1             /* bit 1 */
#define PS2                  OPTION_REGbits.PS2             /* bit 2 */
#define PSA                  OPTION_REGbits.PSA             /* bit 3 */
#define T0SE                 OPTION_REGbits.T0SE            /* bit 4 */
#define T0CS                 OPTION_REGbits.T0CS            /* bit 5 */
#define INTEDG               OPTION_REGbits.INTEDG          /* bit 6 */
#define NOT_RBPU             OPTION_REGbits.NOT_RBPU        /* bit 7 */

#define NOT_BO               PCONbits.NOT_BO                /* bit 0 */
#define NOT_BOR              PCONbits.NOT_BOR               /* bit 0 */
#define NOT_POR              PCONbits.NOT_POR               /* bit 1 */

#define TMR1IE               PIE1bits.TMR1IE                /* bit 0 */
#define TMR2IE               PIE1bits.TMR2IE                /* bit 1 */
#define CCP1IE               PIE1bits.CCP1IE                /* bit 2 */
#define SSPIE                PIE1bits.SSPIE                 /* bit 3 */
#define ADIE                 PIE1bits.ADIE                  /* bit 6 */

#define BCLIE                PIE2bits.BCLIE                 /* bit 3 */
#define EEIE                 PIE2bits.EEIE                  /* bit 4 */

#define TMR1IF               PIR1bits.TMR1IF                /* bit 0 */
#define TMR2IF               PIR1bits.TMR2IF                /* bit 1 */
#define CCP1IF               PIR1bits.CCP1IF                /* bit 2 */
#define SSPIF                PIR1bits.SSPIF                 /* bit 3 */
#define ADIF                 PIR1bits.ADIF                  /* bit 6 */

#define BCLIF                PIR2bits.BCLIF                 /* bit 3 */
#define EEIF                 PIR2bits.EEIF                  /* bit 4 */

#define RA0                  PORTAbits.RA0                  /* bit 0 */
#define RA1                  PORTAbits.RA1                  /* bit 1 */
#define RA2                  PORTAbits.RA2                  /* bit 2 */
#define RA3                  PORTAbits.RA3                  /* bit 3 */
#define RA4                  PORTAbits.RA4                  /* bit 4 */
#define RA5                  PORTAbits.RA5                  /* bit 5 */

#define RB0                  PORTBbits.RB0                  /* bit 0 */
#define RB1                  PORTBbits.RB1                  /* bit 1 */
#define RB2                  PORTBbits.RB2                  /* bit 2 */
#define RB3                  PORTBbits.RB3                  /* bit 3 */
#define RB4                  PORTBbits.RB4                  /* bit 4 */
#define RB5                  PORTBbits.RB5                  /* bit 5 */
#define RB6                  PORTBbits.RB6                  /* bit 6 */
#define RB7                  PORTBbits.RB7                  /* bit 7 */

#define RC0                  PORTCbits.RC0                  /* bit 0 */
#define RC1                  PORTCbits.RC1                  /* bit 1 */
#define RC2                  PORTCbits.RC2                  /* bit 2 */
#define RC3                  PORTCbits.RC3                  /* bit 3 */
#define RC4                  PORTCbits.RC4                  /* bit 4 */
#define RC5                  PORTCbits.RC5                  /* bit 5 */
#define RC6                  PORTCbits.RC6                  /* bit 6 */
#define RC7                  PORTCbits.RC7                  /* bit 7 */

#define SEN                  SSPCON2bits.SEN                /* bit 0 */
#define RSEN                 SSPCON2bits.RSEN               /* bit 1 */
#define PEN                  SSPCON2bits.PEN                /* bit 2 */
#define RCEN                 SSPCON2bits.RCEN               /* bit 3 */
#define ACKEN                SSPCON2bits.ACKEN              /* bit 4 */
#define ACKDT                SSPCON2bits.ACKDT              /* bit 5 */
#define ACKSTAT              SSPCON2bits.ACKSTAT            /* bit 6 */
#define GCEN                 SSPCON2bits.GCEN               /* bit 7 */

#define SSPM0                SSPCONbits.SSPM0               /* bit 0 */
#define SSPM1                SSPCONbits.SSPM1               /* bit 1 */
#define SSPM2                SSPCONbits.SSPM2               /* bit 2 */
#define SSPM3                SSPCONbits.SSPM3               /* bit 3 */
#define CKP                  SSPCONbits.CKP                 /* bit 4 */
#define SSPEN                SSPCONbits.SSPEN               /* bit 5 */
#define SSPOV                SSPCONbits.SSPOV               /* bit 6 */
#define WCOL                 SSPCONbits.WCOL                /* bit 7 */

#define BF                   SSPSTATbits.BF                 /* bit 0 */
#define UA                   SSPSTATbits.UA                 /* bit 1 */
#define I2C_READ             SSPSTATbits.I2C_READ           /* bit 2 */
#define NOT_W                SSPSTATbits.NOT_W              /* bit 2 */
#define NOT_WRITE            SSPSTATbits.NOT_WRITE          /* bit 2 */
#define R                    SSPSTATbits.R                  /* bit 2 */
#define READ_WRITE           SSPSTATbits.READ_WRITE         /* bit 2 */
#define R_W                  SSPSTATbits.R_W                /* bit 2 */
#define I2C_START            SSPSTATbits.I2C_START          /* bit 3 */
#define S                    SSPSTATbits.S                  /* bit 3 */
#define I2C_STOP             SSPSTATbits.I2C_STOP           /* bit 4 */
#define P                    SSPSTATbits.P                  /* bit 4 */
#define D                    SSPSTATbits.D                  /* bit 5 */
#define DATA_ADDRESS         SSPSTATbits.DATA_ADDRESS       /* bit 5 */
#define D_A                  SSPSTATbits.D_A                /* bit 5 */
#define I2C_DATA             SSPSTATbits.I2C_DATA           /* bit 5 */
#define NOT_A                SSPSTATbits.NOT_A              /* bit 5 */
#define NOT_ADDRESS          SSPSTATbits.NOT_ADDRESS        /* bit 5 */
#define CKE                  SSPSTATbits.CKE                /* bit 6 */
#define SMP                  SSPSTATbits.SMP                /* bit 7 */

#define C                    STATUSbits.C                   /* bit 0 */
#define DC                   STATUSbits.DC                  /* bit 1 */
#define Z                    STATUSbits.Z                   /* bit 2 */
#define NOT_PD               STATUSbits.NOT_PD              /* bit 3 */
#define NOT_TO               STATUSbits.NOT_TO              /* bit 4 */
#define RP0                  STATUSbits.RP0                 /* bit 5 */
#define RP1                  STATUSbits.RP1                 /* bit 6 */
#define IRP                  STATUSbits.IRP                 /* bit 7 */

#define TMR1ON               T1CONbits.TMR1ON               /* bit 0 */
#define TMR1CS               T1CONbits.TMR1CS               /* bit 1 */
#define NOT_T1SYNC           T1CONbits.NOT_T1SYNC           /* bit 2 */
#define T1INSYNC             T1CONbits.T1INSYNC             /* bit 2 */
#define T1SYNC               T1CONbits.T1SYNC               /* bit 2 */
#define T1OSCEN              T1CONbits.T1OSCEN              /* bit 3 */
#define T1CKPS0              T1CONbits.T1CKPS0              /* bit 4 */
#define T1CKPS1              T1CONbits.T1CKPS1              /* bit 5 */

#define T2CKPS0              T2CONbits.T2CKPS0              /* bit 0 */
#define T2CKPS1              T2CONbits.T2CKPS1              /* bit 1 */
#define TMR2ON               T2CONbits.TMR2ON               /* bit 2 */
#define TOUTPS0              T2CONbits.TOUTPS0              /* bit 3 */
#define TOUTPS1              T2CONbits.TOUTPS1              /* bit 4 */
#define TOUTPS2              T2CONbits.TOUTPS2              /* bit 5 */
#define TOUTPS3              T2CONbits.TOUTPS3              /* bit 6 */

#define TRISA0               TRISAbits.TRISA0               /* bit 0 */
#define TRISA1               TRISAbits.TRISA1               /* bit 1 */
#define TRISA2               TRISAbits.TRISA2               /* bit 2 */
#define TRISA3               TRISAbits.TRISA3               /* bit 3 */
#define TRISA4               TRISAbits.TRISA4               /* bit 4 */
#define TRISA5               TRISAbits.TRISA5               /* bit 5 */

#define TRISB0               TRISBbits.TRISB0               /* bit 0 */
#define TRISB1               TRISBbits.TRISB1               /* bit 1 */
#define TRISB2               TRISBbits.TRISB2               /* bit 2 */
#define TRISB3               TRISBbits.TRISB3               /* bit 3 */
#define TRISB4               TRISBbits.TRISB4               /* bit 4 */
#define TRISB5               TRISBbits.TRISB5               /* bit 5 */
#define TRISB6               TRISBbits.TRISB6               /* bit 6 */
#define TRISB7               TRISBbits.TRISB7               /* bit 7 */

#define TRISC0               TRISCbits.TRISC0               /* bit 0 */
#define TRISC1               TRISCbits.TRISC1               /* bit 1 */
#define TRISC2               TRISCbits.TRISC2               /* bit 2 */
#define TRISC3               TRISCbits.TRISC3               /* bit 3 */
#define TRISC4               TRISCbits.TRISC4               /* bit 4 */
#define TRISC5               TRISCbits.TRISC5               /* bit 5 */
#define TRISC6               TRISCbits.TRISC6               /* bit 6 */
#define TRISC7               TRISCbits.TRISC7               /* bit 7 */
#endif /* NO_BIT_DEFINES */

#ifndef NO_LEGACY_NAMES
#define ADCON0_bits          ADCON0bits
#define ADCON1_bits          ADCON1bits
#define CCP1CON_bits         CCP1CONbits
#define EECON1_bits          EECON1bits
#define INTCON_bits          INTCONbits
#define OPTION_REG_bits      OPTION_REGbits
#define PCON_bits            PCONbits
#define PIE1_bits            PIE1bits
#define PIE2_bits            PIE2bits
#define PIR1_bits            PIR1bits
#define PIR2_bits            PIR2bits
#define PORTA_bits           PORTAbits
#define PORTB_bits           PORTBbits
#define PORTC_bits           PORTCbits
#define SSPCON_bits          SSPCONbits
#define SSPCON2_bits         SSPCON2bits
#define SSPSTAT_bits         SSPSTATbits
#define STATUS_bits          STATUSbits
#define T1CON_bits           T1CONbits
#define T2CON_bits           T2CONbits
#define TRISA_bits           TRISAbits
#define TRISB_bits           TRISBbits
#define TRISC_bits           TRISCbits
#endif /* NO_LEGACY_NAMES */

#endif