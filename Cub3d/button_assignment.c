#include "./lib/cub3D.h"

int	ft_exit(void *tmp)
{
	(void)tmp;
	exit(0);
}

int	button_up(int key, t_proc *proc)
{
	if (key == 13)
		proc->kbd.w = 1;
	else if (key == 1)
		proc->kbd.s = 1;
	else if (key == 0)
		proc->kbd.a = 1;
	else if (key == 2)
		proc->kbd.d = 1;
	else if (key == 123)
	{
		proc->kbd.l = 1;
		proc->g_plyr.rotspd = -0.06;
	}
	else if (key == 124)
	{
		proc->kbd.r = 1;
		proc->g_plyr.rotspd = 0.06;
	}
	else if (key == 257)
		proc->g_plyr.movespd += 0.09;
	else if (key == 53)
		exit(1);
	return (1);
}

int	button_down(int key, t_proc *proc)
{
	if (key == 13)
		proc->kbd.w = 0;
	else if (key == 1)
		proc->kbd.s = 0;
	else if (key == 0)
		proc->kbd.a = 0;
	else if (key == 2)
		proc->kbd.d = 0;
	else if (key == 123)
		proc->kbd.l = 0;
	else if (key == 124)
		proc->kbd.r = 0;
	else if (key == 257)
		proc->g_plyr.movespd -= 0.09;
	return (1);
}

void	button_assignment(t_proc *proc)
{
	mlx_hook(proc->mlx_win, 2, 0, button_up, proc);
	mlx_hook(proc->mlx_win, 3, 0, button_down, proc);
	mlx_hook(proc->mlx_win, 17, 0, ft_exit, 0);
	mlx_loop_hook(proc->mlx, print_map, proc);
}
