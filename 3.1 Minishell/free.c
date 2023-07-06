/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:49:23 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/22 10:02:52 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	io_return(char *s, char *strerror, int ret)
{
	ret = false;
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putendl_fd(strerror, STDERR_FILENO);
	return (ret);
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_data(t_data *data, bool clear_history)
{
	if (data && data->argv)
	{
		free_ptr(data->argv);
		data->argv = NULL;
	}
	if (data && data->token)
		lst_clear_token(&data->token, &free_ptr);
	if (data && data->parser)
		lst_clear_cmd(&data->parser, &free_ptr);
	if (clear_history == true)
	{
		if (data && data->pwd)
			free_ptr(data->pwd);
		if (data && data->old_pwd)
			free_ptr(data->old_pwd);
		if (data && data->env)
			free_str_tab(data->env);
		rl_clear_history();
	}
}

void	free_io(t_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_end)
	{
		unlink(io->infile);
		free_ptr(io->heredoc_end);
	}
	if (io->infile)
		free_ptr(io->infile);
	if (io->outfile)
		free_ptr(io->outfile);
	if (io)
		free_ptr(io);
}
