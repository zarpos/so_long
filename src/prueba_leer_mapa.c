/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_leer_mapa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:46 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/10 21:05:28 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function will open the map, read it and then convert it to a (char **)

void	convert_map(char *argv, t_map *map)
{
	int		fd;
	char	*new_arr;
	char	*map1_arr;
	char	*map2_arr;

	fd = open(argv, O_RDONLY);
	if (!fd)
		ft_error("Archivo no encontrado!", map);
		map1_arr = ft_strdup("");
	while (1)
	{
		new_arr = get_next_line(fd);
		if (!new_arr)
			break ;
		map2_arr = ft_strdup(map1_arr);
		free(map1_arr);
		map1_arr = ft_strjoin2(map2_arr, new_arr);
		free(new_arr);
	}
	map->map = ft_split(map1_arr, '\n');
	map->map_copy = ft_split(map1_arr, '\n');
	free(map1_arr);
}

// Created to check that the map is made only of valid chars

int	check_char_map(t_map *map)
{
	char	**read;
	int		x;
	int		y;

	read = map->map;
	y = 0;
	while (read[y])
	{
		x = 0;
		while (read[y][x])
		{
			if (read[y][x] != '0' && read[y][x] != '1' && read[y][x] != 'C'
			&& read[y][x] != 'E' && read[y][x] != 'P')
				ft_error("invalid char detected!", map);
			x++;
		}
		y++;
	}
	return (1);
}



/**
 * It checks the borders of the map
 * 
 * @param map a pointer to the map structure
 * 
 * @return 1
 */
int	check_borders(t_map *map)
{
	// char	**read;
	int		x;
	int		y;

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
		x = 0;
		while (x < map->x_max)
		{
			if (map->map[0][x] != '1' || map->map[map->y_max - 1][x] != '1'
				|| map->map[y][0] != '1' || map->map[y][map->x_max - 1] != '1')
			{
				ft_error("Borders aren't correct", map);
			}	
			x++;
		}
		y++;
	}
	return (1);
}
