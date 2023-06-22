#include "./lib/cub3D.h"

static int	check_map_in(char *map, int *ac)
{
	if (ft_strcmp(map, "NO") || ft_strcmpc(map, 'N'))
		*ac += 1;
	else if (ft_strcmp(map, "SO") || ft_strcmpc(map, 'S'))
		*ac += 1;
	else if (ft_strcmp(map, "WE") || ft_strcmpc(map, 'W'))
		*ac += 1;
	else if (ft_strcmp(map, "EA") || ft_strcmpc(map, 'E'))
		*ac += 1;
	else if (ft_strcmpc(map, 'F'))
		*ac += 1;
	else if (ft_strcmpc(map, 'C'))
		*ac += 1;
	else if (check_spaces(map))
		*ac += 0;
	else
		return (-1);
	if (*ac <= 6)
		return (1);
	return (0);
}

void	check_trans_frgb(char *Frgb, t_proc *proc)
{
	char	**rgbno;
	int		i;

	i = 0;
	while (*Frgb == ' ' || *Frgb == '\t')
		Frgb++;
	rgbno = ft_split(Frgb + 1, ',', proc);
	while (rgbno[i])
		i++;
	if (i != 3)
	{
		printf("Error\nFrgb arguments is fail");
		exit (1);
	}
	check_trans_frgb2(rgbno, proc);
	if ((proc->f_rgb.rgb_r >= 0 && proc->f_rgb.rgb_r <= 255) \
		&& (proc->f_rgb.rgb_g >= 0 && proc->f_rgb.rgb_g <= 255) \
		&& (proc->f_rgb.rgb_b >= 0 && proc->f_rgb.rgb_b <= 255))
		proc->f_rgb.rgb = frgbtrans(rgbno);
	else
	{
		printf("Error\nFrgb not true");
		exit(1);
	}
	free(rgbno);
}

void	check_trans_crgb(char *Crgb, t_proc *proc)
{
	char	**rgbno;
	int		i;

	i = 0;
	while (*Crgb == ' ' || *Crgb == '\t')
		Crgb++;
	rgbno = ft_split(Crgb + 1, ',', proc);
	while (rgbno[i])
		i++;
	if (i != 3)
	{
		printf("Error\nCrgb arguments is fail");
		exit (1);
	}
	check_trans_crgb2(rgbno, proc);
	if ((proc->c_rgb.rgb_r >= 0 && proc->c_rgb.rgb_r <= 255) \
		&& (proc->c_rgb.rgb_g >= 0 && proc->c_rgb.rgb_g <= 255) \
		&& (proc->c_rgb.rgb_b >= 0 && proc->c_rgb.rgb_b <= 255))
		proc->c_rgb.rgb = crgbtrans(rgbno);
	else
	{
		printf("Error\nCrgb not true");
		exit(1);
	}
	free(rgbno);
}

void	check_trans_img(char *map, t_proc *proc)
{
	if (ft_strcmp(map, "NO") || ft_strcmp(map, "SO") \
		|| ft_strcmp(map, "WE") || ft_strcmp(map, "EA"))
		check_img_two(map, proc);
	else if (ft_strcmpc(map, 'N') || ft_strcmpc(map, 'S') \
		|| ft_strcmpc(map, 'W') || ft_strcmpc(map, 'E'))
		check_img_one(map, proc);
	else
	{
		printf("Error\nMap Arguman is wrong\n");
		exit(1);
	}
}

void	map_trans_rpg_img_gmap(t_proc *proc)
{
	int		i;
	int		ac;

	i = 0;
	ac = 0;
	proc->map = skip_space_enter(proc);
	while (proc->map[i])
	{
		if (proc->map[i])
			map_check_all(proc, i);
		if (proc->map[i])
		{
			if (check_map_in(proc->map[i], &ac) == 1)
				i++;
			else
			{
				printf("Error\nWrong map stil\n");
				exit (1);
			}
			if (ac == 6)
				break ;
		}
	}
	proc->g_map.map = proc->map + i;
	gmap_control(proc);
}
