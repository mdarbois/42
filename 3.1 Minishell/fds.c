/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:23:22 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 10:23:23 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	close_fds(t_parser *parser, bool close_backups)
{
	if (parser->fds)
	{
		if (parser->fds->fd_in != -1)
			close(parser->fds->fd_in);
		if (parser->fds->fd_out != -1)
			close(parser->fds->fd_out);
		if (close_backups)
			restore_io(parser->fds);
	}
	close_pipe_fds(parser, NULL);
}

void	close_pipe_fds(t_parser *cmds, t_parser *skip_cmd)
{
	while (cmds)
	{
		if (cmds != skip_cmd && cmds->pipe_fd)
		{
			close(cmds->pipe_fd[0]);
			close(cmds->pipe_fd[1]);
		}
		cmds = cmds->next;
	}
}

bool	set_pipe_fds(t_parser *cmds, t_parser *c)
{
	if (!c)
		return (false);
	if (c->prev && c->prev->pipe_out)
		dup2(c->prev->pipe_fd[0], STDIN_FILENO);
	if (c->pipe_out)
		dup2(c->pipe_fd[1], STDOUT_FILENO);
	close_pipe_fds(cmds, c);
	return (true);
}
