/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:08:47 by mel-haya          #+#    #+#             */
/*   Updated: 2021/11/22 15:29:29 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				nb_philo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nb_meals;
	long long		start;
	pthread_mutex_t	w;
}t_args;

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat;
	long long		last_meal;
	pthread_t		p;
	struct s_philo	*next;
	t_args			*data;
}t_philo;

void		free_philos(t_philo *philos, int e);
long long	time_now(void);
void		ft_usleep(long long sleep_time);
int			check_valid_uint(char *nb);
int			init_args(int c, char **v, t_args *args);
void		init_philo(int i, t_args *data, t_philo *philo);
t_philo		*init_philos(t_args *data);
void		mutex_write(t_args *args, char *msg, int i);
void		*routine(void *data);
#endif