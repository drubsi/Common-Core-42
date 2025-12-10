/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:23:33 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/28 10:31:50 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_pipeline	*alloc_pipeline(int n_cmds)
{
	t_pipeline	*pipeline;

	pipeline = malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->n_cmds = n_cmds;
	pipeline->cmds = malloc(sizeof(t_cmd) * n_cmds);
	if (!pipeline->cmds)
	{
		free(pipeline);
		return (NULL);
	}
	return (pipeline);
}

void	fill_pipeline_cmds(t_pipeline *pipeline, char **cmds, t_mshl *data)
{
	int	i;

	i = 0;
	while (i < pipeline->n_cmds)
	{
		pipeline->cmds[i] = parse_cmd(cmds[i], data);
		i++;
	}
}
