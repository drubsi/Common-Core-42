/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:37:25 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 10:09:28 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	keys_equal(const char *key_a, const char *key_b)
{
	int	i;

	i = 0;
	if (!key_a || !key_b)
		return (0);
	while (key_a[i] || key_b[i])
	{
		if (key_a[i] != key_b[i])
			return (0);
		i++;
	}
	return (1);
}

int	env_equal_index(const char *line)
{
	int		eq_idx;

	eq_idx = 0;
	if (!line)
		return (-1);
	while (line[eq_idx])
	{
		if (line[eq_idx] == '=')
			return (eq_idx);
		eq_idx++;
	}
	return (-1);
}

void	env_list_push_back(t_list **env_head, t_list *node)
{
	if (!env_head || !node)
		return ;
	ft_lstadd_back(env_head, node);
}
