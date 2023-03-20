/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:32:15 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/18 12:01:57 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/so_long.h"
 
// fills all the map with the floor sprite
void all_floor(t_map *map)
{
	int y;
	int x;
	
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->f, 
			x * 56, y * 56);
			x++;
		}
		y++;
	}
 }
 
// Used to decide which sprite to use in base of the map char 
void draw_img(int y, int x, t_map *map)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->w,
		x * 56, y * 56);
	if (map->map[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->p,
		x * 56, y * 56);
	if (map->map[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->c,
		x * 56, y * 56);
	if (map->map[y][x] == 'E')
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
	x = 0;
	all_floor(map);
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			draw_img(y, x, map);
			x++;
		}
		y++;
	}
 } 