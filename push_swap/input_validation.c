/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:32:47 by ahugi             #+#    #+#             */
/*   Updated: 2024/12/19 13:32:51 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0)
		length++;
	return (length);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_no_dup (char **args)
{
	int	current;
	int	rest;
	int	check;
	size_t	len;

	check = 1;
	current = 0;
	while (args[current])
	{
		rest = current + 1;
		while(args[rest])
		{
			len = ft_strlen(args[current]);
			if (ft_strlen(args[current]) < ft_strlen(args[rest]))
				len = ft_strlen(args[rest]);
			if (!ft_strncmp(args[current], args[rest], len))
				check = 0;
			rest++;
		}
		current++;
	}
	return (check);
}

int	ft_is_valid (char **args)
{
	int	i;
	int	j;
	int	check;

	check = 1;
	i = 0;
	while (args[i])
	{
		j = 0;
		while(args[i][j])
		{
			if (args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				check = 0;
			j++;
		}
		i++;
	}
	return (check);
}
