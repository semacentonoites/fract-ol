/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:51:09 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/14 02:51:15 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	get_color(int is)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 255;
	if (is == 100)
		return (create_trgb(255, 0, 0, 0));
	is = is * 12;
	while (is > 0)
	{
		while (r++ < 254 && is-- > 0)
			;
		while (b-- > 1 && is-- > 0)
			;
		while (g++ < 100 && is-- > 0)
			;
		while (r-- > 1 && is-- > 0)
			;
		while (b++ < 100 && is-- > 0)
			;
	}
	return (create_trgb(255, r, g, b));
}

int	create_img(t_vars *vars)
{
	long double	a;
	long double	b;
	int			is;
	int			x;
	int			y;

	x = 0;
	b = (x - vars->x_zero) * 0.005 * vars->multi;
	while (x++ < 800)
	{
		y = 0;
		a = (vars->y_zero - y) * 0.005 * vars->multi;
		while (y++ < 600)
		{
			if (vars->fract)
				is = check_mandel(b, a);
			else
				is = check_julia(b, a, vars->av2, vars->av3);
			my_mlx_pixel_put(vars, x, y, get_color(is));
			a -= 0.005 * vars->multi;
		}
		b += 0.005 * vars->multi;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}

int	ft_multi(int button, int x, int y, t_vars *vars)
{
	long double	aa;
	long double	bb;
	long double	a;
	long double	b;

	aa = (vars->y_zero - y) * 0.005 * vars->multi;
	bb = (x - vars->x_zero) * 0.005 * vars->multi;
	if (button == Button4)
		vars->multi = vars->multi * 0.75;
	else if (button == Button5)
		vars->multi = vars->multi / 0.75;
	a = (vars->y_zero - y) * 0.005 * vars->multi;
	b = (x - vars->x_zero) * 0.005 * vars->multi;
	a = -a + aa;
	b = b - bb;
	if (vars->multi != 0)
	{
		vars->x_zero += b / (0.005 * vars->multi);
		vars->y_zero += a / (0.005 * vars->multi);
	}
	return (0);
}

int	closef(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		closeff(vars);
	else if (keycode == XK_Left)
		vars->x_zero = vars->x_zero + 15;
	else if (keycode == XK_Right)
		vars->x_zero = vars->x_zero - 15;
	else if (keycode == XK_Up)
		vars->y_zero = vars->y_zero + 15;
	else if (keycode == XK_Down)
		vars->y_zero = vars->y_zero - 15;
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		vars.fract = 1;
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0
		&& av[2][0] != '\0' && av[3][0] != '\0')
	{
		vars.av2 = ft_atol(av[2]);
		vars.av3 = ft_atol(av[3]);
		vars.fract = 0;
	}
	else
	{
		write(1, "\nFor mandelbrot set: mandelbrot\n"
			"For julia sets: julia [value_x] [value_y]\n\n", 76);
		return (0);
	}
	datainit(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, create_img, &vars);
	mlx_mouse_hook(vars.win, ft_multi, &vars);
	mlx_key_hook(vars.win, closef, &vars);
	mlx_hook(vars.win, 17, 0L, closeff, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
