/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/28 15:46:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if ((argc == 5 || argc == 6) && ft_check_args(argv))
	{
		if (ft_load_table(argc, argv, &table))
		{
			write(2, "error: invalid variables\n", 26);
			return (1);
		}
		ft_philosophers(&table);
	}
	else
	{
		write(2, "error: invalid parameters\n", 27);
		return (1);
	}
	ft_destroy_table(&table);
	return (0);
}
