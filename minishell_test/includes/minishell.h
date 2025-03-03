/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:27:48 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/03 13:30:38 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <termcap.h>

typedef struct s_simp_com {
	int		num_allocated_arg;
	int		num_arg;
	char	**arguments;
	void	*insert_argument;
}				t_simp_com;

typedef struct s_command {
	int		num_allocated_com;
	int		num_com;
	int		pipe;
	int		rd_output;
}				t_command;

int		input_validation(int argc);
int		check_heredoc(char *str);
int		buff_check(char *limiter, char *buffer);
void	print_error(char *msg, int err_num);
void	free_array(char **array);
void	run_cmd(char *cmd, char **envp);
void	b_next_child_process(int *pipe_fd, int tmp_fd, char *cmd, char **envp);
void	b_first_child_process(int *pipe_fd, char **argv, char **envp, int hd);
void	b_parent_process(int tmp_fd, int argc, char **argv, char **envp);

#endif