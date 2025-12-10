/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:55:50 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 20:09:03 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex **data)
{
	*data = (t_pipex *)malloc(sizeof (t_pipex));
	if (!data)
	{
		perror ("data");
		exit (1);
	}
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	free_all(t_pipex *data)
{
	free_split(data->path);
	free_split(data->cmd2_args);
	free_split(data->cmd1_args);
	free (data->cmd1_path);
	free (data->cmd2_path);
	free (data);
}
