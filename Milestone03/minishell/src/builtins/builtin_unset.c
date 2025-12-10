/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:49:44 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/28 09:08:08 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_args_unset(char *argv)
{
	int	i;

	i = 1;
	if (argv == NULL)
		return (1);
	if (argv[0] != '_' && ft_isalpha(argv[0]) == 0)
		return (1);
	while (argv[i])
	{
		if ((ft_isalnum(argv[i]) == 0 && argv[i] != '_') || argv[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static void	unset_one_key(t_list **env, char *key)
{
	t_list	*current;
	t_list	*previous;
	t_env	*pair;

	current = *env;
	previous = NULL;
	while (current)
	{
		pair = (t_env *)current->content;
		if (keys_equal(pair->key, key) == 1)
		{
			if (!previous)
				*env = current->next;
			else
				previous->next = current->next;
			env_content_free(current->content);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

int	builtin_unset(char **argv, t_list **env)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	while (argv[++i])
	{
		if (check_args_unset(argv[i]) == 1)
			continue ;
		unset_one_key(env, argv[i]);
	}
	return (status);
}
