/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:31:02 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 16:31:04 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_exit_code;

static int	execute_builtin(t_data *data, t_parser *cmd)
{
	int	ret;

	ret = 127;
	if (ft_strncmp(cmd->command, "cd", 3) == 0)
		ret = builtin_cd(data, cmd);
	else if (ft_strncmp(cmd->command, "echo", 5) == 0)
		ret = builtin_echo(data, cmd->argument);
	else if (ft_strncmp(cmd->command, "env", 4) == 0)
		ret = builtin_env(data, cmd->argument);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		ret = builtin_export(data, cmd);
	else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
		ret = builtin_pwd(data, cmd->argument);
	else if (ft_strncmp(cmd->command, "unset", 6) == 0)
		ret = builtin_unset(data, cmd->argument);
	else if (ft_strncmp(cmd->command, "exit", 5) == 0)
		ret = builtin_exit(data, cmd->argument);
	return (ret);
}

int	execute_command(t_data *data, t_parser *cmd)
{
	int	ret;

	if (!cmd || !cmd->command)
	{
		ft_putendl_fd("Error child: parsing error, \
		no command to execute", STDERR_FILENO);
		exit_shell(data, 1);
		return (1);
	}
	if (!check_infile_outfile(cmd->fds))
		exit_shell(data, 1);
	set_pipe_fds(data->parser, cmd);
	redirect_io(cmd->fds);
	close_fds(data->parser, false);
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		ret = execute_builtin(data, cmd);
		if (ret != 127)
			exit_shell(data, ret);
		ret = execute_sys_bin(data, cmd);
		if (ret != 127)
			exit_shell(data, ret);
	}
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
}

static int	prep(t_data *data)
{
	if (!data || !data->parser || data->token->type == HEREDOC)
		return (0);
	if (!data->parser->command)
	{
		if (data->parser->fds
			&& !check_infile_outfile(data->parser->fds))
			return (1);
		return (0);
	}
	if (!create_pipes(data))
		return (1);
	return (127);
}

int	execute(t_data *data)
{
	int	ret;

	ret = prep(data);
	if (ret != 127)
		return (ret);
	if (!data->parser->pipe_out && !data->parser->prev
		&& check_infile_outfile(data->parser->fds))
	{
		redirect_io(data->parser->fds);
		ret = execute_builtin(data, data->parser);
		restore_io(data->parser->fds);
	}
	if (ret != 127)
		return (ret);
	return (create_children(data));
}
