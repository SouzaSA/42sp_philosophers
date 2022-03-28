/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_last_meal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:21 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:32:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->critical_mtx);
	philo->philo_meals++;
	philo->time_meal = ft_get_time_msec();
	pthread_mutex_unlock(philo->critical_mtx);
}
