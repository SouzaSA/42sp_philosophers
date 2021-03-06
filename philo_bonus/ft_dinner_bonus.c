/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/03 22:42:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static void	*ft_reaper(void *arg);
static void	ft_alone_actions(t_philo *philo);
static void	ft_philo_actions(t_philo *philo);
static void	ft_meal_checker(t_philo *philo);

void	ft_dinner(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	if (pthread_create(&philo->phi_t, NULL, &ft_reaper, (void *)philo))
	{
		ft_clean_exit(philo, 1);
	}
	if (philo->stats->num_philo == 1)
		ft_alone_actions(philo);
	else
		ft_philo_actions(philo);
	ft_clean_exit(philo, 0);
}

static void	*ft_reaper(void *philo_void)
{
	long	last_meal;
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	ft_set_last_meal_time(philo);
	while (1)
	{
		usleep(500);
		ft_get_last_meal_time(philo, &last_meal);
		if (last_meal + philo->stats->time_to_die <= ft_get_time_msec())
		{
			ft_put_msg("died", philo, DEAD);
			break ;
		}
	}
	return (NULL);
}

static void	ft_alone_actions(t_philo *philo)
{
	sem_wait(philo->semaphores->sem_fork);
	ft_put_msg("has taken a fork", philo, ALIVE);
	sem_wait(philo->semaphores->sem_fork);
	ft_msleep(philo->stats->time_to_die + 1);
}

static void	ft_philo_actions(t_philo *philo)
{
	while (1)
	{
		usleep(500);
		sem_wait(philo->semaphores->sem_fork);
		sem_wait(philo->semaphores->sem_fork);
		ft_put_msg("has taken a fork", philo, ALIVE);
		ft_put_msg("has taken a fork", philo, ALIVE);
		ft_put_msg("is eating", philo, ALIVE);
		ft_set_last_meal(philo);
		if (philo->stats->meals_counter)
			ft_meal_checker(philo);
		ft_msleep(philo->stats->time_to_eat);
		sem_post(philo->semaphores->sem_fork);
		sem_post(philo->semaphores->sem_fork);
		ft_put_msg("is sleeping", philo, ALIVE);
		ft_msleep(philo->stats->time_to_sleep);
		ft_put_msg("is thinking", philo, ALIVE);
	}
}

static void	ft_meal_checker(t_philo *philo)
{
	int	num_meals;

	ft_get_last_meal_num(philo, &num_meals);
	if (num_meals == philo->stats->num_meals)
	{
		sem_post(philo->semaphores->sem_meals);
	}
}
