/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/03 23:35:28 by ael-asri         ###   ########.fr       */
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
# define UP -1
# define DOWN 1
# define RIGHT 1
# define LEFT -1

typedef struct	s_map
{
	int win_width;
	int win_height;
	int map_size;
	int map_x;
	int map_y;
	int	dx;
	int dy;
	int theta;
	int len_wall;
} 				t_map;

typedef struct	s_player
{
	int	player_posx;
	int	player_posy;
	int	speed;
	int	fov; ///field of view
}				t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**newmap;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
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
	int		longestWidth_start;
	int		longestWidth_end;
	int		paths_valid;
	int		colors_valid;
	t_player *gamer;
	t_map    *mapp;
}	t_game;

//// -------------- map

// get map
void	get_map(char *av, t_game *my_game, t_player *player, t_map *map);

// check paths of the map
void	check_map_paths(t_game *my_game);

// check map
void	check_map(t_game *my_game);


int	ft_strncmp(char *s1, char *s2, int n);

//// -------------- utils
char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
char	*ft_substr(char	*s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr(char *s);
void	ft_putstr_error_exit(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);
void	free_map(t_game *my_game);
int		ft_strlcpy(char *dst, char *src, int dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcat(char *s1, char *s2);
char	*ft_substrzwina(char	*s, int start, int end);

// window
void    initializer(t_game *game);
void    creation_window(t_game *game);
void 	create_window(t_game *game);

// movement of player

int		keyword_move(int keyword, t_game *game);
void    movement_fun(t_game *game, char axis, int direction);
int		exit_function(t_game *game);
int		winning_function(void);

// creation of elements

void    put_wall(t_game *game);
void    put_floor(t_game *game);
void    put_player(t_game *game);

#endif