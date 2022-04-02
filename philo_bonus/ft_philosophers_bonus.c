/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/04/02 23:58:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static void	*ft_waiter(void *table_void);
static int	ft_create_philo_processess(t_table *table);

int	ft_philosophers(t_table	*table)
{
	if (ft_init_semaphores(&table->semaphores, table->stats.num_philo))
		return (1);
	table->time_start = ft_get_time_msec();
	if (ft_create_philo_processess(table))
		return (1);
	if (pthread_create(&table->meals_watcher, NULL, &ft_waiter, (void *)table))
		return (1);
	wait(NULL);
	ft_destroy_semaphores(&table->semaphores);
	pthread_join(table->meals_watcher, NULL);
	ft_destroy_table(table);
	return (0);
}

static void	*ft_waiter(void *table_void)
{
	t_table	*table;
	int		counter;

	table = (t_table *)table_void;
	counter = 0;
	while (counter < table->stats.num_philo)
	{
		sem_wait(table->semaphores.sem_meals);
		counter++;
	}
	while (--counter >= 0)
		kill(table->pid[counter], SIGKILL);
	return (NULL);
}

static int	ft_create_philo_processess(t_table *table)
{
	int	i;

	i = 0;
	table->pid = malloc(table->stats.num_philo * sizeof(pid_t));
	if (!table->pid)
		return (1);
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
	return (0);
}
