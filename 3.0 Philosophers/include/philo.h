/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:21:34 by mdarbois          #+#    #+#             */
/*   Updated: 2023/04/17 17:21:36 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> 
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_philo	t_philo;

typedef struct s_state {
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	time_t			time;
	int				stop;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	writing;
	pthread_mutex_t	*forks;
	pthread_t		death;
	t_philo			**philo;
}	t_state;

typedef struct s_philo {
	pthread_t		thread_id;
	int				place;
	int				meals;
	time_t			last_meal;
	int				fork[2];
	pthread_mutex_t	mu_last_meal;
	t_state			*state;
}	t_philo;

void		stop_all(t_state *state);
void		*free_state(t_state *state);
t_state		*init_state(char **argv);
void		write_state(t_state *state, int id, char *str);
void		*routine(void *void_philo);
int			start_threads(t_state *state);
void		*death(void *data);
int			stop_philo(t_state *state);
int			msg_error(char *str, t_state *state);
void		*null_error(char *str, t_state *state);
time_t		get_time(void);
long long	ft_atoi(char *str);

#endif
