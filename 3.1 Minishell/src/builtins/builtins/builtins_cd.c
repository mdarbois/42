/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:54:16 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:02:08 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

bool	set_env_var(t_data *data, char *key, char *value)
{
	int		idx;
	char	*tmp;

	idx = env_index(data->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin(ft_strdup("="), value);
	if (!tmp)
		return (false);
	if (idx != -1 && data->env[idx])
	{
		free_ptr(data->env[idx]);
		data->env[idx] = ft_strjoin(ft_strdup(key), tmp);
	}
	else
	{
		idx = env_count(data->env);
		data->env = realloc_env(data, idx + 1);
		if (!data->env)
			return (false);
		data->env[idx] = ft_strjoin(ft_strdup(key), tmp);
	}
	free_ptr(tmp);
	return (true);
}

static void	update_pwds(t_data *data, char *wd)
{
	set_env_var(data, "OLDPWD", env_value(data->env, "PWD"));
	set_env_var(data, "PWD", wd);
	if (data->old_pwd)
	{
		free_ptr(data->old_pwd);
		data->old_pwd = ft_strdup(data->pwd);
	}
	if (data->pwd)
	{
		free_ptr(data->pwd);
		data->pwd = ft_strdup(wd);
	}
	free_ptr(wd);
}

static bool	change_dir(t_data *data, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
	{
		ft_putendl_fd("cd: no such file or directory", STDERR_FILENO);
		return (false);
	}
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		ft_putendl_fd("cd: error retrieving current directory, \
			getcwd: cannot access parent directories", STDERR_FILENO);
		ret = ft_strjoin(ft_strdup(data->pwd), "/");
		tmp = ret;
		ret = ft_strjoin(ft_strdup(tmp), path);
	}
	else
		ret = ft_strdup(cwd);
	update_pwds(data, ret);
	return (true);
}

static int	cd_return(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	return (1);
}

int	builtin_cd(t_data *data, t_parser *cmd)
{
	char	*path;

	if (!cmd->argument[1] || !cmd->argument
		|| is_space(cmd->argument[1][0]) || cmd->argument[1][0] == '\0')
	{
		path = env_value(data->env, "HOME");
		if (!path || *path == '\0' || is_space(*path))
			return (cd_return("cd HOME not set"));
		return (!change_dir(data, path));
	}
	if (ft_strncmp(cmd->argument[1], "-", 2) == 0)
	{
		path = env_value(data->env, "OLDPWD");
		if (!path)
			return (cd_return("cd OLDPWD not set"));
		return (!change_dir(data, path));
	}
	if (cmd->argument[2])
		return (cd_return("cd error: too many arguments"));
	return (!change_dir(data, cmd->argument[1]));
}
