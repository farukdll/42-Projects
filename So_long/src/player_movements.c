#include "so_long.h"

void	moveup(t_data *data)
{
	if (data->buffer[data->index - data->map_width - 1] != '1'
		&& (data->buffer[data->index - data->map_width - 1] != 'E'
			|| data->collect == data->exp))
	{
		data->step++;
		data->character = data->img[7];
		if (data->buffer[data->index - data->map_width - 1] == 'C')
			data->exp += 1;
		data->buffer[data->index] = '0';
		if (data->buffer[data->index - data->map_width - 1] == 'E')
			data->gameend = 1;
		data->buffer[data->index - data->map_width - 1] = 'P';
		ft_printf("%d\n", data->step);
	}
}

void	movedown(t_data *data)
{
	if (data->buffer[data->index + data->map_width + 1] != '1'
		&& (data->buffer[data->index + data->map_width + 1] != 'E'
			|| data->collect == data->exp))
	{
		data->step++;
		data->character = data->img[4];
		if (data->buffer[data->index + data->map_width + 1] == 'C')
			data->exp += 1;
		data->buffer[data->index] = '0';
		if (data->buffer[data->index + data->map_width + 1] == 'E')
			data->gameend = 1;
		data->buffer[data->index + data->map_width + 1] = 'P';
		ft_printf("%d\n", data->step);
	}
}

void	moveright(t_data *data)
{
	if (data->buffer[data->index + 1] != '1'
		&& (data->buffer[data->index + 1] != 'E'
			|| data->collect == data->exp))
	{
		data->step++;
		data->character = data->img[5];
		if (data->buffer[data->index + 1] == 'C')
			data->exp += 1;
		data->buffer[data->index] = '0';
		if (data->buffer[data->index + 1] == 'E')
			data->gameend = 1;
		data->buffer[data->index + 1] = 'P';
		ft_printf("%d\n", data->step);
	}
}

void	moveleft(t_data *data)
{
	if (data->buffer[data->index - 1] != '1'
		&& (data->buffer[data->index - 1] != 'E'
			|| data->collect == data->exp))
	{
		data->step++;
		data->character = data->img[6];
		if (data->buffer[data->index - 1] == 'C')
			data->exp += 1;
		data->buffer[data->index] = '0';
		if (data->buffer[data->index - 1] == 'E')
			data->gameend = 1;
		data->buffer[data->index - 1] = 'P';
		ft_printf("%d\n", data->step);
	}
}

int	key_events(int keycode, t_data *data)
{
	if (keycode == 13)
		moveup(data);
	if (keycode == 0)
		moveleft(data);
	if (keycode == 1)
		movedown(data);
	if (keycode == 2)
		moveright(data);
	if (keycode == 53)
		game_finish(data);
	mlx_clear_window(data->mlx, data->mlx_window);
	put_image_background(data);
	put_image_to_window(data);
	write_scr(data);
	return (keycode);
}
