/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:10:24 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/26 12:01:28 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	handle_path_with_slash(t_mshl *data, t_cmd *cmd)
{
	struct stat	st;

	if (access(cmd->argv[0], F_OK) != 0)
	{
		print_no_such(cmd->argv[0]);
		data->exit_status = 127;
		return (0);
	}
	else if (stat(cmd->argv[0], &st) == 0 && S_ISDIR(st.st_mode))
	{
		print_is_dir(cmd->argv[0]);
		data->exit_status = 126;
		return (0);
	}
	else if (access(cmd->argv[0], X_OK) != 0)
	{
		print_perm_denied(cmd->argv[0]);
		data->exit_status = 126;
		return (0);
	}
	return (0);
}

static int	handle_path_error(t_mshl *data, t_cmd *cmd)
{
	const char	*path;

	if (ft_strchr(cmd->argv[0], '/'))
		return (handle_path_with_slash(data, cmd));
	path = env_get(data->env, "PATH");
	if (path && path[0] != '\0')
	{
		if (not_exec_in_path(path, cmd->argv[0]))
		{
			print_perm_denied(cmd->argv[0]);
			data->exit_status = 126;
			return (0);
		}
		put_error("minishell: ", cmd->argv[0],
			": command not found\n");
		data->exit_status = 127;
		return (0);
	}
	return (handle_no_path(data, cmd));
}

static void	child_process(char *path, t_cmd *cmd, t_mshl *data)
{
	char	**envp;

	set_signals_child();
	if (apply_redirs(cmd) == 1)
	{
		free (path);
		exit (1);
	}
	envp = env_to_envp(data->env);
	if (!envp)
	{
		free (path);
		exit (1);
	}
	execve (path, cmd->argv, envp);
	free (path);
	perror ("minishell");
	envp_free(envp);
	exit (1);
}

static int	parent_process(pid_t pid, t_mshl *data)
{
	int		status;

	waitpid(pid, &status, 0);
	update_exit_status_from_status(status, data);
	set_signals_interactive();
	if (WIFEXITED(status))
		data->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data->exit_status = 128 + WTERMSIG(status);
	return (0);
}

int	exec_external(t_mshl *data, t_cmd *cmd)
{
	char	*path;
	pid_t	pid;

	path = resolve_path(cmd->argv[0], data->env);
	if (!path)
		return (handle_path_error(data, cmd));
	set_signals_parent_execution();
	pid = fork ();
	if (pid < 0)
	{
		perror ("fork");
		data->exit_status = 1;
		free (path);
		return (1);
	}
	if (pid == 0)
		child_process(path, cmd, data);
	parent_process(pid, data);
	free (path);
	return (data->exit_status);
}
