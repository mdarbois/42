/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:21:16 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 15:21:17 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

bool	restore_io(t_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	if (io->std_in != -1)
	{
		if (dup2(io->std_in, STDIN_FILENO) == -1)
			ret = false;
		close(io->std_in);
		io->std_in = -1;
	}
	if (io->std_out != -1)
	{
		if (dup2(io->std_out, STDOUT_FILENO) == -1)
			ret = false;
		close(io->std_out);
		io->std_out = -1;
	}
	return (ret);
}

bool	redirect_io(t_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	io->std_in = dup(STDIN_FILENO);
	if (io->std_in == -1)
		io_return("Error dup std_in", strerror(errno), ret);
	io->std_out = dup(STDOUT_FILENO);
	if (io->std_out == -1)
		io_return("Error dup std_out", strerror(errno), ret);
	if (io->fd_in != -1)
		if (dup2(io->fd_in, STDIN_FILENO) == -1)
			io_return("Error dup2 infile", strerror(errno), ret);
	if (io->fd_out != -1)
		if (dup2(io->fd_out, STDOUT_FILENO) == -1)
			io_return("Error dup2 outfile", strerror(errno), ret);
	return (ret);
}

bool	check_infile_outfile(t_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((io->infile && io->fd_in == -1)
		|| (io->outfile && io->fd_out == -1))
		return (false);
	return (true);
}

bool	remove_old_file_ref(t_fds *io, bool infile)
{
	if (infile == true && io->infile)
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (false);
		if (io->heredoc_end != NULL)
		{
			free_ptr(io->heredoc_end);
			io->heredoc_end = NULL;
			unlink(io->infile);
		}
		free_ptr(io->infile);
		close(io->fd_in);
	}
	else if (infile == false && io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (false);
		free_ptr(io->outfile);
		close(io->fd_out);
	}
	return (true);
}

void	init_fds(t_parser *parser)
{
	if (!parser->fds)
	{
		parser->fds = malloc(sizeof * parser->fds);
		if (!parser->fds)
			return ;
		parser->fds->infile = NULL;
		parser->fds->outfile = NULL;
		parser->fds->heredoc_end = NULL;
		parser->fds->heredoc_quotes = false;
		parser->fds->fd_in = -1;
		parser->fds->fd_out = -1;
		parser->fds->std_in = -1;
		parser->fds->std_out = -1;
	}
}
