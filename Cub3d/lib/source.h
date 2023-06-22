#ifndef SOURCE_H
# define SOURCE_H

//sort code
# define WIDTH 1920
# define HEIGHT 1080
# define IMG_WIDTH 256
# define IMG_HEIGHT 256

//mapcheck.c
int		mapcheck(char *map);
void	check_img_one(char *av, t_proc *proc);
void	check_img_two(char *av, t_proc *proc);
void	map_character_check(t_gmap *g_map);

//function.c
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c, t_proc *proc);

//function2.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(char *str);
int		ft_strcmpc(const char *s1, const char s2);
char	*ft_strchr(const char *str, int c);

//function3.c
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2, char const *s3);
int		ft_atoic(char str);

//set_zero.c
int		set_zero(t_proc *proc);

//set_zero2.c
void	set_zero2(t_proc *proc);

//mapread.c
void	map_read(t_proc *proc, char *av);
void	*get_map_free(void *f);
char	*get_map(int fd, char *av);
int		map_len(char *av);

//mapread2.c
void	map_trans_rpg_img_gmap(t_proc *proc);
void	check_trans_frgb(char *Frgb, t_proc *proc);
void	check_trans_crgb(char *Crgb, t_proc *proc);
void	check_trans_img(char *map, t_proc *proc);

//mapread3.c
void	gmap_control(t_proc *proc);	
void	gmap_wall_oc_check(t_proc *proc);
int		map_wall_check(char **map, char c);

//mapread4.c
int		frgbtrans(char **rgbno);
int		crgbtrans(char **rgbno);
void	g_mapexportintmap(t_proc *proc);

//mapread5.c
char	poles_casting(char cmap, int i, int j, t_proc *proc);
void	map_check_all(t_proc *proc, int i);
void	check_trans_crgb2(char	**rgbno, t_proc *proc);
void	check_trans_frgb2(char	**rgbno, t_proc *proc);

//mapread6.c
char	**skip_space_enter(t_proc *proc);
int		check_spaces(char *map);

//mapread7.c
void	map_enter_check(char *map);

//game_build.c
void	f_rgb_up_color(t_proc *proc);
void	c_rgb_down_color(t_proc *proc);
void	game_pixel_put(t_proc *proc, int x, int y, int color);
int		print_map(t_proc *proc);

//button_assignment.c
int		ft_exit(void *tmp);
int		button_up(int key, t_proc *proc);
int		button_down(int key, t_proc *proc);
void	button_assignment(t_proc *proc);

//key_move.c
void	key_move(t_proc *proc, t_cam *cam);

//wall_image_making.c
void	wall_image_make(t_proc *proc);
void	raycasting_column_start_end(t_proc *proc);
void	mlx_image_make(t_proc *proc);
void	raycasting_all(t_proc *proc);

//raycasting_init.c
void	raycasting_init(t_proc *proc);
void	raycasting_wall_pass(t_proc *proc);
void	raycasting_player_angle(t_proc *proc);
void	raycasting_wall_dist(t_proc *proc);
void	raycasting_wall_orien(t_proc *proc);

//playerloc.c
int		player_loc(t_proc *proc, int x, int y, char c);
int		player_loc2(t_proc *proc, int x, int y, char c);

#endif
