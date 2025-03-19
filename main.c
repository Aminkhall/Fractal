/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:09:00 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/19 22:56:17 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((2 == ac && !ft_strncmp(av[1], "Mandelbrot", 10))
		|| (4 == ac && !ft_strncmp(av[1], "Julia", 5)))
	{
		fractol.name = av[1];
		if (!ft_strncmp(fractol.name, "Julia", 5))
		{
			fractol.julia_x = ft_atod(av[2]);
			fractol.julia_y = ft_atod(av[3]);
		}
		fraclot_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_con);
	}
	else
	{
		perror(ERROR_TEXT);
		exit(1);
	}
}
