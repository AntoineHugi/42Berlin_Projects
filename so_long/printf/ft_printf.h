/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:03:11 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:27:57 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printhex(unsigned int arg, char c);
int		ft_printnum(int n, char c);
int		ft_printstr(char *str);
int		ft_printpointer(void *arg);
char	*ft_itoa_hex(unsigned int n);
char	*ft_itoa_hex_pointer(unsigned long n);
void	ft_toupper_str(char *str);
#endif
