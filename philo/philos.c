/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:45:40 by erantala          #+#    #+#             */
/*   Updated: 2025/06/06 02:12:29 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_begin_philo(t_philo **philo)
{
	int	i;

	i = 0;
	gettimeofday(&philo[0]->data->tv, NULL);
	philo[0]->data->start = get_time();
	philo[0]->data->status = 1;
	printf("Thread target: %d\n", philo[0]->data->n);
	while(i < philo[0]->data->n)
	{
		philo[i]->philo_n = i;
		printf("Thread %d\n", i);
		if(pthread_create(&philo[i]->id, NULL, &loop, (void *)philo[i]) != 0)
		{
			printf("Here?\n");
			return (0);
		}
		printf("Ready to make next thread\n");
		i++;
		while (philo[0]->data->status != 0)
			{}
	}
	return (1);
}

void	*loop(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->last_meal = philo->data->start;
	printf("Started thread %d\n", philo->philo_n);
	while (1)
	{
		if (think(philo->philo_n, philo) == 0)
			break ;
		if (check_eat(philo->philo_n, philo) == 0)
			break ;
		if (philo->times_eaten == philo->data->number_of_eat)
			break ; // add special case
		printf("After eat\n");
		if (rest(philo->philo_n, philo) == 0)
			break ;
		if (ft_check_death(philo->philo_n, philo))
			break ;
	}
	return (0);
}

int	ft_philo_printf(int n, char *s, t_philo *philos)
{
	long	time;
	
	
	pthread_mutex_lock(philos->data->print);
	if (philos->data->status != 0)
	{
		time = get_time();
		printf("%li %d %s\n", time, n, s);
	}
	pthread_mutex_unlock(philos->data->print);
	return (1);
}

int	check_eat(int i, t_philo *philos)
{
	if (grab_fork(i, philos) == 0)
		return (0);
	else if (ft_check_death(i, philos))
		return (0);
	eat(i, philos);
	pthread_mutex_unlock(&philos->data->forks[i]);
	pthread_mutex_unlock(&philos->data->forks[(i + 1) % philos->data->n]);
	if (ft_check_death(i, philos))
		return (0);
	return (1);
}
