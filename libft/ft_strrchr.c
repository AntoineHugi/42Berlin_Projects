/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:27:49 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/07 11:37:02 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	size_t	i;

	i = 0;
	ptr = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (unsigned char)c)
		{
			ptr = &s[i];
		}
		i++;
	}

	return ((char *)ptr);
}
