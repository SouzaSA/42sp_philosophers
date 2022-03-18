/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_table_load.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 12:28:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_load_stats(t_stats *stats, int argc, char **argv);

int	ft_load_table(int argc, char **argv, t_table *table)
{
	int	i;
	int	rtn;

	i = 0;
	rtn = 0;
	rtn = ft_load_stats(&table->stats, argc, argv);
	if (!rtn)
	{
		table->dead_flag = 0;
		table->forks_mtx = (pthread_mutex_t *)malloc(table->stats.num_philo \
			* sizeof(pthread_mutex_t));
		if (table->forks_mtx)
		{
			while (i < table->stats.num_philo)
			{
				pthread_mutex_init(&table->forks_mtx[i], NULL);
				i++;
			}
			pthread_mutex_init(&table->mtx, NULL);
		}
	}
	return (rtn);
}

static int	ft_load_stats(t_stats *stats, int argc, char **argv)
{
	stats->num_philo = ft_atoi(argv[1]);
	stats->time_to_die = ft_atoi(argv[2]);
	stats->time_to_eat = ft_atoi(argv[3]);
	stats->time_to_sleep = ft_atoi(argv[4]);
	stats->num_meals = -1;
	if (argc == 6)
		stats->num_meals = ft_atoi(argv[5]);
	return (0);
}
