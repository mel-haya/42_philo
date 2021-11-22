/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:08:52 by mel-haya          #+#    #+#             */
/*   Updated: 2021/11/22 15:59:48 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philo *philos)
{
	int				i;

	i = 0;
	while (i < philos->data->nb_philo)
	{
		pthread_create(&(philos->p), NULL, &routine, philos);
		usleep(50);
		philos = philos->next;
		i++;
	}
}

int	supervisor(t_philo *philos)
{
	int	done;

	done = 0;
	while (1)
	{
		if (!philos->data->nb_philo)
			free_philos(philos, 0);
		pthread_mutex_lock(&(philos->eat));
		if (philos->id && (time_now() - philos->last_meal > philos->data->tdie))
		{
			mutex_write(philos->data, "died", philos->id);
			free_philos(philos, 0);
		}
		pthread_mutex_unlock(&(philos->eat));
		philos = philos->next;
	}
}

void	free_philos(t_philo *philos, int e)
{
	int		i;
	t_philo	*tmp;
	t_philo	*next;

	i = 0;
	tmp = philos->next;
	pthread_mutex_destroy(&(tmp->data->w));
	free(tmp->data);
	while (!i)
	{
		next = tmp->next;
		if (tmp == philos)
			i++;
		pthread_mutex_destroy(&(tmp->fork));
		pthread_mutex_destroy(&(tmp->eat));
		free(tmp);
		tmp = next;
	}
	exit(e);
}

int	main(int c, char **v)
{
	t_args	*args;
	t_philo	*philos;

	args = malloc(sizeof(t_args));
	if (!args || (c != 5 && c != 6) || !init_args(c, v, args))
	{
		printf("ERR: Invalid args\n");
		return (1);
	}
	if (!args->nb_philo || !args->nb_meals)
		return (0);
	philos = init_philos(args);
	if (!philos)
	{
		printf("ERR: Malloc failed\n");
		return (1);
	}
	start_simulation(philos);
	supervisor(philos);
	return (0);
}
