#include	"libft.h"
//#include	<stdio.h>

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}
/*
int	main()
{
	printf("%d", ft_tolower('A'));
}
*/
