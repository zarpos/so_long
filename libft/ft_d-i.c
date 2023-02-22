/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d-i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:25:54 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:00:57 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ret += write(1, "-2", 2);
			n = 147483648;
		}
		else
		{
			ret += write(1, "-", 1);
			n = -n;
		}
	}
	if (n > 9)
		ret += ft_putnbr(n / 10);
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}
/*
int main(void)
{
	int	n;
	n = 10;
	ft_putnbr(n);
	printf("\n%d", ft_putnbr(n));
}
*/
