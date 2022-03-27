/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/27 01:40:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_philo_actions(t_philo *philo);
static void	ft_msleep(long sleep_time);

void	*ft_dinner(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->id % 2 == 0)
		usleep(500);
	ft_philo_actions(philo);
	return (NULL);
}

static void	ft_philo_actions(t_philo *philo)
{
	philo->time_meal = ft_get_time_msec();
	ft_put_msg("is thinking", philo);
	while (!(*philo->dead_flag))
	{
		pthread_mutex_lock(philo->left_fork);
		ft_put_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork);
		ft_put_msg("has taken a fork", philo);
		philo->time_meal = ft_get_time_msec();
		ft_put_msg("is eating", philo);
		philo->philo_meals++;
		ft_msleep(philo->stats->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_put_msg("is sleeping", philo);
		ft_msleep(philo->stats->time_to_sleep);
		ft_put_msg("is thinking", philo);
	}
}

static void	ft_msleep(long sleep_time)
{
	long	current;

	current = ft_get_time_msec();
	usleep((sleep_time - 1) * 1000);
	while (current + sleep_time > ft_get_time_msec())
		usleep(50);
}
