/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 00:19:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_philo_actions(t_philo *philo);
static void	ft_take_forks(t_philo *philo);
static void	ft_msleep(long sleep_time);

void	*ft_dinner(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->id % 2 == 1)
		usleep(100);
	ft_philo_actions(philo);
	pthread_mutex_destroy(&philo->meal_mtx);
	return (NULL);
}

static void	ft_philo_actions(t_philo *philo)
{
	int	dead_flag;

	ft_get_death_flag(philo, &dead_flag);
	ft_exec_critical_action("is thinking", philo, PHILO_ALIVE);
	while (!dead_flag)
	{
		usleep(200);
		ft_take_forks(philo);
		ft_exec_critical_action("is eating", philo, PHILO_ALIVE);
		ft_set_last_meal(philo);
		ft_msleep(philo->stats->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_exec_critical_action("is sleeping", philo, PHILO_ALIVE);
		ft_msleep(philo->stats->time_to_sleep);
		ft_exec_critical_action("is thinking", philo, PHILO_ALIVE);
		ft_get_death_flag(philo, &dead_flag);
	}
}

static void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ft_exec_critical_action("has taken a fork", philo, PHILO_ALIVE);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_exec_critical_action("has taken a fork", philo, PHILO_ALIVE);
}

static void	ft_msleep(long sleep_time)
{
	long	current;

	current = ft_get_time_msec();
	usleep((sleep_time - 1) * 1000);
	while (current + sleep_time > ft_get_time_msec())
		usleep(50);
}
