/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:27 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/21 12:56:30 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Created to just initialize some variables and reduce other functions length
void	init_vars(t_map *map)
{
	map->player = 0;
	map->coin = 0;
	map->exit = 0;
	map->mov = 0;
}

void	init_img(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->x_max * 56, map->y_max * 56,
			"So_Long");
	map->p = mlx_xpm_file_to_image(map->mlx, PL, &map->img_w, &map->img_h);
    if (map->p == NULL)
        ft_error("Image couldn't be opened!", map);
	map->c = mlx_xpm_file_to_image(map->mlx, CO, &map->img_w, &map->img_h);
    if (map->c == NULL)
        ft_error("Image couldn't be opened!", map);
	map->f = mlx_xpm_file_to_image(map->mlx, FL, &map->img_w, &map->img_h);
    if (map->f == NULL)
        ft_error("Image couldn't be opened!", map);
	map->ex = mlx_xpm_file_to_image(map->mlx, EX, &map->img_w, &map->img_h);
    if (map->ex == NULL)
        ft_error("Image couldn't be opened!", map);
	map->w = mlx_xpm_file_to_image(map->mlx, WL, &map->img_w, &map->img_h);
    if (map->w == NULL)
        ft_error("Image couldn't be opened!", map);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	check_args(argc, argv[1], &map);
	convert_map(argv[1], &map);
	check_char_map(&map);
	count_elements(&map);
	check_borders(&map);
	check_path(&map, map.player_y, map.player_x);
	check_and_free(&map);
	init_img(&map);
	print_map(&map);
	mlx_key_hook(map.win, detect_key, &map);
	mlx_hook(map.win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
}
