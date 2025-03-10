#include "fractol.h"

int main(int ac, char **av)
{
    t_fractol fractol;

    if ((2 == ac && !ft_strncmp(av[1], "Mandelbrot", 10))
        || (4 == ac && !ft_strncmp(av[1], "Julia", 5)))
    {
        fractol.name = av[1];
        fraclot_init(&fractol);
        fractol_render(&fractol);
        mlx_loop(fractol.mlx_con);
    }
    else
    {
        perror("Enter correct prams");
        exit(1);
    }
}
