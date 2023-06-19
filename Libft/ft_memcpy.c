#include	"libft.h"
//#include	<stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!n || src == dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char x[10] = "";
	char y[] = "leonardo";
	printf("\nKopyalanan Kısım = %s\n\n", ft_memcpy(x, y, 3));
}
*/
