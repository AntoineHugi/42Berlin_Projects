/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:43:45 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/14 15:45:23 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

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

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif
