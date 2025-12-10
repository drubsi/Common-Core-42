/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:34:20 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/28 10:25:53 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	malloc_exp_ctx(t_exp_ctx **exp_ctx, t_list *env, int last_status)
{
	*exp_ctx = malloc(sizeof(t_exp_ctx));
	if (!(*exp_ctx))
		return (0);
	(*exp_ctx)->env = env;
	(*exp_ctx)->last_status = last_status;
	return (1);
}

int	init_tokens_ctx(char *cmd_str, char ***tokens)
{
	*tokens = tokenize(cmd_str);
	if (!(*tokens))
		return (0);
	return (1);
}

int	validate_and_free_tokens(char **tokens, t_mshl *data)
{
	if (!is_valid_redir_sequence(tokens, data))
	{
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->redirs = NULL;
	cmd->argv = NULL;
	cmd->n_redirs = 0;
	cmd->is_builtin = 0;
}

void	free_if_error(t_cmd *cmd, char **tokens)
{
	free_tokens(tokens);
	if (cmd->redirs)
		free(cmd->redirs);
	if (cmd->argv)
		free(cmd->argv);
	init_cmd(cmd);
}
