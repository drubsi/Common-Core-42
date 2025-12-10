/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:41:08 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 13:18:32 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_heredoc_prompt(void)
{
	if (isatty(STDIN_FILENO))
		ft_putstr_fd("> ", STDOUT_FILENO);
}

void	normalize_heredoc_line(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_heredoc_delim(const char *line, const char *delim)
{
	if (!line || !delim)
		return (0);
	if (ft_strlen(line) != ft_strlen(delim))
		return (0);
	if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
		return (1);
	return (0);
}
