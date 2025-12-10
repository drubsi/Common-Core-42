/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:58:09 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 20:08:13 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	extract_path(char **envp, t_pipex *data)
{
	int		i;
	char	*temp_env;

	temp_env = NULL;
	i = 0;
	if (!envp | !*envp)
	{
		dprintf (2, "Error: entorno no valido\n");
		free_all (data);
		exit (1);
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			temp_env = envp[i] + 5;
		i++;
	}
	data->path = ft_split(temp_env, ':');
	i = 0;
}

void	found_cmd_1(char **argv, t_pipex *data)
{
	int		flag;
	int		i;
	char	*temp_path;

	flag = 0;
	i = 0;
	data->cmd1_path = NULL;
	data->cmd1_args = ft_split(argv[2], ' ');
	while (data->path[i])
	{
		temp_path = ft_strjoin(data->path[i], "/");
		if (data->cmd1_path)
			free (data->cmd1_path);
		data->cmd1_path = ft_strjoin(temp_path, data->cmd1_args[0]);
		free (temp_path);
		if (access(data->cmd1_path, X_OK) == 0)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		cmd_not_found(data, 1);
}

void	found_cmd_2(char **argv, t_pipex *data)
{
	int		flag;
	int		i;
	char	*temp_path;

	flag = 0;
	i = 0;
	data->cmd2_path = NULL;
	data->cmd2_args = ft_split(argv[3], ' ');
	while (data->path[i])
	{
		temp_path = ft_strjoin(data->path[i], "/");
		if (data->cmd2_path)
			free (data->cmd2_path);
		data->cmd2_path = ft_strjoin(temp_path, data->cmd2_args[0]);
		free (temp_path);
		if (access(data->cmd2_path, X_OK) == 0)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		cmd_not_found(data, 2);
}
