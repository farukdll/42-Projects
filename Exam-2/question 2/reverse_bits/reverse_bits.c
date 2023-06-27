#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
    return (((octet >> 0) & 1) << 7) |
           (((octet >> 1) & 1) << 6) |
           (((octet >> 2) & 1) << 5) |
           (((octet >> 3) & 1) << 4) |
           (((octet >> 4) & 1) << 3) |
           (((octet >> 5) & 1) << 2) |
           (((octet >> 6) & 1) << 1) |
           (((octet >> 7) & 1) << 0);
}
/*
int main()
{
    printf("%d\n", reverse_bits(38));
    printf("%d\n", reverse_bits(100));
}
*/
