/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:11:59 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 15:08:33 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_numeric(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(t_mshl *data, char **argv)
{
	long	code;

	if (data->interactive == 1)
		ft_putstr_fd("exit\n", 1);
	data->should_exit = 1;
	if (!argv[1])
		return (0);
	if (!is_numeric(argv[1]))
	{
		put_error("minishell: exit: ",
			argv[1], ": numeric argument required\n");
		data->exit_status = 2;
		return (2);
	}
	if (argv[2])
	{
		put_error("minishell: exit: too many arguments\n", "", "");
		data->should_exit = 0;
		data->exit_status = 1;
		return (1);
	}
	code = ft_atoi(argv[1]);
	return (data->exit_status = (unsigned char)code);
}
