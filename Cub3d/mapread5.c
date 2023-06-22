#include "./lib/cub3D.h"

char	poles_casting(char cmap, int i, int j, t_proc *proc)
{
	if (cmap == 'E' && player_loc2(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'W' && player_loc2(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'N' && player_loc(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'S' && player_loc(proc, j, i, cmap))
		cmap = '0';
	else
		cmap = '1';
	return (cmap);
}

void	map_check_all(t_proc *proc, int i)
{
	if (ft_strcmp(proc->map[i], "NO") || ft_strcmpc(proc->map[i], 'N') \
		|| ft_strcmp(proc->map[i], "SO") || ft_strcmpc(proc->map[i], 'S') \
		|| ft_strcmp(proc->map[i], "WE") || ft_strcmpc(proc->map[i], 'W') \
		|| ft_strcmp(proc->map[i], "EA") || ft_strcmpc(proc->map[i], 'E'))
		check_trans_img(proc->map[i], proc);
	else if (ft_strcmpc(proc->map[i], 'F'))
		check_trans_crgb(proc->map[i], proc);
	else if (ft_strcmpc(proc->map[i], 'C'))
		check_trans_frgb(proc->map[i], proc);
}

void	check_trans_crgb2(char	**rgbno, t_proc *proc)
{
	proc->c_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->c_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->c_rgb.rgb_b = ft_atoi(rgbno[2]);
}

void	check_trans_frgb2(char	**rgbno, t_proc *proc)
{
	proc->f_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->f_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->f_rgb.rgb_b = ft_atoi(rgbno[2]);
}
