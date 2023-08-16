/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiffert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:13:28 by msiffert          #+#    #+#             */
/*   Updated: 2023/05/31 11:13:29 by msiffert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

bool	is_space(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (true);
	else
		return (false);
}

bool	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_sep(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (true);
	else
		return (false);
}

bool	is_between_quotes(char *str, int i)
{
	if (i > 0)
	{
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (true);
		else
			return (false);
	}
	return (false);
}

int	count_len(char *str, int count, int i)
{
	int	quotes;

	quotes = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && quotes == QUOTE_OK)
		{
			if (str[i] == '\'')
				quotes = QUOTE_S;
			if (str[i] == '\"')
				quotes = QUOTE_D;
			i++;
			continue ;
		}
		else if ((str[i] == '\'' && quotes == QUOTE_S)
			|| (str[i] == '\"' && quotes == QUOTE_D))
		{
			quotes = QUOTE_OK;
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count + 1);
}
