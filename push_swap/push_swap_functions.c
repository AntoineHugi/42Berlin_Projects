/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:56 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 14:42:57 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		*b = temp->next;
		ft_lstadd_front(a, temp);
	}
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		*a = temp->next;
		ft_lstadd_front(b, temp);
	}
}

void	swap(t_list **a)
{
	t_list	*temp;

	if (*a && (*a)->next != NULL)
	{
		temp = (*a)->next;
		(*a)->next = temp->next;
		ft_lstadd_front(a, temp);
	}
}

void	swap_both(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
