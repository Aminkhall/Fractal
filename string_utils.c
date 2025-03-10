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

void putstr_fd (char *str, int fd)
{
    if (!str || fd < 0)
        return;
    while (*str)
    {
        write(fd, &(*str), 1);
        ++str;
    }
}
