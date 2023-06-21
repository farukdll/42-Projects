#include "push_swap.h"

void	ft_swap_a(t_data *data)
{
	int	tmp;

	if (data->a_size > 1)
	{
		tmp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_swap_b(t_data *data)
{
	int	tmp;

	if (data->b_size > 1)
	{
		tmp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_ra(t_data *data)
{
	int	b;

	b = data->a[0];
	ft_memmove(data->a, data->a + 1, data->a_size * 4);
	data->a[data->a_size -1] = b;
	write(1, "ra\n", 3);
}

void	ft_rb(t_data *data)
{
	int	b;

	b = data->b[0];
	ft_memmove(data->b, data->b + 1, data->b_size * 4);
	data->b[data->b_size -1] = b;
	write(1, "rb\n", 3);
}

void	ft_rra(t_data *data)
{
	int	b;

	b = data->a[data->a_size -1];
	ft_memmove(data->a + 1, data->a, data->a_size * 4);
	data->a[0] = b;
	write(1, "rra\n", 4);
}
