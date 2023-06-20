#include "so_long.h"

static void	player(t_data *data, int i)
{
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->character,
		data->x, data->y);
	data->index = i;
}

void	put_image_to_window(t_data *data)
{
	data->mapw1 = 0;
	while (data->buffer[data->mapw1])
	{
		if (data->buffer[data->mapw1] == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1],
				data->x, data->y);
		if (data->buffer[data->mapw1] == 'C')
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2],
				data->x, data->y);
		if (data->buffer[data->mapw1] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3],
				data->x, data->y);
		if (data->buffer[data->mapw1] == '0')
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
				data->x, data->y);
		if (data->buffer[data->mapw1] == 'P')
			player(data, data->mapw1);
			data->x += 64;
		if (data->buffer[data->mapw1] == '\n')
		{
			data->x = 0;
			data->y += 64;
		}
		data->mapw1++;
	}
}

void	put_image_background(t_data *data)
{
	int	i;

	data->x = 0;
	data->y = 0;
	i = 0;
	while (data->buffer[i] != 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
			data->x, data->y);
		data->x += 64;
		if (data->buffer[i] == '\n')
		{
			data->x = 0;
			data->y += 64;
		}
		i++;
	}
	data->x = 0;
	data->y = 0;
}
