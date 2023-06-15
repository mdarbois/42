/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:04 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 09:36:06 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int init_env(t_data *data, char **env)
{
    int i;

    i = 0;
    data->env = ft_calloc(count_env(env) + 1, sizeof * data->env);
    if (!data->env)
        return (1);
    while (env[i] != NULL)
    {
        data->env[i] = ft_strdup(env[i]);
        if (!data->env[i])
            return (1);
		printf("data->env[%d]=%s\n",i,data->env);
        i++;
    }
    return (0);
}

static int init_dir(t_data *data)
{  
    int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
			data->pwd = ft_substr(data->env[i],
					4, ft_strlen(data->env[i]) - 4);
		if (!ft_strncmp(data->env[i], "OLDPWD=", 7))
			data->old_pwd = ft_substr(data->env[i],
					7, ft_strlen(data->env[i]) - 7);
		printf("data->old_pwd[%d]=%s\n",i,data->old_pwd);
		printf("data->pwd[%d]=%s\n",i,data->pwd);
		i++;
	}
	return (0);
}

char	*find_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

int init_path(t_data *data)
{
    char	*path_from_env;
	int		i;
	char	*tmp;

	path_from_env = find_path(data->env);
	data->path = ft_split(path_from_env, ':');
	free(path_from_env);
	i = 0;
	while (data->path[i])
	{
		if (ft_strncmp(&data->path[i][ft_strlen(data->path[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(data->path[i], "/");
			free(data->path[i]);
			data->path[i] = tmp;
		}
		printf("data->path[%d]=%s\n",i,data->path);
		i++;
	}
	return (0);
}

int init(t_data *data, char **env)
{
    if (init_env(data, env))
    {
        printf("Could not initialize environment\n");
        return (1);
    }
    if (init_dir(data))
    {
        printf("Could not initialize directories\n");
        return (1);
    }
    if (init_path(data))
    {
        printf("Could not initialize environment\n");
        return (1);
    }
    data->token = NULL;
    data->argv = NULL;
    data->input = NULL;
    data->pid = -1;
	data->fd_out = -1;
	data->fd_in = -1;
	data->pipe_out = -1;
	data->pipe_in = -1;
	data->in = dup(STDIN);
	data->out = dup(STDOUT);
	
    return (0);
}
