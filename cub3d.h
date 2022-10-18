/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/18 11:02:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"
# include "utils/gnl/get_next_line.h"
# include <mlx.h>
# include <math.h>

# define IMG_H 64
# define IMG_W 64
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define VIEW_RIGHT 2
# define VIEW_LEFT 3
# define UP -1
# define DOWN 1
# define RIGHT 1
# define LEFT -1
# define DR 0.0174533

typedef struct s_rays
{
	double	rx;
	double	ry;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	int		mp;
	int		mx;
	int		my;
	double	h_x0;
	double	h_y0;
	double	v_x0;
	double	v_y0;
	int		h_fov;
	int		v_fov;
	double	atan;
	double	ntan;
	double	dish;
	double	disv;
}				t_rays;

typedef struct s_path_text
{
	void	*mlx_text_so;
	char	*addr_text_so;
	int		bpp_text_so;
	int		line_len_text_so;
	int		endian_so;
	int		img_w_so;
	int		img_h_so;
	void	*mlx_text_no;
	char	*addr_text_no;
	int		bpp_text_no;
	int		line_len_text_no;
	int		endian_no;
	int		img_w_no;
	int		img_h_no;
	void	*mlx_text_ea;
	char	*addr_text_ea;
	int		bpp_text_ea;
	int		line_len_text_ea;
	int		endian_ea;
	int		img_w_ea;
	int		img_h_ea;
	void	*mlx_text_we;
	char	*addr_text_we;
	int		bpp_text_we;
	int		line_len_text_we;
	int		endian_we;
	int		img_w_we;
	int		img_h_we;
}				t_path_text;

typedef struct s_texture
{
	void	*mlx_text;
	char	*addr_text;
	int		bpp_text;
	int		line_len_text;
	int		endian;
	int		img_w;
	int		img_h;
	int		text_pos_x;
	char	*path_img;
}				t_texture;

typedef struct s_win
{
	void	*mlx_win;
	char	*addr_win;
	int		bpp_win;
	int		line_len_win;
	int		endian;
	int		scale_resize;
	int		offset;
}				t_win;

typedef struct s_map
{
	double	win_width;
	double	win_height;
	int		map_size;
	int		color_floor;
	int		color_ceiling;
	double	map_x;
	double	map_y;
	double	position_map_x;
	double	position_map_y;
	double	dx;
	double	dy;
	double	theta;
	double	length_wall;
	double	intersection_wall;
	double	new_pos_x;
	double	new_pos_y;
	int		side_vertical;
	int		max_fov;
}				t_map;

typedef struct s_player
{
	int		moved;
	double	player_posx;
	double	player_posy;
	double	player_angle;
	double	player_dx;
	double	player_dy;
	int		speed;
	double	fov;
}				t_player;

typedef struct s_minimap
{
	double	win_width;
	double	win_height;
	void	*new_image;
	char	*addr_img;
	int		bpp_mini;
	int		line_len_mini;
	int		endian_mini;
	void	*mlx_text;
	char	*addr_text;
	int		bpp_text;
	int		line_len_text;
	int		endian_text;
	int		img_w;
	int		img_h;
	int		length_square_width;
	int		length_square_height;
	double	start_x;
	double	start_y;
	double	magic_x;
	double	magic_y;
}				t_minimap;

typedef struct s_normsht
{
	int	i;
	int	*j;
}				t_normsht;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**newmap;
	char		**newestmap;
	int			map_w;
	int			map_h;
	void		*background;
	void		*wall;
	void		*player;
	void		*collect;
	void		*enemy;
	void		*exit;
	int			nb_collect;
	int			moves;
	int			frame;
	int			loop;
	int			gg;
	int			longestwidth;
	int			num_rows;
	int			paths_valid;
	int			colors_valid;
	int			is_no;
	int			is_so;
	int			is_we;
	int			is_ea;
	int			is_f;
	int			is_c;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_path;
	char		*c_path;
	char		**char_f_rgb;
	char		**char_c_rgb;
	int			*f_rgb;
	int			*c_rgb;
	int			c_color;
	int			f_color;
	double		min_rad;
	double		max_rad;
	int			one_and_only;
	int			p_valid;
	t_player	*gamer;
	t_map		*mapp;
	t_rays		*rays;
	t_win		*img;
	t_texture	*text;
	t_minimap	*minimap;
	t_path_text	*path;
}	t_game;

// initializer

void	ft_initialize(t_game *my_game);

//// -------------- map

// get map

void	ft_get_map(char *av, t_game *my_game);
char	**ft_render_new_map(t_game *my_game);

// check paths and rgb of the map

void	ft_check_map_paths_rgbs(t_game *my_game);
int		ft_is_path_rgb(char *s);
void	ft_assign_paths_rgbs(t_game *my_game, char *s);
void	check_vis(char *sf, char *sc);

// check map

void	ft_check_map(t_game *my_game);
char	**ft_check_map_map(t_game *my_game);
int		ft_strncmp(char *s1, char *s2, int n);

// map utils

void	ft_get_longestwidth(t_game *my_game);
char	**ft_split_rgb(char *s, char c);
void	ft_fill_em(t_game *game, char *s, int *i);
void	ft_skip_em(char *s, int *i);
char	*ft_create_fill(int x);
char	*ft_get_space_tab(char *s, int *j);
char	*ft_get_other_chars(t_game *game, char *s, int *j);
void	ft_check_for_one_and_only(t_game *game, char c);
void	ft_is_path_color(t_game *game, char *t, char *s, int *i);
void	ft_check_alone(char **s, int i, int j);

//// -------------- utils

int		ft_check_rev_file(char *s);
char	**ft_split(t_game *my_game, char *s, char c);
int		ft_strlen(char *s);
char	*ft_substr(char	*s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_rev_strncmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	ft_putstr_error_exit(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);
void	ft_free_map(t_game *my_game);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_sstrcpy(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcat(char *s1, char *s2);
char	*ft_substrzwina(char	*s, int *startend, int index);
int		ft_atoi(char *str);
int		ft_check_only_spaces(char *s);
void	ft_assign_paths_rgbs(t_game *my_game, char *s);
int		ft_is_path_rgb(char *s);
void	ft_deal_with_c(char *s, int *i);
int		is_str_digit(char *s);
void	ft_chack_char(char c);
char	*ft_trim_last_spaces(char *s);

// void	check_missin_pc(t_game *my_game);

void	ft_missin_path_color(t_game *my_game, int count);
void	ft_path_checker(t_game *game, char *path);

// errors

void	ft_print_error_and_exit(char *s);

// window

void	ft_initializer(t_game *game);
void	ft_creation_window(t_game *game);
void	ft_create_window(t_game *game);
void	ft_draw_2d_map(t_game *game);

// movement of player

int		ft_keyword_move(int keyword, t_game *game);
void	ft_movement_fun(t_game *game, char axis, int direction);
int		ft_mouse_move(int button, int x, int y, t_game *game);
int		ft_exit_function(t_game *game);
int		ft_winning_function(void);
void	ft_movement_mouse_fun(t_game *game, char axis, int direction);
void	ft_movement_x_left_axis_fun(t_game *game, char axis, int direction);
void	ft_movement_x_right_axis_fun(t_game *game, char axis, int direction);
void	ft_movement_y_up_axis_fun(t_game *game, char axis, int direction);
void	ft_movement_y_down_axis_fun(t_game *game, char axis, int direction);
int		ft_specialstrncmp(char *s1, char *s2, int n);

// creation of elements

void	ft_put_wall(t_game *game);
int		ft_draw_line(t_game *game, int color);
void	ft_rgb_converter(t_game *game);
void	ft_check_direction_of_player(t_game *game);
void	ft_put_player(t_game *game);
char	*ft_image_path_finder(t_game *game, double deg_rad);
void	ft_information_imgs(t_game *game);
void	ft_initialize_dx_dy(t_game *game);
void	ft_put_in_minimap_image(t_game *game, int x, int y, int color);
void	ft_assign_max_fov(t_game *game);

// check functions for raycasting

double	ft_dist(double ax, double ay, double bx, double by);
int		ft_collision_with_wall(t_game *game, double pos_x, double pos_y);
void	ft_update_putting_floor(t_game *game, int pos_x, int pos_y);
void	ft_complete_rays_fov(t_game *game, double player_x, double player_y);
void	ft_dda_algorithm(t_game *game);

// raycasting functions:

void	ft_assign_x0_y0_horizontal(t_game *game, double angle);
void	ft_check_horizontal_lines(t_game *game, double angle);
void	ft_assign_x0_y0_vertical(t_game *game, double angle);
void	ft_check_vertical_lines(t_game *game, double angle);
void	ft_initializer_rays_struct(t_game *game);

// minimap functions

void	ft_create_minimap(t_game *game);
int		ft_draw(t_game *game, double end_x, double end_y);
void	ft_player_as_circle(t_game *game, int color);
void	ft_borders_of_minimap(t_game *game);
void	ft_length_of_square_minimap(t_game *game);
int		ft_texture_minimap(t_game *game, int x, int y);
int		ft_check_player_map(t_game *game, int x, int y);
void	ft_check_file_paths_images(t_game *game);
int		ft_collision_special_case(t_game *game, double posx, double posy, \
			int dir);

// exit function
void	ft_exit_error(t_game *game);

#endif