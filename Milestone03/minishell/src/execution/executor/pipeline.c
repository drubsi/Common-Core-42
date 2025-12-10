/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:46:25 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 23:34:20 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	create_pipeline_processes(t_mshl *data, pid_t *pid)
{
	int	prev_pipe[2];
	int	next_pipe[2];
	int	i;

	prev_pipe[0] = -1;
	prev_pipe[1] = -1;
	i = 0;
	while (i < data->pipeline->n_cmds)
	{
		next_pipe[0] = -1;
		next_pipe[1] = -1;
		if (i < (data->pipeline->n_cmds - 1))
			if (pipe(next_pipe) == -1)
				return (data->exit_status = 1,
					cleanup_on_pipe_error(pid, i -1, prev_pipe));
		pid[i] = fork ();
		if (pid[i] < 0)
			return (data->exit_status = 1,
				clean_on_fork_error(pid, i -1, prev_pipe, next_pipe));
		if (pid[i] == 0)
			launch_child(data, i, prev_pipe, next_pipe);
		switch_pipes_to_next(prev_pipe, next_pipe);
		i++;
	}
	return (0);
}

int	run_pipeline(t_mshl *data)
{
	pid_t	*pid;

	pid = malloc(data->pipeline->n_cmds * sizeof (pid_t));
	if (!pid)
	{
		data->exit_status = 1;
		return (1);
	}
	set_signals_parent_execution();
	if (create_pipeline_processes(data, pid) == 1)
	{
		free (pid);
		return (1);
	}
	wait_for_children(pid, data->pipeline->n_cmds, data);
	set_signals_interactive();
	free (pid);
	return (0);
}
