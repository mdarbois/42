/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:18:20 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:22 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static void	destroy_mutex(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->nb_philosophers)
	{
		pthread_mutex_destroy(&state->forks[i]);
		pthread_mutex_destroy(&state->philo[i]->mu_last_meal);
		i++;
	}
	pthread_mutex_destroy(&state->writing);
	pthread_mutex_destroy(&state->stop_lock);
}

void	*free_state(t_state *state)
{
	int	i;

	if (!state)
		return (NULL);
	if (state->forks != NULL)
		free(state->forks);
	if (state->philo != NULL)
	{
		i = 0;
		while (i < state->nb_philosophers)
		{
			if (state->philo[i] != NULL)
				free(state->philo[i]);
			i++;
		}
		free(state->philo);
	}
	free(state);
	return (NULL);
}

void	stop_all(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->nb_philosophers)
	{
		pthread_join(state->philo[i]->thread_id, NULL);
		i++;
	}
	if (state->nb_philosophers > 1)
		pthread_join(state->death, NULL);
	destroy_mutex(state);
	free_state(state);
}
