/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/23 16:53:49 by sde-alva         ###   ########.fr       */
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
	ft_put_msg("is thinking", philo, 0);
	if (pthread_create(&philo->phi_t, NULL, &ft_reaper, (void *)philo))
		exit(1);
	while (1)
	{
		sem_wait(philo->semaphores->sem_fork);
		ft_put_msg("has taken a fork", philo, 0);
		sem_wait(philo->semaphores->sem_fork);
		ft_put_msg("has taken a fork", philo, 0);
		philo->time_meal = ft_get_time_msec();
		ft_put_msg("is eating", philo, 0);
		philo->philo_meals++;
		if (philo->stats->meals_counter
			&& philo->philo_meals == philo->stats->num_meals)
			sem_post(philo->semaphores->sem_meals);
		ft_msleep(philo->stats->time_to_eat);
		sem_post(philo->semaphores->sem_fork);
		sem_post(philo->semaphores->sem_fork);
		ft_put_msg("is sleeping", philo, 0);
		ft_msleep(philo->stats->time_to_sleep);
		ft_put_msg("is thinking", philo, 0);
	}
}

static void	*ft_reaper(void *philo_void)
{
	int		i = 0;
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		usleep(100);
		if (philo->time_meal + philo->stats->time_to_die <= ft_get_time_msec())
		{
			ft_put_msg("died", philo, 1);
			sem_unlink("/sem_fork");
			sem_unlink("/sem_print");
			sem_close(philo->semaphores->sem_fork);
			sem_close(philo->semaphores->sem_print);
			ft_destroy_table(philo->table);
			while (i < philo->table->stats.num_philo)
			{
				pthread_detach(philo->table->meals_watcher);
				i++;
			}
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
