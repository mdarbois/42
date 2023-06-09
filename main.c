#include "minishell.h"


int main (int argc, char **argv, char **env)
{
    NOM_STRUCT STRUCT_VARIABLE;
    // no arg allowed otherwise error
    if (argc != 1 || argv[1])
    {
		printf("This program does not accept arguments\n");
		exit(0);
	}

    // INIT
    // struct
    ft_memset(&STRUCT_VARIABLE, 0, sizeof(NOM_STRUCT));
    
    // envp: save the env variable in the struct
    // current working directory: look for PWD & OLDPWD and save both in the struct
    // find path and sve it in the struct
    if (init(&STRUCT_VARIABLE, env))
        exit_shell(NULL, EXIT_FAILURE);


    // SIGNALS
    signal_setup();

    // READLINE -> store in the struct
   STRUCT_VARIABLE.args = readline(PROMPT);
    
    signal_setup_both();

    // HISTORY
    
    // MAXIME TOKENISATION LEXER
    /*
    - if args== '\0';
    - if quotes % 2 != 0
    */

    // EXPANDER + QUOTES

    // CREATE COMMANDS

    // MARIE PARSER

    /* EXECUTOR 
    - PIPEX
    - IO redirections
    - BUILTIN
    */

    // EXIT: FREE, CLOSE fds

}

   