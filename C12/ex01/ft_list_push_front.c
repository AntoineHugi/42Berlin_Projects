/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:13 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/14 16:15:38 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	struct t_list	*new_elem;

	new_elem = ft_create_elem(data);
	if (!new_elem)
	{
		return ;
	}
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}
