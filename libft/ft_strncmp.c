/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:59:16 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:24:36 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*l;

	s = (unsigned char *)s1;
	l = (unsigned char *)s2;
	i = 0;
	while (i < n && l[i] && s[i])
	{
		if (s[i] != l[i])
			return (s[i] - l[i]);
		i++;
	}
	if (i != n && s[i] != l[i])
		return (s[i] - l[i]);
	return (0);
}
/*
int	main(int ac, char **av)
{
	(void) ac;
	printf("%d", ft_strncmp(av[1], av[2], 1));
	return 0;
}*/
