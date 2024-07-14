/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:26:44 by erferrei          #+#    #+#             */
/*   Updated: 2023/10/10 12:41:31 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			a = 1;
			break ;
		}
		i++;
	}
	if (a || (unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	printf("%s", ft_strchr(av[1], 358));
	return 0;
}*/
