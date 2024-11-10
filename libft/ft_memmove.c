#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    char    *tempsrc;
    char    *tempdst;
    if (!dst || !src)
    {
        return (NULL);
    }

    tempsrc = (char*)src;
    tempdst = (char*)dst;
    if (dst > src)
    {
        i = len;
        while (i > 0)
        {
            tempdst[i - 1] = tempsrc[i - 1];
            i--;
        }
    }
    else
    {
        i = 0;
        while (i < len)
        {
            tempdst[i] = tempsrc[i];
            i++;
        }
    }
    return (dst);
}