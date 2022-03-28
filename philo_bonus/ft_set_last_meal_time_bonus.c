/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_last_meal_time_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:21 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:59:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_set_last_meal_time(t_philo *philo)
{
	sem_wait(philo->semaphores->sem_critical);
	philo->time_meal = ft_get_time_msec();
	sem_post(philo->semaphores->sem_critical);
}
