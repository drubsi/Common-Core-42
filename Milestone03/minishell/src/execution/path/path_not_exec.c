/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_not_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:47:30 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 13:19:01 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	check_segment(const char *path, const char *cmd,
			size_t *start, size_t end)
{
	char	*dir;
	char	*full;

	dir = copy_path(path, *start, end);
	if (!dir)
		return (0);
	full = ft_strjoin(dir, cmd);
	free (dir);
	if (!full)
		return (0);
	if (access(full, F_OK) == 0 && access(full, X_OK) != 0)
	{
		free (full);
		return (1);
	}
	free (full);
	*start = end + 1;
	return (0);
}

int	not_exec_in_path(const char *path, const char *cmd)
{
	size_t	i;
	size_t	start;

	if (!path || !cmd || cmd[0] == '\0')
		return (0);
	i = 0;
	start = 0;
	while (1)
	{
		if (find_delimiter(path[i], ':')
			|| find_delimiter(path[i], '\0'))
		{
			if (check_segment(path, cmd, &start, i))
				return (1);
		}
		if (path[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	handle_no_path(t_mshl *data, t_cmd *cmd)
{
	if (access(cmd->argv[0], F_OK) == 0
		&& access(cmd->argv[0], X_OK) != 0)
	{
		print_perm_denied(cmd->argv[0]);
		data->exit_status = 126;
		return (0);
	}
	put_error("minishell: ", cmd->argv[0], ": command not found\n");
	data->exit_status = 127;
	return (0);
}
