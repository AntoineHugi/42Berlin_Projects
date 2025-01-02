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

void	swap(t_list **a);
void	swap_both(t_list **a, t_list **b);
void	push_to_a(t_list **a, t_list **b);
void	push_to_b(t_list **a, t_list **b);
void	rotate(t_list **a);
void	rotate_both(t_list **a, t_list **b);
void	rev_rotate(t_list **a);
void	rev_rotate_both(t_list **a, t_list **b);


#endif
