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
}	t_philo;

typedef struct s_table
{
	int				dead_flag;
	long			time_start;
	t_stats			stats;
	t_philo			*philos;
}	t_table;
#endif
