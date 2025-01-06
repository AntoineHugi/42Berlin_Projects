/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:48:58 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/06 13:48:59 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_create_stack(char **args)
{
	t_list	**new_stack;
	t_list	*new_elem;
	t_list	*temp;

	new_stack = malloc(sizeof(t_list *));
	if (!new_stack)
		return (NULL);
	while (*args)
	{
		new_elem = ft_lstnew(ft_atoi(*args));
		if (!new_elem)
		{
			while (*new_stack)
			{
				temp = *new_stack;
				*new_stack = (*new_stack)->next;
				free(temp);
			}
			free(new_stack);
			exit (0);
		}
		ft_lstadd_back(new_stack, new_elem);
		args++;
	}
	return (new_stack);
}

void	ft_indexing(t_list **stack)
{
	int		size;
	int		min;
	t_list	*current;
	t_list	*biggest;

	size = ft_lstsize(*stack);
	while (size > 0)
	{
		current = *stack;
		min = -2147483648;
		while (current)
		{
			if (current->value > min && current->index == 0)
			{
				min = current->value;
				biggest = current;
			}
			current = current->next;
		}
		if (biggest)
			biggest->index = size;
		size--;
	}
}

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
