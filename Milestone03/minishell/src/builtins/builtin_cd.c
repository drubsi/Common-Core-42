/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:09:02 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/10 19:15:27 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_args(char **argv)
{
	if (argv[1] && argv[2] != NULL)
	{
		put_error("minishell: ", "cd: ", "too many arguments\n");
		return (1);
	}
	return (0);
}

static int	ch_chdir_error(char *target, char *old_value)
{
	int	saved;

	saved = errno;
	if (old_value != NULL)
		free(old_value);
	put_error("minishell: cd: ", target, ": ");
	ft_putstr_fd(strerror(saved), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static char	*cd_get_target(char **argv, t_list *env)
{
	t_env	*pair;

	if (argv[1] != NULL)
	{
		if (ft_strncmp(argv[1], "-", 2) == 0)
		{
			pair = env_get_pair(env, "OLDPWD");
			if (!pair || !pair->value)
			{
				put_error("minishell: ", "cd: ", "OLDPWD not set\n");
				return (NULL);
			}
			ft_putstr_fd(pair->value, 1);
			ft_putstr_fd("\n", 1);
			return (pair->value);
		}
		return (argv[1]);
	}
	pair = env_get_pair(env, "HOME");
	if (pair == NULL || pair->value == NULL)
	{
		put_error("minishell: ", "cd: ", "HOME not set\n");
		return (NULL);
	}
	return (pair->value);
}

static void	cd_update_env(t_list *env, char *old_value, char *new_pwd)
{
	t_env	*node;

	if (old_value != NULL)
	{
		node = env_get_pair(env, "OLDPWD");
		if (node != NULL)
			env_update_value(node, old_value);
	}
	if (new_pwd != NULL)
	{
		node = env_get_pair(env, "PWD");
		if (node != NULL)
			env_update_value(node, new_pwd);
	}
}

int	builtin_cd(char **argv, t_list *env)
{
	char	*pwd;
	t_env	*old_node;
	char	*old_value;
	char	*target;

	if (check_args(argv) == 1)
		return (1);
	target = cd_get_target(argv, env);
	if (target == NULL)
		return (1);
	old_node = env_get_pair(env, "PWD");
	if (old_node != NULL)
		old_value = ft_strdup(old_node->value);
	else
		old_value = NULL;
	if (chdir(target) != 0)
		return (ch_chdir_error(target, old_value));
	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		cd_update_env(env, old_value, pwd);
		free (pwd);
	}
	free (old_value);
	return (0);
}
