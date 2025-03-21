/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:10:44 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/21 22:59:34 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	if (!s1 || !s2 || size <= 0)
		return (0);
	i = -1;
	while (s1[++i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] += 32;
	}
	while (*s1 && *s1 == *s2 && size)
	{
		++s1;
		++s2;
		--size;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(2, &(*str++), 1);
}

void	print_err(void)
{
	ft_putstr("\n");
	ft_putstr(" +------------------ Let me help you! ---------------------+\n");
	ft_putstr(" | Usage: ./fractol [mandelbrot / julia 'c_real' 'c_imag'  |\n");
	ft_putstr(" |                                                         |\n");
	ft_putstr(" | e.g: ./fractol mandelbrot                               |\n");
	ft_putstr(" |      ./fractol julia -0.4 0.6                           |\n");
	ft_putstr(" |                                                         |\n");
	ft_putstr(" |----------------------- KEYBOARD ------------------------|\n");
	ft_putstr(" |                                                         |\n");
	ft_putstr(" | Press the arrow keys to change the space/viewpoint      |\n");
	ft_putstr(" | Press +/- keys to change the number of iterations       |\n");
	ft_putstr(" | Use mouse scroll to zoom in and out of the fractal      |\n");
	ft_putstr(" | Press Space to change the color of the fractal          |\n");
	ft_putstr(" | Press ESC to close the window                           |\n");
	ft_putstr(" +---------------------------------------------------------+\n");
	ft_putstr("\n");
	exit(1);
}

char	*check_pars(char *str, int *sign)
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
			print_err();
		if (str[i] == '.')
			++count;
		++i;
	}
	if (!i || count > 1 || (count && i == 1))
		print_err();
	return (str);
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
	integ = 0;
	s = check_pars(s, &sign);
	while (*s && *s != '.' && (*s >= '0' && *s <= '9'))
	{
		integ = (integ * 10) + (*s - '0');
		++s;
	}
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
