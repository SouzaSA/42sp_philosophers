/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 11:46:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int main(int argc, char **argv)
{
	t_table table;

	if ((argc == 5 || argc == 6) && ft_check_args(argv))
	{
		if (ft_load_table(argc, argv, &table))
		{
			ft_error_put_msg("error: can't load variables");
			return (1);
		}
		ft_philosophers(&table);
	}
	else
	{
		ft_error_put_msg("error: invalid parameters");
		return (1);
	}
	return (0);
}
