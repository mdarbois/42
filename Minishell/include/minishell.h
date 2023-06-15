/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:18 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 09:36:19 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define PROMPT "Minishell>$"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/include/libft.h"

typedef enum token_types {
	ARGS,
	INPUT, 
	OUTPUT,
	COMMAND,
	PIPE,
	HEREDOC,
	APPEND,
	SPACE,
	QUOTE_S,
	QUOTE_D,
}  t_token_enum;

typedef struct s_token
{
	char			*str;
	int				type;
	int				i;
	t_token_enum	e_token;
	struct s_token	*prev;
	struct s_token	*next;
}		t_token;


typedef struct s_parser
{
	char				*command;
	int					*pipe_fd;
    int					pipe_output;
	struct s_parser	*next;
	struct s_parser	*prev;
}	t_parser;

typedef struct s_data
{
	t_token	*token;
	char	**argv;
	char	*input;
	char	**env;
    char    *pwd;
    char    *old_pwd;
    char    *path;
	t_parser *parser;
	pid_t	pid;
	int fd_out;
	int fd_in;
	int in;
	int out;
	int pipe_out;
	int pipe_in;
}	t_data;

int	is_space(char c);
int	skip_spaces(char *str, int i);
int	check_separator(int c);
int	handle_quotes(int i, char *str, char quote);

int	add_node(char *str, t_token_enum token, t_token **lexer_list);
int tokenization(t_data *data);

void	close_fds(t_data *data);
void	ft_close(int fd);
void	reset_std(t_data *data);
void	parse_out_app(t_data *data, t_token *token, int type);
void	parse_input(t_data *data, t_token *token);
int		parse_pipe(t_data *data);

char	*find_path(char **env);
int init_path(t_data *data);
int init(t_data *data, char **env);

void	parse_command(t_data *data, t_token *token);

void signal_reset(int sig);
void	signal_newline(int signal);
void	signal_sigquit_ignore(void);
void	signal_setup_both(void);
void signal_setup_sigint(void);

void	ft_lexeradd_back(t_token **lst, t_token *new);
void	ft_lstadd_back(t_parser **lst, t_parser *new);
t_parser	*ft_lstlast(t_parser *lst);
t_parser	*ft_lstnew(void *content);
t_token	*ft_lexernew(char *str, t_token_enum token);

int	count_env(char **env);
//void	count_pipes(t_lexer *lexer_list, t_tools *tools)
//int	count_args(t_lexer *lexer_list);

#endif
