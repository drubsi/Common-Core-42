/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:23:53 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 23:45:08 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	export_prepare_arg(char *arg, char **key, const char **value,
		int *eq_pos)
{
	*eq_pos = env_equal_index(arg);
	if (check_args_export(arg) == 1)
		return (1);
	if (export_split_kv(arg, key, value, *eq_pos) == 1)
		return (1);
	return (0);
}

static int	export_apply_arg(t_list **env, char *key_text, const char *val,
		int eq_pos)
{
	t_env	*pair;

	pair = env_get_pair(*env, key_text);
	if (!pair)
	{
		if (export_create_var(env, key_text, val) == 1)
			return (1);
	}
	else
	{
		if (export_update_var(pair, eq_pos, val) == 1)
			return (1);
	}
	return (0);
}

static int	export_process_arg(char *arg, t_list **env)
{
	int			eq_pos;
	char		*key_text;
	const char	*value_text;

	if (export_prepare_arg(arg, &key_text, &value_text, &eq_pos) == 1)
		return (1);
	if (export_apply_arg(env, key_text, value_text, eq_pos) == 1)
	{
		free(key_text);
		return (1);
	}
	free(key_text);
	return (0);
}

int	builtin_export(char **argv, t_list **env)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (argv[1] == NULL)
	{
		export_print_list(*env);
		return (0);
	}
	while (argv[++i])
	{
		if (export_process_arg(argv[i], env) == 1)
			status = 1;
	}
	return (status);
}
