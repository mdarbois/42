/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:55:51 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 11:55:52 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "Minihell >$ "

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/include/libft.h"

extern int	g_exit_code;

typedef enum e_token_types {
	WHITESPACE = 1,
	ARGS,
	VAR,
	PIPE,
	INPUT,
	OUTPUT,
	HEREDOC,
	APPEND,
	END,
}	t_token_enum;

enum e_quotes {
	QUOTE_OK,
	QUOTE_S,
	QUOTE_D,
};

typedef struct s_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_end;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		std_in;
	int		std_out;
}	t_fds;

typedef struct s_token
{
	char			*str;
	int				type;
	int				quotes;
	bool			var;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}		t_token;

typedef struct s_parser
{
	char			*command;
	int				*pipe_fd;
	bool			pipe_out;
	char			**argument;
	t_fds			*fds;
	struct s_parser	*prev;
	struct s_parser	*next;
}	t_parser;

typedef struct s_data
{
	char		**env;
	char		*pwd;
	char		*old_pwd;
	char		*path;
	char		*argv;
	t_token		*token;
	t_parser	*parser;
	pid_t		pid;
}	t_data;

int			init(t_data *data, char **env);
char		*init_path(t_data *data, char *cmd);
char		*find_cmd_path(char *cmd, char **paths);

void		exit_shell(t_data *data, int exno);

void		signal_setup_sigint(void);
void		signal_setup_both(void);

int			builtin_exit(t_data *data, char **argument);
char		**ft_arrdup(char **arr);

bool		only_space(char *str);

int			lexer(char *input, t_data *data);
int			check_quotes(int status, char input);
int			check_enum_types(char *input, int i);
t_token		*lst_new_token(char *str, int type, int quotes);
void		lst_add_back_token(t_token **alst, t_token *new_node);
void		update_status(t_token **token_node, char c);
int			check(t_token **token_lst);
void		check_var(t_token **token_node);
int			check_consecutives(t_token **token_lst);

int			var_expander(t_data *data, t_token **token_lst);
bool		is_sep(char c);
bool		is_between_quotes(char *str, int i);
char		*recover_val(t_token *token, char *str, t_data *data);
int			erase_var(t_token **token_node, char *str, int index);
char		*erase_and_replace(t_token **token_node,
				char *str, char *var_value, int index);
int			var_length(char *str);
char		*get_new_token_string(char *oldstr, char *var_value,
				int newstr_size, int index);
void		copy_var_value(char *new_str, char *var_value, int *j);
char		*identify_var(char *str);
int			var_exists(t_data *data, char *var);
char		*search_env_var(t_data *data, char *var);

int			handle_quotes(t_data *data);
bool		if_quote(char *str);
int			remove_quotes(t_token **token_node);
int			count_len(char *str, int count, int i);
char		*remove_specific_quotes(char *str, char c);

void		parser(t_data *data, t_token *token);
void		lst_add_back_cmd(t_parser **alst, t_parser *new_node);
t_parser	*lst_new_cmd(bool value);
void		parse_pipe(t_parser **parser, t_token **token_lst);
void		parse_input(t_parser **last_cmd, t_token **token_lst);
void		parse_heredoc(t_data *data, t_parser **last_cmd,
				t_token **token_lst);
void		parse_output(t_parser **last_cmd, t_token **token_lst);
void		parse_append(t_parser **last_cmd, t_token **token_lst);
void		parse_args(t_parser **cmd, t_token **token_lst);
t_parser	*lst_last_cmd(t_parser *parser);

int			count_arguments(t_token *temp);
char		**copy_args(int len, char **new_tab,
				t_parser *last_cmd, t_token **tk_node);
void		lst_delone_token(t_token *lst, void (*del)(void *));

int			add_args_echo(t_token **token_node, t_parser *last_cmd);
int			create_args_echo(t_token **token_node, t_parser *last_cmd);
int			count_arguments_echo(t_token *temp);

void		init_fds(t_parser *parser);

void		open_infile(t_fds *io, char *file);
void		open_outfile_output(t_fds *io, char *file);
void		open_outfile_append(t_fds *io, char *file);
bool		open_heredoc(t_data *data, t_fds *io);

bool		remove_old_file_ref(t_fds *io, bool infile);

bool		heredoc_fill(t_data *data, t_fds *io, int fd);
char		*expander_heredoc(t_data *data, char *str);
char		*heredoc_delim(char *delim, bool *quotes);
char		*heredoc_name(void);
char		*make_str_from_tab(char **tab);

int			execute(t_data *data);
bool		create_pipes(t_data *data);
bool		check_infile_outfile(t_fds *io);
bool		restore_io(t_fds *io);
bool		redirect_io(t_fds *io);

int			builtin_cd(t_data *data, t_parser *cmd);
char		*env_value(char **env, char *var);
bool		set_env_var(t_data *data, char *key, char *value);
int			env_count(char **env);
bool		is_space(char c);

int			builtin_echo(t_data *data, char **argument);

int			builtin_env(t_data *data, char **argument);

int			builtin_export(t_data *data, t_parser *cmd);
bool		is_valid_env(char *var);

int			builtin_pwd(t_data *data, char **argument);

int			builtin_unset(t_data *data, char **argument);
int			env_index(char **env, char *var);
char		**realloc_env(t_data *data, int size);

int			create_children(t_data *data);
int			execute_command(t_data *data, t_parser *cmd);
bool		set_pipe_fds(t_parser *cmds, t_parser *c);
void		close_pipe_fds(t_parser *cmds, t_parser *skip_cmd);
void		close_fds(t_parser *parser, bool close_backups);

int			execute_local_bin(t_data *data, t_parser *cmd);
int			execute_sys_bin(t_data *data, t_parser *cmd);

void		free_io(t_fds *io);
void		free_data(t_data *data, bool clear_history);
void		free_str_tab(char **tab);
void		free_ptr(void *ptr);
void		lst_clear_token(t_token **lst, void (*del)(void *));
void		lst_clear_cmd(t_parser **lst, void (*del)(void *));
int			io_return(char *s, char *strerror, int ret);
#endif 