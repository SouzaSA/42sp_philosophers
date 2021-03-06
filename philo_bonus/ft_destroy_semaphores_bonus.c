/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_semaphores_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:13:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:57:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_destroy_semaphores(t_semaphores *semaphores)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_critical");
	sem_unlink("/sem_meals");
	sem_close(semaphores->sem_fork);
	sem_close(semaphores->sem_critical);
	sem_close(semaphores->sem_meals);
}
