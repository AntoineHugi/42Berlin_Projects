/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:59:21 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/11 17:00:02 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t ft_check_set(char const *s1, char const *set)
{
    size_t len;
    size_t len_set;

    len = 0;
    len_set = ft_strlen(set);
    while (*s1 && *set)
    {
        if (*s1 == *set)
        {
            len++;
        }
        s1++;
        set++;
    }
    if (len == len_set)
    {
        return (len);
    }
    else
    {
        return (0);
    }
}


char	*ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    size_t i;
    char    *result;

    i = 0;
    start = ft_check_set(&s1[0], set);
    end = ft_check_set(&s1[ft_strlen(s1) - ft_strlen(set)], set);
    result = (char *)malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
    while (start < ft_strlen(s1) - end)
    {
        result[i++] = s1[start++];
    }
    result[i] = '\0';
    return (result);
}
