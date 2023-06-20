#include "so_long.h"

int	xbutton(t_data *data)
{
	game_finish(data);
	return (0);
}

int	happyend(t_data *data)
{
	int	i;

	i = 0;
	if (data->gameend == 1)
	{
		ft_printf("Game Over!\n");
		while (i++ < 100000)
			;
		game_finish(data);
	}
	return (0);
}

int	error_handler( char **argv, t_data	*data)
{
	if (check_map_type(argv[1]))
	{
		get_map(data, argv[1]);
	}
	else
		map_type_error();
	if (control_path(data))
	{
		ft_printf("Error\n Map Not Working");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)ft_calloc(sizeof(t_data), 1);
		if (!data)
			exit(1);
		data->mlx = mlx_init();
		if (error_handler(argv, data))
			return (-1);
		create_image_and_window(data);
		check_img_and_window(data);
		put_image_background(data);
		put_image_to_window(data);
		map_key_control(data);
		mlx_loop_hook(data->mlx, happyend, data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_events, data);
		mlx_hook(data->mlx_window, 17, 0, xbutton, data);
		write_scr(data);
		mlx_loop(data->mlx);
	}
	else
		ft_printf("Error\n Wrong Argument");
	exit(1);
}
