/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:00:17 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/22 22:03:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// It will eavluate if there is a valid way to the exit
void	check_path(t_map *map, int y, int x)
{
	char	*p;

	p = &map->map_copy[y][x];
	if (*p != '1' && *p != 'K')
	{
		if (*p == 'C')
			map->coin_copy--;
		*p = '1';
		if (map->map_copy[y][x + 1] != '1')
			check_path(map, y, x + 1);
		if (map->map_copy[y][x - 1] != '1')
			check_path(map, y, x - 1);
		if (map->map_copy[y - 1][x] != '1')
			check_path(map, y - 1, x);
		if (map->map_copy[y + 1][x] != '1')
			check_path(map, y + 1, x);
	}
}

// Frees all the copy of the map and checks all the coins have been collected
void	check_and_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_copy[i])
	{
		free(map->map_copy[i]);
		i++;
	}
	free(map->map_copy);
	if (map->coin_copy != 0 || map->exit != 1)
		ft_error("\nError\nEl mapa no tiene camino valido\n", map);
}

void check_if_rect(t_map *map)
{
	int	y;
	
	y = 0;
	map->y_max = 0;
	map->x_max = ft_strlen(map->map[y]);
	while (map->map[y])
	{
		map->y_max++;
		y++;
	}
	y = 0;
	while (y < map->y_max)
	{
		if (map->x_max != ft_strlen(map->map[y]))
			ft_error("\nThe map is not a rectangle!", map);
		y++;
	}	
}
