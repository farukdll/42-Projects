#include	"libft.h"
//#include	<stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
/*
char	fonk(unsigned int i, char c)
{
	return (c + i);
}
int	main()
{
    printf("%s", ft_strmapi("Ldmk]m^h", fonk));
}
*/
