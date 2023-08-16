/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:04:27 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/22 09:49:27 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static bool	remove_env(t_data *data, int idx)
{
	int	i;
	int	count;

	if (idx > env_count(data->env))
		return (false);
	free_ptr(data->env[idx]);
	i = idx;
	count = idx;
	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free_ptr(data->env[i + 1]);
		count++;
		i++;
	}
	data->env = realloc_env(data, count);
	if (!data->env)
		return (false);
	return (true);
}

int	builtin_unset(t_data *data, char **argument)
{
	int	i;
	int	idx;
	int	ret;

	ret = 0;
	i = 1;
	while (argument[i])
	{
		if (!is_valid_env(argument[i])
			|| ft_strchr(argument[i], '=') != NULL)
		{
			ft_putendl_fd("unset: not a valid identifier", STDERR_FILENO);
			ret = 1;
		}
		else
		{
			idx = env_index(data->env, argument[i]);
			if (idx != -1)
				remove_env(data, idx);
		}
		i++;
	}
	return (ret);
}
