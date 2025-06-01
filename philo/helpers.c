/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:13 by erantala          #+#    #+#             */
/*   Updated: 2025/06/01 19:11:07 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	philo_atoi(char	*s)
{
	int		i;
	long	res;
	
	i = 0;
	res = 0;
	if (s[i] == '-')
		return (-1);
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		if (res > INT_MAX)
			return (-1);
	}
	if (s[i] != '\0')
		return (-1);
	return ((int)res);
}

