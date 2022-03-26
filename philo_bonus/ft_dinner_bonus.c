/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/26 15:55:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static void	*ft_reaper(void *arg);
static void	ft_msleep(long sleep_time);
static void	ft_philo_actions(t_philo *philo);
static void	ft_clean_exit(t_philo *philo);

void	ft_dinner(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	philo->time_meal = ft_get_time_msec();
	if (pthread_create(&philo->phi_t, NULL, &ft_reaper, (void *)philo))
	{
		ft_clean_exit(philo);
		exit(1);
	}
	ft_put_msg("is thinking", philo, 0);
	ft_philo_actions(philo);
	ft_clean_exit(philo);
}

static void	*ft_reaper(void *philo_void)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		usleep(100);
		if (philo->time_meal + philo->stats->time_to_die <= ft_get_time_msec())
		{
			ft_put_msg("died", philo, 1);
			philo->keep_dinning = 0;
			i = 0;
			while (i < philo->table->stats.num_philo)
			{
				sem_post(philo->semaphores->sem_meals);
				i++;
			}
			break ;
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

static void	ft_philo_actions(t_philo *philo)
{
	ft_put_msg("is thinking", philo, 0);
	philo->time_meal = ft_get_time_msec();
	while (philo->keep_dinning)
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
		{
			philo->keep_dinning = 0;	
			sem_post(philo->semaphores->sem_meals);
		}
		ft_msleep(philo->stats->time_to_eat);
		sem_post(philo->semaphores->sem_fork);
		sem_post(philo->semaphores->sem_fork);
		ft_put_msg("is sleeping", philo, 0);
		ft_msleep(philo->stats->time_to_sleep);
		ft_put_msg("is thinking", philo, 0);
	}
}

static void	ft_clean_exit(t_philo *philo)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_print");
	sem_unlink("/sem_meals");
	sem_close(philo->semaphores->sem_fork);
	sem_close(philo->semaphores->sem_print);
	sem_close(philo->semaphores->sem_meals);
	ft_destroy_table(philo->table);
	exit(0);
}
