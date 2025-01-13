/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:15 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:23:45 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_list	**stack_a;
	t_list	**stack_b;

	args = NULL;
	if (is_valid_input(argc, argv, &args))
	{
		stack_b = (t_list **)malloc(sizeof(t_list *));
		if (!stack_b)
			return (0);
		*stack_b = NULL;
		stack_a = create_stack(args);
		if (!stack_a)
			return (0);
		indexing(stack_a);
		sorting(stack_a, stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
