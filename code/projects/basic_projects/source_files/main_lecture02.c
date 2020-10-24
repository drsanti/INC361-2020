
#include<stdio.h>
#include <xc.h>

int main(void) 
{
    int x = 0;
    
    while(1)
    {
        printf("x = %d\r\n", x);
        x = x+1;
    }
}

