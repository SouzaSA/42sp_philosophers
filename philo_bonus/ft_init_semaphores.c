#include "ft_philo_bonus.h"

static int	ft_init_semaphore(sem_t	**sem, char *sem_name, int value);

int ft_init_semaphores(t_semaphores *semaphores, int num_philo)
{

	if (ft_init_semaphore(&semaphores->sem_fork, "sem_fork", num_philo))
		return (1);
	if (ft_init_semaphore(&semaphores->sem_print, "sem_print", 1))
	{
		sem_unlink("sem_fork");
		sem_close(semaphores->sem_fork);
		return (1);
	}
	if (ft_init_semaphore(&semaphores->sem_meals, "sem_meals", 1))
	{
		sem_unlink("sem_fork");
		sem_unlink("sem_print");
		sem_close(semaphores->sem_fork);
		sem_close(semaphores->sem_print);
		return (1);
	}
	return (0);
}

static int	ft_init_semaphore(sem_t	**sem, char *sem_name, int value)
{
	sem_unlink(sem_name);
	*sem = sem_open(sem_name, O_CREAT, S_IRWXU, value);
	if (*sem == SEM_FAILED)
	{
		sem_unlink(sem_name);
		*sem = sem_open(sem_name, O_CREAT, S_IRWXU, value);
		if (*sem == SEM_FAILED)
			return (1);
	}
	return (0);
}
