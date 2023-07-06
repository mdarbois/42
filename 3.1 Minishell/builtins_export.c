/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:03:59 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:04:01 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static char	**get_key_value_pair(char *arg)
{
	char	**tmp;
	char	*eq_pos;

	eq_pos = ft_strchr(arg, '=');
	tmp = malloc(sizeof * tmp * (2 + 1));
	tmp[0] = ft_substr(arg, 0, eq_pos - arg);
	tmp[1] = ft_substr(eq_pos, 1, ft_strlen(eq_pos));
	tmp[2] = NULL;
	return (tmp);
}

bool	is_valid_env(char *var)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
	{
		return (false);
	}
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

int	builtin_export(t_data *data, t_parser *cmd)
{
	int		i;
	char	**tmp;
	int		ret;

	ret = 0;
	i = 1;
	if (!cmd->argument[i])
		return (builtin_env(data, NULL));
	while (cmd->argument[i])
	{
		if (!is_valid_env(cmd->argument[i]))
		{
			ft_putstr_fd("minishell: export: ", STDERR_FILENO);
			ft_putendl_fd("not a valid identifier", STDERR_FILENO);
			ret = 1;
		}
		else if (ft_strchr(cmd->argument[i], '=') != NULL)
		{
			tmp = get_key_value_pair(cmd->argument[i]);
			set_env_var(data, tmp[0], tmp[1]);
			free_str_tab(tmp);
		}
		i++;
	}
	return (ret);
}
