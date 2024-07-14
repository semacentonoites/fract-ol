/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:47:17 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:43:53 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_malloc(char const *s1, char const *set, int b)
{
	int	i;
	int	j;
	int	a;

	if (b == 1)
		i = 0;
	else
		i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		a = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				a++;
			j++;
		}
		if (a != 0)
			i = i + b;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	char	*string;
	int		j;

	j = 0;
	i = num_malloc(s1, set, 1);
	f = num_malloc(s1, set, -1);
	if ((2 + f - i) < 1)
	{
		f = -2;
		i = -1;
	}
	string = (char *)malloc((2 + f - i) * sizeof(char));
	if (!string)
		return (NULL);
	while (i <= f)
	{
		string[j] = s1[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

/*
int	main(void)
{
	char s1[] = "  \t \t \n   \n\n\n\t";
	puts(ft_strtrim(s1, " \n\t"));
	//printf("%d", ft_strlen(s1));
	return 0;
}*/
