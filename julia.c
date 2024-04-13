#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_map {
	int	x_zero;
	int	y_zero;
}				map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	closef(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{	
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}	
	return (0);
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
	return (0);
}

int	check_d(double x, double y)
{
	if (sqrt(x * x + y * y) > 2)
		return 0;
	return 1;
}
	
	

int check_mandel(double x, double y)
{
    int i;
	double a;
	double b;
	double temp_a;
	a = y;
	b = x;
	i = 0;

    while (i <= 100)
    {
        if (!check_d(a, b))
            return i;
           temp_a = a;
        a = 2 * a * b + y;
        b = - temp_a * temp_a + b * b + x;
        i++;
    }

    return i;
}

int	check_julia(double x, double y, double b_j, double a_j)
{
	    int i;
	double a;
	double b;
	double temp_a;
	a = a_j + 2*y*x;
	b = b_j + x*x - y * y;
	i = 0;

    while (i < 100)
    {
        if (!check_d(a, b))
            return i;
           temp_a = a;
        a = 2 * a * b + a_j;
        b = - temp_a * temp_a + b * b + b_j;
        i++;
    }
    return i;
   }
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int	get_color(int is)
{
int r;
int g;
int b;
r = 0;
g = 0;
b = 255;
	if (is == 100)
		return (create_trgb(255, 0, 0, 0));
	is = is * 12;
	while (r <= 255 && is > 0)
	{
		r++;
		is--;
	}
	while (b >= 0 && is > 0)
	{
		b--;
		is--;
	}
	while (g <= 255 && is > 0)
	{
		b++;
		is--;
	}
	while (r >= 0 && is > 0)
	{
		r--;
		is--;
	}
	while (b <= 255 && is > 0)
	{
		b++;
		is--;
	}
	return (create_trgb(255, r, g, b));
}
int	main(void)
{

	t_data	img;
	map	map;
	t_vars	vars;
	int	x;
	int	y;
		double	a;
	double	b;
	int	trgb;
	int	is;
	x = 0;
	y = 0;
	map.x_zero = 750;
	map.y_zero = 450;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 900, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1500, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	a = (map.y_zero - y) * 0.005;
	b = (x - map.x_zero) * 0.005;
	
	while (x < 1500)
	{
		y = 0;
		a = (map.y_zero - y) * 0.005;
		while (y < 900)
		{
			is = check_julia(b , a, -0.12, -0.77);
			trgb = create_trgb(255, 0, 255, 255);
			//trgb = get_color(is);						
			my_mlx_pixel_put(&img, x, y, 0x0FAE1);
			a -= 0.005;
			y++;
		}
		b += 0.005;
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_key_hook(vars.win, closef, &vars);
	mlx_loop(vars.mlx);
}

