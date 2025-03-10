#include "fractol.h"

int close_handler(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx_con, fractol->img.img);
    mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
    free(fractol->mlx_con);
    exit(0);
}

int key_hook(int keycode, t_fractol *fractol)
{
    printf("%d\n",keycode);
    if (keycode == 53) //ESCAPE
        close_handler(fractol);
    else if (keycode == 65361) // LEFT
        fractol->shift_x += 0.5;
    else if (keycode == 65363) // RIGHT
        fractol->shift_x -= 0.5;
    else if (keycode == 65362) // UP
        fractol->shift_y -= 0.5;
    else if (keycode == 65364) // DOWN
        fractol->shift_y += 0.5;
    else if (keycode == 61) //PLUS
        fractol->iterations_def += 10;
    else if (keycode == 45) //MINUS
        fractol->iterations_def -= 10;
    fractol_render(fractol);
    return (0);
}

int mouse_hook(int button, int x, int y, t_fractol *fractol)
{
    (void)x;
    (void)y;
    printf("%d\n",button);
    if (button == 4)
        fractol->zoom *= 1.1;
    else if (button == 5)
        fractol->zoom *= 0.9;
    fractol_render(fractol);
    return (0);
}