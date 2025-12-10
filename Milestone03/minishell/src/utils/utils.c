/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:41:26 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 23:46:05 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	put_error(char *a, char *b, char *c)
{
	ft_putstr_fd(a, 2);
	ft_putstr_fd(b, 2);
	ft_putstr_fd(c, 2);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (cmd->argv)
	{
		i = 0;
		while (cmd->argv[i])
		{
			free (cmd->argv[i]);
			i++;
		}
		free (cmd->argv);
	}
	if (cmd->redirs)
	{
		i = 0;
		while (i < cmd->n_redirs)
		{
			free (cmd->redirs[i].target);
			i++;
		}
		free(cmd->redirs);
	}
}

void	free_pipeline(t_pipeline *pipeline)
{
	int	i;

	i = 0;
	if (!pipeline)
		return ;
	while (i < pipeline->n_cmds)
	{
		free_cmd(&pipeline->cmds[i]);
		i++;
	}
	free (pipeline->cmds);
	free(pipeline);
}

void	handle_signals_in_loop(t_mshl *data)
{
	if (g_signal_received == SIGINT)
	{
		data->exit_status = 130;
		g_signal_received = 0;
	}
	if (g_signal_received == SIGQUIT)
	{
		data->exit_status = 131;
		g_signal_received = 0;
	}
}
