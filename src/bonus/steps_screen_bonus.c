/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:11:08 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/22 16:15:52 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	print_all_movs(t_map *map)
{
	print_movs_terminal(map);
	print_movs_screen(map);
}

void	print_movs_terminal(t_map *map)
{
	ft_printf("\n%d", map->mov);
}

void	print_movs_screen(t_map *map)
{
	char	*str;

	str = ft_itoa(map->mov);
	mlx_string_put(map->mlx, map->win, 10, 27, 0x000000, "Movs: ");
	mlx_string_put(map->mlx, map->win, 75, 27, 0x000000, str);
	free(str);
}
