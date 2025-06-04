/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:03 by erantala          #+#    #+#             */
/*   Updated: 2025/06/04 19:37:58 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(int n, t_philo *philos)
{
	while (1)
	{

	}
}

int	eat(int n, t_philo *philos)
{
	int			timer;
	int			i;
	suseconds_t	curr_time;

	ft_philo_printf(n, "eating", philos);
	i = 0;
	timer = philos->data->time_to_eat;
	gettimeofday(philos->data->tv, NULL);
	while (i < timer)
	{
		usleep(1000);
		i++;
		if (philos->data->death(n, philos));
			return (0);
	}
	return (1);
}
int	rest(int n, t_philo *philos)
{
	int			timer;
	int			i;
	suseconds_t	curr_time;

	ft_philo_printf(n, "sleeping", philos);
	i = 0;
	timer = philos->data->time_to_sleep;
	gettimeofday(philos->data->tv, NULL);
	while (i < timer)
	{
		usleep(1000);
		i++;
		if (philos->data->death(n, philos));
			return (0);
	}
	return (1);
}

int	think(int n, t_philo *philos)
{
	usleep(10);
	ft_philo_printf(n, "thinking", philos);
	ft_check_death(n, philos);
	philos->data->grab(n, philos);

}

int	ft_check_death(int n, t_philo *philos)
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