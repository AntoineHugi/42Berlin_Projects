/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:15 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/07 16:05:43 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_for_test(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	while (temp)
	{
		ft_printf("value: %i; ", temp->value);
		ft_printf("index: %i; ", temp->index);
		ft_printf("\n");
		temp2 = temp->next;
		temp = temp2;
	}
	ft_printf("Stack A\n");
	ft_print_for_test(stack);
}

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
		indexing(stack_a);
		sorting(stack_a, stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
