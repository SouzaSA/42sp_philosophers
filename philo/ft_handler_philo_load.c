/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_philo_load.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:08:55 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 12:09:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_load_philos(t_philo **philos, t_stats *stats)
{
	int	i;

	i = 0;
	*philos = (t_philo *)malloc(stats->num_philo * sizeof(t_philo));
	if (*philos)
	{
		while (i < stats->num_philo)
		{
			(*philos)[i].id = i + 1;
			(*philos)[i].philo_meals = 0;
			(*philos)[i].philo_status = THINKING;
			(*philos)[i].time_meal = ft_get_time_msec();
			(*philos)[i].time_dead = ft_get_time_msec();
			(*philos)[i].time_sleep = ft_get_time_msec();
			(*philos)[i].time_stamp = ft_get_time_msec();
			(*philos)[i].time_start = ft_get_time_msec();
			i++;
		}
	}
	else
	{
		return (1);
	}
	return (0);
}
