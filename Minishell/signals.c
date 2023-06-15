/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:36:34 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 09:36:36 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"
// ctrl-C displays a new prompt on a new line.
// ctrl-D exits the shell.
// ctrl-\ does nothing.

void signal_reset(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_newline(int signal)
{
	(void)signal;
	rl_on_new_line();
}

void	signal_sigquit_ignore(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

void	signal_setup_both(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

void signal_setup_sigint(void)
{
    struct sigaction	act;

	signal_sigquit_ignore();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset;
	sigaction(SIGINT, &act, NULL);
}
