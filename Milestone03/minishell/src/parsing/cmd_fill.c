/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:32:11 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/10 10:41:17 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	init_cmd_struct_arrays(t_fill_ctx *ctx)
{
	int	i;

	i = 0;
	ctx->cmd->argv = malloc(sizeof(char *) * (ctx->argc + 1));
	if (!ctx->cmd->argv)
		return (0);
	if (ctx->n_redirs > 0)
	{
		ctx->cmd->redirs = malloc(sizeof(t_redir) * ctx->n_redirs);
		if (!ctx->cmd->redirs)
		{
			free(ctx->cmd->argv);
			return (0);
		}
		while (i < ctx->n_redirs)
		{
			ctx->cmd->redirs[i].hd_fd = -1;
			i++;
		}
	}
	return (1);
}

static int	fill_a_r_loop(t_args_ctx *args_ctx, t_fill_ctx *ctx)
{
	args_ctx->args->i = 0;
	args_ctx->args->a_i = 0;
	args_ctx->args->r_i = 0;
	args_ctx->args->ok = 1;
	while (ctx->tokens[args_ctx->args->i])
	{
		if (!handle_a_r_token(args_ctx))
			return (0);
	}
	ctx->cmd->argv[args_ctx->args->a_i] = NULL;
	ctx->cmd->n_redirs = ctx->n_redirs;
	return (1);
}

int	fill_a_and_r(t_fill_ctx *ctx)
{
	t_args_fill	args;
	t_args_ctx	args_ctx;

	args_ctx.cmd = ctx->cmd;
	args_ctx.tokens = ctx->tokens;
	args_ctx.args = &args;
	args_ctx.exp = ctx->exp;
	if (!init_cmd_struct_arrays(ctx))
		return (0);
	return (fill_a_r_loop(&args_ctx, ctx));
}

int	count_argv(char **tokens)
{
	int	i;
	int	argc;

	i = 0;
	argc = 0;
	while (tokens[i])
	{
		if (get_redir_type(tokens[i]) != -1)
		{
			if (tokens[i + 1])
				i += 2;
			else
				break ;
		}
		else
		{
			argc++;
			i++;
		}
	}
	return (argc);
}
