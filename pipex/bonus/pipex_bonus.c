/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:48:09 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/17 14:51:16 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	check_heredoc(char *str)
{
	if (!ft_strncmp(str, "here_doc", 9) && ft_strlen(str) == 8)
		return (1);
	else
		return (0);
}

static int	first(char **argv, char **envp, int hd)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		print_error("piping failed", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		print_error("forking failed", EXIT_FAILURE);
	else if (pid == 0)
		b_first_child_process(pipe_fd, argv, envp, hd);
	close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	return (pipe_fd[0]);
}

static int	middle(int tmp_fd, int argc, char **argv, char **envp, int hd)
{
	int		pipe_fd[2];
	int		i;
	pid_t	pid;

	i = 3 + hd;
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			print_error("piping failed", EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			print_error("forking failed", EXIT_FAILURE);
		if (pid == 0)
			b_next_child_process(pipe_fd, tmp_fd, argv[i], envp);
		waitpid(pid, NULL, 0);
		close(tmp_fd);
		close(pipe_fd[1]);
		tmp_fd = pipe_fd[0];
		i++;
	}
	return (tmp_fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	tmp_fd;
	int	hd;


	if (input_validation(argc))
	{
		tmp_fd = -1;
		hd = check_heredoc(argv[1]);
		tmp_fd = first(argv, envp, hd);
		tmp_fd = middle(tmp_fd, argc, argv, envp, hd);
		b_parent_process(tmp_fd, argc, argv, envp, hd);
	}
	return (0);
}
