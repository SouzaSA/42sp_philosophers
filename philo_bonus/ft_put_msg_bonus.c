/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 14:40:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_put_msg(char *msg, t_philo *philo)
{
	long	delta_time;

	if (!philo->keep_dinning)
		return ;
	sem_wait(philo->semaphores->sem_critical);
	delta_time = ft_get_time_msec() - *philo->time_start;
	if (philo->keep_dinning)
		printf("%-5ld %2d %s\n", delta_time, philo->id, msg);
	sem_post(philo->semaphores->sem_critical);
}
