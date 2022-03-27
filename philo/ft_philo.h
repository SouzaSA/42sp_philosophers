/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:47 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 01:30:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define PHILO_ALIVE 0
# define PHILO_DIED 1
# define PHILO_PLEASED 2

typedef struct s_stats
{
	int		num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		meals_counter;
	int		num_meals;
}	t_stats;

typedef struct s_philo
{
	int				id;
	int				*dead_flag;
	int				philo_meals;
	long			time_meal;
	long			*time_start;
	t_stats			*stats;
	pthread_t		phi_t;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*critical_mtx;
	pthread_mutex_t	*death_mtx;
	pthread_mutex_t	meal_mtx;
}	t_philo;

typedef struct s_table
{
	int				dead_flag;
	long			time_start;
	t_stats			stats;
	pthread_mutex_t	critical_mtx;
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	*forks_mtx;
	t_philo			*philos;
}	t_table;

int		ft_atoi(const char *nptr);
int		ft_check_args(char **argv);
void	ft_destroy_forks_mutex(t_table *table, int amount);
void	ft_destroy_philo_threads(t_table *table, int amount);
void	*ft_dinner(void *table_void);
void	ft_get_death_flag(t_philo *philo, int *flag);
void	ft_get_last_meal_time(t_philo *philo, long *time);
void	ft_get_last_meal_num(t_philo *philo, int *num);
long	ft_get_time_msec(void);
void	ft_destroy_table(t_table *table);
int		ft_load_table(int argc, char **argv, t_table *table);
int		ft_load_philos(t_table *table, t_philo **philos, t_stats *stats);
int		ft_philosophers(t_table	*table);
void	ft_exec_critical_action(char *msg, t_philo *philo, int status_flag);
void	ft_set_death_flag(int *dead_flag, pthread_mutex_t *death_mtx);
void	ft_set_last_meal_time(t_philo *philo);
void	ft_set_last_meal(t_philo *philo);
size_t	ft_strlen(const char *s);

#endif
