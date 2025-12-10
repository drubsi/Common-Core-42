/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:28:41 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/26 17:27:44 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	search_slash(const char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static char	*test_path_with_slash(const char *cmd)
{
	struct stat	st;

	if (cmd == NULL || cmd[0] == '\0')
		return (NULL);
	if (stat(cmd, &st) != 0)
		return (NULL);
	if (S_ISDIR(st.st_mode))
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*resolve_path(const char *cmd, t_list *env)
{
	const char	*path;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (search_slash(cmd))
		return (test_path_with_slash(cmd));
	if (ft_strncmp(cmd, ".", 2) == 0)
		return (NULL);
	path = env_get(env, "PATH");
	if (!path || path[0] == '\0')
		return (NULL);
	return (path_join(path, cmd));
}
