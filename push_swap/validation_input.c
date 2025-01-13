/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:46:13 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:25:02 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_no_dup(char **args)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			len = ft_strlen(args[i]);
			if (ft_strlen(args[i]) < ft_strlen(args[j]))
				len = ft_strlen(args[j]);
			if (!ft_strncmp(args[i], args[j], len))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_number(char *args)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (args[i] == '-')
		i++;
	while (args[i])
	{
		check = 1;
		if (!ft_isdigit(args[i]))
			return (0);
		i++;
	}
	return (check);
}

static int	is_zero(char *args)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	while (args[i] && args[i] == '0')
	{
		check = 1;
		i++;
	}
	if (args[i] != '\0')
		return (0);
	else
		return (check);
}

static int	is_valid(char **args)
{
	int	i;
	int	num_zero;

	if (!ft_no_dup(args))
		return (0);
	i = 0;
	num_zero = 0;
	while (args[i])
	{
		if (ft_atoll(args[i]) > 2147483647 \
			|| ft_atoll(args[i]) < -2147483648)
			return (0);
		if (!is_number(args[i]))
			return (0);
		if (is_zero(args[i]))
			num_zero++;
		i++;
	}
	if (num_zero > 1)
		return (0);
	return (1);
}

int	is_valid_input(int argc, char **argv, char ***args)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	if (argc > 2)
		*args = argv + 1;
	if (!is_valid(*args))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	else
		return (1);
}
