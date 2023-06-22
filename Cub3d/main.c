#include "./lib/cub3D.h"

static int	start_proc(t_proc *proc)
{
	proc->mlx = mlx_init();
	proc->mlx_win = mlx_new_window(proc->mlx, WIDTH, HEIGHT, "Cub3D");
	wall_image_make(proc);
	mlx_image_make(proc);
	button_assignment(proc);
	mlx_loop(proc->mlx);
	return (0);
}

static int	checker(char **av, t_proc *proc)
{
	if (!mapcheck(av[1]))
	{
		printf("Error\nWrong Map\n");
		return (0);
	}
	map_read(proc, av[1]);
	map_trans_rpg_img_gmap(proc);
	map_character_check(&proc->g_map);
	g_mapexportintmap(proc);
	if (!start_proc(proc))
		printf("Error\nGame is not start");
	return (0);
}

int	main(int ac, char **av)
{
	t_proc	proc;

	if (ac == 2)
	{
		set_zero(&proc);
		checker(av, &proc);
	}
	else
		printf("Error\nMissing argument or picture extension!!\n");
	return (0);
}
