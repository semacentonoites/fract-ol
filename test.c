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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

typedef struct	s_map {
	int	x_zero;
	int	y_zero;
	double multi;
}				map;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
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
		//mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		//free(vars->win);
		exit(1);
	}	
	return (0);
}

int	close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_loop_end(vars->mlx);
	//mlx_destroy_display(vars->mlx);
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

    while (i < 100)
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
void datainit(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;}

int	ft_multi(int keycode, map *map)
{
printf("ola");
	if (keycode == 4)
	{
		printf("ola");
		map->multi = map->multi * 0.75;
	}
	if (keycode == 5)
		map->multi = map->multi * 1.5;
	return 0;
}

int	main(void)
{

	map	map;
	t_vars	vars;
	int	x;
	int	y;
	double	a;
	double	b;
	int	trgb;
	int	is;
	//double	multi;
	//trgb = create_trgb(255, 255, 0, 255);
	x = 0;
	y = 0;
	map.multi = 0.75;
	datainit(&vars);
	map.x_zero = 750;
	map.y_zero = 450;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 900, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 1500, 900);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,&vars.endian);
	a = (map.y_zero - y) * 0.005 * map.multi;
	b = (x - map.x_zero) * 0.005 * map.multi;
	
	while (x < 1500)
	{
		y = 0;
		a = (map.y_zero - y) * 0.005 * map.multi;
		while (y < 900)
		{
			
			
			is = check_julia(b , a, -0.1, -0.75);
			//trgb = create_trgb(255, 255, 255, 255);
			trgb = get_color(is);						
			my_mlx_pixel_put(&vars, x, y, trgb);
			a -= 0.005 * map.multi;
			y++;
		}
		b += 0.005 * map.multi;
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_key_hook(vars.win, closef, &vars);
	mlx_mouse_hook(vars.win, ft_multi, &map);
	mlx_loop(vars.mlx);
}

