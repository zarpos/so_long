/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:27 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/15 16:09:02 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Created to just initialize some variables and reduce other functions length
void init_vars(t_map *map)
{
    map->player = 0;
    map->coin = 0;
    map->exit = 0;
    map->mov = 0;
}

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

    /*  while (map.map[i])
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
      */
    // ft_printf("%c%d", '\n', border);
    printf("%c%d%c", '\n', map.coin, '\n');
    printf("%c%d%c", '\n', map.coin_copy, '\n');
	print_map(&map);

    return 0;
}