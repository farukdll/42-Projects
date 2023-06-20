#include "so_long.h"

void	check_c_e_control(char *map, t_data *data, int *exit)
{
	if (*map == 'C')
		data->collect++;
	else if (*map == 'E')
		(*exit)++;
}

void	check_all_p_c_e(t_data *data, int *player, int *exit, int *other)
{
	if (!(*player == 1 && data->collect >= 1 && *exit == 1)
		|| (int)data->map_height != ++(*other))
		map_parent_error(data, 1);
}

static int	map_row_cnt(t_data *data)
{
	char	**map;
	int		i;

	i = 0;
	map = data->map;
	while (*map++)
		i++;
	return (i);
}

void	map_key_control(t_data *data)
{
	int	arg;
	int	idx;
	int	row_cnt;

	arg = 1;
	idx = 1;
	row_cnt = map_row_cnt(data);
	while (arg < row_cnt)
	{
		idx = 1;
		while (data->map[arg][idx])
		{
			if (data->map[arg][idx] == '0' || data->map[arg][idx] == 'P' || \
				data->map[arg][idx] == '1' || data->map[arg][idx] == 'C' || \
				data->map[arg][idx] == 'E')
					idx++;
			else
			{
				ft_printf("Error\nUndefined CHARACTER!!\n");
				ft_printf("Arg: %d\nIdx: %d\n", arg, idx);
				exit(1);
			}
		}
		arg++;
	}
}
