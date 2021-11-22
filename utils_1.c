/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:17:45 by mel-haya          #+#    #+#             */
/*   Updated: 2021/11/22 15:23:39 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(t_args *data)
{
	int		i;
	t_philo	*philos;
	t_philo	*head;

	i = 1;
	head = malloc(sizeof(t_philo));
	if (!head)
		return (NULL);
	philos = head;
	while (i <= data->nb_philo)
	{
		init_philo(i, data, philos);
		if (i != data->nb_philo)
			philos->next = malloc(sizeof(t_philo));
		else
			philos->next = head;
		if (!philos->next)
			return (NULL);
		philos = philos->next;
		i++;
	}
	return (head);
}

void	mutex_write(t_args *args, char *msg, int i)
{
	pthread_mutex_lock(&(args->w));
	printf("%lld ", time_now() - args->start);
	printf("philo %d %s\n", i, msg);
	pthread_mutex_unlock(&(args->w));
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->nb_meals != philo->data->nb_meals)
	{
		pthread_mutex_lock(&(philo->fork));
		mutex_write(philo->data, "took a fork", philo->id);
		pthread_mutex_lock(&(philo->next->fork));
		mutex_write(philo->data, "is eating", philo->id);
		pthread_mutex_lock(&(philo->eat));
		philo->last_meal = time_now();
		pthread_mutex_unlock(&(philo->eat));
		ft_usleep(philo->data->teat);
		philo->nb_meals++;
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		mutex_write(philo->data, "is sleeping", philo->id);
		ft_usleep(philo->data->tsleep);
		mutex_write(philo->data, "is thinking", philo->id);
	}
	philo->data->nb_philo--;
	philo->id = 0;
	return (NULL);
}
