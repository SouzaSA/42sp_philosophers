/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_death_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/27 23:38:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_get_death_flag(t_philo *philo, int *flag)
{
	pthread_mutex_lock(philo->death_mtx);
	*flag = *philo->dead_flag;
	pthread_mutex_unlock(philo->death_mtx);
}
