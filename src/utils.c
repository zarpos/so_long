/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:51:16 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/07 18:21:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/so_long.h"


//Prints the error and the liberates all the memory allocated to finally, exit de program
int ft_error(char *error, t_map *map)
{
    ft_printf("%s%s", RED, error);
    free_full_map(map);
    exit(EXIT_FAILURE);
}

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

