/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:09:38 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/22 15:46:27 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGTH)
	{
		pos = (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)(img->addr + pos) = color;
	}
}

void	mandel_or_juli(t_complex *z, t_complex *p, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		p->x = fractol->julia_x;
		p->y = fractol->julia_y;
	}
	else
	{
		p->x = z->x;
		p->y = z->y;
	}
}

void	handler_pixels(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	p;
	int			i;
	int			color;

	i = 0;
	z.x = (scale_between(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (scale_between(y, -2, 2, HEIGTH) * fractol->zoom) + fractol->shift_y;
	mandel_or_juli(&z, &p, fractol);
	while (i < fractol->iterations_def)
	{
		z = add_complex(square_complex(z, fractol), p);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escaped_val)
		{
			color = scale_between(i, BLACK, fractol->color,
					fractol->iterations_def);
			pixel_put(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	pixel_put(x, y, &fractol->img, WHITE);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	mlx_clear_window(fractol->mlx_con, fractol->mlx_window);
	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			handler_pixels(x, y, fractol);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractol->mlx_con, fractol->mlx_window,
		fractol->img.img, 0, 0);
}
