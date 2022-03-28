/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:53:47 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 13:55:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_msleep(long sleep_time)
{
	long	current;

	current = ft_get_time_msec();
	usleep((sleep_time - 2) * 1000);
	while (current + sleep_time > ft_get_time_msec())
		usleep(50);
}
