/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:21:25 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:21:26 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

static int	check_command_not_found(t_data *data, t_parser *cmd)
{
	if (ft_strchr(cmd->command, '/') == NULL
		&& env_index(data->env, "PATH") != -1)
	{
		ft_putstr_fd("command not found : ", STDERR_FILENO);
		ft_putendl_fd(cmd->command, STDERR_FILENO);
		return (127);
	}
	if (access(cmd->command, F_OK) != 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (127);
	}
	else if (cmd_is_dir(cmd->command))
	{
		ft_putendl_fd("command is a directory", STDERR_FILENO);
		return (126);
	}
	else if (access(cmd->command, F_OK | X_OK) != 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (126);
	}
	return (0);
}

int	execute_sys_bin(t_data *data, t_parser *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (127);
	if (cmd_is_dir(cmd->command))
		return (127);
	data->path = init_path(data, cmd->command);
	if (!data->path)
		return (127);
	if (execve(data->path, cmd->argument, data->env) == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putendl_fd("error execve sys", STDERR_FILENO);
	}
	return (1);
}

int	execute_local_bin(t_data *data, t_parser *cmd)
{
	int	ret;

	ret = check_command_not_found(data, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->command, cmd->argument, data->env) == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putendl_fd("error execve bin", STDERR_FILENO);
		return (errno);
	}
	return (1);
}

char	*make_str_from_tab(char **tab)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		tmp = str;
		if (i == 0)
			str = ft_strdup(tab[0]);
		else
		{
			str = ft_strjoin(ft_strdup(tmp), tab[i]);
			free_ptr(tmp);
		}
		if (tab[i + 1])
		{
			tmp = str;
			str = ft_strjoin(ft_strdup(tmp), " ");
			free_ptr(tmp);
		}
	}
	free_str_tab(tab);
	return (str);
}
