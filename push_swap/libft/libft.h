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
	int				value;
	int				index;
	int				pos;
	int				target;
	int				move_a;
	int				move_b;
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_toupper(int c);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *lst);
long long	ft_atoll(const char *nptr);

#endif
