/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:50:43 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 23:38:44 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	run_external_command(t_mshl *data, t_cmd *cmd)
{
	char	*path;
	char	**envp;

	path = resolve_path(cmd->argv[0], data->env);
	if (!path)
	{
		put_error("minishell: ", cmd->argv[0], ": command not found\n");
		exit (127);
	}
	envp = env_to_envp(data->env);
	if (!envp)
		exit (1);
	execve(path, cmd->argv, envp);
	free (path);
	perror ("minishell");
	envp_free(envp);
	exit (1);
}

void	run_command(t_mshl *data, t_cmd *cmd)
{
	if (cmd->is_builtin == 1)
		exit (builtin_dispatch(data, cmd));
	run_external_command(data, cmd);
}
