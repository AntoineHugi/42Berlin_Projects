/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:24 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:23:59 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_single_a(t_list **stack, int *move)
{
	while (*move > 0)
	{
		rotate_a(stack);
		*move = *move - 1;
	}
	while (*move < 0)
	{
		rev_rotate_a(stack);
		*move = *move + 1;
	}
}

static void	move_single_b(t_list **stack, int *move)
{
	while (*move > 0)
	{
		rotate_b(stack);
		*move = *move - 1;
	}
	while (*move < 0)
	{
		rev_rotate_b(stack);
		*move = *move + 1;
	}
}

static void	move_double(t_list **a, t_list **b, int *move_a, int *move_b)
{
	while (*move_a > 0 && *move_b > 0)
	{
		rotate_both(a, b);
		*move_a = *move_a - 1;
		*move_b = *move_b - 1;
	}
	while (*move_a < 0 && *move_b < 0)
	{
		rev_rotate_both(a, b);
		*move_a = *move_a + 1;
		*move_b = *move_b + 1;
	}
}

void	execute_move(t_list **a, t_list **b, int *move_a, int *move_b)
{
	if (*move_a != 0 && *move_b != 0)
		move_double(a, b, move_a, move_b);
	if (*move_a != 0)
		move_single_a(a, move_a);
	if (*move_b != 0)
		move_single_b(b, move_b);
	push_to_a(a, b);
}
