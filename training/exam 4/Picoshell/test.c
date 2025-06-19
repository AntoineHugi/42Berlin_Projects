#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int fd[2];
	int tmp_fd = -1;
	if (pipe(fd) == -1)
		return (1);
	pid_t	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		if (tmp_fd != -1)
		{
			dup2(tmp_fd,STDIN_FILENO);
			close(tmp_fd);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		child_process();
		exit(1);
	}
	else
	{
		if (tmp_fd != -1)
			close(tmp_fd);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		tmp_fd = fd[0];
	}
	return (0);
}