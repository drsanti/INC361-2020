/************************************************************
 * Example Program for INC361                               *
 ************************************************************
 * File:    main.c                                          *
 * Author:  Asst.Prof.Dr.Santi Nuratch                      *
 *          Embedded Computing and Control Laboratory       *
 *          ECC-Lab, INC, KMUTT, Thailand                   *
 ************************************************************
 * Update:  19 November 2020                                *
 ************************************************************/

/*
 * Note:
 * In VSCode, use the following command:
 * ecc-pic24-cli -build
 */


#include <xc.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Comment this line to enable full speed (32MHz)
 */
#define USE_SIM_FCY_1MHZ




#ifdef USE_SIM_FCY_1MHZ
    #define FOSC    (2e6)       // Internal fast RC (8MHz) with DIV4 (2MHz)
#else
    #define FOSC    (32e6)      // Internal fast RC (8MHz) with x4 PLL (32MHz)
#endif

#define FCY     FOSC/2          // Instruction clock frequency
#include <libpic30.h>           // For delay functions

/**
 * MCU Clock setting
 */
void System_Clock_Init(void)
{

#ifdef USE_SIM_FCY_1MHZ
    CLKDIVbits.RCDIV    = 0b010;    // RCDIV<2:0>: FRC Postscaler Select bits
#else
    CLKDIVbits.RCDIV    = 0b000;    // RCDIV<2:0>: FRC Postscaler Select bits
#endif
                                    // 000: 8MHz/1      = 8MHz
                                    // 001: 8MHz/2      = 4MHz
                                    // 010: 8MHz/4      = 2MHz
                                    // 011: 8MHz/8      = 1MHz
                                    // 100: 8MHz/16     = 500kHz
                                    // 101: 8MHz/32     = 250kHz
                                    // 110: 8MHz/64     = 125kHz
                                    // 111: 8MHz/256    = 31.25kHz

    CLKDIVbits.DOZEN    = 0b0;      // DOZEN: DOZE Enable bit
                                    // 0: CPU peripheral clock ratio is set to 1:1
                                    // 1: The DOZE<2:0> bits specify the CPU peripheral clock ratio
                                    // Note: This bit is automatically cleared when the ROI bit is set and an interrupt occurs

    CLKDIVbits.DOZE     = 0b000;    // DOZE<2:0>: CPU Peripheral Clock Ratio Select bits
                                    // 000: 1:1
                                    // 001: 1:2
                                    // 010: 1:4
                                    // 011: 1:8
                                    // 100: 1:16
                                    // 101: 1:32
                                    // 110: 1:64
                                    // 111: 1:128
                                    // Note: Proteus simulator not supports these bits

    CLKDIVbits.ROI      = 0b0;      // Recover on Interrupt bit
                                    // 0: Interrupts have no effect on the DOZEN bit
                                    // 1: Interrupts clear the DOZEN bit and reset the CPU peripheral clock ratio to 1:1
}


/**
 * IO Ports setting
 */
void System_IO_Init(void)
{
    AD1PCFG |= 0x0FFF;              // PCFG<12:0>: Analog Input Pin Configuration Control bits
                                    // 0: Digital mode (Disable ANx)
                                    // 1: Analog mode (Enable ANx)
                                    // Note: AN6, AN7 and AN8, are unavailable on 28-pin devices

    AD1PCFG |= 0x8000;              // PCFG15: Analog Input Pin Configuration Control bit
                                    // 0: Band gap voltage reference is enabled
                                    // 1: Band gap voltage reference is disabled

    ODCA = 0x0000;                  // Disable Open-drain operation of PORTA
    ODCB = 0x0000;                  // Disable Open-drain operation of PORTB
}


/**
 * Display code for common cathode 7-segment display
 */
const uint8_t segment_code[] = {
0x3F,   // 0
0x06,   // 1
0x5B,   // 2
0x4F,   // 3
0x66,   // 4
0x6D,   // 5
0x7D,   // 6
0x07,   // 7
0x7F,   // 8
0x6F,   // 9
};

/**
 * Display buffer
 */
uint8_t disp_arr[4] = {0};

/**
 * Display index
 */
uint8_t disp_idx = 0;


/**
 * Update the display
 * This function should be called every 5 milliseconds
 */
void Display_Update(void) {
    LATB &= ~(0xF<<8);              // Turn off all drivers
    LATB = disp_arr[disp_idx];      // Write display data
    LATB |= 1<<(8+disp_idx);        // Turn on digit pointed by index
    disp_idx = (disp_idx + 1)%4;    // Next position
}


/**
 * Write display code to display buffer
 */
void Display_Write_Code(uint8_t index, uint8_t code) {
    index %= 4;
    uint8_t temp = disp_arr[index] & 0x80;
    disp_arr[index] = (temp | code);
}


/**
 * Write a digit code to display buffer
 */
void Display_Write_Digit(uint8_t index, uint8_t digit) {
    Display_Write_Code(index, segment_code[digit]);
}


/**
 * Zeros padding
 */
void Display_Write_Uint16_Z(int16_t value) {
    uint8_t i;
    value %= 10000;     // 0-9999
    for(i=0; i<4; i++) {
        Display_Write_Digit(3-i, value%10);
        value/=10;
    }
}


/**
 * No zeros padding with no loop (time) reduction
 */
void Display_Write_Uint16_Nz(int16_t value) {
    uint8_t i=0;
    value %= 10000;     // 0-9999
    Display_Write_Digit(3-i, value%10);
    value/=10;
    for(i=1; i<4; i++) {
        if(value<=0) {
            Display_Write_Code(3-i, 0x00);
        }
        else{
            Display_Write_Digit(3-i, value%10);
        }
        value/=10;
    }
}


/**
 * No zeros padding with loop (time) reduction
 */
void Display_Write_Uint16(int16_t value) {
    uint8_t i;
    value %= 10000;     // 0-9999
    for(i=0; i<4; i++) {
        Display_Write_Digit(3-i, value%10);
        value/=10;
        if(value <= 0) break;
    }
}


/**
 * Main function
 */
int main(void)
{
    System_Clock_Init();
    System_IO_Init();

    TRISB &= 0xF000; // TRISB<11:0> = 0
    LATB  &= 0xF000; // LATB<11:0>  = 0

    uint16_t ticks = 0;
    uint16_t counter = 1234;

    while(!0) {


        if( (++ticks % 190) == 0) {
            counter++;
        }

        if( (ticks % (190>>3)) == 0) {
            disp_arr[3] ^= 0x80;
        }

        Display_Write_Uint16(counter);


        Display_Update();
        __delay_ms(5);
    }
}
