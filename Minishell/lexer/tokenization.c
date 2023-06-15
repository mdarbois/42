/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiffert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:54:12 by msiffert          #+#    #+#             */
/*   Updated: 2023/05/30 16:54:15 by msiffert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	add_node(char *str, t_token_enum token, t_token **lexer_list)
{
	t_token	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}

static int	handle_separators(char *str, int i, t_token **lexer_list)
{
	t_token_enum	token;

	token = check_separator(str[i]);
	if (token == INPUT && check_separator(str[i + 1]) == INPUT)
	{
		if (!add_node(NULL, GREAT_GREAT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == OUTPUT && check_separator(str[i + 1]) == OUTPUT)
	{
		if (!add_node(NULL, LESS_LESS, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
			if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}	
	return (0);
}

static int	read_words(char *str, int i, t_data **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_separator(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (is_space(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int tokenization(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->argv[i])
	{
		j = 0;
		i += skip_spaces(data->argv, i);
		if (check_separator(data->argv[i]))
			j = handle_separator(data->argv, i, &data->lexer_list);
		else
			j = read_words(data->argv, i, &data->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
