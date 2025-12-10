/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:25:25 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 18:31:49 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_no_such(char *name)
{
	put_error("minishell: ", name, ": ");
	ft_putstr_fd("No such file or directory\n", 2);
}

void	print_is_dir(char *name)
{
	put_error("minishell: ", name, ": ");
	ft_putstr_fd("is a directory\n", 2);
}

void	print_perm_denied(char *name)
{
	put_error("minishell: ", name, ": ");
	ft_putstr_fd("Permission denied\n", 2);
}
