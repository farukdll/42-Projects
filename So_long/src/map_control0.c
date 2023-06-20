#include "so_long.h"

static void	control(int fd, char *buffer, char *tmp)
{
	if (!tmp)
	{
		free(buffer);
		ft_printf("Error\n Your Map İs NULL\n");
		exit(1);
	}
}

void	get_map(t_data *data, char *argv2)
{
	int		fd;
	char	*tmp;
	char	*buffer;
	char	*buff;

	buff = NULL;
	fd = open(argv2, O_RDONLY);
	if (fd < 0)
		map_type_error();
	buffer = ft_calloc(sizeof(char), 1);
	tmp = get_next_line(fd);
	control(fd, buffer, tmp);
	data->map_width = ft_strlen(tmp) - 1;
	while (tmp)
	{
		buff = ft_strjoin(buffer, tmp);
		free(buffer);
		free(tmp);
		buffer = buff;
		tmp = get_next_line(fd);
	}
	data->buffer = buffer;
	data->map = ft_split(buffer, '\n');
	check_map_wall(data);
}

void	check_map_parent(t_data *data)
{
	char		*map;
	static int	player = 0;
	static int	exit = 0;
	static int	other = 0;
	static int	ply_x = 0;

	map = data->buffer;
	while (*map)
	{
		if (*map == 'P')
		{
			data->player_y = other;
			data->player_x = ply_x;
			player++;
		}
		else if (*map == '\n')
		{
			ply_x = -1;
			other++;
		}
		check_c_e_control(map, data, &exit);
		ply_x++;
		map++;
	}
	check_all_p_c_e(data, &player, &exit, &other);
}

void	check_map_wall(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
		if (ft_strlen(data->map[i]) != data->map_width)
			map_parent_error(data, 2);
	i = -1;
	while (data->map[++i])
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
			map_parent_error(data, 3);
	j = i - 1;
	data->map_height = j + 1;
	i = -1;
	while (data->map[0][++i] && data->map[j][i])
		if (data->map[0][i] != '1' || data->map[j][i] != '1')
			map_parent_error(data, 4);
	check_map_parent(data);
}

int	check_map_type(char *argv2)
{
	size_t	size;

	if (!argv2)
		return (0);
	size = ft_strlen(argv2) - 1;
	if (argv2[size] == 'r' && argv2[size - 1] == 'e'
		&& argv2[size - 2] == 'b' && argv2[size - 3] == '.')
		return (1);
	else
		map_type_error();
	return (0);
}
