#include "../includes/pipex.h"

static char	*get_param(char *limiter)
{
	char	*param;
	char	*buffer;

	param = ft_strdup("");
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (buff_check(limiter, buffer))
			if (!param)
				param = ft_gnl_strjoin(param, buffer);
			else
			{
				param = ft_gnl_strjoin(param, " ");
				param = ft_gnl_strjoin(param, buffer);
			}
		else
		{
			free(buffer);
			break;
		}
		free (buffer);
	}
	return (param);
}

static char	*get_command(char *limiter, char *cmd)
{
	char	*param;
	char	*buffer;
	char	*final_cmd;

	param = get_param(limiter);
	if (!param)
		return (cmd);
	buffer = ft_strjoin(cmd, " ");
	final_cmd = ft_strjoin(buffer, param);
	free(buffer);
	free(param);
	return (final_cmd);
}

void	b_first_child_process(int *pipe_fd, char **argv, char **envp, int hd)
{
	int		fd_infile;
	char	*final_cmd;

	if (hd == 1)
	{
		final_cmd = get_command(argv[2], argv[3]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		run_cmd(final_cmd, envp);
		free(final_cmd);
	}
	else
	{
		fd_infile = open(argv[1], O_RDONLY);
		if (fd_infile == -1)
			print_error("problem opening infile", ENOENT);
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(fd_infile);
		close(pipe_fd[1]);
		run_cmd(argv[2], envp);
	}
	print_error("execve failed", EXIT_FAILURE);
}

void	b_next_child_process(int *pipe_fd, int tmp_fd, char *cmd, char **envp)
{
	dup2(tmp_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(tmp_fd);
	close(pipe_fd[1]);
	run_cmd(cmd, envp);
	print_error("execve failed", EXIT_FAILURE);
}

void	b_parent_process(int tmp_fd, int ac, char **av, char **envp, int hd)
{
	int	fd_out;

	if (hd == 0)
		fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd_out == -1)
		print_error("problem opening outfile", ENOENT);
	dup2(tmp_fd, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(tmp_fd);
	run_cmd(av[ac - 2], envp);
	print_error("execve failed", EXIT_FAILURE);
}
