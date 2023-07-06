/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opens.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:17:52 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/20 15:17:53 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	open_infile(t_fds *io, char *file)
{
	if (!remove_old_file_ref(io, true))
		return ;
	io->infile = ft_strdup(file);
	if (io->infile && io->infile[0] == '\0')
	{
		ft_putstr_fd("Infile: ambiguous redirection", STDERR_FILENO);
		return (ft_putstr_fd(file, STDERR_FILENO));
	}
	io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		return (ft_putendl_fd(": No such file or directory", STDERR_FILENO));
	}
}

void	open_outfile_output(t_fds *io, char *file)
{
	if (!remove_old_file_ref(io, false))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0')
	{
		ft_putstr_fd("Output: ambiguous redirection", STDERR_FILENO);
		return (ft_putstr_fd(file, STDERR_FILENO));
	}
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io->fd_out == -1)
		return (ft_putendl_fd("Output: Fail opening fd_out", STDERR_FILENO));
}

void	open_outfile_append(t_fds *io, char *file)
{
	if (!remove_old_file_ref(io, false))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0' && file)
	{
		ft_putstr_fd("Append: Ambiguous redirection", STDERR_FILENO);
		return (ft_putstr_fd(file, STDERR_FILENO));
	}
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (io->fd_out == -1)
		return (ft_putendl_fd("Append: Fail opening fd_out", STDERR_FILENO));
}

bool	open_heredoc(t_data *data, t_fds *io)
{
	int		tmp_fd;
	bool	ret;

	ret = true;
	tmp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = heredoc_fill(data, io, tmp_fd);
	close(tmp_fd);
	return (ret);
}
