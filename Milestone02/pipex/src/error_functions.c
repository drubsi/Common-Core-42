/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:24:09 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 20:08:13 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_dup_2(t_pipex *data)
{
	close(data->infile_fd);
	close(data->outfile_fd);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	free_all(data);
	perror("dup2");
	exit (1);
}

void	error_open_fd(t_pipex *data, int id_fd)
{
	if (id_fd == 1)
	{
		close(data->infile_fd);
		free_all(data);
		perror ("open file");
		exit (1);
	}
	else if (id_fd == 2)
	{
		close(data->infile_fd);
		close(data->outfile_fd);
		free_all(data);
		perror("open outfile");
		exit (1);
	}
	else if (id_fd == 3)
	{
		close(data->infile_fd);
		close(data->outfile_fd);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		free_all(data);
		perror("pipe");
		exit (1);
	}
}

void	cmd_not_found(t_pipex *data, int cmd)
{
	if (cmd == 1)
	{
		free_split(data->path);
		free_split(data->cmd1_args);
		free (data->cmd1_path);
		free (data);
		exit(126);
	}
	else if (cmd == 2)
	{
		free_split(data->cmd1_args);
		free (data->cmd1_path);
		free_split(data->path);
		free_split(data->cmd2_args);
		free (data->cmd2_path);
		free (data);
		exit(126);
	}
}

void	incorrect_args(void)
{
	dprintf (2, "Numero de argumentos incorrecto\n");
	exit (1);
}
