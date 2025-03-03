/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:48:09 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/17 14:48:10 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	parent_process(int *pipe_fd, char **argv, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_outfile == -1)
		print_error(argv[4], ENOENT);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(argv[3], envp);
}

static void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		print_error(argv[1], ENOENT);
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd_infile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (input_validation(argc))
	{
		if (pipe(pipe_fd) == -1)
			print_error(strerror(errno), errno);
		pid = fork();
		if (pid == -1)
			print_error(strerror(errno), errno);
		else if (pid == 0)
			child_process(pipe_fd, argv, envp);
		waitpid(pid, NULL, 0);
		parent_process(pipe_fd, argv, envp);
	}
	return (0);
}
