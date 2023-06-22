#include "./lib/cub3D.h"

static int	map_space(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'F' || map[i] == 'C')
		{
			while (map[i])
			{
				if (map[i] == '\n')
					break ;
				else
					i++;
			}
		}
		else if (map[i] != '1')
			i++;
		else
			break ;
	}
	return (i);
}

static int	map_rspace(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	while (map[i])
	{
		if (map[i] != '1')
			i--;
		else
			break ;
	}
	i++;
	return (i);
}

static void	wall_enter(char *map, int j)
{
	int	i;

	i = 0;
	while (map[i] && i < j)
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			printf("Error\nMap is not close\n");
			exit(1);
		}
		i++;
	}
}

void	map_enter_check(char *map)
{
	int	i;
	int	j;
	int	idx;

	i = map_space(map);
	j = map_rspace(map);
	idx = j - i;
	wall_enter(map + i, idx);
}
