/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:42:46 by erantala          #+#    #+#             */
/*   Updated: 2025/06/01 20:37:08 by erantala         ###   ########.fr       */
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
