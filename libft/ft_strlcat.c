/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:37:47 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:27:17 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

size_t	ft_strlcat(char *dst, const char *src, int size)
{
	int				nsize;
	size_t			i;
	size_t			j;
	size_t			ret;

	ret = ft_strlen(dst) + ft_strlen(src);
	if (size < 0)
		size = ret + 1;
	nsize = size - ft_strlen(dst);
	i = 0;
	j = ft_strlen(dst);
	while (nsize > 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
		nsize--;
	}
	if (size > 0)
		dst[j] = '\0';
	if (size == 0)
		ret = ft_strlen(src);
	if (nsize <= 0)
		return (ft_strlen(src) + size);
	return (ret);
}

/*
int	main(void)
{
	//(void) ac;
	char	str[30] = "CCCCC";
	char	src[10] = "AAAAAAAAA";

	//puts(str);
	//printf("\n");
	//puts(src);
	//printf("\n");
	printf("%zu", ft_strlcat(str, src, -1));
	//printf("%lu", strlen(str));
        //puts(str);
        printf("\n");
        puts(str);
        printf("\n");
	//printf("%d", strlcat(str, src, 5));
	//strlcat(str, src, atoi(av[1]));
        //puts(str);
        //printf("\n");
        //puts(src);
        //printf("\n");
		//printf("%d %d", ft_strlcat(st
		//, src, atoi(av[1])), strlcat(str, src, atoi(av[1])));
	return 0;
}*/
