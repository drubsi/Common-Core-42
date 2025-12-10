/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:08 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 13:16:55 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_args_export(char *argv)
{
	int	i;

	i = 1;
	if (argv == NULL)
		return (1);
	if (argv[0] != '_' && ft_isalpha(argv[0]) == 0)
	{
		put_error("minishell: ", "export: ", argv);
		ft_putstr_fd(": not a valid identifier\n", 2);
		return (1);
	}
	while (argv[i])
	{
		if (argv[i] == '=')
			break ;
		else if ((ft_isalnum(argv[i]) == 0 && argv[i] != '_'))
		{
			put_error("minishell: ", "export: ", argv);
			ft_putstr_fd(": not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	export_print_list(t_list *env)
{
	t_env	*pair;

	while (env)
	{
		pair = (t_env *)env->content;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(pair->key, 1);
		if (pair->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(pair->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}

int	export_split_kv(char *arg, char **key_text, const char **val, int eq_pos)
{
	if (eq_pos >= 0)
	{
		*key_text = ft_substr(arg, 0, eq_pos);
		if (!*key_text)
			return (1);
		*val = arg + eq_pos + 1;
	}
	else
	{
		*key_text = ft_strdup(arg);
		if (!*key_text)
			return (1);
		*val = NULL;
	}
	return (0);
}

int	export_create_var(t_list **env, char *key_text, const char *value_text)
{
	t_env	*pair;
	t_list	*node;

	pair = env_pair_from_key(key_text, value_text);
	if (!pair)
		return (1);
	node = ft_lstnew(pair);
	if (!node)
	{
		env_content_free(pair);
		return (1);
	}
	env_list_push_back(env, node);
	return (0);
}

int	export_update_var(t_env *pair, int eq_pos, const char *value_text)
{
	if (eq_pos < 0)
		return (0);
	if (env_update_value(pair, value_text) != 0)
		return (1);
	return (0);
}
