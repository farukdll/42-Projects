#include "../src/so_long.h"

void	write_scr(t_data *data)
{
	char	*variable;

	variable = ft_itoa(data->exp * 42);
	mlx_string_put(data->mlx, data->mlx_window, 0, 20, 0xffff99, "Game Point");
	mlx_string_put(data->mlx, data->mlx_window, 80, 20, 0xffff99, variable);
	free(variable);
	variable = ft_itoa(data->step);
	mlx_string_put(data->mlx, data->mlx_window, 150, 20, 0xffff99, "Step : ");
	mlx_string_put(data->mlx, data->mlx_window, 200, 20, 0xffff99, variable);
	free(variable);
}
