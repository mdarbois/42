/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:26 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 09:36:27 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// global variable = exit_code;

#include "./include/minishell.h"
	
void	parse_command(t_data *data, t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == END)
		return ;
	while (temp)
	{
		if (temp == token)
			ft_lstadd_back(&data->parser, ft_lstnew(0));
		if (temp->type == ARGS)
			parse_args(&data->parser, &temp);
		else if (temp->type == INPUT)
			parse_input(&data->parser, &temp);
		else if (temp->type == OUTPUT)
			parse_output(&data->parser, &temp);
		else if (temp->type == HEREDOC)
			parse_heredoc(data, &data->parser, &temp);
		else if (temp->type == APPEND)
			parse_append(&data->parser, &temp);
		else if (temp->type == PIPE)
			parse_pipe(&data->parser, &temp);
		/* else if (temp->type == END)
			break ; */
		temp = temp->next;
	}
}
