/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:07:44 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/07 16:06:41 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_to_end(t_list **stack_a, t_list *elem_b)
{
	int		index_holder;
	t_list	*temp;

	index_holder = 2147483647;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index < index_holder)
		{
			index_holder = temp->index;
			elem_b->target = temp->pos;
		}
		temp = temp->next;
	}
}

static void	find_target(t_list **stack_a, t_list *elem_b)
{
	int		index_holder;
	t_list	*temp;

	index_holder = 2147483647;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index > elem_b->index && temp->index < index_holder)
		{
			index_holder = temp->index;
			elem_b->target = temp->pos;
		}
		temp = temp->next;
	}
	if (index_holder == 2147483647)
	{
		target_to_end(stack_a, elem_b);
	}
}

void	ft_set_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	set_position(stack_a);
	set_position(stack_b);
	temp = *stack_b;
	while (temp)
	{
		find_target(stack_a, temp);
		temp = temp->next;
	}
}
