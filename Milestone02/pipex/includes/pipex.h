/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:48:48 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 20:09:03 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**path;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1_args;
	char	**cmd2_args;
}	t_pipex;

//Error Functions:
void	incorrect_args(void);
void	cmd_not_found(t_pipex *data, int cmd);
void	error_open_fd(t_pipex *data, int fd);
void	error_dup_2(t_pipex *data);

//Memory functions:
void	init_struct(t_pipex **data);
void	free_split(char **arr);
void	free_all(t_pipex *data);

//Check Functions:
void	check_arg(int argc);
void	check_path(char **argv, char **envp, t_pipex *data);

//Util Functions:
void	extract_path(char **envp, t_pipex *data);
void	found_cmd_1(char **argv, t_pipex *data);
void	found_cmd_2(char **argv, t_pipex *data);

//create proceses:
void	launch_pipeline(char **argv, char **envp, t_pipex *data);
void	create_first_child(t_pipex *data, char **envp);
void	create_second_child(t_pipex *data, char **envp);

#endif