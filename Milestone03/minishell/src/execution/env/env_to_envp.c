/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:24:36 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 13:17:34 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**free_partial_env(char **env, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(env[i]);
		i++;
	}
	free (env);
	return (NULL);
}

static char	*join_pair(t_env *node)
{
	char	*line;
	char	*temp_key;
	char	*temp_value;

	if (!node)
		return (NULL);
	temp_key = ft_strjoin(node->key, "=");
	if (!temp_key)
		return (NULL);
	temp_value = node->value;
	if (!node->value)
		temp_value = "";
	line = ft_strjoin(temp_key, temp_value);
	if (!line)
	{
		free (temp_key);
		return (NULL);
	}
	free (temp_key);
	return (line);
}

char	**env_to_envp(t_list *env_list)
{
	int		i;
	int		size;
	char	**env;
	t_env	*pair;

	size = ft_lstsize(env_list);
	env = malloc((size + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (env_list)
	{
		pair = env_list->content;
		env[i] = join_pair(pair);
		if (!env[i])
			return (free_partial_env(env, i));
		i++;
		env_list = env_list->next;
	}
	env[i] = NULL;
	return (env);
}
