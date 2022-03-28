/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:42:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 15:47:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_clean_exit(t_philo *philo)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_critical");
	sem_unlink("/sem_meals");
	sem_close(philo->semaphores->sem_fork);
	sem_close(philo->semaphores->sem_critical);
	sem_close(philo->semaphores->sem_meals);
	ft_destroy_table(philo->table);
	exit(0);
}
