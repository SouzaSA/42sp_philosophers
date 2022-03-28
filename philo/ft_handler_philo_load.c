/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_philo_load.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:08:55 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:27:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_load_all_philos(t_table *table, t_philo *philos, t_stats *stats);

int	ft_load_philos(t_table *table, t_philo **philos, t_stats *stats)
{
	*philos = (t_philo *)malloc(stats->num_philo * sizeof(t_philo));
	if (*philos)
		ft_load_all_philos(table, *philos, stats);
	else
		return (1);
	return (0);
}

static void	ft_load_all_philos(t_table *table, t_philo *philos, t_stats *stats)
{
	int	i;

	i = 0;
	while (i < stats->num_philo)
	{
		philos[i].id = i + 1;
		philos[i].dead_flag = &table->dead_flag;
		philos[i].philo_meals = 0;
		philos[i].time_meal = ft_get_time_msec();
		philos[i].time_start = &table->time_start;
		philos[i].stats = &table->stats;
		philos[i].left_fork = &table->forks_mtx[i];
		philos[i].right_fork = &table->forks_mtx[(i + 1) % stats->num_philo];
		philos[i].critical_mtx = &table->critical_mtx;
		i++;
	}
}
