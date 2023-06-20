#include "so_long.h"

void	cpy_make_map(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	data->cpy_map = ft_calloc(sizeof(char *), data->map_height + 1);
	i = -1;
	while (++i < data->map_height)
		data->cpy_map[i] = ft_calloc(sizeof(char), data->map_width + 1);
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			data->cpy_map[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	data->tmp_collect = data->collect;
}

void	valid_map_punctuation(t_data *data, int x, int y)
{
	char	*point;

	point = &data->cpy_map[y][x];
	if (*point == 'E')
		data->map_exit_control = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			data->tmp_collect--;
		*point = '.';
		if (data->cpy_map[y][x + 1] != '1'
		&& data->cpy_map[y][x + 1] != '.')
			valid_map_punctuation(data, x + 1, y);
		if (data->cpy_map[y][x - 1] != '1'
		&& data->cpy_map[y][x - 1] != '.')
			valid_map_punctuation(data, x - 1, y);
		if (data->cpy_map[y + 1][x] != '1'
		&& data->cpy_map[y + 1][x] != '.')
			valid_map_punctuation(data, x, y + 1);
		if (data->cpy_map[y - 1][x] != '1'
		&& data->cpy_map[y - 1][x] != '.')
			valid_map_punctuation(data, x, y - 1);
	}
}

void	collectible_control(t_data *data)
{
	int	i;

	i = 0;
	if (data->tmp_collect != 0)
	{
		while (i < data->map_height)
		{
			free(data->cpy_map[i]);
			i++;
		}
		free(data->cpy_map);
		free(data->buffer);
		free(data);
		invalid_valid_map_error();
	}
}

void	exit_controlll(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_exit_control == 0)
	{
		while (i < data->map_height)
		{
			free(data->cpy_map[i]);
			i++;
		}
		free(data->cpy_map);
		free(data->buffer);
		free(data);
		invalid_valid_map_error();
	}
}

int	control_path(t_data *data)
{
	int	result;
	int	i;

	i = 0;
	cpy_make_map(data);
	valid_map_punctuation(data, data->player_x, data->player_y);
	collectible_control(data);
	exit_controlll(data);
	while (i < data->map_height)
	{
		free(data->cpy_map[i]);
		i++;
	}
	free(data->cpy_map);
	result = 0;
	return (result);
}
