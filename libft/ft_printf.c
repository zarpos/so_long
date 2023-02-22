/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:36:20 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:09:44 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	select_type(va_list par, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (ft_putchar(va_arg (par, int)));
	else if (type == 's')
		count += (ft_putstr(va_arg (par, const char *)));
	else if (type == 'p')
		count += (ft_pointer(va_arg (par, unsigned long), "0123456789abcdef"));
	else if (type == 'd')
		count += (ft_putnbr(va_arg (par, int)));
	else if (type == 'i')
		count += (ft_putnbr(va_arg (par, int)));
	else if (type == 'u')
		count += (ft_unsigned_putnbr(va_arg (par, unsigned int)));
	else if (type == 'x')
		count += (ft_hexa(va_arg (par, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		count += (ft_hexa(va_arg (par, unsigned int), "0123456789ABCDEF"));
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				count += write(1, "%%", 1);
			else
				count += select_type(args, str[i]);
		}
		else
			count += write(1, str + i, 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	int n = 5;
	ft_printf("%u", -1);
	printf("\n%u", -1);
	return (0);
}
*/
