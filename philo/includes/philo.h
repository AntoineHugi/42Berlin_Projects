/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:03:21 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/17 15:44:04 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo {
	int			id;
	int			tte;
	int			tts;
	int			ttt;
	int			ttd;
	int			times_eaten;
	int			is_dead;
	void		*fork_l;
	void		*fork_r;
	pthread_t	*tid;
}			t_philo;

typedef struct s_table {
	t_philo			**philos;
	pthread_t		*tid_obs;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
	pthread_mutex_t *death;
}			t_table;

long long	ft_atoll(const char *nptr);
t_table		*init_table(char **argv);
void		free_table(t_table *table);
void		start_meal(t_table *table);
void		error_table(t_table *table, char *msg);
void		error_arguments();

#endif