/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:26:57 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/25 14:37:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if ((argc == 5 || argc == 6) && ft_check_args(argv))
	{
		if (ft_load_table(argc, argv, &table))
		{
			write(2, "error: can't load variables\n", 29);
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
