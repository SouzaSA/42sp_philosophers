/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:38:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/18 11:39:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_atoi_err(int signal);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		signal;
	long	result;
	long	prev;

	i = 0;
	signal = -1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13 && nptr[i] != '\0'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		prev = result;
		result = result * 10 - (nptr[i] - '0');
		if (prev < result)
			return (ft_atoi_err(signal));
		i++;
	}
	return (signal * result);
}

static int	ft_atoi_err(int signal)
{
	int	err_val;

	err_val = 0;
	if (signal < 0)
		err_val = -1;
	return (err_val);
}
