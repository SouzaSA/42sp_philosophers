/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/22 13:46:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static void	*ft_reaper(void *arg);
static void	ft_msleep(long sleep_time);

void	ft_dinner(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	philo->time_meal = ft_get_time_msec();
	ft_put_msg("is thinking", philo);
	if (pthread_create(&philo->phi_t, NULL, &ft_reaper, (void *)philo))
		exit(1);
	while (1)
	{
		sem_wait(philo->semaphores->sem_fork);
		ft_put_msg("has taken a fork", philo);
		sem_wait(philo->semaphores->sem_fork);
		ft_put_msg("has taken a fork", philo);
		philo->time_meal = ft_get_time_msec();
		ft_put_msg("is eating", philo);
		philo->philo_meals++;
		if (philo->stats->meals_counter
			&& philo->philo_meals == philo->stats->num_meals)
			sem_post(philo->semaphores->sem_meals);
		ft_msleep(philo->stats->time_to_eat);
		sem_post(philo->semaphores->sem_fork);
		sem_post(philo->semaphores->sem_fork);
		ft_put_msg("is sleeping", philo);
		ft_msleep(philo->stats->time_to_sleep);
		ft_put_msg("is thinking", philo);
	}
}

static void	*ft_reaper(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		if (philo->time_meal + philo->stats->time_to_die <= ft_get_time_msec())
		{
			ft_put_msg("died", philo);
			exit(0);
		}
	}
	return (NULL);
}

static void	ft_msleep(long sleep_time)
{
	long	current;

	current = ft_get_time_msec();
	usleep((sleep_time - 1) * 1000);
	while (current + sleep_time > ft_get_time_msec())
		usleep(50);
}
