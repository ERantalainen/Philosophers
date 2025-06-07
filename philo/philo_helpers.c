/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:03 by erantala          #+#    #+#             */
/*   Updated: 2025/06/08 01:11:19 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(int i, t_philo *philos)
{
	int	right;
	int	left;

	left = i;
	right = (i + 1) % philos->data->n;
	if (philos->data->status == 0)
		return (0);
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&philos->data->forks[left]);
		pthread_mutex_lock(&philos->data->forks[right]);
		// printf("%d grabbing\n", i);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(&philos->data->forks[right]);
		pthread_mutex_lock(&philos->data->forks[left]);
		// printf("%d grabbing\n", i);
	}
	if (philos->data->status == 0)
	{
		pthread_mutex_unlock(&philos->data->forks[left]);
		pthread_mutex_unlock(&philos->data->forks[right]);
		return (0);
	}
	return (1);
}

int	eat(int i, t_philo *philos)
{
	time_t	target;
	
	if (philos->data->status == 0)
		return (0);
	ft_philo_printf(i, "is eating", philos);
	pthread_mutex_lock(philos->meal);
	philos->last_meal = get_time();
	pthread_mutex_unlock(philos->meal);
	target = get_time() + philos->data->time_to_eat;
	printf("Eat:  %ld\n", target);
	while (get_time() < target)
	{
		usleep(100);
		if (philos->data->status == 0)
			return (0);
	}
	printf("Done: %ld\n", get_time());
	philos->times_eaten += 1;
	if (philos->times_eaten == philos->data->number_of_eat)
	{
		philos->state = 2;
		return (2);
	}
	return (1);
}
int	rest(int i, t_philo *philos)
{
	time_t		target;

	if (philos->data->status != 1)
		return (0);
	ft_philo_printf(i, "is sleeping", philos);
	target = get_time() + philos->data->time_to_sleep;
	printf("Sleep Target %ld\n", target);
	while (get_time() < target)
	{
		usleep(100);
		if (philos->data->status == 0)
			return (0);
	}
	return (1);
}

int	think(int i, t_philo *philos)
{
	time_t	since_meal;
	time_t	target;
	time_t	cycle_time;

	if (philos->data->status == 0)
		return (0);
	since_meal = (get_time() - philos->last_meal);
	cycle_time = philos->data->time_to_eat + philos->data->time_to_sleep;
	ft_philo_printf(i, "is thinking", philos);
	if (philos->data->time_to_die - since_meal < cycle_time)
		target = 1;
	else
		target = cycle_time / 4;
	while (get_time() < target)
	{
		usleep(100);
		if (philos->data->status == 0)
			return (0);
	}
	if (philos->data->status == 0)
		return (0);
	return (1);
}
