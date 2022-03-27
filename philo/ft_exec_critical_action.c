/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_critical_action.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 00:12:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_exec_critical_action(char *msg, t_philo *philo, int status_flag)
{
	int		dead_flag;
	int		num_meals;
	long	delta_time;

	ft_get_death_flag(philo, &dead_flag);
	ft_get_last_meal_num(philo, &num_meals);
	if (dead_flag || (philo->stats->meals_counter \
		&& num_meals >= philo->stats->num_meals))
		return ;
	pthread_mutex_lock(philo->critical_mtx);
	if (*philo->dead_flag == 0 && (philo->stats->meals_counter \
		&& philo->philo_meals < philo->stats->num_meals))
	{
		if (status_flag == PHILO_DIED)
			*philo->dead_flag = 1;
		delta_time = ft_get_time_msec() - *philo->time_start;
		printf("%-5ld %2d %s\n", delta_time, philo->id, msg);	
	}
	pthread_mutex_unlock(philo->critical_mtx);
}
