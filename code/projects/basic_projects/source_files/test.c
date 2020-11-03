/************************************************************
 * Example program for testing of INC361                    *
 ************************************************************
 * File:    test.c                                          *
 * Author:  Asst.Prof.Dr.Santi Nuratch                      *
 *          Embedded Computing and Control Laboratory       *
 *          ECC-Lab, INC, KMUTT, Thailand                   *
 ************************************************************
 * Update:  01 November 2020                                *
 ************************************************************/

#include <xc.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    
    uint8_t x = 0x00;
    printf("Address: 0x%2X, Size: %d, Value: %d\r\n", &x, sizeof(x), x);
    
    while(1)
    {
        
    }
    return 0;
}
