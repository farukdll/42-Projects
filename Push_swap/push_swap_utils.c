#include "push_swap.h"

void	incoming_arg(t_data *data)
{
	if (data->a_size == 3)
		three_arg_operations(data);
	else if (data->a_size == 2)
		check_the_first_two(data);
	else if (data->a_size == 5)
		five_sorted(data);
	else
		radix_sort(data);
}

int	find_min_number(int *arr, size_t size, long start)
{
	size_t	i;
	int		second;

	i = -1;
	while (++i < size)
		if (arr[i] > start)
			second = i;
	i = -1;
	while (++i < size)
	{
		if (arr[i] > start && arr[i] < arr[second])
			second = i;
	}
	return (second);
}

void	index_a(t_data *data)
{
	int		i;
	long	min;
	int		minindex;
	int		*temp;

	temp = malloc(sizeof(int) * data->a_size);
	i = -1;
	min = -2147483649;
	while (++i < data->a_size)
	{
		minindex = find_min_number(data->a, data->a_size, min);
		min = data->a[minindex];
		temp[minindex] = i + 1;
	}
	free(data->a);
	data->a = temp;
}

int	same_number_cont(t_data *x)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = x->a_size;
	while (i < size)
	{
		j = 1 + i;
		while (j < size)
		{
			if (x->a[i] == x->a[j])
				ft_error();
			else
				j++;
		}
		i++;
	}
	return (0);
}
