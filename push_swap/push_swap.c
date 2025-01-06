/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:15 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 14:43:16 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_print_for_test(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	while (temp)
	{
		ft_printf("value: %i; ", temp->value);
		ft_printf("index: %i; ", temp->index);
		ft_printf("\n");
		temp2 = temp->next;
		temp = temp2;
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (argc > 2)
		args = argv + 1;
	if (!is_valid(args))
		write(2, "Error\n", 6);
	else
	{
		stack_b = malloc(sizeof(t_list *));
		if (!stack_b)
			return (0);
		stack_a = ft_create_stack(args);
		ft_indexing(stack_a);
		//ft_print_for_test(stack_a);
		ft_sorting(stack_a, stack_b);
		ft_sort_basic(stack_a);
		ft_printf("stack A:\n");
		ft_print_for_test(stack_a);
		ft_printf("stack B:\n");
		ft_print_for_test(stack_b);
	}
	return (0);
}
