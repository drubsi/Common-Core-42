/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:44:36 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/13 12:34:57 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	redir_in(t_redir *redir)
{
	int	fd;
	int	saved;

	fd = open(redir->target, O_RDONLY);
	if (fd < 0)
		return (print_redir_error("minishell: ", redir->target));
	if (dup2(fd, 0) == -1)
	{
		saved = errno;
		close(fd);
		return (print_dup2_error(strerror(saved)));
	}
	close(fd);
	return (0);
}

int	redir_out(t_redir *redir)
{
	int	fd;
	int	saved;

	fd = open(redir->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (print_redir_error("minishell: ", redir->target));
	if (dup2(fd, 1) == -1)
	{
		saved = errno;
		close(fd);
		return (print_dup2_error(strerror(saved)));
	}
	close(fd);
	return (0);
}

int	redir_append(t_redir *redir)
{
	int	fd;
	int	saved;

	fd = open(redir->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (print_redir_error("minishell: ", redir->target));
	if (dup2(fd, 1) == -1)
	{
		saved = errno;
		close(fd);
		return (print_dup2_error(strerror(saved)));
	}
	close(fd);
	return (0);
}

int	redir_heredoc(t_redir *redir)
{
	int	saved;

	if (redir->hd_fd < 0)
		return (print_redir_error("minishell: ", redir->target));
	if (dup2(redir->hd_fd, STDIN_FILENO) == -1)
	{
		saved = errno;
		close(redir->hd_fd);
		return (print_dup2_error(strerror(saved)));
	}
	close(redir->hd_fd);
	return (0);
}
