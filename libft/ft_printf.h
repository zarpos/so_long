/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:37:53 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/14 20:53:33 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_pointer(unsigned long n, char *hex);
int	ft_putnbr(int n);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_hexa(unsigned int n, char *hex);
#endif
