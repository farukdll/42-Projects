#include "push_swap.h"

int	number_countt(int argc, char **argv)
{
	int	i;
	int	number_count;

	i = 1;
	number_count = 0;
	while (i < argc)
	{
		number_count += w_c(argv[i], ' ');
		i++;
	}
	return (number_count);
}

int	number_control(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || \
			((*str == '-' || *str == '+') && (str[1] >= '0' && str[1] <= '9'))))
			return (1);
		if (*str == '+' && str[1] == '+')
			return (1);
		if ((*str == '-' || *str == '+') && str[1] == '0')
			return (1);
		str++;
	}
	return (0);
}

void	arg_al(t_data *x, int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;
	int		number_count;

	number_count = number_countt(argc, argv);
	x->a = (int *)malloc(number_count * sizeof(int *));
	x->b = (int *)malloc(number_count * sizeof(int *));
	i = 1;
	x->a_size = 0;
	x->b_size = 0;
	while (i < argc)
	{
		str = ft_split(argv[i++], ' ');
		j = 0;
		while (str[j])
		{
			if (number_control(str[j]) == 1)
				ft_error();
			ft_atoi(str[j], x);
			x->a[x->a_size++] = ft_atoi(str[j++], x);
		}
		ft_free(str);
	}
}

int	sort_control(t_data *x)
{
	int	i;
	int	size;

	size = x->a_size;
	i = 0;
	while (i < size - 1)
	{
		if (x->a[i] < x->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
		if (!ft_strlen(argv[i++]))
			ft_error();
	arg_al(&data, argc, argv);
	if (sort_control(&data) == 1 || same_number_cont(&data) == 1)
		return (0);
	index_a(&data);
	incoming_arg(&data);
	if (data.a[0] > data.a[1])
		ft_swap_a(&data);
	free(data.a);
	free(data.b);
}
