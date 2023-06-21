#include "push_swap.h"

void	three_arg_operations(t_data *data)
{
	if (data->a[0] == 3)
		ft_ra(data);
	if (data->a[1] == 3)
		ft_rra(data);
	if (data->a[0] == 2)
		ft_swap_a(data);
}

int	ft_find(t_data *data)
{
	int	i;

	i = 0;
	while (data->a_size > i)
	{
		if (data->a[i] == 1 || data->a[i] == 2)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	five_sorted(t_data *data)
{
	while (ft_find(data) != -1)
	{
		if (ft_find(data) == 0)
		{
			ft_pb(data);
		}
		else
			ft_ra(data);
	}
	if (data->a[0] == 5)
		ft_ra(data);
	if (data->a[1] == 5)
		ft_rra(data);
	if (data->a[0] == 4)
		ft_swap_a(data);
	ft_pa(data);
	ft_pa(data);
	if (data->a[0] == 2)
		ft_swap_a(data);
}

void	change_to_bit(t_data *data, int j)
{
	if (((data->a[0] >> j) & 1) == 0)
		ft_pb(data);
	else
		ft_ra(data);
}

void	radix_sort(t_data *data)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	i = 0;
	j = 0;
	bit_size = 8;
	if (data->a_size == 100)
	{
		bit_size = 6;
	}
	while (j <= bit_size)
	{
		i = 0;
		size = data->a_size;
		while (i < size)
		{
			change_to_bit(data, j);
			i++;
		}
		while (data->b_size != 0)
			ft_pa(data);
		j++;
	}
}
