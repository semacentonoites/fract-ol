/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:16:56 by erferrei          #+#    #+#             */
/*   Updated: 2023/10/10 14:13:36 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			a = 1;
			break ;
		}
		i++;
	}
	if (a && n != 0)
		return ((void *)s + i);
	return (NULL);
}
/*
#include <string.h>
int	main(int ac, char **av)
{
	(void) ac;
	printf("%s",(char *)ft_memchr(av[1], 'a', 3));
	return 0;
}*/
