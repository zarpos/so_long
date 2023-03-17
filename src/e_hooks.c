/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:21:11 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/17 23:56:42 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    mov_up(t_map *map)
{
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y - 1][map->player_x] = 'P';
    map->mov++;
    print_map(map);
}

void  mov_down(t_map *map)
{
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y + 1][map->player_x] = 'P';
    map->mov++;
    print_map(map);
}

void mov_right(t_map *map)
{
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y][map->player_x + 1] = 'P';
    map->mov++;
    print_map(map);
}

void mov_left(t_map *map)
{
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y][map->player_x - 1] = 'P';
    map->mov++;
    print_map(map);
}

int detect_key(int key, t_map *map)
{
    if (key == ESC)
        end_game(map);
    if (map->coin == 0 && 
    ((key == W && map->map[map->player_y - 1][map->player_x] == 'E') || 
    (key == D && map->map[map->player_y][map->player_x + 1] == 'E') ||
    (key == S && map->map[map->player_y + 1][map->player_x] == 'E') ||
    (key == A && map->map[map->player_y][map->player_x - 1] == 'E')))
    {
        ft_printf("%s", "Congrats!!! You are financially free!");
        end_game(map);
    }
    if (key == W && map->map[map->player_y - 1][map->player_x] != '1'
        && map->map[map->player_y - 1][map->player_x] != 'E')
        mov_up(map);
    if (key == D && map->map[map->player_y - 1][map->player_x] != '1'
        && map->map[map->player_y - 1][map->player_x] != 'E')
        mov_right(map);
    if (key == S && map->map[map->player_y - 1][map->player_x] != '1'
        && map->map[map->player_y - 1][map->player_x] != 'E')
        mov_down(map);
    if (key == W && map->map[map->player_y - 1][map->player_x] != '1'
        && map->map[map->player_y - 1][map->player_x] != 'E')
        mov_left(map);
¡    return (0);   
}