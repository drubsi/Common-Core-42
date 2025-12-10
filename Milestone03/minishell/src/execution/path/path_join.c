/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:51:23 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/26 12:01:18 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	find_delimiter(char character, char delimiter)
{
	if (character == delimiter)
		return (1);
	return (0);
}

static char	*actual_dir(void)
{
	char	*dir_text;

	dir_text = malloc (sizeof (char) * 3);
	if (!dir_text)
		return (NULL);
	dir_text[0] = '.';
	dir_text[1] = '/';
	dir_text[2] = '\0';
	return (dir_text);
}

char	*copy_path(const char *path, size_t start, const size_t end)
{
	char	*dir_text;
	char	*dir_with_slash;
	size_t	segment_len;
	size_t	real_len;

	segment_len = end - start;
	if (segment_len == 0)
		return (actual_dir());
	dir_text = ft_substr(path, start, segment_len);
	if (!dir_text)
		return (NULL);
	real_len = ft_strlen(dir_text);
	if (real_len > 0 && dir_text[real_len - 1] != '/')
	{
		dir_with_slash = ft_strjoin(dir_text, "/");
		free(dir_text);
		return (dir_with_slash);
	}
	return (dir_text);
}

static char	*test_path(const char *dir_text, const char *cmd)
{
	char	*full_path;

	if (!dir_text)
		return (NULL);
	full_path = ft_strjoin(dir_text, cmd);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free (full_path);
	return (NULL);
}

char	*path_join(const char *path, const char *cmd)
{
	size_t	i;
	size_t	start;
	char	*dir_text;
	char	*full_path;

	i = 0;
	start = 0;
	if (!path || !cmd || cmd[0] == '\0')
		return (NULL);
	while (1)
	{
		if (find_delimiter(path[i], ':') || find_delimiter(path[i], '\0'))
		{
			dir_text = copy_path(path, start, i);
			full_path = test_path(dir_text, cmd);
			free (dir_text);
			if (full_path)
				return (full_path);
			start = i + 1;
		}
		if (path[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
