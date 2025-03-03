/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:03:21 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/27 11:13:51 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo {
	int		tte;
	int		tts;
	int		ttt;
	int		ttd;
	int		times_eaten;
	int		is_dead;
	void	*fork_a;
	void	*fork_b;
}			t_philo;

typedef struct s_obs {
	int	ded;
}			t_obs;

typedef struct s_table {
	t_philo	**philos;
	t_obs	obs;
}			t_table;

#endif