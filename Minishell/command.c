/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:37:23 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/13 14:37:24 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	close_fds(t_data *data)
{
	ft_close(data->fd_in);
	ft_close(data->fd_out);
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
}
void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	reset_std(t_data *data)
{
	dup2(data->in, STDIN);
	dup2(data->out, STDOUT);
}

void	parse_out_app(t_data *data, t_token *token, int type)
{
	ft_close(data->fdout);
	if (type == OUTPUT)
		data->fd_out = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		data->fd_out = open(token->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (data->fd_out == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		return ;
	}
	dup2(data->fd_out, STDOUT);
}

void	parse_input(t_data *data, t_token *token)
{
	ft_close(data->fd_in);
	data->fd_in = open(token->str, O_RDONLY, S_IRWXU);
	if (data->fd_in == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		return ;
	}
	dup2(data->fd_in, STDIN);
}

int		parse_pipe(t_data *data)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		ft_close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN);
		data->pipe_in = pipe_fd[0];
		data->pid = -1;
		return (2);
	}
	else
	{
		ft_close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT);
		data->pipe_out = pipe_fd[1];
		data->pid = pid;
		return (1);
	}
}