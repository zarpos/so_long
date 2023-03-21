/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:36:10 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/21 22:40:28 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void choose_player(t_map *map)
{
    map->p = mlx_xpm_file_to_image(map->mlx, map->dir, &map->img_w, &map->img_h);
    if (map->p == NULL)
		ft_error("Image couldn't be opened!", map);
}