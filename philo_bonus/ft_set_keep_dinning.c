/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_keep_dinning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:01 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 13:27:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_set_keep_dinning(t_philo *philo)
{
	sem_wait(philo->semaphores->sem_critical);
	philo->keep_dinning = 0;
	sem_post(philo->semaphores->sem_critical);
}
