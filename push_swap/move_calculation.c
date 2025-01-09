/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:47:21 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/07 16:05:51 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static void	get_moves(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	t_list	*temp;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	temp = *stack_b;
	while (temp)
	{
		if (temp->pos <= size_b / 2)
			temp->move_b = temp->pos;
		else
			temp->move_b = -(size_b - temp->pos);
		if (temp->target <= size_a / 2)
			temp->move_a = temp->target;
		else
			temp->move_a = -(size_a - temp->target);
		temp = temp->next;
	}
}

void	make_best_move(t_list **stack_a, t_list **stack_b)
{
	int		best;
	int		move_a;
	int		move_b;
	t_list	*temp;

	temp = *stack_b;
	best = 2147483647;
	get_moves(stack_a, stack_b);
	while (temp)
	{
		if (ft_abs(temp->move_a) + ft_abs(temp->move_b) < ft_abs(best))
		{
			best = ft_abs(temp->move_b) + ft_abs(temp->move_a);
			move_a = temp->move_a;
			move_b = temp->move_b;
		}
		temp = temp->next;
	}
	execute_move(stack_a, stack_b, &move_a, &move_b);
}
