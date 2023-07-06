/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:03:26 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:03:27 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	builtin_env(t_data *data, char **argument)
{
	int	i;

	if (!data->env)
		return (1);
	i = 0;
	if (argument && argument[1])
	{
		ft_putendl_fd("env error: too many arguments", STDERR_FILENO);
		return (2);
	}
	while (data->env[i])
		ft_putendl_fd(data->env[i++], STDOUT_FILENO);
	return (0);
}
