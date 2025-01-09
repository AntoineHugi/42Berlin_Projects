/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:37:57 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/07 16:06:36 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;

	if (*stack && (*stack)->next != NULL)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		ft_lstadd_front(stack, temp);
	}
}

void	swap_a(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
