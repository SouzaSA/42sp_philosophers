/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_semaphores_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:12:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static int	ft_init_semaphore(sem_t	**sem, char *sem_name, int value);

int	ft_init_semaphores(t_semaphores *semaphores, int num_philo)
{
	if (ft_init_semaphore(&semaphores->sem_fork, "/sem_fork", num_philo))
		return (1);
	if (ft_init_semaphore(&semaphores->sem_critical, "/sem_critical", 1))
	{
		sem_unlink("/sem_fork");
		sem_close(semaphores->sem_fork);
		return (1);
	}
	if (ft_init_semaphore(&semaphores->sem_meals, "/sem_meals", 0))
	{
		sem_unlink("/sem_fork");
		sem_unlink("/sem_critical");
		sem_close(semaphores->sem_fork);
		sem_close(semaphores->sem_critical);
		return (1);
	}
	return (0);
}

static int	ft_init_semaphore(sem_t	**sem, char *sem_name, int value)
{
	sem_unlink(sem_name);
	*sem = sem_open(sem_name, O_CREAT, S_IRWXU, value);
	if (*sem == SEM_FAILED)
		return (1);
	return (0);
}
