#include "./lib/cub3D.h"

int	player_loc2(t_proc *proc, int x, int y, char c)
{
	proc->t_cam.pos_x = (double)x + 0.5;
	proc->t_cam.pos_y = (double)y + 0.5;
	if (c == 'W')
	{
		proc->t_cam.dir_x = -1;
		proc->t_cam.dir_y = 0;
		proc->t_cam.plane_x = 0;
		proc->t_cam.plane_y = -1;
		return (1);
	}
	if (c == 'E')
	{
		proc->t_cam.dir_x = 1;
		proc->t_cam.dir_y = 0;
		proc->t_cam.plane_x = 0;
		proc->t_cam.plane_y = 1;
		return (1);
	}
	return (0);
}

int	player_loc(t_proc *proc, int x, int y, char c)
{
	proc->t_cam.pos_x = (double)x + 0.5;
	proc->t_cam.pos_y = (double)y + 0.5;
	if (c == 'N')
	{
		proc->t_cam.dir_x = 0;
		proc->t_cam.dir_y = -1;
		proc->t_cam.plane_x = 1;
		proc->t_cam.plane_y = 0;
		return (1);
	}
	if (c == 'S')
	{
		proc->t_cam.dir_x = 0;
		proc->t_cam.dir_y = 1;
		proc->t_cam.plane_x = -1;
		proc->t_cam.plane_y = 0;
		return (1);
	}
	return (0);
}
