/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:36:01 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:03:52 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_exit_code;

static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	determine_exit_code(char **str)
{
	if (!str[1])
		g_exit_code = 0;
	else if (is_str_digit(str[1]))
		g_exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		g_exit_code = 255;
	}
	free_str_tab(str);
	exit (g_exit_code);
}

int	builtin_exit(t_data *data, char **argument)
{
	char	**str;
	int		exit_code;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (!argument || !argument[1])
		exit_code = g_exit_code;
	else
	{
		if (argument[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			return (1);
		}
		str = ft_arrdup(argument);
		exit_code = determine_exit_code(str);
	}
	exit_shell(data, exit_code);
	return (2);
}
