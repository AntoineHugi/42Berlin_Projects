/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:48:33 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/06 15:53:19 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	if (s == NULL)
	{
		printf("\nnull\n");
		return;
	}
	unsigned char	*ptr;
	ptr = (unsigned char*)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}