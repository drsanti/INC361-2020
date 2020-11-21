#include <xc.h>
#include <stdio.h>
#include <stdint.h>

#define FOS  2e6
#define FCY  FOS/2
#include <libpic30.h>

/*
 * Set MCU clock (FOS) to 2MHz
 * Check #define FOS
 */
void System_Clock_Init(void) {
    CLKDIVbits.RCDIV = 0x2;
}

/*
 * Set IO Ports, PORTB<11:0) as digital output ports
 */
void System_IO_Init(void) {
    AD1PCFG |= 0x1FFF;
    TRISB = 0xF000;
    LATB &= 0xF000;
}

int main(void) {

    System_Clock_Init();
    System_IO_Init();

    uint8_t idx;

    LATB &= 0xF000;
    LATB |= 0x00FF; // 8.
    while(1) {
        /*
        LATB ^= 1<<11;      // DIGIT3 ON
        __delay_ms(500);
        LATB ^= 1<<11;      // DIGIT3 OFF

        LATB ^= 1<<10;      // DIGIT2 ON
        __delay_ms(500);
        LATB ^= 1<<10;      // DIGIT2 OFF

        LATB ^= 1<<9;      // DIGIT1 ON
        __delay_ms(500);
        LATB ^= 1<<9;      // DIGIT1 OFF

        LATB ^= 1<<8;      // DIGIT0 ON
        __delay_ms(500);
        LATB ^= 1<<8;      // DIGIT0 OFF
        */

        /*
        for(idx=11; idx>=8; idx--) {
            LATB ^= 1<<idx;      // DIGIT<idx> ON
            __delay_ms(500);
            LATB ^= 1<<idx;      // DIGIT3<idx> OFF
        }
        */

        for(idx=11; idx>=8; idx--) {
            LATB |= 1<<idx;         // DIGIT<idx> ON
            __delay_ms(500);
            LATB &= ~(1<<idx);      // DIGIT3<idx> OFF
        }
    }
}




// void System_Clock_Init(void) {
//     // FOSC = 2 MHz

//     /*
//     // 1)
//     uint16_t temp = CLKDIV;
//     temp &= ~(0b111<<8);
//     temp |=  (0b010<<8);
//     CLKDIV = temp;
//     */

//     /*
//     // 2)
//     CLKDIVbits.RCDIV = 0b010;
//     */

//     /*
//     // 3)
//     CLKDIVbits.RCDIV0 = 0;
//     CLKDIVbits.RCDIV1 = 1;
//     CLKDIVbits.RCDIV2 = 0;
//     */

//     CLKDIVbits.RCDIV = 0x2;
// }



// void System_IO_Init(void) {

//     // Disable All ANs ( used as Digital mode)
//     AD1PCFG |= 0x1FFF;

//     // Set direction of PORTB
//     //  - PORTB<15:12> -- Input
//     //  - PORTB<11:0>  -- Output
//     TRISB = 0xF000;

//     // Clear LATB<11:0>
//     LATB &= 0xF000;
// }
