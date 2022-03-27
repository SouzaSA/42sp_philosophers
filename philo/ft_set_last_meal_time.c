/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_last_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:21 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 01:29:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_set_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->time_meal = ft_get_time_msec();
	pthread_mutex_unlock(&philo->meal_mtx);
}
