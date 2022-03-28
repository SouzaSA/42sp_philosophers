/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_keep_dinning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:01 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 13:34:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_get_keep_dinnig(t_philo *philo, int *dinning)
{
	sem_wait(philo->semaphores->sem_critical);
	*dinning = philo->keep_dinning;
	sem_post(philo->semaphores->sem_critical);
}
