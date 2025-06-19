/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:10 by erantala          #+#    #+#             */
/*   Updated: 2025/06/20 01:09:06 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*validate_input(char **args, int count)
{
	t_data	*data;

	if (count < 4 || count > 5)
		return (NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->n = philo_atoi(args[0]);
	if (data->n <= 0)
		return (NULL);
	data->time_to_die = philo_atoi(args[1]);
	if (data->time_to_die <= 0)
		return (NULL);
	data->time_to_eat = philo_atoi(args[2]);
	if (data->time_to_eat <= 0)
		return (NULL);
	data->time_to_sleep = philo_atoi(args[3]);
	if (data->time_to_sleep <= 0)
		return (NULL);
	if (count == 5)
		data->number_of_eat = philo_atoi((args[4]));
	if (data->number_of_eat == -1)
		return (NULL);
	return (data);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n);
	if (!data->forks)
		return (-1);
	while (i < data->n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (-1);
		}
		i++;
	}
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		return (-1);
	if (pthread_mutex_init(data->print, NULL) != 0)
		return (-1);
	return (0);
}

t_philo	**ft_init_philos(t_data *data)
{
	int		i;
	t_philo	**philosophers;

	i = 0;
	philosophers = malloc(sizeof(t_philo *) * data->n);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < data->n)
	{
		philosophers[i]->philo_n = i;
		philosophers[i]->times_eaten = 0;
		philosophers[i]->last_meal = 0;
		philosophers[i]->state = 1;
		philosophers[i]->data = data;
		i++;
	}
	return (philosophers);
}

t_philo	**philo_data(t_data *data, t_philo **philosophers)
{
	int	i;

	i = 0;
	while (i < data->n)
	{
		philosophers[i] = malloc(sizeof(t_philo));
		if (!philosophers[i])
		{
			free_philo(philosophers, i);
		}
		philosophers[i]->meal = malloc(sizeof(pthread_mutex_t));
		if (!philosophers[i]->meal)
		{
			printf("Malloc error\n");
			return (NULL);
		}
		if (pthread_mutex_init(philosophers[i]->meal, NULL) != 0)
		{
			printf("Mutex error");
			return (NULL);
		}
		i++;
	}
}
