/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:10:54 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:23:51 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*it(char *str, int n, int nn, int a)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 1;
		n = -2147483647;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while ((nn > 0 && str[0] != '-') || (nn > 1 && str[0] == '-'))
	{
		nn--;
		str[nn] = n % 10 + 48;
		n = n / 10;
	}
	if (i)
		str[a - 1]++;
	return (str);
}

char	*ft_itoa(int n)
{
	int		nn;
	char	*str;
	int		i;
	int		a;

	nn = 0;
	i = n;
	if (i <= 0)
		nn++;
	while (i != 0)
	{
		i = i / 10;
		nn++;
	}
	a = nn;
	str = (char *)malloc((nn + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nn] = '\0';
	return (it(str, n, nn, a));
}
/*
int	main(void)
{
	puts(ft_itoa(156));
	return 0;
}*/
