/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:32:15 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/17 14:56:46 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/so_long.h"
 
 
// Used to decide which sprite to use in base of the map char 
void draw_img(int y, int x, t_map *map)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->w,
		x * 56, y * 56);
	else if (map->map[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->f,
		x * 56, y * 56);
	else if (map->map[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->p,
		x * 56, y * 56);
	else if (map->map[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->c,
		x * 56, y * 56);
	else if (map->map[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->ex,
		x * 56, y * 56);
}
 
// The main function to start printing sprites
// It prints all floors and then it places over, the sprite. 
void	print_map(t_map *map)
 {
	int y;
	int x;
	
	y = 0;
	init_img(map);
	map->win = mlx_new_window(map->mlx, map->x_max * 56, map->y_max * 56,
			"So_Long");
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->f, 
			x * 56, y * 56);
			draw_img(y, x, map);
			x++;
		}
		y++;
	}
 } 


 