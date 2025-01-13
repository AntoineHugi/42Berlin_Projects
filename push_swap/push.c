/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:56 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:24:08 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = temp->next;
		ft_lstadd_front(stack_a, temp);
	}
	write(1, "pa\n", 3);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		ft_lstadd_front(stack_b, temp);
	}
	write(1, "pb\n", 3);
}
