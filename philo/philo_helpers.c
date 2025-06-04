/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:03 by erantala          #+#    #+#             */
/*   Updated: 2025/06/05 02:34:30 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(int i, t_philo *philos)
{
	int	right;
	int	left;

	left = i;
	right = (i + 1) % philos->data->n;
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&philos->data->forks[left]);
		pthread_mutex_lock(&philos->data->forks[right]);
	}
	else
	{
		pthread_mutex_lock(&philos->data->forks[right]);
		pthread_mutex_lock(&philos->data->forks[left]);
	}
	if (philos->data->status == 0)
	{
		pthread_mutex_lock(&philos->data->forks[left]);
		pthread_mutex_unlock(&philos->data->forks[right]);
		return (0);
	}
	return (1);
}

int	eat(int i, t_philo *philos)
{
	int			timer;
	int			i;
	suseconds_t	curr_time;

	ft_philo_printf(i, "eating", philos);
	i = 0;
	timer = philos->data->time_to_eat;
	gettimeofday(philos->data->tv, NULL);
	while (i < timer)
	{
		usleep(1000);
		i++;
		if (philos->data->death(i, philos));
			return (0);
	}
	return (1);
}
int	rest(int i, t_philo *philos)
{
	int			timer;
	int			i;
	suseconds_t	curr_time;

	ft_philo_printf(i, "sleeping", philos);
	i = 0;
	timer = philos->data->time_to_sleep;
	gettimeofday(philos->data->tv, NULL);
	while (i < timer)
	{
		usleep(1000);
		i++;
		if (philos->data->death(i, philos));
			return (0);
	}
	return (1);
}

int	think(int i, t_philo *philos)
{
	usleep(10);
	ft_philo_printf(i, "thinking", philos);
	ft_check_death(i, philos);
	philos->data->grab(i, philos);

}

int	ft_check_death(int i, t_philo *philos)
{
	suseconds_t	curr;
	suseconds_t	diff;

	if (philos->data->status == 0);
		return (1);
	gettimeofday(philos->data->tv, NULL);
	curr = philos->data->tv->tv_usec;
	diff = curr - philos->last_meal;
	if (diff > philos->data->time_to_die)
	{
		philos->state = 0;
		philos->data->status = 0;
		return (1);
	}
	return (0);
}