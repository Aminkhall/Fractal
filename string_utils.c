/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:10:44 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/20 14:32:10 by mkhallou         ###   ########.fr       */
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

char	*skip_space_or_signs(char *str, int *sign)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*str == '-')
	{
		(*sign) *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			ft_error(1);
		if (str[i] == '.')
			++count;
		++i;
	}
	if (count > 1 || (count && i == 1))
		ft_error(1);
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
