/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:27 by drubio-m          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:16 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char *argv[])
{
    t_map map;
    int i;
    int valid;
    int border;

    i = 0;
	
	ft_check_args(argc, *argv, &map);
    convert_map(argv[1], &map);
    valid = check_char_map(&map);
    border = check_borders(&map);
    while (map.map[i])
    {
        ft_printf("%s%c", map.map[i], '\n');
        i++;
    }
    ft_printf("%c%d", '\n', border);
    return 0;
}