#include "fractol.h"

void ft_error(void)
{
    perror("Problem with maloc");
    exit(1);
}

void data_init(t_fractol *fractol)
{
    fractol->escaped_val = 4;
    fractol->iterations_def = 42;   
}

void fraclot_init(t_fractol *fractol)
{
    fractol->mlx_con = mlx_init();
    if (!fraclot_init)
        ft_error();
    fractol->mlx_window = mlx_new_window(fractol->mlx_con, WIDTH, HEIGTH, fractol->name);
    if (!fractol->mlx_window)
    {
        mlx_destroy_display(fractol->mlx_con);
        free(fractol->mlx_con);
        ft_error();
    }
    fractol->img.img = mlx_new_image(fractol->mlx_con, WIDTH, HEIGTH);
    if (!fractol->img.img)
    {
        mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
        mlx_destroy_display(fractol->mlx_con);
        free(fractol->mlx_con);
        ft_error();
    }
    fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, &fractol->img.line_length, &fractol->img.endian);
}
