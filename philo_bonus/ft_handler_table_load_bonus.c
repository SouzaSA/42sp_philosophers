/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_table_load_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/03 16:42:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static int	ft_load_stats(t_stats *stats, int argc, char **argv);

int	ft_load_table(int argc, char **argv, t_table *table)
{
	if (ft_load_stats(&table->stats, argc, argv) == 0)
	{
		if (ft_load_philos(table, &table->philos, &table->stats))
			return (1);
	}
	else
		return (1);
	return (0);
}

static int	ft_load_stats(t_stats *stats, int argc, char **argv)
{
	stats->num_philo = ft_atoi(argv[1]);
	if (stats->num_philo <= 0)
		return (1);
	stats->time_to_die = ft_atoi(argv[2]);
	stats->time_to_eat = ft_atoi(argv[3]);
	stats->time_to_sleep = ft_atoi(argv[4]);
	stats->num_meals = -1;
	stats->meals_counter = 0;
	if (argc == 6)
	{
		stats->meals_counter = 1;
		stats->num_meals = ft_atoi(argv[5]);
		if (stats->num_meals == 0)
			return (1);
	}
	return (0);
}
