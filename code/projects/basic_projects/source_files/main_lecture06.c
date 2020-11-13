
#include <stdio.h>
#include <stdint.h>

void test(void)
{
    int16_t  x = 0;
    int16_t za = 0;
    
    register int16_t  y = 0;
    register int16_t zb = 0;
    
    for(x=0; x<500; x++) {
        za++;
    }
    
    for(y=0; y<500; y++) {
        zb--;
    }
}

int main(void) {
    while(1) {
        test();
    }
}







/*
int32_t  v1 = 120;

// 1) Print value of v1
printf("value: %ld\r\n", v1);

// 2) Print size of v1
printf("size: %d bits\r\n", sizeof(v1)*8);

// 3) Print address of v1
printf("address: 0x%p\r\n", &v1);
printf("address: 0x%x\r\n", (unsigned int)&v1);
printf("address: 0x%X\r\n", (uint16_t)&v1);
*/

/*
float vf  = 22.0f/7.0f;
double vd = 22.0/7.0;

printf("float -->  value: %f, size: %d, address: 0x%p\r\n", (double)vf, sizeof(vf), &vf);
//printf("value: %e, size: %d, address: 0x%p\r\n", (double)vf, sizeof(vf), &vf);
//printf("value: %E, size: %d, address: 0x%p\r\n", (double)vf, sizeof(vf), &vf);

printf("double --> value: %f, size: %d, address: 0x%p\r\n", vd, sizeof(vd), &vd);
*/

/*
uint8_t v1   = 0x12;
uint8_t v2   = 0x34;
uint16_t v3 = 0xAB56;
uint32_t v4 = 0x12345678;

printf("address of v1: 0x%p\r\n", &v1);
printf("address of v2: 0x%p\r\n", &v2);
printf("address of v3: 0x%p\r\n", &v3);
printf("address of v4: 0x%p\r\n", &v4);
 */