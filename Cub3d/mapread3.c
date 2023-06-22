#include "./lib/cub3D.h"

void	gmap_control(t_proc *proc)
{
	char	**map;
	int		i;
	int		j;

	map = proc->g_map.map;
	i = 0;
	j = 0;
	while (i < proc->row_cnt - 6)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N' || \
				map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E' || \
				map[i][j] == ' ')
					j++;
			else
			{
				printf("Error\nWrong chacter in map\ni %d\tj %d\n", i + 1, j + 1);
				exit(1);
			}
		}
		i++;
	}
	gmap_wall_oc_check(proc);
}

int	map_wall_check(char **map, char c)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] && map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c && ((!j || map[i][j - 1] == ' ' || \
			!map[i][j + 1] || map[i][j] == ' ') || \
			(j + 1 > ft_strlen(map[i - 1]) || map[i - 1][j] == ' ') || \
			(j + 1 > ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')))
				return (-1);
			j++;
		}
		i++;
	}
	if (ft_strchr(map[i], c) || ft_strchr(map[0], c))
		return (-1);
	return (0);
}

void	gmap_wall_oc_check(t_proc *proc)
{
	char	**map;

	map = proc->g_map.map;
	if (map_wall_check(map, '0') || map_wall_check(map, 'N') || \
		map_wall_check(map, 'S') || map_wall_check(map, 'W') || \
		map_wall_check(map, 'E'))
	{
		printf("Error\nMap is not close\n");
		exit (1);
	}
}
