
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

int		input_validation(int argc);
void	print_error(char *msg);
void	free_array(char **array);
void	run_cmd(char *cmd, char **envp);

#endif
