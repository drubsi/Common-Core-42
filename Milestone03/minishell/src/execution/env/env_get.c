/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:48:26 by drubio-s          #+#    #+#             */
/*   Updated: 2025/10/27 10:50:21 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

const char	*env_get(t_list *env, const char *key)
{
	t_env	*content;

	if (!key || key[0] == '\0')
		return (NULL);
	while (env)
	{
		content = env->content;
		if (content && content->key && keys_equal(content->key, key))
			return (content->value);
		env = env->next;
	}
	return (NULL);
}

t_env	*env_get_pair(t_list *env, const char *key)
{
	t_env	*content;

	if (!key || key[0] == '\0')
		return (NULL);
	while (env)
	{
		content = env->content;
		if (content && content->key && keys_equal(content->key, key))
			return (content);
		env = env->next;
	}
	return (NULL);
}
