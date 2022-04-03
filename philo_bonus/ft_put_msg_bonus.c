/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/03 01:47:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_put_msg(char *msg, t_philo *philo, int status)
{
	int		i;
	int		max_meal;
	long	delta_time;

	sem_wait(philo->semaphores->sem_critical);
	max_meal = philo->stats->num_meals;
	delta_time = ft_get_time_msec() - *philo->time_start;
	if (max_meal == -1 || (max_meal >= 0 && philo->philo_meals < max_meal))
		printf("%-5ld %2d %s\n", delta_time, philo->id, msg);
	if (status == ALIVE)
		sem_post(philo->semaphores->sem_critical);
	else
	{
		i = 0;
		while (i < philo->table->stats.num_philo)
		{
			sem_post(philo->semaphores->sem_meals);
			i++;
		}
	}
}
