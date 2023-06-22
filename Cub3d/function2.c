#include "./lib/cub3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	if (s1[i] == s2[0])
	{
		if (s1[i + 1] == s2[1] && s1[i + 1] != ' ')
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	check_alp(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (-1);
		else if (str[i] == ' ')
			i++;
		else if ((str[i] >= 'a' && str[i] <= 'z') \
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (-1);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	while (str[a] == '\t' || str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '\0')
		return (-1);
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = (c * 10) + (str[a] - '0');
			a++;
	}
	if (check_alp(str + a) == -1)
		return (-1);
	return (c);
}

int	ft_strcmpc(const char *s1, const char s2)
{
	while (*s1 == ' ' || *s1 == '\t')
		s1++;
	if (*s1 == s2)
		return (1);
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	while (str && *str && *str != c)
		str++;
	if (c && !*str)
		return (NULL);
	return ((char *)str);
}
