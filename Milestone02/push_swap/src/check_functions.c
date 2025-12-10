/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:26:38 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 08:42:55 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int_min_max(int size, long int *number_list)
{
	int			n;

	n = 0;
	while (n < size)
	{
		if (number_list[n] > 2147483647 || number_list[n] < -2147483648)
		{
			free (number_list);
			ft_error_1 ();
		}
		n++;
	}
}

void	check_no_number(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			ft_error_1 ();
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			j++;
			if (argv[i][j] == '\0')
				ft_error_1 ();
		}
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				ft_error_1 ();
			j++;
		}
		i++;
	}
}

void	check_duplicate_number(int size, long int *number_list)
{
	int			i;
	int			j;
	long int	actual_number;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		actual_number = number_list[i];
		while (j < size)
		{
			if (actual_number == number_list[j])
			{
				free (number_list);
				ft_error_1 ();
			}
			else
				j++;
		}
		i++;
	}
}

void	check_order_arg(int size, long int *number_list)
{
	int	i;

	i = 0;
	if (size <= 1)
	{
		free (number_list);
		exit (0);
	}
	while (i < size - 1)
	{
		if (number_list[i] > number_list[i + 1])
			return ;
		i++;
	}
	free (number_list);
	exit (0);
}

void	convert_to_numbers_and_validate_args(int argc, const char **argv)
{
	int			i;
	int			j;
	long int	*number_list;
	int			size;

	if (argc < 2)
		exit (1);
	size = argc - 1;
	check_no_number(argc, argv);
	number_list = (long int *)malloc((argc - 1) * sizeof(long int));
	i = 1;
	j = 0;
	while (i < argc)
	{
		number_list[j] = ft_atol(argv[i]);
		i++;
		j++;
	}
	check_arg(size, number_list);
	free (number_list);
}
