/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:39:41 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/28 10:32:28 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_pipeline	*parse_line(char *line, t_mshl *data)
{
	t_pipeline	*pipeline;
	char		**cmds;
	int			n_cmds;

	cmds = split_pipes_outside_quotes(line);
	n_cmds = count_strings(cmds);
	if (has_empty_pipe_cmds(cmds, n_cmds))
	{
		ft_putstr_fd("Error: empty pipe command\n", 2);
		data->exit_status = 2;
		free_strings(cmds);
		return (NULL);
	}
	pipeline = alloc_pipeline(n_cmds);
	if (!pipeline)
	{
		free_strings(cmds);
		return (NULL);
	}
	fill_pipeline_cmds(pipeline, cmds, data);
	free_strings(cmds);
	return (pipeline);
}
