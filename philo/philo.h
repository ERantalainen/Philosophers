/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:34:35 by erantala          #+#    #+#             */
/*   Updated: 2025/06/01 19:25:59 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdatomic.h>

typedef	struct s_data
{
	int	philo_count;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	number_of_eat;
	pthread_mutex_t	*forks;
	pthread_t	**philos;
}	t_data;

t_data	*validate_input(char **args, int count);
int	philo_atoi(char	*s);

#endif