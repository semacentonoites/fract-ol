/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:44:51 by erferrei          #+#    #+#             */
/*   Updated: 2023/10/03 17:15:28 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)s)[i++] = c;
		n--;
	}
	return (s);
}

/*
#include <string.h>
int main () {
   char str[50];

   strcpy(str,"Teste teste teste");
   puts(str);

   ft_memset(str, '%', 3);
   //printf("%d %d %d", str[0], str[1], str[2]);
   puts(str);

   return(0);
}*/
