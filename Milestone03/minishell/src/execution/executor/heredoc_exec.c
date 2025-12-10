/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:34:19 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/29 12:46:07 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	heredoc_real_loop(const char *delim, int write_fd)
{
	char	*line;

	while (1)
	{
		print_heredoc_prompt();
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_putstr_fd("warning: here-doc delimited by end-of-file\n", 2);
			break ;
		}
		normalize_heredoc_line(line);
		if (is_heredoc_delim(line, delim))
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	return (0);
}

static int	init_heredoc_pipe(int fd[2], t_mshl *data)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		data->exit_status = 1;
		return (-1);
	}
	return (0);
}

static pid_t	spawn_heredoc_child(int fd[2], t_redir *redir)
{
	pid_t	pid;

	pid = fork ();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(fd[0]);
		signal(SIGINT, SIG_DFL);
		heredoc_real_loop(redir->target, fd[1]);
		close(fd[1]);
		exit(0);
	}
	return (pid);
}

static int	handle_heredoc_parent(pid_t pid, int fd[2]
	, t_redir *redir, t_mshl *data)
{
	int		status;
	void	(*old_sigint)(int);

	old_sigint = signal(SIGINT, SIG_IGN);
	close (fd[1]);
	waitpid(pid, &status, 0);
	signal(SIGINT, old_sigint);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(fd[0]);
		data->exit_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		redir->hd_fd = fd[0];
		return (0);
	}
	close(fd[0]);
	data->exit_status = 1;
	return (1);
}

int	create_heredoc_fd(t_redir *redir, t_mshl *data)
{
	int		fd[2];
	pid_t	pid;

	if (init_heredoc_pipe(fd, data) == -1)
		return (-1);
	pid = spawn_heredoc_child(fd, redir);
	if (pid < 0)
	{
		perror("fork");
		close_pipe_if_open(fd);
		data->exit_status = 1;
		return (1);
	}
	return (handle_heredoc_parent(pid, fd, redir, data));
}
