/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:21:11 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 13:20:48 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_unquoted_pipes(const char *s)
{
	int	i;
	int	count;
	int	sq;
	int	dq;

	i = 0;
	count = 0;
	sq = 0;
	dq = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !dq)
			sq = !sq;
		else if (s[i] == '"' && !sq)
			dq = !dq;
		else if (s[i] == '|' && !sq && !dq)
			count++;
		i++;
	}
	return (count);
}

static int	segment_len(const char *s, int start)
{
	int	sq;
	int	dq;
	int	len;

	sq = 0;
	dq = 0;
	len = 0;
	while (s[start + len])
	{
		if (s[start + len] == '\'' && !dq)
			sq = !sq;
		else if (s[start + len] == '"' && !sq)
			dq = !dq;
		else if (s[start + len] == '|' && !sq && !dq)
			break ;
		len++;
	}
	return (len);
}

static void	free_segments(char **arr, int seg)
{
	int	i;

	i = 0;
	while (i < seg)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	fill_cmds(const char *line, char **arr, int n)
{
	int	i;
	int	seg;
	int	len;

	i = 0;
	seg = 0;
	while (seg < n)
	{
		while (line[i] == ' ')
			i++;
		len = segment_len(line, i);
		arr[seg] = ft_substr(line, i, len);
		if (!arr[seg])
			return (seg);
		i += len;
		if (line[i] == '|')
			i++;
		seg++;
	}
	arr[seg] = NULL;
	return (-1);
}

char	**split_pipes_outside_quotes(const char *line)
{
	char	**arr;
	int		n;
	int		failed;

	if (!line)
		return (NULL);
	n = count_unquoted_pipes(line) + 1;
	arr = malloc((n + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	failed = fill_cmds(line, arr, n);
	if (failed != -1)
	{
		free_segments(arr, failed);
		return (NULL);
	}
	return (arr);
}
