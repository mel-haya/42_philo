/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:17:41 by mel-haya          #+#    #+#             */
/*   Updated: 2021/11/22 15:23:42 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long sleep_time)
{
	long long	start;

	start = time_now();
	usleep((sleep_time - 5) * 1000);
	while ((time_now() - sleep_time) < start)
		;
}

int	check_valid_uint(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		return (0);
	if (ft_strlen(nb) > 10 || (ft_strlen(nb) == 10 && \
	ft_strncmp(nb, "2147483647", 10) > 0))
		return (0);
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_args(int c, char **v, t_args *args)
{
	int	i;

	i = 1;
	args->nb_meals = -1;
	while (i < c)
	{
		if (!check_valid_uint(v[i]))
			return (0);
		i++;
	}
	args->nb_philo = ft_atoi(v[1]);
	args->tdie = ft_atoi(v[2]);
	args->teat = ft_atoi(v[3]);
	args->tsleep = ft_atoi(v[4]);
	args->start = time_now();
	pthread_mutex_init(&(args->w), NULL);
	if (c == 6)
		args->nb_meals = ft_atoi(v[5]);
	return (1);
}

void	init_philo(int i, t_args *data, t_philo *philo)
{
	philo->id = i;
	philo->nb_meals = 0;
	pthread_mutex_init(&(philo->fork), NULL);
	pthread_mutex_init(&(philo->eat), NULL);
	philo->last_meal = data->start;
	philo->data = data;
}
