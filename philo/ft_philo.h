/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:47 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 12:09:32 by sde-alva         ###   ########.fr       */
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

enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
};

typedef struct s_stats
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_meals;
}	t_stats;

typedef struct s_philo
{
	int				id;
	int				philo_meals;
	enum e_state	philo_status;
	long			time_meal;
	long			time_dead;
	long			time_sleep;
	long			time_stamp;
	long			time_start;
	pthread_t		phi_t;
}	t_philo;

typedef struct s_table
{
	int				pth_id;
	int				dead_flag;
	t_stats			stats;
	t_philo			*philos;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	mtx;
}	t_table;

int		ft_atoi(const char *nptr);
int		ft_check_args(char **argv);
long	ft_get_time_msec(void);
void	ft_destroy_table(t_table *table);
int		ft_load_table(int argc, char **argv, t_table *table);
int		ft_philosophers(t_table	*table);
size_t	ft_strlen(const char *s);
int		ft_load_philos(t_philo **philos, t_stats *stats);

#endif
