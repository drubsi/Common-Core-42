/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:48:40 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 23:36:55 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	setup_pipes_for_child(int index, int total_cmds,
	int prev_pipe[2], int next_pipe[2])
{
	if (index == 0)
	{
		dup2(next_pipe[1], STDOUT_FILENO);
		close_pipe_if_open(next_pipe);
		close_pipe_if_open(prev_pipe);
	}
	else if (index < total_cmds - 1)
	{
		dup2(prev_pipe[0], STDIN_FILENO);
		dup2(next_pipe[1], STDOUT_FILENO);
		close_pipe_if_open(next_pipe);
		close_pipe_if_open(prev_pipe);
	}
	else
	{
		dup2(prev_pipe[0], STDIN_FILENO);
		close_pipe_if_open(prev_pipe);
	}
}

void	launch_child(t_mshl *data, int index,
	int prev_pipe[2], int next_pipe[2])
{
	set_signals_child();
	setup_pipes_for_child(index, data->pipeline->n_cmds, prev_pipe, next_pipe);
	if (apply_redirs(&data->pipeline->cmds[index]) == 1)
		exit (1);
	run_command(data, &data->pipeline->cmds[index]);
}
