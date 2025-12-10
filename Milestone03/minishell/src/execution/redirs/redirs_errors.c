/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:44:51 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/05 19:21:13 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	print_redir_error(char *prefix, char *target)
{
	int	saved;

	saved = errno;
	put_error(prefix, target, ": ");
	ft_putstr_fd(strerror(saved), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	print_dup2_error(char *msg)
{
	put_error("minishell: dup2: ", msg, "\n");
	return (1);
}
