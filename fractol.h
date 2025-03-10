#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define HEIGTH 800
#define WIDTH 800

typedef struct s_complex
{
	double x;
	double y;
}				t_complex;

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)	
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
    char *name;
    void *mlx_con;
    void *mlx_window;
    t_img img;
	double escaped_val;
	int iterations_def;
}               t_fractol;

int ft_strncmp(char *s1, char *s2, int size);
void fraclot_init(t_fractol *fractol);
double scaleBetween(double unscaledNum, double minAllowed, double maxAllowed, double min, double max);
void fractol_render(t_fractol *fractol);
void data_init(t_fractol *fractol);
t_complex add_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

#endif