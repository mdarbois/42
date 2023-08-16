/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:04:17 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/22 09:49:15 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	builtin_pwd(t_data *data, char **argument)
{
	char	buf[4096];
	char	*cwd;

	(void)argument;
	(void)data;
	cwd = getcwd(buf, 4096);
	if (cwd)
	{
		data->pwd = cwd;
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (0);
	}
	ft_putstr_fd("pwd: ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	return (1);
}
