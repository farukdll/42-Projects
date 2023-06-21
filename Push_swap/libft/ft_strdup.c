#include "libft.h"
//#include	<stdio.h>

char	*ft_strdup(const char *s)
{
	size_t	a;
	char	*b;

	a = ft_strlen(s);
	b = (char *)malloc(sizeof(char) * (a + 1));
	if (b == NULL)
		return (NULL);
	b[a] = 0;
	while (a--)
		b[a] = s[a];
	return (b);
}
/*
int	main()
{
	printf("%s", ft_strdup("ninja kaplumbağalar"));
}
*/
