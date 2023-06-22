#include "./lib/cub3D.h"

int	ft_strlen(const char *str)
{
	long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strjon(char const *s1, char const *s2, char *ab, int a)
{
	long	b;

	b = 0;
	while (a < ft_strlen(s1))
	{
		ab[a] = s1[a];
		a++;
	}
	while (b < ft_strlen(s2))
	{
		ab[a] = s2[b];
		a++;
		b++;
	}
	return (ab);
}

char	*ft_strjoin(char const *s1, char const *s2, char const *s3)
{
	long		a;
	long		b;
	char		*ab;

	a = 0;
	b = 0;
	ab = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + \
		ft_strlen(s3) + 1));
	if (!ab || !s1 || !s2 || !s3)
		return (0);
	ft_strjon(s1, s2, ab, a);
	a = ft_strlen(s1) + ft_strlen(s2);
	b = 0;
	while (b < ft_strlen(s3))
	{
		ab[a] = s3[b];
		a++;
		b++;
	}
	ab[a] = '\0';
	return (ab);
}

int	ft_atoic(char str)
{
	int	c;

	c = 0;
	if (str >= '0' && str <= '9')
		c = str - '0';
	return (c);
}
