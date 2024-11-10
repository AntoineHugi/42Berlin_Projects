#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t  i;

    if (!s1 || !s2)
    {
        return (0);
    }
    while (i < n && s1 && s2)
    {
        if ((unsigned char)*(char*)(s1 + i) != (unsigned char)*(char*)(s2 + i))
        {
            return ((unsigned char)*(char*)(s1 + i) - (unsigned char)*(char*)(s2 + i));
        }
        i++;
    }
    return (0);
}
