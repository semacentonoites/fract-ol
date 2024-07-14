/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:36:47 by erferrei          #+#    #+#             */
/*   Updated: 2024/06/17 20:38:16 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>
//#include "libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	long int		x_zero;
	long int		y_zero;
	long double		multi;
	int				fract;
	long double		av2;
	long double		av3;
}				t_vars;

void		datainit(t_vars *vars);
int			closeff(t_vars *vars);
int			check_d(long double x, long double y);
long double	ft_atol(const char *nbr);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			check_mandel(long double x, long double y);
int			check_julia(long double x, long double y,
				long double b_j, long double a_j);
int			create_trgb(int t, int r, int g, int b);

#endif
