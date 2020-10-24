/************************************************************
 * PIC24FJ48GA002 Configuration for INC361                  *
 ************************************************************
 * File:    mcu_config.c                                    *
 * Author:  Asst.Prof.Dr.Santi Nuratch                      *
 *          Embedded Computing and Control Laboratory       *
 *          ECC-Lab, INC, KMUTT, Thailand                   *
 ************************************************************
 * Update:  24 October 2020 (Initial version)               *
 ************************************************************/

#pragma config IESO     = OFF
#pragma config FNOSC    = FRCPLL
#pragma config FCKSM    = CSECMD
#pragma config IOL1WAY  = OFF
#pragma config OSCIOFNC = ON
#pragma config JTAGEN   = OFF
#pragma config GCP      = ON
#pragma config GWRP     = OFF
#pragma config BKBUG    = OFF
#pragma config ICS      = PGx3
#pragma config FWDTEN   = OFF
#pragma config WINDIS   = OFF
#pragma config FWPSA    = PR32
#pragma config WDTPS    = PS1024

/* EOF */
