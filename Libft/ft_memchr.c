#include	"libft.h"
//#include	<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	dll;

	dll = 0;
	while (dll < n)
	{
		if (*(unsigned char *)(s + dll) == (unsigned char)c)
			return ((void *)(s + dll));
		dll++;
	}
	return (NULL);
}
/*
int main()
{
	char a[] = "LEOnardo";
	printf("%s",ft_memchr(a,'n',5));
}
*/
