#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (i);
}
