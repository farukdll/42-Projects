#include "./lib/cub3D.h"

static void	set_camera_zero(t_proc *proc)
{
	proc->t_cam.pos_x = 0;
	proc->t_cam.pos_y = 0;
	proc->t_cam.dir_x = 0;
	proc->t_cam.dir_y = 0;
	proc->t_cam.plane_x = 0;
	proc->t_cam.plane_y = 0;
	proc->t_cam.display = 1;
}

static void	set_plyr_zero(t_proc *proc)
{
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0;
	proc->g_plyr.ddist_x = 0;
	proc->g_plyr.ddist_y = 0;
	proc->g_plyr.dir_x = 0;
	proc->g_plyr.dir_y = 0;
	proc->g_plyr.loc_x = 0;
	proc->g_plyr.loc_y = 0;
	proc->g_plyr.sdist_x = 0;
	proc->g_plyr.sdist_y = 0;
	proc->g_plyr.sx = 0;
	proc->g_plyr.sy = 0;
	proc->g_plyr.movespd = 0.03;
	proc->g_plyr.rotspd = 0.02;
}

void	set_zero2(t_proc *proc)
{
	set_camera_zero(proc);
	set_plyr_zero(proc);
}
