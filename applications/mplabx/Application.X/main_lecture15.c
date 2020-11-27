/**
 * Lecture 15
 */


/**
 * Include Files
 */
#include <xc.h>
#include <stdio.h>
#include <stdint.h>


/**
 * CPU Clock Frequency
 */
#define FOS  2e6


/**
 * Instruction Clock Frequency
 */
#define FCY  FOS/2
#include <libpic30.h>


/**
 * Display Hex Codes of 0-F
 */
const uint8_t disp_hex[] = {
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
    0x77,   // A (10)
    0x7C,   // b (11)
    0x39,   // C (12)
    0x5E,   // d (13)
    0x79,   // E (14)
    0x71    // F (15)
};

/**
 * Set MCU Clock Frequency (FOS) to 2MHz
 * Check the #define FOS
 */
void System_Clock_Init(void) {
    CLKDIVbits.RCDIV = 0x2;
}

/**
 * Set IO Ports
 *  - PORTB<11:0>  as digital output ports
 *  - PORTB<15:12> as digital input ports
 */
void System_IO_Init(void) {
    AD1PCFG |= 0x1FFF;
    TRISB = 0xF000;
    LATB &= 0xF000;
}


/**
 * Display Buffer
 */
uint8_t disp_buf[4] = {0xFF, 0xFF, 0xFF, 0xFF};


/**
 * Update Display on 7-Segment
 */
void Display_Multiplex(void) {
    static uint8_t idx = 0;
    LATB &= 0xF000;             // Clear DATA<7:0> and DIGIT<3:0>
    LATB |= 1<<(8+idx);         // Turn on DIGIT<idx>
    LATB |= disp_buf[idx];      // Write display code to DATA<7:0>
    idx = (idx+1)%4;            // Next Digit (0, 1, 2, 3, 0, ...)
}

/**
 * Update Display Buffer (decimal format)
 */
void Display_Uint(uint16_t value) {
    int8_t i;
    for(i=3; i>=0; i--) {
        disp_buf[i] = disp_hex[value%10];
        value /= 10;
    }
}

/**
 * Update Display Buffer (hexadecimal format)
 */
void Display_Uhex(uint16_t value) {
    int8_t i;
    for(i=3; i>=0; i--) {
        disp_buf[i] = disp_hex[value%16];
        value /= 16;
    }
}


void System_Timer1_Init(void) {
    // 1) Clock source
    T1CONbits.TCS = 0;      // 0 = Internal clock (FOSC/2)

    // 2) Prescaler
    T1CONbits.TCKPS = 0b00; // 1:1 Input Clock Prescaler

    // 3) Start T1
    T1CONbits.TON = 1;      // 1 = Starts 16-bit Timer1

    // 4) Clear Timer1 (Counter)
    TMR1 = 0;
}

/**
 * Main Function
 */
int main(void) {

    System_Clock_Init();        // Initialize System Clock
    System_IO_Init();           // Initialize I/O Ports
    System_Timer1_Init();       // Initialize Timer1
    Display_Uhex(0x0000);

    while(1) {

        if(TMR1 >= 5000) {
            TMR1 = 0;
            Display_Multiplex();    // Update display 7-Segment display (every 5mS)
        }

        if( (PORTB & 0xF000) != 0xF000) {
            Display_Uhex(PORTB & 0xF000);
        }
    }
}


/*
Display_Uhex(0xFEDC);

uint16_t cnt = 0;

while(1) {

    cnt++;

    if(cnt >= 350) {
        cnt = 0;
        Display_Multiplex();    // Update display 7-Segment display
    }

    if( (PORTB & 0xF000) != 0xF000) {
        Display_Uhex(PORTB & 0xF000);
    }
}
*/
