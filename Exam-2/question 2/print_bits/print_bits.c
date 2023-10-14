#include <stdio.h>
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 7;

	while (i--)
	{
		if (octet >> i & 1)
			write(1,"1",1);
            	else
                	write(1,"0",1);
	}
}

/*
int main(void)
{
	print_bits(1);
	printf("\n");
	print_bits(2);
	printf("\n");
	print_bits(3);
}
*/
