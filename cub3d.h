/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/07 11:10:59 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"
# include "utils/gnl/get_next_line.h"

typedef struct	s_player
{
	int	pos_x;
	int	pos_y;
	int	speed;
	int	angle_view;
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
	t_player *gamer;
}	t_game;

//// -------------- map

// get map
void	get_map(char *av, t_game *my_game, t_player *player);

// check paths of the map
void	check_map_paths(t_game *my_game);

// check map
void	check_map(t_game *my_game);
char	**check_map_map(t_game *my_game);

int	ft_strncmp(char *s1, char *s2, int n);

//// -------------- utils
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
int	ft_atoi(const char	*str);

// window
void    initializer(t_game *game);
void    creation_window(t_game *game);

#endif