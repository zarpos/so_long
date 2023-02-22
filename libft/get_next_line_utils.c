/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:57:45 by drubio-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:09:57 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	if (!s)
		return (NULL);
	i = 0;
	cast_s = (char *) s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return (cast_s + i);
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (str == (0))
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_print_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_new_static(char *aux)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (!aux[i])
	{
		free(aux);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(aux) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (aux[i] != '\0')
		ret[j++] = aux[i++];
	ret[j] = '\0';
	free(aux);
	return (ret);
}
/*
int main(void)
{
	char *str = "hola que tal\n peter";
	char *sol;
	sol = ft_print_line(str);
	puts(sol);
	return (0);
}
*/
