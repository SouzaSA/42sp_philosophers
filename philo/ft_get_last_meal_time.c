/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:01 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:31:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_get_last_meal_time(t_philo *philo, long *time)
{
	pthread_mutex_lock(philo->critical_mtx);
	*time = philo->time_meal;
	pthread_mutex_unlock(philo->critical_mtx);
}
