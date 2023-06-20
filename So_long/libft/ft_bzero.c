#include	"libft.h"
//#include	<stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int main()
{
	char	x[] = "leonardo";
	ft_bzero(x+3, 5);
	printf("%c\n", x);
}
*/
