/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiffert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:35:47 by msiffert          #+#    #+#             */
/*   Updated: 2023/05/22 10:35:50 by msiffert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define PROMPT "Minishell>$"

# include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../libft/libft.h"

/********************************* STRUCTURES *********************************/
typedef struct s_token
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}		t_token;


typedef struct s_data
{
	t_token		*token;
	char		*argv;
	char		*input;
	char		**env;
	char		*pwd;
	char		*old_pwd;
	char		*path;
	t_parser	*command;
	pid_t		pid;
	t_token		lexer_list;
}		t_data;

typedef	struct s_parser
{
	char	*command;
	int		*pipe_fd;
	//bool pipe_output
	struct s_parser	*next;
	struct s_parser	*prev;
}		t_parser;

typedef struct s_parser_tools
{
	t_data	*lexer_list;
	t_data	*redirections;
}		t_parser_tools;


/********************************* ENUM *********************************/
				/* Creates a user defined data type where COMMANDS = 1,
					ARGS = 2, INPUT = 3, etc */
typedef enum token_types {
	SPACES = 1,
	ARGS,
	INPUT,
	OUTPUT,
	GREAT_GREAT,
	LESS_LESS,
	COMMAND,
	PIPE,
	HEREDOC,
	APPEND,
	END,
}		t_token_types;

			/* Status of the quote to define type of ARG */
enum quote_status {
	DEFAULT,
	SINGLEQ,
	DOUBLEQ
};

			/* lexer utils */

#endif