/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:51:55 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/13 20:28:51 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	wait_for_children(pid_t *pid, int n_cmds, t_mshl *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < n_cmds)
	{
		waitpid (pid[i], &status, 0);
		i++;
	}
	update_exit_status_from_status(status, data);
}

void	update_exit_status_from_status(int status, t_mshl *data)
{
	int	sig;

	if (WIFEXITED(status))
		data->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		data->exit_status = 128 + sig;
		if (sig == SIGINT)
			write(1, "\n", 1);
		else if (sig == SIGQUIT)
			write(1, "Quit (core dumped)\n", 19);
	}
}
