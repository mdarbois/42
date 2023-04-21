/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:18:34 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:36 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	write_state(t_state *state, int id, char *str)
{
	pthread_mutex_lock(&state->writing);
	if (stop_philo(state) == 0)
	{
		pthread_mutex_unlock(&state->writing);
		return ;
	}
	printf("%ld %d %s\n", get_time() - state->time, id + 1, str);
	pthread_mutex_unlock(&state->writing);
	return ;
}

static int	check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!((ft_atoi(argv[1]) >= 1) && (ft_atoi(argv[1]) <= INT_MAX)))
	{
		printf("number of philosophers is from 1 to MAX INT\n");
		return (1);
	}
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
		{
			printf("only positive numbers allowed\n");
			return (1);
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			printf("only int allowed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	*state;

	state = NULL;
	if ((argc != 5 && argc != 6) || check(argc, argv))
	{
		printf("Problem with arguments\n");
		exit(1);
	}
	state = init_state(argv);
	if (!state)
	{
		printf("Problem parameters\n");
		exit(1);
	}
	if (start_threads(state))
	{
		msg_error("Threads problem\n", state);
		exit(1);
	}
	stop_all(state);
	return (0);
}
