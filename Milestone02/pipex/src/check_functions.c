/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:14:33 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/14 19:51:48 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_arg(int argc)
{
	if (argc < 5)
		incorrect_args();
}

void	check_path(char **argv, char **envp, t_pipex *data)
{
	extract_path(envp, data);
	found_cmd_1(argv, data);
	found_cmd_2(argv, data);
}
