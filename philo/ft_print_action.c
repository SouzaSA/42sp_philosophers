/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:48:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_print_action(char *msg, t_philo *philo)
{
	long	delta_time;

	delta_time = ft_get_time_msec() - *philo->time_start;
	pthread_mutex_lock(philo->critical_mtx);
	if ((!*philo->dead_flag && !philo->stats->meals_counter) \
		|| (!*philo->dead_flag && philo->stats->meals_counter \
		&& philo->philo_meals < philo->stats->num_meals))
	{
		printf("%-5ld %2d %s\n", delta_time, philo->id, msg);
	}
	pthread_mutex_unlock(philo->critical_mtx);
}
