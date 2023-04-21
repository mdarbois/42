/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:18:27 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static void	give_fork(t_philo *philo)
{
	philo->fork[0] = philo->place;
	philo->fork[1] = (philo->place + 1) % philo->state->nb_philosophers;
	if (philo->place % 2)
	{
		philo->fork[0] = (philo->place + 1) % philo->state->nb_philosophers;
		philo->fork[1] = philo->place;
	}
}

static t_philo	**init_philos(t_state *state)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo) * state->nb_philosophers);
	if (!philos)
		return (null_error("Malloc error", 0));
	i = 0;
	while (i < state->nb_philosophers)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (null_error("Malloc error", 0));
		if (pthread_mutex_init(&philos[i]->mu_last_meal, 0) != 0)
			return (null_error("Mutex last meal error", 0));
		philos[i]->state = state;
		philos[i]->place = i;
		philos[i]->meals = 0;
		give_fork(philos[i]);
		i++;
	}
	return (philos);
}

static int	init_mutex(t_state *state)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * state->nb_philosophers);
	if (!fork)
	{
		msg_error("Malloc error", 0);
		return (1);
	}
	i = 0;
	while (i < state->nb_philosophers)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (msg_error("Mutex init forks", state) != 0);
		i++;
	}
	state->forks = fork;
	if (!state->forks)
		return (1);
	if ((pthread_mutex_init(&state->writing, NULL)) != 0)
		return (msg_error("Mutex init writing", state));
	if (pthread_mutex_init(&state->stop_lock, NULL) != 0)
		return (msg_error("Mutex init stop lock", state));
	return (0);
}

t_state	*init_state(char **argv)
{
	t_state	*state;

	state = malloc(sizeof(t_state) * 1);
	if (!state)
		return (null_error("Malloc error", 0));
	state->nb_philosophers = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		state->eating_times = ft_atoi(argv[5]);
	else
		state->eating_times = -1;
	if (state->nb_philosophers < 1 || state->time_to_die < 0
		|| state->time_to_eat < 0 || state->time_to_sleep < 0
		|| state->eating_times < -1)
		return (NULL);
	state->philo = init_philos(state);
	if (!state->philo)
		return (NULL);
	if (init_mutex(state) != 0)
		return (NULL);
	state->stop = 1;
	return (state);
}
