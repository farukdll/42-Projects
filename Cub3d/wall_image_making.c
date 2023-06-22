#include "./lib/cub3D.h"

void	wall_image_make(t_proc *proc)
{
	proc->imgs[0].img = mlx_xpm_file_to_image(proc->mlx, \
			proc->img.ea, &proc->imgs[0].img_y, &proc->imgs[0].img_x);
	proc->imgs[1].img = mlx_xpm_file_to_image(proc->mlx, \
			proc->img.no, &proc->imgs[1].img_y, &proc->imgs[1].img_x);
	proc->imgs[2].img = mlx_xpm_file_to_image(proc->mlx, \
			proc->img.so, &proc->imgs[2].img_y, &proc->imgs[2].img_x);
	proc->imgs[3].img = mlx_xpm_file_to_image(proc->mlx, \
			proc->img.we, &proc->imgs[3].img_y, &proc->imgs[3].img_x);
	proc->imgs[0].imgadd = mlx_get_data_addr(proc->imgs[0].img, \
		&proc->bpp, &proc->line_size, &proc->endian);
	proc->imgs[1].imgadd = mlx_get_data_addr(proc->imgs[1].img, \
		&proc->bpp, &proc->line_size, &proc->endian);
	proc->imgs[2].imgadd = mlx_get_data_addr(proc->imgs[2].img, \
		&proc->bpp, &proc->line_size, &proc->endian);
	proc->imgs[3].imgadd = mlx_get_data_addr(proc->imgs[3].img, \
		&proc->bpp, &proc->line_size, &proc->endian);
}

void	mlx_image_make(t_proc *proc)
{
	proc->mlx_img = mlx_new_image(proc->mlx, WIDTH, HEIGHT);
	proc->imgaddr = mlx_get_data_addr(proc->mlx_img, &proc->bpp, \
		&proc->line_size, &proc->endian);
}

void	raycasting_column_start_end(t_proc *proc)
{
	proc->lineheight = abs((int)((double)HEIGHT / proc->g_plyr.wall_dist));
	proc->draw_start = -proc->lineheight / 2 + (double)HEIGHT / 2;
	proc->draw_end = proc->lineheight / 2 + (double)HEIGHT / 2;
	if (proc->draw_start < 0)
		proc->draw_start = 0;
	if (proc->draw_end >= HEIGHT)
		proc->draw_end = HEIGHT - 1;
}

static void	raycasting_print_map(t_proc *proc)
{
	int	color;

	proc->y = proc->draw_start;
	while (proc->y < proc->draw_end)
	{
		proc->img.img_y = (int)((proc->y * 2 - HEIGHT + proc->lineheight)
				* (IMG_HEIGHT / 2) / proc->lineheight);
		if (proc->g_plyr.wall_dir == 0 && proc->g_plyr.dir_x > 0)
			proc->color = 0;
		else if (proc->g_plyr.wall_dir == 0 && proc->g_plyr.dir_x < 0)
			proc->color = 1;
		else if (proc->g_plyr.wall_dir == 1 && proc->g_plyr.dir_y > 0)
			proc->color = 2;
		else if (proc->g_plyr.wall_dir == 1 && proc->g_plyr.dir_y < 0)
			proc->color = 3;
		color = ((unsigned int *)proc->imgs[proc->color].imgadd) \
		[(IMG_WIDTH * proc->img.img_y + proc->img.img_x)];
		game_pixel_put(proc, proc->x, proc->y, color);
		proc->y++;
	}
}

void	raycasting_all(t_proc *proc)
{
	raycasting_init(proc);
	raycasting_player_angle(proc);
	raycasting_wall_pass(proc);
	raycasting_column_start_end(proc);
	raycasting_wall_orien(proc);
	raycasting_print_map(proc);
}
