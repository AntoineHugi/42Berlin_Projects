/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:03:21 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/31 16:56:46 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	time_t			last_meal;
	time_t			ttt;
	int				times_eaten;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		tid;
	struct s_table	*table;
}			t_philo;

typedef struct s_table
{
	int				nb_ph;
	int				meal_end;
	int				max_meals;
	t_philo			**philos;
	pthread_t		tid_obs;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_end_lock;
	time_t			start;
	time_t			tte;
	time_t			tts;
	time_t			ttd;
}			t_table;

int			ft_is_numerical(const char *str);
long long	ft_atoll(const char *nptr);
t_table		*init_table(char **argv);
void		free_table(t_table *table);
void		start_meal(t_table *table);
void		error_table(t_table *table, char *msg);
void		error_arguments(void);
void		print_action(char a, t_philo *philo);
void		solo_philo_routine(t_philo *philo);
void		multi_philo_routine(t_philo *philo);
void		get_time(time_t *time, t_table *table);
int			meal_stops(t_table *table);

#endif