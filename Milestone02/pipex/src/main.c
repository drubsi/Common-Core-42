/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:58:03 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 20:09:03 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	check_arg (argc);
	init_struct(&data);
	check_path(argv, envp, data);
	launch_pipeline(argv, envp, data);
	free_all(data);
	return (0);
}
