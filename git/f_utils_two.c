/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:51:56 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/14 02:51:58 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	datainit(t_vars *vars)
{
	vars->multi = 1;
	vars->x_zero = 400;
	vars->y_zero = 300;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 600, "fract-ol");
	vars->img = mlx_new_image(vars->mlx, 800, 600);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

int	closeff(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
	return (0);
}

int	check_d(long double x, long double y)
{
	if (sqrt((x * x) + (y * y)) > 2)
		return (0);
	return (1);
}
