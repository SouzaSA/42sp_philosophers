/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:52:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/20 21:30:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_put_msg(t_table *table, char *msg, t_philo *philo)
{
	long	time;

	if (table->dead_flag)
		return ;
	pthread_mutex_lock(&table->mtx);
	time = ft_get_time_msec() - philo->time_stamp;
	printf("%ld %3d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&table->mtx);
}
