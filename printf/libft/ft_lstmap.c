/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:48:17 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/18 12:52:15 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_start;
	t_list	*new_list_iter;
	t_list	*new_list_next;

	if (!lst)
		return (NULL);
	new_list_iter = ft_lstnew(f(lst->content));
	if (!new_list_iter)
		return (NULL);
	new_list_start = new_list_iter;
	lst = lst->next;
	while (lst)
	{
		new_list_next = ft_lstnew(f(lst->content));
		if (!new_list_next)
		{
			ft_lstclear(&new_list_start, del);
			return (NULL);
		}
		new_list_iter->next = new_list_next;
		lst = lst->next;
		new_list_iter = new_list_next;
	}
	return (new_list_start);
}
