#include "push_swap.h"

void	ft_rrb(t_data *data)
{
	int	b;

	b = data->b[data->b_size -1];
	ft_memmove(data->b + 1, data->b, data->b_size * 4);
	data->b[0] = b;
	write(1, "rrb\n", 4);
}

void	ft_pb(t_data *data)
{
	int	tmp;

	if (data->a_size > 0)
	{
		tmp = data->a[0];
		ft_memmove(data->a, data->a + 1, data->a_size * 4);
		ft_memmove(data->b + 1, data->b, data->b_size * 4);
		data->b[0] = tmp;
		data->a_size--;
		data->b_size++;
		write(1, "pb\n", 3);
	}
}

void	ft_pa(t_data *data)
{
	int	tmp;

	if (data->b_size > 0)
	{
		tmp = data->b[0];
		ft_memmove(data->b, data->b + 1, data->b_size * 4);
		ft_memmove(data->a + 1, data->a, data->a_size * 4);
		data->a[0] = tmp;
		data->b_size--;
		data->a_size++;
		write(1, "pa\n", 3);
	}
}

void	check_the_first_two(t_data *data)
{
	if (data->a[0] == 2)
		ft_swap_a(data);
}
