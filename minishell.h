#define PROMPT "Minishell>$"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


typedef struct s_command
{
	char				*command;

	bool				pipe_output;
	int					*pipe_fd;
	
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;