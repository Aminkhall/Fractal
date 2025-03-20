/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:04:06 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/20 15:52:37 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_con, fractol->img.img);
	mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
	exit(0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		close_handler(fractol);
	else if (keycode == 123)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keycode == 124)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keycode == 126)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keycode == 125)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keycode == 69)
		fractol->iterations_def += 10;
	else if (keycode == 78)
		fractol->iterations_def -= 10;
	else if (keycode == 49)
		fractol->color += (fractol->color << 8);
	if (fractol->iterations_def < 10)
		fractol->iterations_def = 10;
	fractol_render(fractol);
	return (0);
}

int	motion_notify(int x, int y, t_fractol *fractol)
{
	fractol->cursor_x = scale_between(x, -2, 2, WIDTH)
		* fractol->zoom + fractol->shift_x;
	fractol->cursor_y = scale_between(y, -2, 2, HEIGTH)
		* fractol->zoom + fractol->shift_y;
	fractol_render(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		fractol->zoom *= 1.3;
	else if (button == 5)
		fractol->zoom *= 0.9;
	fractol->shift_x = fractol->cursor_x - (scale_between(x, -2, 2, WIDTH)
			* fractol->zoom);
	fractol->shift_y = fractol->cursor_y - (scale_between(y, -2, 2, HEIGTH)
			* fractol->zoom);
	fractol_render(fractol);
	return (0);
}
