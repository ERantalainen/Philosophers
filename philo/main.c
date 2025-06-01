/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:42:46 by erantala          #+#    #+#             */
/*   Updated: 2025/06/02 02:22:04 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(argc, argv)
{
	t_data *data;
	
	data = validate_input((argv + 1), argc - 1);
	if (!data)
		return ;
	if (argc == 5)
		data->number_of_eat - 1;
	ft_init_data()
}
// Init forks, make thread array, create think, sleep, and eat functions. Fork logic, avoid deadlocks, have philos try to pick 1 fork if they can only then go for 2nd fork. 
// Eg, philo 1 picks up fark 0, only then checks for fork 1, philo 2 picks up fork 2, only then checks for 1.
// How to check for deaths? Check constantly for time since last eat? Make array to store philo stats? Add in philo stats to main array or own array?  Add optional argument support
// Create printing output 
// Core loop eat -> sleep -> think -> eat