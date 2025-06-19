/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:42:46 by erantala          #+#    #+#             */
/*   Updated: 2025/06/19 15:50:14 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	**philosophers;

	philosophers = ft_init_data(argc, argv);
	if (!philosophers)
	{
		printf("ERROR\n");
		return (1);
	}
	ft_begin_philo(philosophers);
	ft_stop_sim(philosophers);
	return (0);
}
