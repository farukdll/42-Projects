#include "./so_long.h"

void	ft_img_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 8)
		mlx_destroy_image(data->mlx, data->img[i]);
	free(data->img);
}

void	ft_map_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i++] = NULL;
	}
	free(data->map);
}

void	game_finish(t_data *data)
{
	if (data->collect == data->exp && data->gameend == 1)
		ft_printf("Number of player moves = %d\n", data->step);
	ft_img_free(data);
	mlx_destroy_window(data->mlx, data->mlx_window);
	ft_map_free(data);
	free(data->buffer);
	free(data);
	exit(1);
}
