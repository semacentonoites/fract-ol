/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:41:55 by erferrei          #+#    #+#             */
/*   Updated: 2023/10/10 12:58:51 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	i = 0;
	a = -1;
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			a = i;
		i++;
	}
	if (a != -1)
		return ((char *)s + a);
	if ((unsigned char)c == 0 && s[i] == 0)
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	printf("%s", ft_strrchr(av[1], '\0'));
	return 0;
}*/
