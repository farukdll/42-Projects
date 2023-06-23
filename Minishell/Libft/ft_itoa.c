#include "libft.h"

char	ft_getdigit(int nb)
{
	int	i;

	i = 1;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_putint(unsigned int u_nb, const int nb, const char len, char *arr)
{
	int	i;
	int	index;

	if (nb < 0)
	{
		index = 2;
		arr[len - 1] = '\0';
	}
	else
	{
		index = 3;
		arr[len - 2] = '\0';
	}
	i = 0;
	while (u_nb)
	{
		arr[len - index - i++] = u_nb % 10 + '0';
		u_nb /= 10;
	}
	return (arr);
}

char	*ft_itoa(int nb)
{
	unsigned int	u_nb;
	char			*arr;
	char			ndigit;

	if (nb == 0)
		return (ft_strdup("0\0"));
	ndigit = ft_getdigit(nb) + 1;
	arr = malloc(ndigit);
	if (!arr)
		return (0);
	if (nb < 0)
	{
		u_nb = -nb;
		arr[0] = '-';
	}
	else
		u_nb = nb;
	return (ft_putint(u_nb, nb, ndigit, arr));
}
