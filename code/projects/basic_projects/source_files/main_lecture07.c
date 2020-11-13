/*
 * Lecture07 -- Real Numbers
 */

#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

int main(void) 
{
    uint16_t i;
    
    for(i=0; i<1000; i++)
    {
        double x = sin(2.0*22.0/7.0 * i * 3.0 / 1000.0);
        double y = 1.5*cos(2.0*22.0/7.0 * i * 4.0 / 1000.0);
        printf("%i,%e,%e\r\n", i, x, y);
    }
    while(1);
}


/*
 uint16_t i, j;
    
    float x = 0.0f;
    long double y = 0.0;

    
    for(i=0; i<50000; i++) {
        x = x + 1e-5f;
    }
    
    for(j=0; j<50000; j++) {
        y = y + 1e-5;
    }
 
 */

/*
    printf("---\r\n");
            
    printf("min: %e, max: %e\r\n", (double)FLT_MIN, (double)FLT_MAX);
    printf("size: %d\r\n", sizeof(float));
    
    
    printf("min: %e, max: %e\r\n", DBL_MIN, DBL_MAX);
    printf("size: %d\r\n", sizeof(double));
    
    printf("min: %Le, max: %Le\r\n", LDBL_MIN, LDBL_MAX);
    printf("size: %d\r\n", sizeof(long double));
 */

/*
     printf("size of float: %d bytes\r\n", sizeof(float));
    
    printf("size of double: %d bytes\r\n", sizeof(double));

    printf("size of long double: %d bytes\r\n", sizeof(long double));
 */