/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:52:57 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:44:03 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	i;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((unsigned int)ft_strlen(s) - start < len)
		size = (unsigned int)ft_strlen(s) - start;
	else
		size = len;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start] && size > 0)
	{
		sub[i] = s[start];
		size--;
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	puts(ft_substr("olaola", 10, 1));
	return 0;
}*/
