/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:15:50 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 15:15:54 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	parse_pipe(t_parser **parser, t_token **token_lst)
{
	t_parser	*last_cmd;

	last_cmd = lst_last_cmd(*parser);
	last_cmd->pipe_out = true;
	lst_add_back_cmd(&last_cmd, lst_new_cmd(false));
	*token_lst = (*token_lst)->next;
}

void	parse_input(t_parser **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_parser	*parser;

	temp = *token_lst;
	parser = lst_last_cmd(*last_cmd);
	init_fds(parser);
	open_infile(parser->fds, temp->next->str);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}

void	parse_heredoc(t_data *data, t_parser **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_parser	*parser;
	t_fds		*io;

	temp = *token_lst;
	parser = lst_last_cmd(*last_cmd);
	init_fds(parser);
	io = parser->fds;
	if (!remove_old_file_ref(io, true))
		return ;
	io->infile = heredoc_name();
	io->heredoc_end = heredoc_delim(temp->next->str, &(io->heredoc_quotes));
	if (open_heredoc(data, io))
		io->fd_in = open(io->infile, O_RDONLY);
	else
		io->fd_in = -1;
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}

void	parse_output(t_parser **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_parser	*parser;

	temp = *token_lst;
	parser = lst_last_cmd(*last_cmd);
	init_fds(parser);
	open_outfile_output(parser->fds, temp->next->str);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}

void	parse_append(t_parser **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_parser	*parser;

	temp = *token_lst;
	parser = lst_last_cmd(*last_cmd);
	init_fds(parser);
	open_outfile_append(parser->fds, temp->next->str);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
