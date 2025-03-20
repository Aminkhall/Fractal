/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:46 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/20 15:46:33 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	perror("Error during initialization or memory allocation");
	exit(1);
}

void	data_init(t_fractol *fractol)
{
	fractol->escaped_val = 4;
	fractol->iterations_def = 100;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	fractol->color = WHITE;
	fractol->cursor_x = 0.0;
	fractol->cursor_y = 0.0;
}

void	event_init(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, key_hook, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_hook, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
	mlx_hook(fractol->mlx_window, 6, 0, motion_notify, fractol);
}

void	fraclot_init(t_fractol *fractol)
{
	fractol->mlx_con = mlx_init();
	if (!fractol->mlx_con)
		ft_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_con, WIDTH, HEIGTH,
			fractol->name);
	if (!fractol->mlx_window)
	{
		free(fractol->mlx_con);
		ft_error();
	}
	fractol->img.img = mlx_new_image(fractol->mlx_con, WIDTH, HEIGTH);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
		free(fractol->mlx_con);
		ft_error();
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	data_init(fractol);
	event_init(fractol);
}
