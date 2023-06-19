#include	"libft.h"
//#include	<stdio.h>

static size_t	ft_toklen(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
/*
int	main()
{
	char	*a = "Ninja Kaplumbağalar Regulary Show";
	char	**res = ft_split(a, ' ');
	int		index = 0;
	
	while (res[index])
	{
		printf("%s\n", res[index]);
		index++;
	}
}
*/
