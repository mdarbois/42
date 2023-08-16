/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:33:02 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 12:33:03 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static char	*join_vars(t_token **token_node)
{
	t_token	*temp;
	char	*str;

	temp = *token_node;
	str = ft_strdup(temp->str);
	while (temp->type == VAR && temp->next->type == VAR
		&& temp->next->join == true)
	{
		str = ft_strjoin(ft_strdup(str), temp->next->str);
		temp = temp->next;
	}
	*token_node = temp;
	return (str);
}

static char	**copy_in_new_tab(int len, char **new_tab,
			t_parser *last_cmd, t_token *tmp)
{
	int	i;

	i = 0;
	while (i < len)
	{
		new_tab[i] = last_cmd->argument[i];
		i++;
	}
	while (tmp->next && (tmp->type == ARGS || tmp->type == VAR))
	{
		if (tmp->join == true)
			new_tab[i] = join_vars(&tmp);
		else
			new_tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

static void	remove_empty(t_token **tokens)
{
	t_token	*temp;

	temp = *tokens;
	while (temp && (temp->type == ARGS || temp->type == VAR))
	{
		if (temp->type == VAR && temp->str[0] == '\0'
			&& temp->var == false)
		{
			temp = temp->next;
			if (temp == (*tokens)->next)
				(*tokens) = (*tokens)->next;
			lst_delone_token(temp->prev, free_ptr);
		}
		else
			temp = temp->next;
	}
}

int	create_args_echo(t_token **token_node, t_parser *last_cmd)
{
	int		nb_args;
	t_token	*temp;
	int		i;

	remove_empty(token_node);
	temp = *token_node;
	nb_args = count_arguments_echo(temp);
	last_cmd->argument = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->argument)
		return (1);
	i = 0;
	last_cmd->argument[i] = ft_strdup(last_cmd->command);
	i++;
	while (temp && (temp->type == ARGS || temp->type == VAR))
	{
		if (temp->join == true)
			last_cmd->argument[i] = join_vars(&temp);
		else
			last_cmd->argument[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	last_cmd->argument[i] = NULL;
	*token_node = temp;
	return (0);
}

int	add_args_echo(t_token **token_node, t_parser *last_cmd)
{
	int		len;
	int		nb_args;
	char	**new_tab;
	t_token	*temp;

	remove_empty(token_node);
	temp = *token_node;
	nb_args = count_arguments_echo(temp);
	len = 0;
	while (last_cmd->argument[len])
		len++;
	new_tab = malloc(sizeof(char *) * (nb_args + len + 1));
	if (!new_tab)
		return (1);
	new_tab = copy_in_new_tab(len, new_tab, last_cmd, temp);
	free(last_cmd->argument);
	last_cmd->argument = new_tab;
	while (temp && (temp->type == ARGS || temp->type == VAR))
		temp = temp->next;
	*token_node = temp;
	return (0);
}
