/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:55:04 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/21 23:25:43 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define HEIGTH 800
# define WIDTH 800

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

# define BLACK       0x000000
# define WHITE       0xFFFFFF

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_con;
	void	*mlx_window;
	t_img	img;
	double	escaped_val;
	int		iterations_def;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	int		color;
	double	zoom;
	double	cursor_x;
	double	cursor_y;
}				t_fractol;

int			ft_strncmp(char *s1, char *s2, int size);
void		fraclot_init(t_fractol *fractol);
double		scale_between(double unscaled_num, double min_allowed,
				double max_allowed, double max);
void		fractol_render(t_fractol *fractol);
void		data_init(t_fractol *fractol);
t_complex	add_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			close_handler(t_fractol *fractol);
int			key_hook(int keycode, t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
int			motion_notify(int x, int y, t_fractol *fractol);
double		ft_atod(char *s);
void		ft_error(void);
void		print_err(void);
void		ft_putstr(char *str);

#endif