/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:28:51 by drubio-s          #+#    #+#             */
/*   Updated: 2025/10/06 12:25:43 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	env_content_free(void *content)
{
	t_env	*pair;

	pair = (t_env *)content;
	if (!pair)
		return ;
	free (pair->value);
	free (pair->key);
	free (pair);
}

void	list_content_free(t_list **head)
{
	ft_lstclear(head, env_content_free);
}

void	envp_free(char **copy_envp)
{
	int	i;

	i = 0;
	while (copy_envp[i])
	{
		free(copy_envp[i]);
		i++;
	}
	free (copy_envp);
}
