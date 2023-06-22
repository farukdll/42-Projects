#include "./lib/cub3D.h"

static	void	proc_zero(t_proc *proc)
{
	proc->row_cnt = 0;
	proc->row_len = 0;
	proc->new_cnt = 0;
	proc->c_arg = 0;
	proc->c_idx = 0;
}

static	void	gmap_zero(t_gmap *g_map)
{
	g_map->c_arg = 0;
	g_map->c_idx = 0;
	g_map->char_cnt = 0;
}

static	void	kbd_zero(t_kbd *kbd)
{
	kbd->a = 0;
	kbd->d = 0;
	kbd->l = 0;
	kbd->r = 0;
	kbd->s = 0;
	kbd->w = 0;
}

static	void	rgp_zero(t_rpg *rgb)
{
	rgb->rgb_r = 0;
	rgb->rgb_g = 0;
	rgb->rgb_b = 0;
	rgb->rgb = 0;
}

int	set_zero(t_proc *proc)
{
	rgp_zero(&proc->f_rgb);
	rgp_zero(&proc->c_rgb);
	kbd_zero(&proc->kbd);
	gmap_zero(&proc->g_map);
	proc_zero(proc);
	set_zero2(proc);
	return (1);
}
