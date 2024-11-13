/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:52:09 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/11 12:53:55 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
	{
		return (0);
	}
	n = sizeof(*s1) * n;
	return (ft_strncmp((const char *)s1, (const char *)s2, n));
}
