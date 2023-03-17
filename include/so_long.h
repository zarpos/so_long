/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:52:30 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/17 23:39:42 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

# include "../minilibx_opengl/mlx.h"
//# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define NORMAL "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENT "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define PL "./sprites/Player.xpm"
# define CO "./sprites/Coin.xpm"
# define EX "./sprites/Exit.xpm"
# define WL "./sprites/Wall.xpm"
# define FL "./sprites/Floor.xpm"

typedef struct s_map
{
	char **map;
	char **map_copy;
	int y_max;
	int x_max;
	int coin;
	int	coin_copy;
	int player;
	int player_y;
	int player_x;
	int exit;
	int starg;
	int mov;
	void *mlx;
	void *win;
	int	img_w;
	int	img_h;
	void *img;
	void *p;
	void *c;
	void *f;
	void *ex;
	void *w;
	

} t_map;

void check_args(int argc, char *argv, t_map *map);
void convert_map(char *argv, t_map *map);
void free_full_map(t_map *map);
int ft_error(char *error, t_map *map);
int check_char_map(t_map *map);
int check_borders(t_map *map);
void count_elements(t_map *map);
void init_vars(t_map *map);
void check_path(t_map *map, int x, int y);
void check_and_free(t_map *map);
void	print_map(t_map *map);
void init_img(t_map *map);
void draw_img(int y, int x, t_map *map);
int end_game(t_map *map);
void coin_count(t_map *map);
int detect_key(int key, t_map *map);


#endif
