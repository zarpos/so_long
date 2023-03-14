/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:52:30 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/14 13:12:59 by drubio-m         ###   ########.fr       */
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

# define NORMAL  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENT  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		y_max;
	int		x_max;
	int		coin;
	int		player;
	int		exit;
	int		starg;
	int 	mov;
}	t_map;

void check_args(int argc, char *argv, t_map *map);
void convert_map(char *argv, t_map *map);
void free_full_map(t_map *map);
int ft_error(char *error, t_map *map);
int	check_char_map(t_map *map);
int	check_borders(t_map *map);
void count_elements(t_map *map);
void init_vars(t_map *map);




#endif
