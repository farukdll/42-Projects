#ifndef FUNC_H
# define FUNC_H

typedef struct s_gmap
{
	char	**map;
	int		**mapi;
	int		c_arg;
	int		c_idx;
	int		char_cnt;
}	t_gmap;

typedef struct s_kbd
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	r;
	int	l;
}	t_kbd;

typedef struct s_rpg
{
	int		rgb_r;
	int		rgb_b;
	int		rgb_g;
	int		rgb;
}		t_rpg;

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	void	*img;
	char	*imgadd;
	int		img_x;
	int		img_y;
}		t_img;

typedef struct s_plyr
{
	double	loc_x;
	double	loc_y;
	double	dir_x;
	double	dir_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	double	movespd;
	double	rotspd;
	double	cam_x;
	double	cam_y;
	double	map_x;
	double	map_y;
	double	wall_x;
	double	wall_y;
	double	wall_dist;
	int		wall_pass;
	int		wall_dir;
	int		sx;
	int		sy;

}		t_plyr;

typedef struct s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		display;
}		t_cam;

typedef struct s_proc
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;

	char	**map;
	int		row_cnt;
	int		row_len;
	int		new_cnt;
	int		c_arg;
	int		c_idx;

	char	*imgaddr;
	int		bpp;
	int		line_size;
	int		endian;
	int		color;
	int		x;
	int		y;
	int		draw_start;
	int		draw_end;
	int		lineheight;
	t_rpg	f_rgb;
	t_rpg	c_rgb;
	t_kbd	kbd;
	t_img	img;
	t_img	imgs[4];
	t_img	screen;
	t_gmap	g_map;
	t_plyr	g_plyr;
	t_cam	t_cam;
}		t_proc;

#endif