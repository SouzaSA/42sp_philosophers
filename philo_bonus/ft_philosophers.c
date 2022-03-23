/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/22 21:15:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static void	*ft_meals_watcher(void *table_void);

int	ft_philosophers(t_table	*table)
{
	int		i;

	if (ft_init_semaphores(&table->semaphores, table->stats.num_philo))
		return (1);
	if (table->stats.meals_counter)
	{
		if (pthread_create(&table->meals_watcher, NULL, &ft_meals_watcher, \
			(void *)table))
			return (1);
	}
	table->pid = malloc(table->stats.num_philo * sizeof(pid_t));
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
			ft_dinner(&table->philos[i]);

		i++;
	}
	wait(NULL);
	return (0);
}

static void	*ft_meals_watcher(void *table_void)
{
	t_table	*table;
	int		counter;

	table = (t_table *)table_void;
	counter = 0;
	while (counter < table->stats.num_philo)
	{
		sem_wait(table->semaphores.sem_meals);
		counter ++;
	}
	while (--counter >= 0)
		kill(table->pid[counter], SIGKILL);
	return (NULL);
}
