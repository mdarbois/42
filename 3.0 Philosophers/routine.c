/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:18:41 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:42 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static void	sleep_tight(time_t time, t_state *state)
{
	time_t	i;

	i = get_time() + time;
	while (get_time() < i)
	{
		if (!stop_philo(state))
			break ;
		usleep(100);
	}
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->fork[0]]);
	write_state(philo->state, philo->place, "has taken a fork");
	pthread_mutex_lock(&philo->state->forks[philo->fork[1]]);
	write_state(philo->state, philo->place, "has taken a fork");
	write_state(philo->state, philo->place, "is eating");
	pthread_mutex_lock(&philo->mu_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->mu_last_meal);
	sleep_tight(philo->state->time_to_eat, philo->state);
	if (stop_philo(philo->state))
	{
		pthread_mutex_lock(&philo->mu_last_meal);
		philo->meals += 1;
		pthread_mutex_unlock(&philo->mu_last_meal);
	}
	write_state(philo->state, philo->place, "is sleeping");
	pthread_mutex_unlock(&philo->state->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->state->forks[philo->fork[0]]);
	sleep_tight(philo->state->time_to_sleep, philo->state);
}

static void	think(t_philo *philo, bool s)
{
	int	time_to_think;

	pthread_mutex_lock(&philo->mu_last_meal);
	time_to_think = (philo->state->time_to_die - (get_time()
				- philo->last_meal) - philo->state->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->mu_last_meal);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && s == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (s == false)
		write_state(philo->state, philo->place, "is thinking");
	sleep_tight(time_to_think, philo->state);
}

static void	*alone_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->fork[0]]);
	write_state(philo->state, philo->place, "has taken a fork");
	sleep_tight(philo->state->time_to_die, philo->state);
	write_state(philo->state, philo->place, "died");
	pthread_mutex_unlock(&philo->state->forks[philo->fork[0]]);
	return (NULL);
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->state->eating_times == 0)
		return (NULL);
	pthread_mutex_lock(&philo->mu_last_meal);
	philo->last_meal = philo->state->time;
	pthread_mutex_unlock(&philo->mu_last_meal);
	if (philo->state->time_to_die == 0)
		return (NULL);
	if (philo->state->nb_philosophers == 1)
		return (alone_philo(philo));
	else if (philo->place % 2)
		think(philo, true);
	while (stop_philo(philo->state) != 0)
	{
		eat(philo);
		think(philo, false);
	}
	return (NULL);
}
