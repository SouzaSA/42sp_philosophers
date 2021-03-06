/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:46 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/21 15:56:14 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_all_char_valid(char **argv);
static int	ft_all_int_valid(char **argv);
static int	ft_number_converter_abs_dif(char *charnum, int number);

int	ft_check_args(char **argv)
{
	int	is_valid;

	is_valid = ft_all_char_valid(argv);
	if (is_valid)
		is_valid = ft_all_int_valid(argv);
	return (is_valid);
}

static int	ft_all_char_valid(char **argv)
{
	int	i;
	int	j;
	int	is_valid;

	i = 1;
	is_valid = 1;
	while (is_valid && argv[i])
	{
		j = 0;
		while (is_valid && argv[i][j])
		{
			if (j == 0 && argv[i][0] == '+')
				j++;
			if (argv[i][j] && (argv[i][j] < '0' || argv[i][j] > '9'))
				is_valid = 0;
			j++;
		}
		i++;
	}
	return (is_valid);
}

static int	ft_all_int_valid(char **argv)
{
	int		i;
	int		is_valid;
	long	number;

	i = 1;
	is_valid = 1;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number < 0 || ft_number_converter_abs_dif(argv[i], number) > 2)
			is_valid = 0;
		i++;
	}
	return (is_valid);
}

static int	ft_number_converter_abs_dif(char *charnum, int number)
{
	int	charnum_size;
	int	number_size;

	charnum_size = ft_strlen(charnum);
	number_size = 0;
	if (number == 0)
		number_size = 1;
	while (number > 0)
	{
		number_size++;
		number /= 10;
	}
	if (number_size > charnum_size)
		return (number_size - charnum_size);
	else
		return (charnum_size - number_size);
}
