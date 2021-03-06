/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_table_destroy_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:40 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/25 14:37:13 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

void	ft_destroy_table(t_table *table)
{
	if (table->philos)
		free(table->philos);
	table->philos = NULL;
	if (table->pid)
		free(table->pid);
	table->pid = NULL;
}
