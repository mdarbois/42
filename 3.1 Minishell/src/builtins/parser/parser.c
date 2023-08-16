/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:37:56 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 17:57:04 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	no_argument(t_data *data)
{
	t_parser	*parser;

	if (!data || !data->parser)
		return ;
	parser = data->parser;
	while (parser && parser->command)
	{
		if (!parser->argument)
		{
			parser->argument = malloc(sizeof * parser->argument * 2);
			parser->argument[0] = ft_strdup(parser->command);
			parser->argument[1] = NULL;
		}
		parser = parser->next;
	}
	parser = lst_last_cmd(data->parser);
}

int	handle_quotes(t_data *data)
{
	t_token	*temp;

	temp = data->token;
	while (temp)
	{
		if (temp && if_quote(temp->str) == true
			&& (!temp->prev || (temp->prev && temp->prev->type != HEREDOC)))
			remove_quotes(&temp);
		temp = temp->next;
	}
	return (0);
}

void	parser(t_data *data, t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == END)
		return ;
	while (temp)
	{
		if (temp == token)
			lst_add_back_cmd(&data->parser, lst_new_cmd(false));
		if (temp->type == ARGS || temp->type == VAR)
			parse_args(&data->parser, &temp);
		else if (temp->type == PIPE)
			parse_pipe(&data->parser, &temp);
		else if (temp->type == INPUT)
			parse_input(&data->parser, &temp);
		else if (temp->type == HEREDOC)
			parse_heredoc(data, &data->parser, &temp);
		else if (temp->type == OUTPUT)
			parse_output(&data->parser, &temp);
		else if (temp->type == APPEND)
			parse_append(&data->parser, &temp);
		else if (temp->type == END)
			break ;
	}
	no_argument(data);
}
