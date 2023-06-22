#include "./lib/cub3D.h"

void	raycasting_init(t_proc *proc)
{
	proc->g_plyr.cam_x = (2 * (double)proc->x / (double)WIDTH) - 1;
	proc->g_plyr.loc_x = proc->t_cam.pos_x;
	proc->g_plyr.loc_y = proc->t_cam.pos_y;
	proc->g_plyr.dir_x = proc->t_cam.dir_x + \
	proc->t_cam.plane_x * proc->g_plyr.cam_x;
	proc->g_plyr.dir_y = proc->t_cam.dir_y + \
	proc->t_cam.plane_y * proc->g_plyr.cam_x;
	proc->g_plyr.map_x = (int)proc->g_plyr.loc_x;
	proc->g_plyr.map_y = (int)proc->g_plyr.loc_y;
	proc->g_plyr.ddist_x = sqrt(1 + (proc->g_plyr.dir_y * proc->g_plyr.dir_y) \
		/ (proc->g_plyr.dir_x * proc->g_plyr.dir_x));
	proc->g_plyr.ddist_y = sqrt(1 + (proc->g_plyr.dir_x * proc->g_plyr.dir_x) \
		/ (proc->g_plyr.dir_y * proc->g_plyr.dir_y));
	proc->g_plyr.wall_pass = 0;
}

void	raycasting_player_angle(t_proc *proc)
{
	if (proc->g_plyr.dir_x < 0)
	{
		proc->g_plyr.sx = -1;
		proc->g_plyr.sdist_x = (proc->g_plyr.loc_x - proc->g_plyr.map_x)
			* proc->g_plyr.ddist_x;
	}
	else
	{
		proc->g_plyr.sx = 1;
		proc->g_plyr.sdist_x = (proc->g_plyr.map_x + 1 - proc->g_plyr.loc_x)
			* proc->g_plyr.ddist_x;
	}
	if (proc->g_plyr.dir_y < 0)
	{
		proc->g_plyr.sy = -1;
		proc->g_plyr.sdist_y = (proc->g_plyr.loc_y - proc->g_plyr.map_y)
			* proc->g_plyr.ddist_y;
	}
	else
	{
		proc->g_plyr.sy = 1;
		proc->g_plyr.sdist_y = (proc->g_plyr.map_y + 1 - proc->g_plyr.loc_y)
			* proc->g_plyr.ddist_y;
	}
}

void	raycasting_wall_pass(t_proc *proc)
{
	while (proc->g_plyr.wall_pass == 0)
	{
		if (proc->g_plyr.sdist_x < proc->g_plyr.sdist_y)
		{
			proc->g_plyr.sdist_x += proc->g_plyr.ddist_x;
			proc->g_plyr.map_x += proc->g_plyr.sx;
			proc->g_plyr.wall_dir = 0;
		}
		else
		{
			proc->g_plyr.sdist_y += proc->g_plyr.ddist_y;
			proc->g_plyr.map_y += proc->g_plyr.sy;
			proc->g_plyr.wall_dir = 1;
		}
		if (proc->g_map.mapi[(int)proc->g_plyr.map_y] \
			[(int)proc->g_plyr.map_x] == 1)
		{
			proc->g_plyr.wall_pass = 1;
		}
	}
	raycasting_wall_dist(proc);
}

void	raycasting_wall_dist(t_proc *proc)
{
	if (proc->g_plyr.wall_dir == 0)
	{
		proc->g_plyr.wall_dist = fabs((proc->g_plyr.map_x - proc->t_cam.pos_x \
			+ (1 - proc->g_plyr.sx) / 2) / proc->g_plyr.dir_x);
	}
	else
	{
		proc->g_plyr.wall_dist = fabs((proc->g_plyr.map_y - proc->t_cam.pos_y \
			+ (1 - proc->g_plyr.sy) / 2) / proc->g_plyr.dir_y);
	}
}

void	raycasting_wall_orien(t_proc *proc)
{
	if (proc->g_plyr.wall_dir == 0)
	{
		proc->g_plyr.wall_x = proc->g_plyr.loc_y + proc->g_plyr.wall_dist \
			* proc->g_plyr.dir_y;
	}
	else
	{
		proc->g_plyr.wall_x = proc->g_plyr.loc_x + proc->g_plyr.wall_dist \
			* proc->g_plyr.dir_x;
	}
	proc->g_plyr.wall_x -= floor(proc->g_plyr.wall_x);
	proc->img.img_x = (int)(proc->g_plyr.wall_x * IMG_WIDTH);
	if (proc->g_plyr.wall_dir == 0 && proc->g_plyr.dir_x > 0)
		proc->img.img_x = IMG_WIDTH - proc->img.img_x - 1;
	if (proc->g_plyr.wall_dir == 1 && proc->g_plyr.dir_y < 0)
		proc->img.img_x = IMG_WIDTH - proc->img.img_x - 1;
}
