/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:51:16 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/14 12:49:12 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/so_long.h"

// This function checks that there is only 1 argument and its a file '.ber'
void ft_check_args(int argc, char *argv, t_map *map)
{
	int len;

	map->starg = 1;
	if (argc != 2)
	{
		map->starg = 0;
		ft_error("Error, you can only try one argument!", map);
	}
	else
	{
		len = ft_strlen(argv);
		if (ft_strncmp(argv + (len - 4), ".ber", 4))
		{
			map->starg = 0;
			ft_error("Extension not valid! try a .ber", map);
		}
	}
}

//Prints the error and the liberates all the memory allocated to finally, exit de program
int ft_error(char *error, t_map *map)
{
    ft_printf("%s%s", RED, error);
    if (map->starg == 1)
        free_full_map(map);
    exit(EXIT_FAILURE);
}

// Liberates all the map
void free_full_map(t_map *map)
{
    int i;

    i = 0;
    if (map->map)
    {
        while (map->map[i])
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
}

