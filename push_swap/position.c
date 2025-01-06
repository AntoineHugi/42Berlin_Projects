/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:07:44 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/06 16:07:59 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		i++;
		temp = temp->next;
	}
}
