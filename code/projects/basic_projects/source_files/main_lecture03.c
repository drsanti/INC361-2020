/************************************************************
 * Example program for Lecture03 of INC361                  *
 ************************************************************
 * File:    main_lecture03.c                                *
 * Author:  Asst.Prof.Dr.Santi Nuratch                      *
 *          Embedded Computing and Control Laboratory       *
 *          ECC-Lab, INC, KMUTT, Thailand                   *
 ************************************************************
 * Update:  25 October 2020                                 *
 ************************************************************/

#include<stdio.h>
#include <xc.h>

#define FOSC    (32e6)
#define FCY     (FOSC/2)
#include <libpic30.h>

int main(void) 
{
    AD1PCFG |= 0xFFFF;
    LATB  &= 0x0000;
    TRISB &= 0x0000;
    
    unsigned short data = 0x0001;
    while(1)
    {
        LATB = data;
        data = data?0x0001:data<<1;
        __delay_ms(200);
    }
}