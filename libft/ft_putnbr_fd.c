/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:45:14 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:42:57 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
		else if (n / 10 == 0)
		{
			n = n + 48;
			write (fd, &n, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
/*
void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
int	pwr(int n)
{
	float	b;

	b = 10.0;
	while (n > 0)
	{
		b = b / 10.0;
		n = n / 10;
	}
	return (1.0 / b);
}			

void	ft_putnbr_fd(int n, int fd)
{

	int	b;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	b = pwr(n);
	while (n / 10 > 0)
	{
		ft_putchar(n / b + 48, fd);
		n = n - n / b * b;
		b = b / 10;
	}
	ft_putchar(n + 48, fd);
}

int	main(void)
{
	printf("%d", pwr(123));
	return 0;
} */
