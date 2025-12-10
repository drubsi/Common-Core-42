/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by drubio-s          #+#    #+#             */
/*   Updated: 2025/10/27 10:48:40 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_env	*env_pair_from_line(const char *entry, size_t eq_pos)//
{
	char	*key;
	char	*value;
	t_env	*pair;

	if (!entry || eq_pos == 0 || entry[eq_pos] != '=')
		return (NULL);
	key = ft_substr(entry, 0, eq_pos);
	if (!key)
		return (NULL);
	value = ft_strdup(entry + eq_pos + 1);
	if (!value)
	{
		free (key);
		return (NULL);
	}
	pair = malloc(sizeof (t_env));
	if (!pair)
	{
		free (value);
		free (key);
		return (NULL);
	}
	pair->key = key;
	pair->value = value;
	return (pair);
}

static void	add_node_from_line(t_list **env_head, const char *line)
{
	int		eq_pos;
	t_env	*node_env;
	t_list	*new_node;

	eq_pos = env_equal_index(line);
	if (eq_pos > 0)
	{
		node_env = env_pair_from_line(line, (size_t)eq_pos);
		if (!node_env)
			return ;
		new_node = ft_lstnew(node_env);
		if (!new_node)
		{
			env_content_free(node_env);
			return ;
		}
		env_list_push_back(env_head, new_node);
	}
}

t_list	*env_build_from_envp(char **envp)
{
	int		i;
	t_list	*env_head;

	env_head = NULL;
	i = -1;
	if (!envp)
		return (NULL);
	while (envp[++i])
	{
		add_node_from_line(&env_head, envp[i]);
	}
	return (env_head);
}
