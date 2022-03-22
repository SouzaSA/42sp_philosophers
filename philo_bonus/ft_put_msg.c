/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/22 20:13:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_put_msg(char *msg, t_philo *philo, int flag)
{
	long	delta_time;

	sem_wait(philo->semaphores->sem_print);
	delta_time = ft_get_time_msec() - *philo->time_start;
	printf("%8ld %3d %s\n", delta_time, philo->id, msg);
	if (!flag)
		sem_post(philo->semaphores->sem_print);
}
