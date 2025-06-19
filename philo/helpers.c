/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:13 by erantala          #+#    #+#             */
/*   Updated: 2025/06/19 15:51:14 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"

int	philo_atoi(char	*s)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (s[i] == '-')
		return (-1);
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (s[i] != '\0')
		return (-1);
	return ((int)res);
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

int	ft_stop_sim(t_philo **philos)
{
	int	i;
	int	n;

	ft_join_philos(philos);
	n = philos[0]->data->n;
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&philos[0]->data->forks[i]);
		i++;
	}
	free(philos[0]->data->forks);
	pthread_mutex_destroy(philos[0]->data->print);
	free(philos[0]->data->print);
	free(philos[0]->data);
	i = 0;
	while (i < n)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
	return (0);
}

void	ft_join_philos(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < philos[0]->data->n)
	{
		if (philos[i]->state != 0)
			pthread_join(philos[i]->id, NULL);
		i++;
	}
}

void	ft_one(t_philo *philo)
{
	ft_philo_printf(0, "has started thinking", philo);
	pthread_mutex_lock(&philo->data->forks[0]);
	ft_philo_printf(0, "has grabbed a fork", philo);
	usleep((philo->data->time_to_die * 1000));
	ft_philo_printf(0, "died", philo);
	philo->state = 0;
	philo->data->status = 0;
	pthread_mutex_unlock(&philo->data->forks[0]);
}
