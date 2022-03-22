#include "ft_philo_bonus.h"

void	ft_destroy_semaphores(t_semaphores *semaphores)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_meals");
	sem_close(semaphores->sem_fork);
	sem_close(semaphores->sem_print);
	sem_close(semaphores->sem_meals);
}
