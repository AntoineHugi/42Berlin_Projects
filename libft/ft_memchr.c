#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    char    *temp_src;

    if (!s)
    {
        return (NULL);
    }
    temp_src = (const char*)s;
    while (i < n)
    {
        if (temp_src[i] == (unsigned char)c)
        {
            return (temp_src);
        }
        i++;
    }
    return (0);
}