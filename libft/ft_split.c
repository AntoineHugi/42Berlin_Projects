/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:17:51 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/11 15:18:29 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c)
{
	int	str_count;
	int	i;

	i = 0;
	str_count = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			str_count++;
		}
		i++;
	}
	return (str_count);
}

static void	ft_fill_grid(char **result, char const *s, char c, int str_count)
{
	int	str_iter;
	int	letter_iter;

	str_iter = 0;
	while (str_iter < str_count)
	{
		letter_iter = 0;
		while (*s != 0 && *s != c)
		{
			result[str_iter][letter_iter++] = *s;
			s++;
		}
		result[str_iter][letter_iter] = '\0';
		s++;
		str_iter++;
	}
}

static void	ft_malloc_words(char **result, char const *s, char c, int str_count)
{
	int	str_iter;
	int	letter_iter;

	str_iter = 0;
	while (str_iter < str_count)
	{
		letter_iter = 0;
		while (*s != 0 && *s != c)
		{
			letter_iter++;
			s++;
		}
		result[str_iter] = (char *)malloc(sizeof(char) * letter_iter + 1);
		s++;
		str_iter++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		str_count;

	if (!s)
	{
		return (NULL);
	}
	str_count = ft_str_count(s, c);
	result = (char **)malloc(sizeof(char *) * (str_count + 1));
	ft_malloc_words(result, s, c, str_count);
	ft_fill_grid(result, s, c, str_count);
	result[str_count] = NULL;
	return (result);
}
