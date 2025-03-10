#include "fractol.h"

void pixel_put(int x, int y, t_img *img, int color)
{
    
}

void handler_pixels(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex p;
    int i;
    int color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;
    p.x = scaleBetween(x, -2, 2, 0, WIDTH);
    p.y = scaleBetween(y, -2, 2, 0, HEIGTH);
    while (i < fractol->iterations_def)
    {
        z = add_complex(square_complex(z), p);
        if (z.x * z.x + z.y * z.y > fractol->escaped_val)
        {
            color = scaleBetween(i, BLACK, WHITE, 0, fractol->iterations_def);
            return ;
        }
        ++i;
    }
    
}

void fractol_render(t_fractol *fractol)
{
    int x;
    int y;

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
    
}