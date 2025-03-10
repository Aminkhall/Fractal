#include "fractol.h"

int ft_strncmp(char *s1, char *s2, int size)
{
    if (!s1 || !s2 || size <= 0)
        return (0);
    while (*s1 && *s1 == *s2 && size)
    {
        ++s1;
        ++s2;
        --size;
    }
    return (*s1 - *s2);
}

void putstr_fd(char *str, int fd)
{
    if (!str || fd < 0)
        return;
    while (*str)
    {
        write(fd, &(*str), 1);
        ++str;
    }
}

double ft_atod(char *s)
{
    int sign;
    long integ;
    double dev;
    double doub;

    sign = 1;
    dev = 1;
    doub = 0.0;
    integ = 0;
    if (*s == '-')
    {
        sign *= -1;
        ++s;
    }
    else if (*s == '+')
        ++s;
    while (*s && *s != '.' && (*s >= '0' && *s <= '9'))
    {
        integ = (integ * 10) + (*s - '0');
        ++s; 
    }
    if (*s == '.')
        ++s;
    while (*s && (*s >= '0' && *s <= '9'))
    {
        dev /= 10;
        doub = doub + ((*s - '0') * dev);
        ++s;
    }
    return ((integ + doub) * sign);
}
