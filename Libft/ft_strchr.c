#include	"libft.h"
//#include	<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	char	str[] = "leonardo";
	printf("%s", ft_strchr(str, 'l'));
}
*/
