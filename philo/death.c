/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:19:54 by erantala          #+#    #+#             */
/*   Updated: 2025/06/08 01:01:11 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_check(void *arg)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)arg;
	while (philos[0]->data->status == -1)
	{}
	usleep(1000);
	while (1)
	{
		i = 0;
		while (i < philos[0]->data->n)
		{
			if (ft_check_death(i, philos[i]))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	ft_check_death(int i, t_philo *philos)
{
	time_t	time;
	if (philos->data->status == 0)
		return (1);
	pthread_mutex_lock(philos->meal);
	time = get_time();
	if (time > philos->data->time_to_die + philos->last_meal)
	{
		printf("Difference: %ld (%ld - %ld)\n", time - philos->last_meal, time, philos->last_meal);
		pthread_mutex_lock(philos->data->print);
		printf("%li %d %s\n", get_time(), i + 1, "died");
		pthread_mutex_unlock(philos->data->print);
		philos->state = 0;
		philos->data->status = 0;
		return (1);
	}
	pthread_mutex_unlock(philos->meal);
	return (0);
}