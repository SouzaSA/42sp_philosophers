/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_death_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:14 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 00:03:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_set_death_flag(int *dead_flag, pthread_mutex_t *death_mtx)
{
	pthread_mutex_lock(death_mtx);
	*dead_flag = 1;
	pthread_mutex_unlock(death_mtx);
}
