#include "libft.h"
//#include <stdio.h>

static	int	atoi_min_max(t_data *x)
{
	write(1, "Error\n", 6);
	free(x->a);
	free(x->b);
	exit(1);
}

int	ft_atoi(const char *str, t_data *x)
{
	long int	num;
	int			n;

	n = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= n;
	if (num > 2147483647 || num < -2147483648)
		atoi_min_max(x);
	return (num);
}
/*
int main()
{
    printf("%d\n", ft_atoi("   -123oo1"));
    printf("%d", atoi("-1231"));
}
*/
