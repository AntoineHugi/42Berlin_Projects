#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t     i;
    char    *tempsrc;
    char    *tempdst;

    if (!dst || !src)
    {
        return (NULL);
    }
    i = 0;
    tempsrc = (char*)src;
    tempdst = (char*)dst;
    while (i < n)
    {
        tempdst[i] = tempsrc[i];
        i++;
    }
    return (dst);
}
