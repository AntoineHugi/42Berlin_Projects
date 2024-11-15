#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int size;

    size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}
/*
#include <stdio.h>

int	main()
{
	t_list	*new_elem;
	int	content = 12345;
    t_list	*new_elem2;
	int	content2 = 9876;

	new_elem = ft_lstnew(&content);
	if (!new_elem)
	{
		printf("creation failed\n");
	}
    new_elem2 = ft_lstnew(&content2);
	if (!new_elem2)
	{
		printf("creation failed for 2\n");
	}
    new_elem->next = new_elem2;
	printf("it worked!\n");
	printf("Here's the content : %i\n", *(int *)new_elem->content);
    printf("Here's the content : %i\n", *(int *)new_elem2->content);
    printf("here's the size %i", ft_lstsize(new_elem));
	free (new_elem);
    free (new_elem2);
}*/