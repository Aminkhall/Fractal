/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:00:57 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/22 15:44:30 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_between(double unscaled_num, double min_allowed,
		double max_allowed, double max)
{
	return ((max_allowed - min_allowed) * unscaled_num / max + min_allowed);
}

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z, t_fractol *fractol)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	if (!ft_strncmp(fractol->name, "tricorn", 7))
		res.y = -2 * z.x * z.y;
	else
		res.y = 2 * z.x * z.y;
	return (res);
}
