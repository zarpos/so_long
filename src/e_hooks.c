/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:21:11 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/21 21:28:49 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mov_up(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y - 1][map->player_x] = 'P';
	map->player_y = map->player_y - 1;
	map->mov++;
	ft_printf("\n%d", map->mov);
	print_map(map);
}

void	mov_down(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y + 1][map->player_x] = 'P';
	map->player_y = map->player_y + 1;
	map->mov++;
	ft_printf("\n%d", map->mov);
	print_map(map);
}

void	mov_right(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y][map->player_x + 1] = 'P';
	map->player_x = map->player_x + 1;
	map->mov++;
	ft_printf("\n%d", map->mov);
	print_map(map);
}

void	mov_left(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y][map->player_x - 1] = 'P';
	map->player_x = map->player_x - 1;
	map->mov++;
	ft_printf("\n%d", map->mov);
	print_map(map);
}

// First, fills all the map with floors
// Detects which key you are pressing and moves your player
int	detect_key(int key, t_map *map)
{
	if (key == ESC)
		end_game(map);
	if (map->coin == 0
		&& ((key == D && map->map[map->player_y][map->player_x + 1] == 'E')
		|| (key == S && map->map[map->player_y + 1][map->player_x] == 'E')
		|| (key == A && map->map[map->player_y][map->player_x - 1] == 'E')
		|| (key == W && map->map[map->player_y - 1][map->player_x] == 'E')))
	{
		ft_printf("\n%s%s", GREEN, "Congrats!!! You are financially free!");
		end_game(map);
	}
	if (key == W && map->map[map->player_y - 1][map->player_x] != '1'
	&& map->map[map->player_y - 1][map->player_x] != 'E')
		mov_up(map);
	if (key == D && map->map[map->player_y][map->player_x + 1] != '1'
	&& map->map[map->player_y][map->player_x + 1] != 'E')
		mov_right(map);
	if (key == S && map->map[map->player_y + 1][map->player_x] != '1'
	&& map->map[map->player_y + 1][map->player_x] != 'E')
		mov_down(map);
	if (key == A && map->map[map->player_y][map->player_x - 1] != '1'
	&& map->map[map->player_y][map->player_x - 1] != 'E')
		mov_left(map);
	return (0);
}
