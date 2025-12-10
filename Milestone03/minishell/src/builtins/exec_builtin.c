/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:10:27 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/10 19:08:42 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	save_stdio(int *in_backup, int *out_backup)
{
	*in_backup = dup(STDIN_FILENO);
	*out_backup = dup(STDOUT_FILENO);
	if (*in_backup < 0 || *out_backup < 0)
		return (1);
	return (0);
}

static int	restore_stdio(int in_backup, int out_backup)
{
	int	saved;

	if (dup2(in_backup, STDIN_FILENO) == -1
		|| dup2(out_backup, STDOUT_FILENO) == -1)
	{
		saved = errno;
		close(in_backup);
		close(out_backup);
		put_error("minishell: dup2: ", strerror(saved), "\n");
		return (1);
	}
	close(in_backup);
	close(out_backup);
	return (0);
}

int	builtin_dispatch(t_mshl *data, t_cmd *cmd)
{
	if (ft_strncmp(cmd->argv[0], "env", 4) == 0)
		return (env_builtin(cmd->argv, data->env));
	else if (ft_strncmp(cmd->argv[0], "cd", 3) == 0)
		return (builtin_cd(cmd->argv, data->env));
	else if (ft_strncmp(cmd->argv[0], "unset", 6) == 0)
		return (builtin_unset(cmd->argv, &data->env));
	else if (ft_strncmp(cmd->argv[0], "export", 7) == 0)
		return (builtin_export(cmd->argv, &data->env));
	else if (ft_strncmp(cmd->argv[0], "pwd", 4) == 0)
		return (builtin_pwd());
	else if (ft_strncmp(cmd->argv[0], "echo", 5) == 0)
		return (builtin_echo(cmd->argv));
	else if (ft_strncmp(cmd->argv[0], "exit", 5) == 0)
		return (builtin_exit(data, cmd->argv));
	return (1);
}

int	exec_builtin_in_parent(t_mshl *data, t_cmd *cmd)
{
	int	status;
	int	fd_in_backup;
	int	fd_out_backup;

	status = 0;
	if (save_stdio(&fd_in_backup, &fd_out_backup) == 1)
	{
		data->exit_status = 1;
		return (1);
	}
	if (apply_redirs(cmd) == 1)
	{
		restore_stdio(fd_in_backup, fd_out_backup);
		data->exit_status = 1;
		return (1);
	}
	status = builtin_dispatch(data, cmd);
	if (restore_stdio(fd_in_backup, fd_out_backup) == 1)
	{
		data->exit_status = 1;
		return (1);
	}
	data->exit_status = status;
	return (0);
}
