/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:18:47 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:48 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	stop_philo(t_state *state)
{
	int	i;

	i = 1;
	pthread_mutex_lock(&state->stop_lock);
	if (state->stop == 0)
		i = 0;
	pthread_mutex_unlock(&state->stop_lock);
	return (i);
}

static int	check_death(t_philo *philo)
{
	time_t	the_time;

	the_time = get_time();
	if ((the_time - philo->last_meal) >= philo->state->time_to_die)
	{
		pthread_mutex_lock(&philo->state->stop_lock);
		philo->state->stop = 0;
		pthread_mutex_unlock(&philo->state->stop_lock);
		pthread_mutex_lock(&philo->state->writing);
		printf("%ld %d %s\n", get_time() - philo->state->time,
			philo->place + 1, "is dead");
		pthread_mutex_unlock(&philo->state->writing);
		pthread_mutex_unlock(&philo->mu_last_meal);
		return (0);
	}
	return (1);
}

static int	ending(t_state *state)
{
	int	i;
	int	all_ate;

	all_ate = 0;
	i = 0;
	while (i < state->nb_philosophers)
	{
		pthread_mutex_lock(&state->philo[i]->mu_last_meal);
		if (check_death(state->philo[i]) == 0)
			return (0);
		if (state->eating_times != -1)
			if (state->philo[i]->meals < state->eating_times)
				all_ate = 1;
		pthread_mutex_unlock(&state->philo[i]->mu_last_meal);
		i++;
	}
	if (state->eating_times != -1 && all_ate == 0)
	{
		pthread_mutex_lock(&state->stop_lock);
		state->stop = 0;
		pthread_mutex_unlock(&state->stop_lock);
		return (0);
	}
	return (1);
}

void	*death(void *data)
{
	t_state	*state;

	state = (t_state *)data;
	if (state->eating_times == 0)
		return (NULL);
	pthread_mutex_lock(&state->stop_lock);
	state->stop = 1;
	pthread_mutex_unlock(&state->stop_lock);
	while (1)
	{
		if (ending(state) == 0)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	start_threads(t_state *state)
{
	int	i;

	state->time = get_time();
	i = 0;
	while (i < state->nb_philosophers)
	{
		if (pthread_create(&state->philo[i]->thread_id, NULL,
				&routine, state->philo[i]) != 0)
			return (1);
		i++;
	}
	if (state->nb_philosophers > 1)
	{
		if (pthread_create(&state->death, NULL, &death, state) != 0)
			return (1);
	}
	return (0);
}
