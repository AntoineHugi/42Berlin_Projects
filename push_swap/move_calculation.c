/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:47:21 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/06 16:47:22 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	t_list	*temp;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	temp = *stack_b;
	while (temp)
	{
		if (temp->pos < size_b / 2)
			temp->move_top_b = temp->pos;
		else
			temp->move_top_b = -(size_b - temp->pos);
		if (temp->target < size_a / 2)
			temp->move_right_a = temp->target;
		else
			temp->move_right_a = -(size_a - temp->target);
		temp = temp->next;
	}
}

void    get_best_move(t_list **stack_a, t_list **stack_b)
{
	t_list		*temp;
	int		best;
	int		move_right_a;
	int		move_top_b;

	temp = *stack_b;
	best = 2147483647;
	while (temp)
	{
		if (ft_abs(temp->move_right_a) + ft_abs(temp->move_top_b) < ft_abs(best))
		{
			best = ft_abs(temp->move_top_b) + ft_abs(temp->move_right_a);
			move_right_a = temp->move_right_a;
			move_top_b = temp->move_top_b;
		}
		temp = temp->next;
	}
	// use moves to decide how many time to rotate
	make_move(stack_a, stack_b, move_right_a, move_top_b);
}

