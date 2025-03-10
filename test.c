#include <stdio.h>

double ft_atod(char *s)
{
    int sign;
    long integ;
    double doub;

    integ = 0;
    doub = 0.0;
    sign = 1;
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
    while (*s && (*s >= '0' && *s <= '9'))
    {
        doub = ((*s - '0') / 10);
        ++s;
    }
    return ((integ + doub) * sign);
}

int main()
{
    printf("%f", ft_atod("123.056"));
}