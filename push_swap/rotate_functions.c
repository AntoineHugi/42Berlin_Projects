/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:43:03 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 14:43:05 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **a)
{
	t_list	*first;

	if (*a)
	{
		first = *a;
		*a = first->next;
		ft_lstadd_back(a, first);
		first->next = NULL;
	}
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate(t_list **a)
{
	t_list	*last;
	t_list	*temp;

	if (*a)
	{
		last = ft_lstlast(*a);
		temp = *a;
		while (temp->next != last && temp->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, last);
	}
}

void	rev_rotate_both(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
