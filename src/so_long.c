/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:27 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/20 21:21:49 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Created to just initialize some variables and reduce other functions length
void	init_vars(t_map *map)
{
	map->player = 0;
	map->coin = 0;
	map->exit = 0;
	map->mov = 0;
}

void	init_img(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->x_max * 56, map->y_max * 56,
			"So_Long");
	map->p = mlx_xpm_file_to_image(map->mlx, PL, &map->img_w, &map->img_h);
	map->c = mlx_xpm_file_to_image(map->mlx, CO, &map->img_w, &map->img_h);
	map->f = mlx_xpm_file_to_image(map->mlx, FL, &map->img_w, &map->img_h);
	map->ex = mlx_xpm_file_to_image(map->mlx, EX, &map->img_w, &map->img_h);
	map->w = mlx_xpm_file_to_image(map->mlx, WL, &map->img_w, &map->img_h);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	check_args(argc, argv[1], &map);
	convert_map(argv[1], &map);
	check_char_map(&map);
	count_elements(&map);
	check_borders(&map);
	check_path(&map, map.player_y, map.player_x);
	check_and_free(&map);
	init_img(&map);
	print_map(&map);
	mlx_key_hook(map.win, detect_key, &map);
	mlx_hook(map.win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
}

/*
int main(int argc, char *argv[])
 {
    t_map map;
    int i;
    int x;
    int valid;
    int border;

    i = 0;
    check_args(argc, argv[1], &map);
    convert_map(argv[1], &map);
    valid = check_char_map(&map);
    count_elements(&map);
    border = check_borders(&map);
 	check_path(&map, map.player_y, map.player_x);
    while (map.map[i])
    {
        printf("%s%c", map.map_copy[i], '\n');
        i++;
    }
    printf("%c", '\n');
  	check_and_free(&map);

    i = 0;
    while (map.map[i])
    {
        printf("%s%c", map.map[i], '\n');
        i++;
    }

      while (map.map[i])
      {
          x = 0;
          while (map.map[i][x])
          {
              write(1, &map.map[i][x], 1);
              usleep(10000);
              x++;
          }
          printf("%c", '\n');
          i++;
      }
    
    ft_printf("%c%d", '\n', border);
 
    return 0;
}
*/