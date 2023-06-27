#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

/*
int main(void)
{
    char k1 = 't';
    char k2 = 'G';
    printf("k1_t After: %c\n", swap_bits(k1));
    printf("k2_G After: %c\n", swap_bits(k2));
}
*/
