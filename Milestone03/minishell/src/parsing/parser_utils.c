/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:22:04 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 13:20:33 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_strings(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_strings(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	has_empty_pipe_cmds(char **cmds, int n_cmds)
{
	int	i;

	i = 0;
	while (i < n_cmds)
	{
		if (!cmds[i] || *cmds[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
