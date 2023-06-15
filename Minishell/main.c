/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:11 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 09:36:13 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"


int main (int argc, char **argv, char **env)
{
    t_data data;
    // no arg allowed otherwise error
    if (argc != 1 || argv[1])
    {
		printf("This program does not accept arguments\n");
		exit(0);
	}

    // INIT
    // struct
    ft_memset(&data, 0, sizeof(t_data));
    
    // envp: save the env variable in the struct
    // current working directory: look for PWD & OLDPWD and save both in the struct
    // find path and sve it in the struct
    if (init(&data, env))
        exit_shell(NULL, EXIT_FAILURE);

    // SIGNALS
    signal_setup_sigint();

    // READLINE -> store in the struct
   data.argv = readline(PROMPT);
    
    signal_setup_both();

    // CHECK INPUT
        if (data.argv == NULL)
      exit_shell(data,NULL);
    else if(ft_strcmp(data.argv, "\0") == 0)
      exit_shell(data,NULL);

    // HISTORY
    add_history(data.argv);
    
    // MAXIME TOKENISATION LEXER

    lexer_token(data.argv, &data);
    //
    //- if quotes % 2 != 0
    
   //tokenization(data);

    // EXPANDER + QUOTES

    // CREATE COMMANDS
      // parse_commands(data, data->token);
    //reset_std(data);
    // MARIE PARSER

    /* EXECUTOR 
    - PIPEX
    - IO redirections
    - BUILTIN
    */

    // EXIT: FREE, CLOSE fds

}

   
