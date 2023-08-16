/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:58:01 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 18:14:03 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	init_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->env = ft_calloc(env_count(env) + 1, sizeof * data->env);
	if (!data->env)
		return (1);
	while (env[i] != NULL)
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			return (1);
		i++;
	}
	return (0);
}

static int	init_dir(t_data *data)
{
	char	buff[PATH_MAX];
	char	*wd;

	wd = getcwd(buff, PATH_MAX);
	data->pwd = ft_strdup(wd);
	if (!data->pwd)
		return (1);
	if (env_index(data->env, "OLDPWD") != -1)
	{
		data->old_pwd = ft_strdup(env_value(data->env,
					"OLDPWD"));
		if (!data->old_pwd)
			return (1);
	}
	else
	{
		data->old_pwd = ft_strdup(wd);
		if (!data->old_pwd)
			return (1);
	}
	return (0);
}

static char	**find_path(t_data *data)
{
	char	**env_path;

	if (env_index(data->env, "PATH") == -1)
		return (NULL);
	env_path = ft_split(env_value(data->env, "PATH"), ':');
	if (!env_path)
		return (NULL);
	return (env_path);
}

char	*init_path(t_data *data, char *cmd)
{
	char	**path_from_env;
	char	*tmp;
	char	*cmd_path;

	if (!cmd)
		return (NULL);
	path_from_env = find_path(data);
	if (!path_from_env)
		return (NULL);
	tmp = ft_strjoin(ft_strdup("/"), cmd);
	if (!tmp)
	{
		free_str_tab(path_from_env);
		return (NULL);
	}
	cmd_path = find_cmd_path(tmp, path_from_env);
	if (!cmd_path)
	{
		free_ptr(tmp);
		free_str_tab(path_from_env);
		return (NULL);
	}
	return (cmd_path);
}

int	init(t_data *data, char **env)
{
	if (init_env(data, env))
	{
		ft_putstr_fd("Could not initialize environment\n", STDERR_FILENO);
		return (1);
	}
	if (init_dir(data))
	{
		ft_putstr_fd("Could not initialize directories\n", STDERR_FILENO);
		return (1);
	}
	data->argv = NULL;
	data->token = NULL;
	data->parser = NULL;
	data->pid = -1;
	g_exit_code = 0;
	return (0);
}
