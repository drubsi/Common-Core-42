/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:24:32 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/13 12:21:24 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	close_cmd_heredocs(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->n_redirs)
	{
		if (cmd->redirs[i].type == R_HEREDOC && cmd->redirs[i].hd_fd >= 0)
		{
			close(cmd->redirs[i].hd_fd);
			cmd->redirs[i].hd_fd = -1;
		}
		i++;
	}
}

static int	prepare_cmd_heredocs(t_cmd *cmd, t_mshl *data)
{
	int	i;

	i = 0;
	while (i < cmd->n_redirs)
	{
		if (cmd->redirs[i].type == R_HEREDOC)
		{
			if (create_heredoc_fd(&cmd->redirs[i], data) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	prepare_all_heredocs(t_mshl *data)
{
	int	i;

	i = 0;
	while (i < data->pipeline->n_cmds)
	{
		if (prepare_cmd_heredocs(&data->pipeline->cmds[i], data) == 1)
		{
			while (--i >= 0)
				close_cmd_heredocs(&data->pipeline->cmds[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	close_all_heredocs(t_mshl *data)
{
	int	i;

	i = 0;
	while (i < data->pipeline->n_cmds)
	{
		close_cmd_heredocs(&data->pipeline->cmds[i]);
		i++;
	}
}
