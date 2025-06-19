/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 01:09:16 by erantala          #+#    #+#             */
/*   Updated: 2025/06/20 01:10:14 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_init_data(int argc, char **argv)
{
	t_data	*data;
	t_philo	**philos;

	philos = NULL;
	data = validate_input(argv + 1, argc - 1);
	if (!data)
		return (NULL);
	if (ft_init_mutex(data) == -1)
	{
		printf("mutex error\n");
		ft_free(philos, data);
		return (NULL);
	}
	philos = ft_init_philos(data);
	if (philos == NULL)
	{
		printf("philo error\n");
		ft_free(philos, data);
		return (NULL);
	}
	return (philos);
}

void	ft_free(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->n)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data)
		free(data);
	if (philos)
		free(philos);
}

void	free_philo(t_philo **philosophers, int i)
{
	if (!philosophers[i])
	{
		while (--i)
			free(philosophers[i]);
		free(philosophers);
		return (NULL);
	}
}
