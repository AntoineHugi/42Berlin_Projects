/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:15 by ahugi             #+#    #+#             */
/*   Updated: 2024/12/17 12:00:17 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
    char    **args;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (argc > 2)
		args = ++argv;
	if (!ft_is_valid(args) || !ft_no_dup(args))
	{
		//write(2, "Error\n", 6);
		printf("Error - val = %i, dup = %i", ft_is_valid(args), ft_no_dup(args));
	}
	else
	{
		write(1, "Valid\n", 6);
		//ft_solve(args);
	}
	return (0);
}