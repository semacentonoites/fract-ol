/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:51:46 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/14 02:51:49 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_atol(const char *nbr)
{
	long double	n;
	long double	sign;
	long double	c;
	int			i;

	i = 0;
	c = 1;
	n = 0.0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
		n = nbr[i++] + n * 10 - 48;
	if (nbr[i] == '.' || nbr[i] == ',')
	{
		i++;
		while (nbr[i] >= '0' && nbr[i] <= '9')
			n = n + ((nbr[i++] - 48.0) / 10.0) / pow(10.0, c++ - 1);
	}
	return (n * sign);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_mandel(long double x, long double y)
{
	int				i;
	long double		a;
	long double		b;
	long double		temp_a;

	a = y;
	b = x;
	i = 0;
	while (i < 100)
	{
		if (!check_d(a, b))
			return (i);
		temp_a = a;
		a = 2 * a * b + y;
		b = ((-temp_a * temp_a) + (b * b)) + x;
		i++;
	}
	return (i);
}

int	check_julia(long double x, long double y, long double b_j, long double a_j)
{
	long double	a;
	long double	b;
	long double	temp_a;
	int			i;

	a = a_j + 2 * y * x;
	b = b_j + x * x - y * y;
	i = 0;
	while (i < 100)
	{
		if (!check_d(a, b))
			return (i);
		temp_a = a;
		a = 2 * a * b + a_j;
		b = -temp_a * temp_a + b * b + b_j;
		i++;
	}
	return (i);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
