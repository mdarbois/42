/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:22:01 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 17:59:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	create_args(t_token **token_node, t_parser *last_cmd)
{
	int		i;
	int		nb_args;
	t_token	*temp;

	i = 0;
	temp = *token_node;
	nb_args = count_arguments(temp);
	last_cmd->argument = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->argument)
		return (1);
	i = 0;
	last_cmd->argument[i] = ft_strdup(last_cmd->command);
	i++;
	while (temp->type == ARGS || temp->type == VAR)
	{
		last_cmd->argument[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	last_cmd->argument[i] = NULL;
	*token_node = temp;
	return (0);
}

static int	add_args(t_token **token_node, t_parser *last_cmd)
{
	int		i;
	int		len;
	char	**new_tab;
	t_token	*temp;

	i = 0;
	temp = *token_node;
	while (temp->type == ARGS || temp->type == VAR)
	{
		i++;
		temp = temp->next;
	}
	len = 0;
	while (last_cmd->argument[len])
		len++;
	new_tab = malloc(sizeof(char *) * (i + len + 1));
	if (!new_tab)
		return (1);
	new_tab = copy_args(len, new_tab, last_cmd, token_node);
	free(last_cmd->argument);
	last_cmd->argument = new_tab;
	*token_node = temp;
	return (0);
}

static int	fill_args(t_token **token_node, t_parser *last_cmd)
{
	if (!ft_strncmp(last_cmd->command, "echo", 5)
		|| !ft_strncmp((*token_node)->str, "echo", 5))
	{
		if (!(last_cmd->argument))
			return (create_args_echo(token_node, last_cmd));
		else
			return (add_args_echo(token_node, last_cmd));
	}
	else
	{
		if (last_cmd && !(last_cmd->argument))
			return (create_args(token_node, last_cmd));
		else
			return (add_args(token_node, last_cmd));
	}
	return (0);
}

static void	split_cmd_token(t_parser *last_cmd, char *cmd_str)
{
	t_token		*new_tokens;
	t_token		*tmp;
	char		**strs;
	int			i;

	new_tokens = NULL;
	strs = ft_split(cmd_str, ' ');
	if (!strs)
		return ;
	last_cmd->command = ft_strdup(strs[0]);
	if (strs[1])
		new_tokens = lst_new_token(ft_strdup(strs[1]), ARGS, QUOTE_OK);
	tmp = new_tokens;
	i = 1;
	while (strs[i] && strs[++i])
		lst_add_back_token(&new_tokens,
			lst_new_token(ft_strdup(strs[i]), ARGS, QUOTE_OK));
	lst_add_back_token(&new_tokens, lst_new_token(NULL, END, QUOTE_OK));
	fill_args(&new_tokens, last_cmd);
	lst_clear_token(&tmp, &free_ptr);
	free_str_tab(strs);
}

void	parse_args(t_parser **cmd, t_token **token_lst)
{
	t_token		*temp;
	t_parser	*last_cmd;

	temp = *token_lst;
	while (temp && (temp->type == ARGS || temp->type == VAR))
	{
		last_cmd = lst_last_cmd(*cmd);
		if (temp->prev == NULL || (temp->prev && temp->prev->type == PIPE)
			|| last_cmd->command == NULL)
		{
			if (temp->type == VAR && ft_strchr(temp->str, ' '))
				split_cmd_token(last_cmd, temp->str);
			else
				last_cmd->command = ft_strdup(temp->str);
			temp = temp->next;
		}
		else
			fill_args(&temp, last_cmd);
	}
	*token_lst = temp;
}
