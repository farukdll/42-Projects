#include "libft.h"
//#include	<stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;

	size = 0;
	if (!s || !len || ft_strlen(s) <= start)
		return (ft_strdup(""));
	while (s[start + size] && size < len)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	size = 0;
	while (s[start] && size < len)
		str[size++] = s[start++];
	str[size] = 0;
	return (str);
}
/*
int	main()
{
    printf("%s", ft_substr("Leonardoooooooo", 0, 3));
}
*/
