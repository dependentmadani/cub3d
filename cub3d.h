/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/20 12:39:55 by ael-asri         ###   ########.fr       */
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
# define PI 3.141592653589793238
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533

typedef struct	s_texture
{
	void	*mlx_text;
	char	*addr_text;
	int	    bpp_text;
	int		line_len_text;
	int		endian;
	int		img_w;
	int		img_h;
	int		text_pos_x;
}				t_texture;

typedef struct	s_win
{
	void    *mlx_win;
	char    *addr_win;
	int     bpp_win; /* bits per pixel */
	int     line_len_win;
	int     endian;
	int		scale_resize;
	int		offset;
}				t_win;

typedef struct	s_map
{
	double win_width;
	double win_height;
	int map_size;
	int color_floor;
	int color_ceiling;
	double map_x;
	double map_y;
	double	dx;
	double	dy;
	double theta;
	int len_wall;
	double	intersection_wall;
	int	side_vertical;
} 				t_map;

typedef struct	s_player
{
	int moved;
	double	player_posx;
	double	player_posy;
	double player_angle;
	double player_dx;
	double player_dy;
	int	speed;
	double fov; ///field of view
}				t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**newmap;
	char	**newestmap;
	int		map_w;
	int		map_h;
	void	*background;
	void	*wall;
	void	*player;
	void	*collect;
	void	*enemy;
	void	*exit;
	int		nb_collect;
	int		moves;
	int		frame;
	int		loop;
	int		gg;
	int		longestWidth;
	// int		longestWidth_start;
	// int		longestWidth_end;
	int		num_rows;
	int		paths_valid;
	int		colors_valid;
	int		is_no;
	int		is_so;
	int		is_we;
	int		is_ea;
	int		is_f;
	int		is_c;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_path;
	char	*c_path;
	char	**char_f_rgb;
	char	**char_c_rgb;
	int		*f_rgb;
	int		*c_rgb;
	int		c_color;
	int		f_color;
	t_player *gamer;
	t_map    *mapp;
	t_win	*img;
	t_texture *text;
	double	min_rad;
	double	max_rad;
}	t_game;

// initializer
void	ft_initializer(t_game *my_game);

//// -------------- map

// get map
void	get_map(char *av, t_game *my_game/*, t_player *player, t_map *map*/);
char	**render_new_map(t_game *my_game);

// check paths of the map
void	check_map_paths_rgbs(t_game *my_game);

// check map
void	check_map(t_game *my_game);
char	**check_map_map(t_game *my_game);

int	ft_strncmp(char *s1, char *s2, int n);

// map utils
void	get_longestWidth(t_game *my_game);
char	**splitRgb(char *s, char c);

//// -------------- utils
int		check_rev_file(char *s);
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
void	free_map(t_game *my_game);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_sstrcpy(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcat(char *s1, char *s2);
char	*ft_substrzwina(char	*s, int start, int end);
int		ft_atoi(const char	*str);

// errors
void print_error_and_exit(char *s);

// window

void    initializer(t_game *game);
void    creation_window(t_game *game);
void 	create_window(t_game *game);
void	draw_2d_map(t_game * game);

// movement of player

int		keyword_move(int keyword, t_game *game);
void    movement_fun(t_game *game, char axis, int direction);
int		exit_function(t_game *game);
int		winning_function(void);

// creation of elements

void    put_wall(t_game *game);
void    put_floor(t_game *game);
void    put_player(t_game *game, int color);
char    *image_path_finder(t_game *game, double deg_rad);
void    information_imgs(t_game *game, char *filename);

// check functions for raycasting

int 	collision_with_wall(t_game *game, double pos_x, double pos_y);
void    spread_rays(t_game *game);
void 	update_putting_floor(t_game *game, int pos_x, int pos_y);
void    complete_rays_fov(t_game *game, double player_x, double player_y);

#endif