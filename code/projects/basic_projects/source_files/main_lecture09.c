/*
 * Lecture09 -- Bitwise and Assignment Operators   
 */


/*
 * Bitwise Operators
 *  1)  &    AND     (x & y)
 *  2)  |    OR      (x | y)
 *  3)  ^    XOR     (x ^ y)
 *  4)  ~    COM     (x ~ y)
 *  5)  <<   SL      (x << y)
 *  6)  >>   SR      (x >> y)
 */


/*
 * Assignment  Operators
 *  1)  =       x = y + z       
 *  2)  +=      x += y  
 *  3)  -=      x -= y
 *  4)  *-      x *= y
 *  5)  /=      x /= y
 *  6)  %=      x %= y
 *  7)  <<=     x <<= y
 *  8)  >>=     x >>= y
 *  9)  &=      x &= y
 * 10)  |=      x |= y
 * 11)  ^=      x ^= y
 */

/*
 * Operators Precedence
 */

#include <xc.h>
#include <stdio.h>
#include <stdint.h>

int main(void) 
{
    
    /*
    * Operators Precedence
    */
    
    double x, y, z;
    
    x = 1.5;
    y = 2.0;
    z = 5.0;
    
    // 1)  x+y*z
    // 2)  (x+y)*z
    // 3)  x+(y*z)
    //printf( "1) %f\r\n", x+y*z    );
    //printf( "2) %f\r\n", (x+y)*z  );
    //printf( "3) %f\r\n", x+(y*z)  );
    
    
    // x + y / z - 1.7
    //printf( "1) %f\r\n", x + y / z - 1.7    );
    //printf( "2) %f\r\n", (x + y) / z - 1.7  );
    //printf( "3) %f\r\n", x + (y / z) - 1.7  );
    
    // 12.0 + 3.0 + 4.0 / 2.0 + 3.0 + 1.0
    //printf( "1) %f\r\n", 12.0 + 3.0 + 4.0 / 2.0 * 3.0 + 4.0 );
    //printf( "2) %f\r\n", 12.0 + 3.0 + (4.0 / 2.0) * 3.0 + 4.0 );
    //printf( "3) %f\r\n", 12.0 + 3.0 + 4.0 / (2.0 * 3.0) + 4.0 );
    //printf( "4) %f\r\n", ( (12.0 + 3.0) + (4.0 / 2.0)) * (3.0 + 4.0) );

    while(!0);
}











