/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:45:02 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:02:26 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n > 9)
		ret += ft_unsigned_putnbr(n / 10);
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}
/*
int main(void)
{
	int	i;
	i = -1;
	printf("%u\n", i);
	ft_unsigned_putnbr(i);
}
*/
