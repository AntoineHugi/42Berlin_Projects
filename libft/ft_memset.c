#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
    char    *temp_ptr;
    size_t     i;

    if (!b)
    {
        return (NULL);
    }
    temp_ptr = (char*)b;
    i = 0;
    while (i < len)
    {
        temp_ptr[i] = (unsigned char)c;
        i++;
    }
    return (b);
}