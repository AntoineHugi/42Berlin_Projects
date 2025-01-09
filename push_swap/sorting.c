/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:02:24 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/07 16:06:31 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_big_index(t_list **stack)
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

static void	sort_basic(t_list **stack)
{
	int	big_index;

	big_index = find_big_index(stack);
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

static void	reduce_a(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;

	size = ft_lstsize(*stack_a);
	pushed = 0;
	/*while (size > 6 && pushed < size / 2 && !is_sorted(stack_a))
	{
		if ((*stack_a)->index < size / 2)
		{
			push_to_b(stack_a, stack_b);
			pushed++;
		}
		else
		{
			ft_printf("reduce\n");
			rotate_a(stack_a);
		}	
	}*/
	while (size - pushed > 3 && !is_sorted(stack_a))
	{
		push_to_b(stack_a, stack_b);
		pushed++;
	}
}

static void	final_sorting(t_list **stack)
{
	int		big_index;
	int		check;
	t_list	*temp;

	big_index = find_big_index(stack);
	temp = *stack;
	set_position(stack);
	while (temp)
	{
		if (temp->index == big_index)
		{
			if (temp->pos >= ft_lstsize(*stack) / 2)
				check = 1;
			else
				check = 0;
		}
		temp = temp->next;
	}
	while (!is_sorted(stack))
	{
		if (check == 1)
			rev_rotate_a(stack);
		else
			rotate_a(stack);
	}
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	reduce_a(stack_a, stack_b);
	sort_basic(stack_a);
	while (*stack_b)
	{
		ft_set_target(stack_a, stack_b);
		make_best_move(stack_a, stack_b);
	}
	//ft_printf("Stack A\n");
	//ft_print_for_test(stack_a);
	final_sorting(stack_a);
}
