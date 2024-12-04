/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:52:09 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 13:56:48 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

/* typedef struct s_text
{
	int	size;
	char	*read;
	char	*line;
	char	*keep;
	struct s_text	*text;
} text; */
char	*get_next_line(int fd);
char	*ft_strchr_mod(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_memcpy(char *dst, char *src, size_t n);
size_t	ft_strlen(char *s);
#endif
