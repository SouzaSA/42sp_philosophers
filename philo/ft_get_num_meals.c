/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num_meals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:10:01 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/27 23:36:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_get_last_meal_num(t_philo *philo, int *num)
{
	pthread_mutex_lock(&philo->meal_mtx);
	*num = philo->philo_meals;
	pthread_mutex_unlock(&philo->meal_mtx);
}
