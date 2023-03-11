/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_leer_mapa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:16:12 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/11 16:31:45 by drubio-m         ###   ########.fr       */
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


// Checks that all the map is sorrounded by walls aka '1'

int	check_borders(t_map *map)
{
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
				ft_error("Borders aren't correct", map);	
			x++;
		}
		y++;
	}
	return (1);
}
