/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:43:03 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 14:43:05 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;

	if (*stack)
	{
		first = *stack;
		*stack = first->next;
		ft_lstadd_back(stack, first);
		first->next = NULL;
	}
}

void	rotate_a(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
