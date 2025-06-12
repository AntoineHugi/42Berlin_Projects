#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose) 
{
	pid_t	pid = fork();

	if (pid < 0)	// Fork failed
		return (-1);
	else if (pid == 0)	// Child process
	{
		alarm(timeout);	// Set an alarm to enforce timeout
		f(); // Run the test function
		exit(EXIT_SUCCESS);	// Exit cleanly
	} 
	else		// Parent process
	{
		int	status;
		pid_t	wpid;
		wpid = waitpid(pid, &status, 0);	// Wait for the child process to be done
		if (wpid == -1) 
			return (-1); // Error while waiting
		if (WIFEXITED(status)) 
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status == EXIT_SUCCESS) 
			{
				if (verbose == true) 
					printf("this is good\n");
				return (1);
			}
			else
			{
				if (verbose == true) 
					printf("bad function, errno: %d\n", errno);
				return (0);
			}
		}
		else if (WIFSIGNALED(status))
		{
			int sig = WTERMSIG(status);
			if (verbose == true) 
				printf("bad function, signal: %s\n", strsignal(sig));
			return (0);
		}
	}
	return (-1);  // Should not reach here
}