/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:48:58 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:23:40 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *elem)
{
	t_list	*temp;

	while (elem)
	{
		temp = elem;
		elem = elem->next;
		free(temp);
	}
}

t_list	**create_stack(char **args)
{
	t_list	**new_stack;
	t_list	*new_elem;

	new_stack = (t_list **)malloc(sizeof(t_list *));
	if (!new_stack)
		return (NULL);
	*new_stack = NULL;
	while (*args)
	{
		new_elem = ft_lstnew(ft_atoi(*args));
		if (!new_elem)
		{
			free_stack(*new_stack);
			free(new_stack);
			return (NULL);
		}
		ft_lstadd_back(new_stack, new_elem);
		args++;
	}
	return (new_stack);
}

void	indexing(t_list **stack)
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

void	set_position(t_list *stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp->pos = i;
		i++;
		temp = temp->next;
	}
}
