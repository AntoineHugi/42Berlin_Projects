/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:46:33 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/14 15:51:42 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

struct t_list	*ft_create_elem(void *data)
{
	struct t_list	*new_elem;

	new_elem = (struct t_list *)malloc(sizeof(struct t_list));
	if (!new_elem)
	{
		return (NULL);
	}
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}
