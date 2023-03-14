/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:25 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/14 10:57:06 by drubio-m         ###   ########.fr       */
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