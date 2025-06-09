/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:03 by erantala          #+#    #+#             */
/*   Updated: 2025/06/09 23:56:56 by erantala         ###   ########.fr       */
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
		ft_philo_printf(i, "has taken a fork", philos);
		pthread_mutex_lock(&philos->data->forks[right]);
		ft_philo_printf(i, "has taken a fork", philos);
	}
	else
	{
		pthread_mutex_lock(&philos->data->forks[right]);
		ft_philo_printf(i, "has taken a fork", philos);
		pthread_mutex_lock(&philos->data->forks[left]);
		ft_philo_printf(i, "has taken a fork", philos);
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
	while (get_time() < target)
	{
		usleep(100);
		if (philos->data->status == 0)
			return (0);
	}
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
	time_t	target;
	time_t	cycle;
	time_t	until_death;

	if (philos->data->status == 0)
		return (0);
	until_death = philos->data->time_to_die - (get_time() - philos->last_meal);
	cycle = philos->data->time_to_eat + philos->data->time_to_sleep;
	target = (until_death - cycle) / 2;
	if (target < 100)
		target = 1;
	else
		target += get_time();
	ft_philo_printf(i, "is thinking", philos);
	usleep(10);
	// while (get_time() < target)
	// {
	// 	if (philos->data->status == 0)
	// 		return (0);
	// 	usleep(250);
	// }
	if (philos->data->status == 0)
		return (0);
	return (1);
}
