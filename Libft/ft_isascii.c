#include	"libft.h"
//#include	<stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main()
{
	printf ("%d", ft_isascii(200));
}
*/
