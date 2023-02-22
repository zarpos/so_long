/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:58:27 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:01:14 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	aux_pointer(unsigned long n, char *hex)
{	
	int	i;

	i = 0;
	if (n >= 16)
		i += aux_pointer(n / 16, hex);
	i += write(1, hex + (n % 16), 1);
	return (i);
}

int	ft_pointer(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += aux_pointer(n, hex);
	return (i);
}
/*
int main(void)
{
	int	ret;
	ret = 16;
	ft_pointer((unsigned long) &ret, "0123456789abcdef");
	printf("\n%p", &ret);
	return (0);
}
*/
