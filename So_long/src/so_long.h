#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define GROUND "./src/img/game_ground.xpm"
# define WALL "./src/img/game_wall.xpm"
# define COLLECT "./src/img/game_collect.xpm"
# define DOOR1 "./src/img/exit_door_position_1.xpm"
# define PL_FT "./src/img/player_front.xpm"
# define PL_LT "./src/img/player_left.xpm"
# define PL_RT "./src/img/player_right.xpm"
# define PL_BK "./src/img/player_back.xpm"

typedef struct s_data
{
	char	**map;
	char	**cpy_map;
	char	*buffer;
	void	*mlx;
	void	*mlx_window;
	void	**img;
	void	*character;
	int		imgx;
	int		imgy;
	int		x;
	int		y;
	int		mapw1;
	int		indeximg;
	int		player_x;
	int		player_y;
	int		collect;
	int		tmp_collect;
	int		map_exit_control;
	int		exp;
	int		step;
	int		gameend;
	int		check_parent;
	size_t	map_width;
	size_t	map_height;
	size_t	index;
}	t_data;

void	write_scr(t_data *data);
void	take_img(t_data *data);
void	moveup(t_data *data);
void	moveleft(t_data *data);
void	movedown(t_data *data);
void	moveright(t_data *data);
int		key_events(int keycode, t_data *data);
void	create_image_and_window(t_data *data);
void	get_map(t_data *data, char *argv2);
void	put_image_to_window(t_data *data);
void	put_image_background(t_data *data);
void	ft_map_free(t_data *data);
void	ft_img_free(t_data *data);
void	check_map_parent(t_data *data);
void	check_map_wall(t_data *data);
int		check_map_type(char *argv2);
void	map_line_boundry_error(void);
void	map_parent_error(t_data *data, int i);
void	map_left_right_wall_error(void);
void	map_bottom_or_top_error(void);
void	map_type_error(void);
void	invalid_valid_map_error(void);
void	game_finish(t_data *data);
void	check_img_and_window(t_data *data);
int		control_path(t_data *win);
void	check_c_e_control(char *map, t_data *data, int *exit);
void	check_all_p_c_e(t_data *data, int *player, int *exit, int *other);
void	cpy_make_map(t_data *data);
void	valid_map_punctuation(t_data *data, int x, int y);
void	collectible_control(t_data *data);
void	exit_controlll(t_data *data);
void	map_key_control(t_data *data);

#endif
