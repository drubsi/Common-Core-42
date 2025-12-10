/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:59:50 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/28 10:30:15 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	set_ctx_and_validate(char *cmd_str, t_mshl *data,
	t_fill_ctx *fill_ctx)
{
	char		**tokens;
	t_exp_ctx	*exp_ctx;

	if (!init_tokens_ctx(cmd_str, &tokens))
		return (0);
	if (!validate_and_free_tokens(tokens, data))
		return (0);
	fill_ctx->argc = count_argv(tokens);
	fill_ctx->n_redirs = count_redirs(tokens);
	if (!malloc_exp_ctx(&exp_ctx, data->env, data->exit_status))
	{
		free_tokens(tokens);
		return (0);
	}
	fill_ctx->tokens = tokens;
	fill_ctx->exp = exp_ctx;
	return (1);
}

static void	cleanup_parse_cmd(t_cmd *cmd, t_fill_ctx *fill_ctx)
{
	free_if_error(cmd, fill_ctx->tokens);
	free(fill_ctx->exp);
}

t_cmd	parse_cmd(char *cmd_str, t_mshl *data)
{
	t_cmd		cmd;
	t_fill_ctx	fill_ctx;
	int			ok;

	init_cmd(&cmd);
	fill_ctx.cmd = &cmd;
	if (!cmd_str || !*cmd_str)
		return (cmd);
	if (!set_ctx_and_validate(cmd_str, data, &fill_ctx))
		return (cmd);
	ok = fill_a_and_r(&fill_ctx);
	if (!ok)
	{
		cleanup_parse_cmd(&cmd, &fill_ctx);
		return (cmd);
	}
	if (cmd.argv && cmd.argv[0])
		cmd.is_builtin = check_if_builtin(cmd.argv[0]);
	free_tokens(fill_ctx.tokens);
	free(fill_ctx.exp);
	return (cmd);
}
