/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:11 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/26 18:20:09 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	input_check(t_data *data)
{
	if (data->argv == NULL)
		builtin_exit(data, NULL);
	else if (ft_strncmp(data->argv, "\0", 1) == 0)
		return (1);
	else if (only_space(data->argv))
		return (0);
	add_history(data->argv);
	if (lexer(data->argv, data))
		return (1);
	if (data->token->type == END)
		return (1);
	if (check(&data->token))
		return (1);
	var_expander(data, &data->token);
	handle_quotes(data);
	parser(data, data->token);
	return (0);
}

void	exit_shell(t_data *data, int exno)
{
	if (data)
	{
		if (data->parser && data->parser->fds)
			close_fds(data->parser, true);
		free_data(data, true);
	}
	exit(exno);
}

int	g_exit_code;

static void	launch_mini(t_data *data)
{
	while (1)
	{
		signal_setup_sigint();
		data->argv = readline(PROMPT);
		signal_setup_both();
		if (input_check(data))
			g_exit_code = 1;
		else
			g_exit_code = execute(data);
		free_data(data, false);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("This program does not accept arguments\n", STDERR_FILENO);
		exit(0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	if (init(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	else
		launch_mini(&data);
	exit_shell(&data, g_exit_code);
	return (0);
}
