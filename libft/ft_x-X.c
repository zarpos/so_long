/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x-X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:49 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:02:53 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned int n, char *hex)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_hexa(n / 16, hex);
	len += write(1, (hex + (n % 16)), 1);
	return (len);
}
/*
int main(void)
{
	unsigned long n;
	n = 123456;
	ft_hexa(n, "0123456789ABCDEF");
	printf("\n%lX", n);
	return (0);
}
*/
