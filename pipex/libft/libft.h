/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:03:11 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/06 12:03:23 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_gnl_strncpy(char *dst, char *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_gnl_strchr_mod(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
