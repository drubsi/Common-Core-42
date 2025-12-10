/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:08 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 12:17:47 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*dup_value_text(const char *value, char *key_text, t_env *node)
{
	char	*value_text;

	value_text = ft_strdup(value);
	if (!value_text)
	{
		free(key_text);
		free(node);
		return (NULL);
	}
	return (value_text);
}

t_env	*env_pair_from_key(const char *key, const char *value)
{
	t_env	*node_pair;
	char	*key_text;
	char	*value_text;

	value_text = NULL;
	key_text = ft_strdup(key);
	if (!key_text)
		return (NULL);
	node_pair = malloc(sizeof (t_env));
	if (!node_pair)
	{
		free (key_text);
		return (NULL);
	}
	node_pair->key = key_text;
	if (value)
	{
		value_text = dup_value_text(value, key_text, node_pair);
		if (!value_text)
			return (NULL);
	}
	node_pair->value = value_text;
	return (node_pair);
}

int	env_update_value(t_env *node, const char *new_val)
{
	char	*dup;

	if (node == NULL)
		return (1);
	if (new_val == NULL)
	{
		if (node->value != NULL)
			free (node->value);
		node->value = NULL;
		return (0);
	}
	dup = ft_strdup(new_val);
	if (dup == NULL)
		return (1);
	if (node->value != NULL)
		free (node->value);
	node->value = dup;
	return (0);
}
