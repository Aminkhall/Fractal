/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:10:44 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/19 22:31:51 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int size)
{
	if (!s1 || !s2 || size <= 0)
		return (0);
	while (*s1 && *s1 == *s2 && size)
	{
		++s1;
		++s2;
		--size;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
	{
		write(fd, &(*str), 1);
		++str;
	}
}

char	*skip_space_or_signs(char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
	{
		(*sign) *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	return (str);
}

int	ft_atoi(char *str)
{
	long	num;

	num = 0;
	while (*str && *str != '.' && (*str >= '0' && *str <= '9'))
	{
		num = (num * 10) + (*str - '0');
		++str;
	}
	return (num);
}

double	ft_atod(char *s)
{
	int		sign;
	long	integ;
	double	dev;
	double	doub;

	dev = 1;
	sign = 1;
	doub = 0.0;
	s = skip_space_or_signs(s, &sign);
	integ = ft_atoi(s);
	while (*s != '.')
		++s;
	if (*s == '.')
		++s;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		dev /= 10;
		doub = doub + ((*s - '0') * dev);
		++s;
	}
	return ((integ + doub) * sign);
}
