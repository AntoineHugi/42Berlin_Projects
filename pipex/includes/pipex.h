/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:48:28 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/17 14:48:31 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

int		input_validation(int argc);
int		buff_check(char *limiter, char *buffer);
void	print_error(char *msg, int err_num);
void	free_array(char **array);
void	run_cmd(char *cmd, char **envp);
void	b_next_child_process(int *pipe_fd, int tmp_fd, char *cmd, char **envp);
void	b_first_child_process(int *pipe_fd, char **argv, char **envp, int hd);
void	b_parent_process(int tmp_fd, int argc, char **argv, char **envp, int hd);

#endif
