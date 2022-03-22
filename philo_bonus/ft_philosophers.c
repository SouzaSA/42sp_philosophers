/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/21 21:23:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

int	ft_philosophers(t_table	*table)
{
	int		i;

	if (table->stats.meals_counter)
	{
		//TODO thread counter
	}
	table->pid = ft_calloc(table->stats.num_philo, sizeof(pid_t));
	i = 0;
	while (i < table->stats.num_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] == -1)
		{
			free(table->pid);
			return (1);
		}
		else if (table->pid[i] == 0)
			//TODO call dinner
		i++;
	}
	//TODO parent
	return (0);
}
