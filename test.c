#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <X11/X.h>
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
	int	x_zero;
	int	y_zero;
	double multi;
	int	fract;
	int	av2;
	int	av3;
}				t_vars;

typedef struct	s_map {
	int	x_zero;
	int	y_zero;
	double multi;
}				map;
int	ft_atoi(const char *nbr)
{
	int	i;
	long	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		n = nbr[i] + n * 10 - 48;
		i++;
	}
	return (n * sign);
}
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} 



int	closeff(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);

	exit(1);
	return (0);
}
/*
double     ft_sqrt(double nb)
{
        double     i;

        i = 0;
        if (nb < 0)
                return (0); 
        if (nb == 4)
                return (2);
        while (i < 46341 && i * i <= nb)
        {
                if (i * i >= nb)
                        return (i);
                i++;
        }
        return (0);
}
*/

double ft_sqrt(double number) {
    if (number == 0) {
        return 0;
    }

    double guess = number / 2.0;
    double epsilon = 0.00001; // Precision level
    double difference;

    do {
        double new_guess = 0.5 * (guess + number / guess);
        difference = guess - new_guess;
        guess = new_guess;
    } while (difference > epsilon || difference < -epsilon);

    return guess;
}

float fastInvSqrt(float x) { 
    float xhalf = 0.5f * x; 
    int i = *(int*)&x; 
    i = 0x5f3759df - (i >> 1); 
    x = *(float*)&i; 
    x = x * (1.5f - xhalf * x * x); 
    return x; 
} 
 
float fastSqrt(float x) { 
    return 1.0f / fastInvSqrt(x); 
}

int	check_d(double x, double y)
{
	if (fastSqrt(x * x + y * y) > 2)
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
	while (r++ < 254 && is-- > 1)
		;
	while (b-- > 1 && is-- > 1)
		;
	while (g++ < 100 && is-- > 1)
		;
	while (r-- > 1 && is-- > 1)
		;
	while (b++ < 100 && is-- > 1)
		;
	return (create_trgb(255, r, g, b));
}
void datainit(t_vars *vars)
{
	vars->multi = 1;
	vars->x_zero = 750;
	vars->y_zero = 450;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1500, 900, "fract-ol");
	vars->img = mlx_new_image(vars->mlx, 1500, 900);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,&vars->endian);
}

int	pr(int keycode, t_vars *vars)
{
	if (keycode == 4|| vars->multi)
		printf("ola");
	//printf("op");
	return 0;
}
void	create_img(t_vars vars)
{
	int	x;
	int	y;
	double	a;
	double	b;
	int	trgb;
	int	is;

	x = 0;
	y = 0;
	a = (vars.y_zero - y) * 0.005 * vars.multi;
	b = (x - vars.x_zero) * 0.005 * vars.multi;
	while (x < 1500)
	{
		y = 0;
		a = (vars.y_zero - y) * 0.005 * vars.multi;
		while (y < 900)
		{
			
			if (vars.fract)
				is = check_mandel(b , a);
			else
				is = check_julia(b, a, vars.av2, vars.av3);
			//trgb = create_trgb(255, 255, 255, 255);
			trgb = get_color(is);						
			my_mlx_pixel_put(&vars, x, y, trgb);
			a -= 0.005 * vars.multi;
			y++;
		}
		b += 0.005 * vars.multi;
		x++;
		
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
}

int abs(int x)
{
	if(x < 0)
		return (-x);
	else
		return (x);
}
int	ft_multi(int button, int x, int y, t_vars *vars)
{
	
	//if (keycode)
	//printf("%p %d", vars, vars->x_zero);
	//printf("%d", keycode);
	//if (vars->multi)
	
	//printf("ola");
	double	aa;
	double	bb;
	double	a;
	double	b;
	
	if (button == Button4)
	{
	/*
	x,y coordenadas do rato
	vars->yxzero coordenadas do (0,0)
	a,b 
	*/
		a = (vars->y_zero - y) * 1 * vars->multi;
		b = (x - vars->x_zero) * 1 * vars->multi;	
		vars->multi = vars->multi * 0.75;
		aa = - (a / (1 * vars->multi) - vars->y_zero);
		bb =  (b / (1 * vars->multi) + vars->x_zero);
		//aa = (vars->y_zero - a) * 0.005 * vars->multi;
		//bb = (b - vars->x_zero) * 0.005 * vars->multi;	
		//aa = (vars->y_zero - a) * 0.005 * vars->multi;
		//bb = (b - vars->x_zero) * 0.005 * vars->multi;	
		vars->x_zero += - x + bb;
        	vars->y_zero +=  y - aa;
		create_img(*vars);
	}
	if (button == Button5)
	{
		a = (vars->y_zero - y) * 1 * vars->multi;
		b = (x - vars->x_zero) * 1 * vars->multi;	
		vars->multi = vars->multi / 0.75;
		aa = - (a / (1 * vars->multi) - vars->y_zero);
		bb =  (b / (1 * vars->multi) + vars->x_zero);
		//aa = (vars->y_zero - a) * 0.005 * vars->multi;
		//bb = (b - vars->x_zero) * 0.005 * vars->multi;	
		//aa = (vars->y_zero - a) * 0.005 * vars->multi;
		//bb = (b - vars->x_zero) * 0.005 * vars->multi;	
		vars->x_zero +=  x - bb;
        	vars->y_zero += - y + aa;
		create_img(*vars);
	/*
		vars->multi = vars->multi / 0.75;
		aa = (vars->y_zero - y) * vars->multi;
		bb = (x - vars->x_zero) * vars->multi;	
		vars->x_zero += - x + bb;
        	vars->y_zero += - y + aa;
		create_img(*vars);
	
	*/
	}
;
		
	return 0;
}

int	closef(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{	
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(1);
	}
	else if (keycode == XK_Left)
	{ 
		vars->x_zero = vars->x_zero + 15;
		create_img(*vars);
	}
	else if (keycode == XK_Right)
	{
		vars->x_zero = vars->x_zero - 15;
		create_img(*vars);
	}
	else if (keycode == XK_Up)
	{
		vars->y_zero = vars->y_zero + 15;
		create_img(*vars);
	}
	else if (keycode == XK_Down)
	{
		vars->y_zero = vars->y_zero - 15;
		create_img(*vars);
	}
	return (0);
}

int ft_strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}

int	main(int ac, char **av)
{

	t_vars	vars;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		vars.fract = 1;
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0 && ft_atoi(av[2]) && ft_atoi(av[3]))
	{
		vars.av2 = ft_atoi(av[2]);
		vars.av3 = ft_atoi(av[3]);
		vars.fract = 0; 
	}
	else
	{
		write(1, "\nFor mandelbrot set: mandelbrot\nFor julia sets: julia [value_x] [value_y]\n\n", 76);
		return (0);
	}
	datainit(&vars);
	create_img(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_mouse_hook(vars.win, ft_multi, &vars);
	mlx_key_hook(vars.win, closef, &vars);
	mlx_hook(vars.win, 17, 0L, closeff, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

