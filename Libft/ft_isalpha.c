#include "libft.h"
//#include	<stdio.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
int main()
{
	printf("%d",ft_isalpha('C'));
}
*/
