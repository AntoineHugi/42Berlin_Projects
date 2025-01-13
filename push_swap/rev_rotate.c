/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:30:20 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:24:25 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (*stack)
	{
		last = ft_lstlast(*stack);
		temp = *stack;
		while (temp->next != last && temp->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack, last);
	}
}

void	rev_rotate_a(t_list **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
