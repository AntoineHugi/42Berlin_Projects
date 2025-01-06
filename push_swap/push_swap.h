/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:45 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/02 14:43:24 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

int		is_valid(char **args);
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
void	ft_indexing(t_list **stack);
void	ft_sort_basic (t_list **stack);
void    ft_sorting(t_list **stack_a, t_list **stack_b);
void	ft_set_position(t_list **stack);
t_list	**ft_create_stack(char **args);

#endif
