/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:47:57 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/27 01:19:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_create_philo_threads(t_table *table);
static int	ft_dinner_checker(t_table *table);
static int	ft_meals_checker(t_table *table);

int	ft_philosophers(t_table	*table)
{
	if (ft_create_philo_threads(table))
		return (1);
	ft_dinner_checker(table);
	ft_destroy_philo_threads(table, table->stats.num_philo);
	ft_destroy_forks_mutex(table, table->stats.num_philo);
	pthread_mutex_destroy(&table->print_mtx);
	return (0);
}

static int	ft_create_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->stats.num_philo)
	{
		if (pthread_create(&table->philos[i].phi_t, NULL, ft_dinner, \
			(void *)&table->philos[i]))
		{
			ft_destroy_philo_threads(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_dinner_checker(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		usleep(100);
		if (table->philos[i].time_meal + table->stats.time_to_die \
			<= ft_get_time_msec())
		{
			ft_put_msg("died", &table->philos[i]);
			break ;
		}
		if (table->stats.meals_counter && ft_meals_checker(table) == 0)
			break ;
		i = (i + 1) % table->stats.num_philo;
	}
	table->dead_flag = 1;
	return (0);
}

static int	ft_meals_checker(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->stats.num_philo)
	{
		if (table->philos[i].philo_meals < table->stats.num_meals)
			return (1);
		i++;
	}
	return (0);
}
