/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_philo_threads.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:52:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/21 13:28:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_destroy_philo_threads(t_table *table, int amount)
{
	int	i;

	i = 0;
	table->dead_flag = 1;
	while (i < amount)
	{
		pthread_mutex_unlock(table->philos[i].left_fork);
		pthread_mutex_unlock(table->philos[i].right_fork);
		pthread_mutex_unlock(&table->print_mtx);
		pthread_join(table->philos[i].phi_t, NULL);
		i++;
	}
}
