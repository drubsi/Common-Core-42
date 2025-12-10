/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:54:08 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 23:40:16 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	apply_one_redir(t_redir *redir)
{
	if (redir->type == R_IN)
		return (redir_in(redir));
	else if (redir->type == R_OUT)
		return (redir_out(redir));
	else if (redir->type == R_APPEND)
		return (redir_append(redir));
	else if (redir->type == R_HEREDOC)
		return (redir_heredoc(redir));
	return (0);
}

int	apply_redirs(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd || !cmd->redirs || cmd->n_redirs <= 0)
		return (0);
	while (i < cmd->n_redirs)
	{
		if (!cmd->redirs[i].target)
			return (1);
		if (apply_one_redir(&cmd->redirs[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
