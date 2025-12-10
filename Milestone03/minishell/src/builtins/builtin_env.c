/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:46:13 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 09:59:38 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_builtin(char **argv, t_list *env_list)
{
	t_env	*pair;

	if (argv[1] != NULL)
	{
		ft_putstr_fd("minishell: env: '", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("': No such file or directory\n", 2);
		return (127);
	}
	while (env_list)
	{
		pair = (t_env *)env_list->content;
		ft_putstr_fd(pair->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(pair->value, 1);
		ft_putstr_fd("\n", 1);
		env_list = env_list->next;
	}
	return (0);
}
