/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:01:42 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 12:01:43 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static bool	consecutive_ops(t_token *token_node)
{
	if (token_node->prev)
	{
		if (token_node->type == PIPE && token_node->prev->type == PIPE)
			return (true);
		if (token_node->type > PIPE && token_node->prev->type > PIPE)
			return (true);
		if ((ft_strncmp(token_node->str, "\0", 1) == 0)
			&& token_node->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

int	check_consecutives(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	while (temp)
	{
		if (consecutive_ops(temp) == true)
		{
			if ((ft_strncmp(temp->str, "\0", 1) == 0)
				&& temp->prev && temp->prev->type > PIPE)
				ft_putstr_fd("syntax error near unexpected token",
					STDERR_FILENO);
			else if ((ft_strncmp(temp->str, "\0", 1) == 0)
				&& temp->prev)
				ft_putstr_fd("syntax error near unexpected token",
					STDERR_FILENO);
			else
				ft_putstr_fd("syntax error near unexpected token",
					STDERR_FILENO);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	check_var(t_token **token_node)
{
	int	i;

	i = 0;
	while ((*token_node)->str[i])
	{
		if ((*token_node)->str[i] == '$')
		{	
			if ((*token_node)->prev && (*token_node)->prev->type == HEREDOC)
				break ;
			(*token_node)->type = VAR;
			return ;
		}
		i++;
	}
}

int	check_quotes(int quotes, char input)
{
	if (input == '\'' && quotes == QUOTE_OK)
		quotes = QUOTE_S;
	else if (input == '\"' && quotes == QUOTE_OK)
		quotes = QUOTE_D;
	else if (input == '\'' && quotes == QUOTE_S)
		quotes = QUOTE_OK;
	else if (input == '\"' && quotes == QUOTE_D)
		quotes = QUOTE_OK;
	return (quotes);
}

int	check_enum_types(char *input, int i)
{
	if (((input[i] > 8 && input[i] < 14) || input[i] == ' '))
		return (WHITESPACE);
	else if (input[i] == '|')
		return (PIPE);
	else if (input[i] == '<' && input[i + 1] == '<')
		return (HEREDOC);
	else if (input[i] == '>' && input[i + 1] == '>')
		return (APPEND);
	else if (input[i] == '<')
		return (INPUT);
	else if (input[i] == '>')
		return (OUTPUT);
	else if (input[i] == '\0')
		return (END);
	else
		return (0);
}
