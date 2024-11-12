/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:55:05 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/11 13:44:28 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	if (nmemb == 0 || size == 0 || nmemb * size > 2147483647)
	{
		return (NULL);
	}
	ptr = (char *)malloc(nmemb * size + 1);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i++] = 0;
	}
	ptr[i] = 0;
	return ((void *)ptr);
}
