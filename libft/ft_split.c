/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:05:10 by erferrei          #+#    #+#             */
/*   Updated: 2023/11/29 09:42:39 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	a;

	i = 0;
	count = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == c)
			a = 0;
		else if (s[i] != c && a == 0)
		{
			count++;
			a = 1;
		}
		i++;
	}
	return (count);
}

static int	alloc_words(char const *s, char c, int index)
{
	int	i;
	int	a;
	int	value;
	int	count;

	i = 0;
	count = 0;
	a = 0;
	value = 1;
	while (s[i])
	{
		if (s[i] == c)
			a = 0;
		else if (s[i] != c && a == 0)
		{
			count++;
			a = 1;
		}
		if ((count - 1) == index && a == 1)
			value++;
		i++;
	}
	return (value);
}

static void	write_words(char **strstr, char const *s, char c, int index)
{
	int	i;
	int	a;
	int	count;
	int	m;

	i = 0;
	a = 0;
	count = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] == c)
			a = 0;
		else if (s[i] != c && a == 0)
		{
			count++;
			a = 1;
		}
		if ((count - 1) == index && a == 1)
			strstr[index][m++] = s[i];
		i++;
	}
	strstr[index][m] = '\0';
}

static void	free_s(char **s)
{
	int	i;

	i = 0;
	if (!s)
	{
		free(s);
		return ;
	}
	while (s[i])
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**strstr;
	int		word_count;

	word_count = count_words(s, c);
	strstr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!strstr)
		return (NULL);
	index = 0;
	while (word_count > 0)
	{
		strstr[index] = (char *)malloc(alloc_words(s, c, index) * sizeof(char));
		if (!strstr[index])
		{
			free_s(strstr);
			return (NULL);
		}
		write_words(strstr, s, c, index);
		word_count--;
		index++;
	}
	strstr[index] = 0;
	return (strstr);
}

/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}


int	main(void)
{
	char **tabstr;
	int	i;
	i = 0;
    //char str1[] = "This is a";
    //char str2[] = "lorem ipsum dolor sit amet, consectetur adipis
	cing elit. Sed non risus. Suspendisse";
    //char str3[] = "SingleWord";
    //char str4[] = "";
    //char delimiter1 = ' ';

    char delimiter2 = ' ';
    // Test case 1
    char **result1 = ft_split(str2, delimiter2);
    printf("Result 1:\n");
    for (int i = 0; result1[i] != NULL; i++)
    {
        printf("%s\n", result1[i]);
    }
    free(result1);
	//printf("%d", count_words("  OLa alegria  o ", 32));
	return 0;

    if (!(tabstr = ft_split("hello!", ' ')))
        ft_print_result("NULL");
    else
    {
        while (tabstr[i] != NULL)
        {
            ft_print_result(tabstr[i]);
            write(1, "\n", 1);
            i++;
        }
        }
       
       if (!(tabstr = ft_split("", 'z')))
        ft_print_result("NULL");
    else
        if (!tabstr[0])
    
           ft_print_result("ok\n");
          }
*/
