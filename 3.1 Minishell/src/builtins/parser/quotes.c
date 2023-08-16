/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:52:44 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 14:53:39 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

bool	if_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

static void	type_quote(t_token **token_node, int *i)
{
	if ((*token_node)->str[*i] == '\'')
		(*token_node)->quotes = QUOTE_S;
	if ((*token_node)->str[*i] == '\"')
		(*token_node)->quotes = QUOTE_D;
	(*i)++;
}

static bool	quote_ok(t_token **token_node, int i)
{
	if (((*token_node)->str[i] == '\'' || (*token_node)->str[i] == '\"')
		&& (*token_node)->quotes == QUOTE_OK)
		return (true);
	else
		return (false);
}

static bool	type_quote_ok(t_token **token_node, int *i)
{
	if (((*token_node)->str[*i] == '\'' && (*token_node)->quotes == QUOTE_S)
		|| ((*token_node)->str[*i] == '\"' && (*token_node)->quotes == QUOTE_D))
	{
		(*token_node)->quotes = QUOTE_OK;
		(*i)++;
		return (true);
	}
	else
		return (false);
}

int	remove_quotes(t_token **token_node)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * count_len((*token_node)->str, i, i));
	if (!new_line)
		return (1);
	while ((*token_node)->str[i])
	{
		if (quote_ok(token_node, i) == true)
		{
			type_quote(token_node, &i);
			continue ;
		}
		else if (type_quote_ok(token_node, &i) == true)
			continue ;
		new_line[j++] = (*token_node)->str[i++];
	}
	new_line[j] = '\0';
	free_ptr((*token_node)->str);
	(*token_node)->str = new_line;
	(*token_node)->join = true;
	return (0);
}
