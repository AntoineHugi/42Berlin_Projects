#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  **new_list_start;
    t_list  *new_list_iter;

    if (!lst)
        return (NULL);
    new_list_iter = ft_lstnew(f(lst->content));
    if (!new_list_iter)
        return (NULL);
    new_list_start = &new_list_iter;
    while (lst->next)
    {
        lst = lst->next;
        new_list_iter->next = ft_lstnew(f(lst->content));
        if (!new_list_iter->next)
        {
            ft_lstclear(new_list_start, del);
            return (NULL);
        }
        new_list_iter = new_list_iter->next;
    }
    return(*new_list_start);
}