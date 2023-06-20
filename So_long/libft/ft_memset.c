#include	"libft.h"
//#include	<stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*wq;
	size_t			dll;

	dll = 0;
	wq = (unsigned char *)b;
	while (dll < len)
	{
		wq[dll++] = c;
	}
	return (wq);
}
/*
int	main()
{
	char str[] = "leonardo";
	printf("%s",ft_memset(str, 'b', 3));
}
*/
