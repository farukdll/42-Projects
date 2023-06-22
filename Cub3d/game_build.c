#include "./lib/cub3D.h"

void	game_pixel_put(t_proc *proc, int x, int y, int color)
{
	char	*offset;

	offset = proc->imgaddr + (y * (proc->line_size) + x * \
		(proc->bpp / 8));
	*(unsigned int *) offset = color;
}

void	f_rgb_up_color(t_proc *proc)
{
	while (proc->y < HEIGHT)
	{
		game_pixel_put(proc, proc->x, HEIGHT - proc->y - 1, proc->f_rgb.rgb);
		proc->y++;
	}
}

void	c_rgb_down_color(t_proc *proc)
{
	if (proc->draw_end < 0)
		proc->draw_end = HEIGHT;
	proc->y = proc->draw_end;
	while (proc->y < HEIGHT)
	{
		game_pixel_put(proc, proc->x, proc->y, proc->c_rgb.rgb);
		proc->y++;
	}
}

int	print_map(t_proc *proc)
{
	if (proc->kbd.w || proc->kbd.s || proc->kbd.a || proc->kbd.d \
		|| proc->kbd.l || proc->kbd.r || proc->t_cam.display)
	{
		proc->t_cam.display = 0;
		proc->x = 0;
		proc->y = 0;
		key_move(proc, &proc->t_cam);
		while (proc->x < WIDTH)
		{
			raycasting_all(proc);
			f_rgb_up_color(proc);
			c_rgb_down_color(proc);
			proc->x++;
		}
	}
	mlx_put_image_to_window(proc->mlx, proc->mlx_win, proc->mlx_img, 0, 0);
	return (1);
}
