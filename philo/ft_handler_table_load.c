/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_table_load.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/20 21:11:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_load_stats(t_stats *stats, int argc, char **argv);
static int	ft_init_forks_mutex(t_table *table);

int	ft_load_table(int argc, char **argv, t_table *table)
{
	if (ft_load_stats(&table->stats, argc, argv) == 0)
	{
		if (ft_load_philos(&table->philos, &table->stats))
			return (1);
		if (pthread_mutex_init(&table->mtx, NULL))
			return (1);
		table->dead_flag = 0;
		table->forks_mtx = (pthread_mutex_t *)malloc(table->stats.num_philo \
			* sizeof(pthread_mutex_t));
		if (ft_init_forks_mutex(table) == 0)
			return (0);
		else
		{
			pthread_mutex_destroy(&table->mtx);
			return (1);
		}
	}
	else
		return (1);
}

static int	ft_load_stats(t_stats *stats, int argc, char **argv)
{
	stats->num_philo = ft_atoi(argv[1]);
	stats->time_to_die = ft_atoi(argv[2]);
	stats->time_to_eat = ft_atoi(argv[3]);
	stats->time_to_sleep = ft_atoi(argv[4]);
	stats->num_meals = -1;
	stats->meals_counter = 0;
	if (argc == 6)
	{
		stats->meals_counter = 1;
		stats->num_meals = ft_atoi(argv[5]);
	}
	return (0);
}

static int	ft_init_forks_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->stats.num_philo)
	{
		if (pthread_mutex_init(&table->forks_mtx[i], NULL))
		{
			ft_destroy_forks_mutex(table, i - 1);
			return (1);
		}
		i++;
	}
	return (0);
}
