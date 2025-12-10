/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:09:41 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/13 09:34:25 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	exec_pipeline(t_mshl *data)
{
	int	ret;

	ret = 0;
	if (data->pipeline->cmds == NULL || data->pipeline->cmds->argv == NULL
		|| data->pipeline->cmds->argv[0] == NULL)
		return (data->exit_status);
	if (prepare_all_heredocs(data) == 1)
		return (1);
	if (data->pipeline->n_cmds == 1 && data->pipeline->cmds[0].is_builtin == 1)
		ret = exec_builtin_in_parent(data, &data->pipeline->cmds[0]);
	else if (data->pipeline->n_cmds == 1
		&& data->pipeline->cmds[0].is_builtin == 0)
		ret = exec_external(data, &data->pipeline->cmds[0]);
	else if (data->pipeline->n_cmds >= 2)
		ret = run_pipeline(data);
	close_all_heredocs(data);
	return (ret);
}
