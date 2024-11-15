#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *first;
    t_list  *next;
    
    if (!*lst || !del)
        return ;
    first = *lst;
    while ((!first))
    {
        next = first->next;
        del(first->content);
        free(first);
        first = next;
    }
    *lst = NULL;
    free(lst);
}