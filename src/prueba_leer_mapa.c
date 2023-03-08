/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_leer_mapa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:46 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/08 18:11:32 by drubio-m         ###   ########.fr       */
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
	free(map1_arr);
}

// Created to check that the map is made only of valid chars

int check_char_map(t_map *map)
{
    char **read;
    int x;
    int y;

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
    return 1;
}

// Checks if all the map is sorrounded by walls aka '1'

int check_borders(t_map *map)
{
    char **read;
    int x;
    int y;

    read = map->map;
    y = 0;
    x = ft_strlen(read[y]);

    while(read[y])
    {
        if (read[y][0] != '1' || read[y][x - 1] != '1')
            ft_error("bad wall placement :(", map);
        y++;
    }
    x = 0;
    while (read[0][x])
    {
        if (read[0][x] != '1')
            ft_error("bad wall placement :(", map);
        x++;
    }
    x = 0;
    while (read[y - 1][x])
    {
        if (read[y - 1][x] != '1')
            ft_error("bad wall placement :(", map);
        x++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    t_map map;
    int i;
    int valid;
    int border;

    i = 0;

    convert_map(argv[1], &map);
    valid = check_char_map(&map);
    border = check_borders(&map);
   /* while (map.map[i])
    {
        ft_printf("%s%c", map.map[i], '\n');
        i++;
    }*/
    ft_printf("%c%d", '\n', border);
    return 0;
}