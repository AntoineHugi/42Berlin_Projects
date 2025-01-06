/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:02:24 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 16:02:26 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_big(t_list **stack)
{
	int		big_index;
	t_list	*current;

	big_index = 0;
	current = *stack;
	while (current)
	{
		if (current->index > big_index)
			big_index = current->index;
		current = current->next;
	}
	return (big_index);
}

void	ft_sort_basic(t_list **stack)
{
	int	big_index;

	big_index = ft_find_big(stack);
	while (!is_sorted(stack))
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			if ((*stack)->index == big_index)
				rotate_a(stack);
			else
				swap_a(stack);
		}
		else
			rev_rotate_a(stack);
	}
}

void	ft_reduce_a(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;

	size = ft_lstsize(*stack_a);
	pushed = 0;
	while (size > 6 && pushed < (size / 2) - 1 && !is_sorted(stack_a))
	{
		if ((*stack_a)->index < size / 2)
		{	
			push_to_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
	}
	while (size - pushed > 3 && !is_sorted(stack_a))
	{
		push_to_b(stack_a, stack_b);
		pushed++;
	}
}

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	ft_reduce_a(stack_a, stack_b);
	
}
