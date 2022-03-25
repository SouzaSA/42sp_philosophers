/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:34 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/25 14:38:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_BONUS_H
# define FT_PHILO_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_stats
{
	int		num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		meals_counter;
	int		num_meals;
}	t_stats;

typedef struct s_semaphores
{
	sem_t	*sem_fork;
	sem_t	*sem_print;
	sem_t	*sem_meals;
}	t_semaphores;

typedef struct s_philo
{
	int				id;
	int				alive;
	int				philo_meals;
	long			time_meal;
	long			*time_start;
	t_stats			*stats;
	pthread_t		phi_t;
	t_semaphores	*semaphores;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	long			time_start;
	pthread_t		meals_watcher;
	t_semaphores	semaphores;
	pid_t			*pid;
	t_stats			stats;
	t_philo			*philos;
}	t_table;

int		ft_atoi(const char *nptr);
int		ft_check_args(char **argv);
void	ft_destroy_semaphores(t_semaphores *semaphores);
void	ft_dinner(t_philo *philo);
long	ft_get_time_msec(void);
int		ft_load_philos(t_table *table, t_philo **philos, t_stats *stats);
void	ft_destroy_table(t_table *table);
int		ft_load_table(int argc, char **argv, t_table *table);
int		ft_init_semaphores(t_semaphores *semaphores, int num_philo);
int		ft_philosophers(t_table	*table);
void	ft_put_msg(char *msg, t_philo *philo, int flag);
size_t	ft_strlen(const char *s);

#endif
