#include	"libft.h"
//#include	<stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			a = (char *)s;
		++s;
	}
	if (!c)
		a = ((char *)s);
	return (a);
}
/*
int	main()
{
	char str[] = "leonardo";
	printf("%s", ft_strrchr(str, 'd'));
}
*/
