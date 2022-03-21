/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/20 21:41:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_philo_actions(t_table *table, int philo_id);
static void	ft_msleep(long sleep_time);

void	*ft_dinner(void *table_void)
{
	int		id;
	t_table	*table;

	table = (t_table *)table_void;
	id = table->pth_id;
	if (id % 2 == 0)
		usleep(100);
	ft_philo_actions(table, id);
	return (NULL);
}

static void	ft_philo_actions(t_table *table, int philo_id)
{
	table->philos[philo_id].time_meal = ft_get_time_msec();
	//ft_put_msg(table, "is thinking", &table->philos[philo_id]);
	while (!table->dead_flag)
	{
		pthread_mutex_lock(&table->forks_mtx[philo_id]);
		ft_put_msg(table, "has taken a fork", &table->philos[philo_id]);
		pthread_mutex_lock(&table->forks_mtx[(philo_id + 1) % table->stats.num_philo]);
		ft_put_msg(table, "has taken a fork", &table->philos[philo_id]);
		table->philos[philo_id].time_meal = ft_get_time_msec();
		ft_put_msg(table, "is eating", &table->philos[philo_id]);
		table->philos[philo_id].philo_meals++;
		ft_msleep(table->stats.time_to_eat);
		pthread_mutex_unlock(&table->forks_mtx[philo_id]);
		pthread_mutex_unlock(&table->forks_mtx[(philo_id + 1) % table->stats.num_philo]);
		ft_put_msg(table, "is sleeping", &table->philos[philo_id]);
		ft_msleep(table->stats.time_to_sleep);
		ft_put_msg(table, "is thinking", &table->philos[philo_id]);
	}
}

static void	ft_msleep(long sleep_time)
{
	long current;

	current = ft_get_time_msec();
	usleep((sleep_time - 10) * 1000);
	while (current + sleep_time > ft_get_time_msec())
		usleep(50);
}