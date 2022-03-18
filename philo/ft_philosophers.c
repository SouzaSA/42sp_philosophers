/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:47:57 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 12:28:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_philosophers(t_table	*table)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&table->mtx);
	while (i < table->stats.num_philo)
	{
		table->pth_id = i;
		table->philos[i].id = i;
		pthread_create(&table->philos[i].phi_t, NULL, ft_dinner, (void *)table);
		i++;
	}
	i = 0;
	while (i < table->stats.num_philo)
	{
		pthread_join(table->philos[i].phi_t, NULL);
		i++;
	}
	i = 0;
	while (i < table->stats.num_philo)
	{
		pthread_mutex_destroy(&table->forks_mtx[i]);
		i++;
	}
	ft_destroy_table(table);
	return (0);
}

static void	*ft_dinner(void *table_void)
{
	int		philo_id;
	t_table	*table;

	table = (t_table *)table_void;
	philo_id = table->pth_id;
	if (philo_id % 2)
		usleep(100);
	while (!table->dead_flag)
	{

	}
}
