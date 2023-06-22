#include "./lib/cub3D.h"

int	mapcheck(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (*map == 0 || i-- < 5)
		return (0);
	if (map[i] == 'b' && map[i - 1] == 'u' && map[i - 2] == 'c' && map[i - 3] \
			== '.')
		return (1);
	else
		return (0);
}

void	check_img_two(char *av, t_proc *proc)
{
	int		fd;

	while (*av == ' ' || *av == '\t')
		av++;
	fd = open(av + 3, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strcmp(av, "NO"))
			proc->img.no = av + 3;
		else if (ft_strcmp(av, "SO"))
			proc->img.so = av + 3;
		else if (ft_strcmp(av, "WE"))
			proc->img.we = av + 3;
		else if (ft_strcmp(av, "EA"))
			proc->img.ea = av + 3;
		close(fd);
	}
	else if (fd == -1)
	{
		printf("Error\nPicture is not true\n");
		close(fd);
		exit(1);
	}
}

void	check_img_one(char *av, t_proc *proc)
{
	int		fd;

	while (*av == ' ' || *av == '\t')
		av++;
	fd = open(av + 2, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strcmpc(av, 'N'))
			proc->img.no = av + 2;
		else if (ft_strcmpc(av, 'S'))
			proc->img.so = av + 2;
		else if (ft_strcmpc(av, 'W'))
			proc->img.we = av + 2;
		else if (ft_strcmpc(av, 'E'))
			proc->img.ea = av + 2;
		close(fd);
	}
	else if (fd == -1)
	{
		printf("Error\nPicture is not true\n");
		close(fd);
		exit(1);
	}
}

static void	check_charif(t_gmap *g_map)
{
	if (g_map->char_cnt == 0)
	{
		printf("Error\nNo character start direction\n");
		exit(1);
	}
	else if (g_map->char_cnt >= 2)
	{
		printf("Error\nCharacter start direction too much\n");
		exit(1);
	}
}

void	map_character_check(t_gmap *g_map)
{
	while (g_map->map[g_map->c_arg])
	{
		g_map->c_idx = 0;
		while (g_map->map[g_map->c_arg][g_map->c_idx])
		{
			if (g_map->map[g_map->c_arg] \
				[g_map->c_idx] == 'N')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'E')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'S')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'W')
			g_map->char_cnt += 1;
			g_map->c_idx++;
		}
		g_map->c_arg++;
	}
	check_charif(g_map);
}
