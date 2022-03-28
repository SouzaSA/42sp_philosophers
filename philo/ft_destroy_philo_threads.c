/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_philo_threads.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:52:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 12:28:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_destroy_philo_threads(t_table *table, int amount)
{
	int	i;

	i = 0;
	ft_set_death_flag(&table->dead_flag, &table->critical_mtx);
	while (i < amount)
	{
		pthread_join(table->philos[i].phi_t, NULL);
		i++;
	}
}
