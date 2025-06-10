/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:34:35 by erantala          #+#    #+#             */
/*   Updated: 2025/06/10 15:04:10 by erantala         ###   ########.fr       */
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

typedef struct s_data
{
	volatile int	n;
	atomic_int		status;
	struct timeval	tv;
	volatile long	start;
	atomic_int	time_to_die;
	atomic_int 	time_to_sleep;
	atomic_int 	time_to_eat;
	volatile int	number_of_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;

}	t_data;

typedef struct s_philo
{
	int				philo_n;
	int				times_eaten;
	suseconds_t		last_meal;
	int				state;
	pthread_t		id;
	t_data			*data;
	pthread_mutex_t	*meal;

}	t_philo;

t_data	*validate_input(char **args, int count);
int		philo_atoi(char	*s);
int		ft_init_mutex(t_data *data);
t_philo	**ft_init_data(int argc, char **argv);

int	grab_fork(int n, t_philo *philos);
int	eat(int n, t_philo *philos);
int	rest(int n, t_philo *philos);
int	think(int n, t_philo *philos);
int	ft_philo_printf(int n, char *s, t_philo *philos);
int	ft_check_death(int n, t_philo *philos);
long	get_time(void);

int		ft_stop_sim(t_philo **philos);
void	ft_free(t_philo **philos, t_data *data);

void	ft_join_philos(t_philo **philos);
void	ft_one(t_philo *philo);

int		ft_begin_philo(t_philo **philo);
void	*loop(void *arg);
int		check_eat(int i, t_philo *philos);
void	*death_check(void *arg);
int		ft_check_meals(t_philo **philos);

#endif