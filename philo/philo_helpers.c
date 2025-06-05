/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:03 by erantala          #+#    #+#             */
/*   Updated: 2025/06/06 02:24:36 by erantala         ###   ########.fr       */
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
	target = philos->data->time_to_eat + get_time();
		// cut time into smaller pieces
	while //blablabla
	philos->times_eaten += 1;
	if (philos->times_eaten == philos->data->number_of_eat)
	{
		philos->state = 2;
		return (1);
	}
	philos->last_meal = get_time();
	return (1);
}
int	rest(int i, t_philo *philos)
{
	time_t		timer;
	time_t		time;
	time_t		t_to_d;

	printf("in sleep\n");
	if (philos->data->status != 1)
		return (0);
	printf("in sleep 2\n");
	ft_philo_printf(i, "is sleeping", philos);
	timer = philos->data->time_to_sleep;
	time = get_time();
	t_to_d = (philos->data->time_to_die + philos->last_meal) - time;
	// cut time into smaller pieces

	return (1);
}

int	think(int i, t_philo *philos)
{
	usleep(10);
	ft_philo_printf(i, "is thinking", philos);
	if (ft_check_death(i, philos))
		return (0);
	return (1);
}

int	ft_check_death(int i, t_philo *philos)
{
	time_t	curr;
	time_t	t_of_d;

	if (philos->data->status == 0)
		return (1);
	curr = get_time();
	t_of_d = philos->last_meal + philos->data->time_to_die;
	if (curr > t_of_d)
	{
		ft_philo_printf(i, "died", philos);
		philos->state = 0;
		philos->data->status = 0;
		return (1);
	}
	return (0);
}