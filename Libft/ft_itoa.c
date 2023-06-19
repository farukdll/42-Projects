#include	"libft.h"
//#include	<stdio.h>

static int	ft_negative(int nb)
{
	if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

static int	len(int n)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	if (n < 0)
	{
		while (n)
		{
			n = n / 10;
			b++;
		}
		return (b);
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		strng;
	int		is_negative;

	is_negative = n < 0;
	strng = len(n);
	p = (char *)malloc(sizeof(char) * (strng + 1));
	if (!p)
		return (NULL);
	p[strng] = '\0';
	strng--;
	while (strng >= 0)
	{
		p[strng--] = (ft_negative(n % 10) + 48);
		n /= 10;
	}
	if (is_negative)
		p[0] = '-';
	return (p);
}
/*
int	main()
{
	printf("%s\n",  ft_itoa(-21));
}
*/
