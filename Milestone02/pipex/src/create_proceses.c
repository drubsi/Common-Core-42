/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proceses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:52:49 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 19:52:51 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	launch_pipeline(char **argv, char **envp, t_pipex *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd < 0)
		error_open_fd(data, 1);
	data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd < 0)
		error_open_fd(data, 2);
	if (pipe(data->pipe_fd) == -1)
		error_open_fd(data, 3);
	create_first_child(data, envp);
	create_second_child(data, envp);
	close(data->infile_fd);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}

void	create_first_child(t_pipex *data, char **envp)
{
	data->pid1 = fork ();
	if (data->pid1 == 0)
	{
		if (dup2(data->infile_fd, STDIN_FILENO) < 0)
			error_dup_2(data);
		if (dup2(data->pipe_fd[1], STDOUT_FILENO) < 0)
			error_dup_2(data);
		close(data->infile_fd);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		execve(data->cmd1_path, data->cmd1_args, envp);
		perror("execve hijo 1");
		close(data->outfile_fd);
		free_all(data);
		exit (1);
	}
}

void	create_second_child(t_pipex *data, char **envp)
{
	data->pid2 = fork ();
	if (data->pid2 == 0)
	{
		if (dup2(data->pipe_fd[0], STDIN_FILENO) < 0)
			error_dup_2 (data);
		if (dup2(data->outfile_fd, STDOUT_FILENO) < 0)
			error_dup_2 (data);
		close(data->outfile_fd);
		close (data->pipe_fd[1]);
		close (data->pipe_fd[0]);
		execve (data->cmd2_path, data->cmd2_args, envp);
		perror ("execve hijo 2");
		free_all(data);
		exit (1);
	}
}
