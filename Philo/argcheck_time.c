#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		i++;
	}
	return (number);
}

int	ft_argcheck(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 6 && argc != 5)
		return (ERROR);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{	
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ERROR);
			if (ft_atol(argv[i]) > INT_MAX)
				return (ERROR);
			if (ft_atol(argv[i]) == 0)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (1);
}
