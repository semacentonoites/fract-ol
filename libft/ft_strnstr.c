/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:47:52 by erferrei          #+#    #+#             */
/*   Updated: 2023/12/12 01:18:53 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		k = 0;
		while (big[i + k] == little[k] && (i + k) < len)
		{
			k++;
			if (!(little[k]))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
int     main(void)
{
        char *s;
        s = ft_strnstr(" s  sit   si sit ", "", 20);
        printf("%s", s);
        //puts(ft_strnstr("lorem ipsum dolor sit amet", "sit", 20));
        return 0;
}*/
