/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:26:33 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/27 21:31:04 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main () {
   //const char src[50] = "https://www.tutorialspoint.com";
   //char dest[50];
   //strcpy(dest,"Heloooo!!");
   //printf("Before memcpy dest = %s\n", dest);
   //memcpy(dest, src, 3);
   //printf("After memcpy dest = %s\n", dest);
   puts(ft_memcpy(((void*)0), ((void*)0), 3));
   return(0);
}*/
