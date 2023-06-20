#include "so_long.h"

static void	mallocfree(t_data *data)
{
	ft_map_free(data);
	free(data->buffer);
	ft_printf("Error\n Malloc Error İn data->img*\n");
	exit(1);
}

static void	specialfree(t_data *data)
{
	while (data->indeximg--)
		if (data->img[data->indeximg] != NULL)
			mlx_destroy_image(data->mlx, data->img[data->indeximg]);
	free(data->img);
	ft_map_free(data);
	free(data->buffer);
	ft_printf("Error\n Malloc Error Or Missing XPM File\n");
	exit(1);
}

static void	subsystem_for_image(t_data *data, char *path)
{
	data->img[data->indeximg] = mlx_xpm_file_to_image(data->mlx, path,
			&data->imgx, &data->imgy);
	if (data->img[data->indeximg] == NULL)
	{
		data->indeximg++;
		specialfree(data);
	}
	else
		data->indeximg++;
}

void	create_image_and_window(t_data *data)
{
	data->img = (void **)malloc(sizeof(void *) * 8);
	if (!data->img)
	{
		free(data->img);
		mallocfree(data);
	}
	subsystem_for_image(data, GROUND);
	subsystem_for_image(data, WALL);
	subsystem_for_image(data, COLLECT);
	subsystem_for_image(data, DOOR1);
	subsystem_for_image(data, PL_FT);
	subsystem_for_image(data, PL_LT);
	subsystem_for_image(data, PL_RT);
	subsystem_for_image(data, PL_BK);
}

void	check_img_and_window(t_data *data)
{
	data->mlx_window = mlx_new_window(data->mlx, 64 * data->map_width,
			64 * data->map_height, "So_Long");
	if (!data->mlx_window)
		game_finish(data);
	data->character = data->img[4];
}
