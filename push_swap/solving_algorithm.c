/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:02:24 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 16:02:26 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorting(t_list **stack_a, t_list **stack_b)
{
    if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_a)->next->content))
    {
        push_to_b(stack_a, stack_b);
        write (1, "pb", 3);
    }
}