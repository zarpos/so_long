/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:53:18 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/20 16:45:29 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int ft_check_args(int argc, char *argv[])
{
	int i;

	i = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_printf("%s", "Error, solo puedes pasar un argumento");
		return 0;
	}
	if ()
}
