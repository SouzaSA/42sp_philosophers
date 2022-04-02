/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/02 18:26:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_put_msg(char *msg, t_philo *philo, int status)
{
	int		i;
	long	delta_time;

	sem_wait(philo->semaphores->sem_critical);
	delta_time = ft_get_time_msec() - *philo->time_start;
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
