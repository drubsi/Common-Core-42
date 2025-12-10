/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:23:54 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 20:01:45 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_space(char character)
{
	if (character == ' ' || character == '\n' || character == '\t'
		|| character == '\r' || character == '\v' || character == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ft_error("Invalid number arguments\n"));
	else if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 250)
		return (ft_error("Number of philosophers has to be > 0 & <= 250\n"));
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (ft_error("All parameters must be positive numbers\n"));
	else if (argc == 6)
		if (ft_atoi(argv[5]) < 1)
			return (ft_error("All parameters must be positive numbers\n"));
	while (argv[i])
	{
		if (is_digit(argv[i]) == 1)
		{
			printf("Error\n");
			return (ft_error(""));
		}
		i++;
	}
	return (0);
}

int	is_digit(char *argv)
{
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
			argv++;
		else
			return (1);
	}
	return (0);
}

int	ft_error(const char *arg)
{
	printf ("%s", arg);
	return (1);
}
