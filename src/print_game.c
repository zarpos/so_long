/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:32:15 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/15 16:06:52 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/so_long.h"
 
 void	print_map(t_map *map)
 {
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->x_max * 56, map->y_max * 56,
			"So_Long");
	map->img = mlx_xpm_file_to_image(map->mlx, PL, &map->img_w, &map->img_h);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_loop(map->mlx);
 }