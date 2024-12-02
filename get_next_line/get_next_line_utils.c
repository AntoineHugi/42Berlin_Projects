/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:41 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 13:52:00 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*z_ptr;
	void			*ptr;
	size_t			i;

	if (nmemb * size > 2147483647)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	z_ptr = (unsigned char *)ptr;
	while (i < size * nmemb)
	{
		z_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	if (!s)
		return (0);	
	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)ft_calloc(sizeof(char), (s1_size + s2_size + 1));
	if (!result)
		return (NULL);
	ft_memcpy(&result[0], s1, s1_size);
	ft_memcpy(&result[s1_size], s2, s2_size);
	return (result);
}

char	*ft_strchr_mod(char *s)
{
	size_t		i;
	char	*ptr;

	while (*s)
	{
		if (*s == '\n')
		{
			s++;
			break ;
		}
		s++;
	}
	i = 0;
	ptr = (char *)ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
