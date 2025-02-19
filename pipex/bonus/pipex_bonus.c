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

static void	hd_parent_process(int *pipe_fd, int argc, char **argv, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	if (fd_outfile == -1)
		print_error("problem opening outfile", ENOENT);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(argv[3], envp);
	print_error("execve failed", EXIT_FAILURE);
}

static void	parent_process(int *pipe_fd, char **argv, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_outfile == -1)
		print_error("problem opening outfile", ENOENT);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(argv[3], envp);
	print_error("execve failed", EXIT_FAILURE);
}

static void	hd_child_process(int *pipe_fd, char **argv, char **envp)
{
	char	*param;
	char	*cmd;
	char	*buffer;

	param = "";
	while (1)
	{
		buffer = get_next_line(1);
		if (ft_strncmp(buffer, argv[2], ft_strlen(buffer)))
			if (ft_strlen(param) == 0)
				ft_strlcat(param, buffer, ft_strlen(param) + strlen(buffer));
			else
			{
				ft_strlcat(param, " ", ft_strlen(param) + strlen(" "));
				ft_strlcat(param, buffer, ft_strlen(param) + strlen(buffer));
			}
		else
		{
			free(buffer);
			break;
		}
		free (buffer);
	}
	ft_printf("\n %s \n", param);
	buffer = ft_strjoin(argv[3], " ");
	cmd = ft_strjoin(buffer, param);
	free(buffer);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(cmd, envp);
	free(cmd);
	print_error("execve failed", EXIT_FAILURE);
}

static void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		print_error("problem opening infile", ENOENT);
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd_infile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	run_cmd(argv[2], envp);
	print_error("execve failed", EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		hd;
	pid_t	pid;

	hd = 0;
	if (input_validation(argc))
	{			
		if (!ft_strncmp(argv[1], "here_doc", 9) && ft_strlen(argv[1]) == 8)
			hd = 1;
		if (pipe(pipe_fd) == -1)
				print_error("piping failed", EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			print_error("forking failed", EXIT_FAILURE);
		else if (pid == 0)
		{
			if (hd == 1)
				hd_child_process(pipe_fd, argv, envp);
			else
				child_process(pipe_fd, argv, envp);
		}
		waitpid(pid, NULL, 0);
		if (hd == 1)
			hd_parent_process(pipe_fd, argc, argv, envp);
		else
			parent_process(pipe_fd, argv, envp);
	}
	return (0);
}
