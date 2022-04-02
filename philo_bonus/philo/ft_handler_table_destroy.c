/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_table_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:40 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 11:46:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_destroy_table(t_table *table)
{
	if (table->philos)
		free(table->philos);
	table->philos = NULL;
	if (table->forks_mtx)
		free(table->forks_mtx);
	table->forks_mtx = NULL;
}
