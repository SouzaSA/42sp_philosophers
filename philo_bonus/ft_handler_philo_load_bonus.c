/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_philo_load_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:08:55 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/25 14:37:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

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
		philos[i].alive = 1;
		philos[i].philo_meals = 0;
		philos[i].time_meal = table->time_start;
		philos[i].time_start = &table->time_start;
		philos[i].stats = &table->stats;
		philos[i].semaphores = &table->semaphores;
		philos[i].table = table;
		i++;
	}
}
