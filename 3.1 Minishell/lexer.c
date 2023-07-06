/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:53:16 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 11:53:18 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	check(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	if (temp->type == PIPE)
	{
		ft_putstr_fd("Syntax error near unexpected token: pipe\n",
			STDERR_FILENO);
		return (1);
	}
	while (temp)
	{
		check_var(&temp);
		if (check_consecutives(&temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	token_assign(t_token **token_lst, char *temp, int index, int type)
{
	int		i;
	char	*sep;

	i = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (1);
		while (i < 2)
			sep[i++] = temp[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, type, QUOTE_OK));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (1);
		while (i < 1)
			sep[i++] = temp[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, type, QUOTE_OK));
	}
	return (0);
}

static int	save_word(t_token **token_lst, char *temp, int index, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[i] = temp[start];
		start++;
		i++;
	}
	word[i] = '\0';
	lst_add_back_token(token_lst, lst_new_token(word, ARGS, QUOTE_OK));
	return (0);
}

static int	saving(int *i, char *input, int start, t_data *data)
{
	int	type;

	type = check_enum_types(input, (*i));
	if (type)
	{
		if ((*i) != 0 && check_enum_types(input, (*i) - 1) == 0)
			save_word(&data->token, input, (*i), start);
		if (type == APPEND || type == HEREDOC || type == PIPE
			|| type == INPUT || type == OUTPUT || type == END)
		{
			token_assign(&data->token, input, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}

int	lexer(char *input, t_data *data)
{
	int		start;
	int		i;
	int		end;
	int		quotes;

	start = 0;
	i = -1;
	end = ft_strlen(input);
	quotes = QUOTE_OK;
	while (++i <= end)
	{
		quotes = check_quotes(quotes, input[i]);
		if (quotes == QUOTE_OK)
			start = saving(&i, input, start, data);
	}
	if (quotes != QUOTE_OK)
	{
		ft_putstr_fd("Syntax error: missing quote\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
