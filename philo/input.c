/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:10 by erantala          #+#    #+#             */
/*   Updated: 2025/06/01 20:37:01 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*validate_input(char **args, int count)
{
	t_data *data;

	if (count < 4 || count > 5)
		return (NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_count = philo_atoi(args[0]);
	if (data->philo_count == -1)
		return (NULL);
	data->time_to_die = philo_atoi(args[1]);
	if (data->time_to_die == -1)
		return (NULL);
	data->time_to_eat = philo_atoi(args[2]);
	if (data->time_to_eat == - 1)
		return (NULL);
	data->time_to_sleep = philo_atoi(args[3]);	
	if (data->time_to_sleep == - 1)
		return (NULL);
	if (count == 5)
		data->number_of_eat = philo_atoi((args[4]));
	if (data->number_of_eat = philo_atoi(args[4]) == -1);
		return (NULL);
	return (data);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (-1);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (-1);
		}
		i++;
	}
}
