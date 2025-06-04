/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:45:40 by erantala          #+#    #+#             */
/*   Updated: 2025/06/04 19:40:27 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_begin_philo(t_philo **philo)
{
	int	i;

	i = 0;
	philo[0]->data->grab = &grab_fork;
	philo[0]->data->eat = &eat;
	philo[0]->data->sleep = &rest;
	philo[0]->data->think = &think;
	philo[0]->data->death = &ft_check_death;
	gettimeofday(philo[0]->data->tv, NULL);
	philo[0]->data->start = philo[0]->data->tv->tv_usec;
	while(i < philo[0]->data->philo_count)
	{
		philo[i]->philo_n = 1;
		if(pthread_create(&philo[i]->id, NULL, &loop, (void *)philo[i]) != 0);
		{

		}
		i++;
	}
}

int	loop(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	gettimeofday(philo->data->tv, NULL);
	philo->last_meal = philo->data->tv->tv_usec;
	while (1)
	{
		if (philo->data->think(philo->philo_n, philo) == 0);
			break ;

	}
}

int	ft_philo_printf(int n, char *s, t_philo **philos)
{
	pthread_mutex_lock(&philos[n]->data->print);
	gettimeofday(philos[n]->data->tv, NULL);
	printf("%li Philo %d started: %s\n", philos[n]->data->tv->tv_usec, n, s);
	pthread_mutex_unlock(&philos[n]->data->philo_count);
}