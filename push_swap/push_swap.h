/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:45 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/13 13:24:16 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int		is_valid_input(int argc, char **argv, char ***args);
int		is_sorted(t_list **stack);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rev_rotate_a(t_list **stack);
void	rev_rotate_b(t_list **stack);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);
void	indexing(t_list **stack);
void	set_position(t_list *stack);
void	sorting(t_list **stack_a, t_list **stack_b);
void	ft_set_target(t_list **stack_a, t_list **stack_b);
void	make_best_move(t_list **stack_a, t_list **stack_b);
void	execute_move(t_list **a, t_list **b, int *move_a, int *move_b);
t_list	**create_stack(char **args);

#endif
