#include "fractol.h"

double scaleBetween(double unscaledNum, double minAllowed, double maxAllowed, double min, double max) 
{
  return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}


t_complex add_complex(t_complex z1, t_complex z2)
{
    t_complex res;

    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return (res);
}

t_complex square_complex(t_complex z)
{
    t_complex res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y;
    return (res);
}
