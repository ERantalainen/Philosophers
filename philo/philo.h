/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:34:35 by erantala          #+#    #+#             */
/*   Updated: 2025/06/04 19:47:32 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdatomic.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int			philo_n;
	int			times_eaten;
	suseconds_t	last_meal;
	int			state;
	pthread_t	*id;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	atomic_int		status;
	struct timeval	*tv;
	suseconds_t		start;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				number_of_eat;
	int				(*death)(int, t_philo *);
	int				(*eat)(int, t_philo *);
	int				(*sleep)(int, t_philo *);
	int				(*think)(int, t_philo *);
	int				(*grab)(int, t_philo *);
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_data;

t_data	*validate_input(char **args, int count);
int		philo_atoi(char	*s);
int		ft_init_mutex(t_data *data);

int	grab_fork(int n, t_philo *philos);
int	eat(int n, t_philo *philos);
int	rest(int n, t_philo *philos);
int	think(int n, t_philo *philos);
int	ft_philo_printf(int n, char *s, t_philo **philos);
int	ft_check_death(int n, t_philo *philos);

#endif