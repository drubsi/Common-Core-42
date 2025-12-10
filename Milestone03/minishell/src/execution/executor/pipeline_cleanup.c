/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_cleanup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:47:37 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 18:35:05 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	cleanup_on_pipe_error(pid_t *pid, int last_index, int prev_pipe[2])
{
	int	status;

	while (last_index >= 0)
	{
		waitpid (pid[last_index], &status, 0);
		last_index--;
	}
	close_pipe_if_open(prev_pipe);
	return (1);
}

int	clean_on_fork_error(pid_t *pid, int last_index,
	int prev_pipe[2], int next_pipe[2])
{
	int	status;

	while (last_index >= 0)
	{
		waitpid (pid[last_index], &status, 0);
		last_index--;
	}
	close_pipe_if_open(prev_pipe);
	close_pipe_if_open(next_pipe);
	return (1);
}

void	switch_pipes_to_next(int prev_pipe[2], int next_pipe[2])
{
	close_pipe_if_open(prev_pipe);
	prev_pipe[0] = next_pipe[0];
	prev_pipe[1] = next_pipe[1];
	next_pipe[0] = -1;
	next_pipe[1] = -1;
}
