/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:45:40 by erantala          #+#    #+#             */
/*   Updated: 2025/06/10 00:10:47 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_begin_philo(t_philo **philo)
{
	int	i;
	pthread_t	death;
	
	i = 0;
	gettimeofday(&philo[0]->data->tv, NULL);
	philo[0]->data->status = -1;
	philo[0]->data->start = get_time();
	while(i < philo[0]->data->n)
	{
		philo[i]->philo_n = i;
		philo[i]->last_meal = philo[0]->data->start;
		if (pthread_create(&philo[i]->id, NULL, &loop, (void *)philo[i]) != 0)
		{
			return (0);
		}
		i++;
	}
	philo[0]->data->status = 1;
	pthread_create(&death, NULL, &death_check, philo);
	pthread_detach(death);
	while (1)
	{
		if (philo[0]->data->status == 0 || philo[0]->data->status == 2)
			break ;
	}
	return (1);
}

void	*loop(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->status == -1)
	{}
	philo->last_meal = philo->data->start;
	if (philo->data->n == 1)
			ft_one(philo);
	while (1 && philo->data->status != 0)
	{
		if (philo->data->status == 0 || think(philo->philo_n, philo) == 0)
			break ;
		if (philo->data->status == 0 || check_eat(philo->philo_n, philo) == 0)
			break ;
		if (rest(philo->philo_n, philo) == 0)
			break ;
		if (philo->times_eaten == philo->data->number_of_eat)
			while (philo->data->status != 0 || philo->data->status != 2)
		if (philo->data->status == 0 || philo->data->status == 2)
			break ;
	}
	if (philo->times_eaten == philo->data->number_of_eat)
		while (philo->data->status != 2 || philo->data->status != 0)
		{}
	philo->state = 0;
	return (0);
}

int	ft_philo_printf(int n, char *s, t_philo *philos)
{
	long	time;

	pthread_mutex_lock(philos->data->print);
	if (philos->data->status != 0)
	{
		time = get_time();
		printf("%li %d %s\n", time, n + 1, s);
	}
	pthread_mutex_unlock(philos->data->print);
	return (1);
}

int	check_eat(int i, t_philo *philos)
{
	if (philos->data->status == 0)
		return (0);
	if (grab_fork(i, philos) == 0)
		return (0);
	eat(i, philos);
	pthread_mutex_unlock(&philos->data->forks[i]);
	pthread_mutex_unlock(&philos->data->forks[(i + 1) % philos->data->n]);
	return (1);
}
