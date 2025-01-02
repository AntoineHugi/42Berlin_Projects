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

int	ft_no_dup(char **args)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			len = ft_strlen(args[i]);
			if (ft_strlen(args[i]) < ft_strlen(args[j]))
				len = ft_strlen(args[j]);
			if (!ft_strncmp(args[i], args[j], len))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_valid(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
		new_elem = ft_lstnew(*args);
		if (!new_elem)
		{
			while (*new_stack)
			{
				temp = *new_stack;
				*new_stack = (*new_stack)->next;
				free(temp);
			}
			free(new_stack);
			return (NULL);
		}
		ft_lstadd_back(new_stack, new_elem);
		args++;
	}
	return (new_stack);
}



void	ft_print_for_test(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	while (temp)
	{
		ft_printf("%s\n", temp->content);
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
	if (!ft_is_valid(args) || !ft_no_dup(args))
		write(2, "Error\n", 6);
	else
	{
		
		stack_a = ft_create_stack(args);
		stack_b = malloc(sizeof(t_list *));
		if (!stack_a || !stack_b)
			return (0);
		ft_print_for_test(stack_a);
		write(1, "\n", 1);
		rotate(stack_a);
		ft_print_for_test(stack_a);
		write(1, "\n", 1);
		rev_rotate(stack_a);
		ft_print_for_test(stack_a);
	}
	return (0);
}
