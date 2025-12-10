/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:33:27 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 13:14:42 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_quoted_token(const char *token)
{
	int	len;

	if (!token)
		return (0);
	len = ft_strlen(token);
	if (len >= 2)
	{
		if ((token[0] == '\'' && token[len - 1] == '\'')
			|| (token[0] == '"' && token[len - 1] == '"'))
			return (1);
	}
	return (0);
}

static int	token_to_argv(t_args_ctx *ctx, int token_idx)
{
	char	*expanded;
	char	*original_token;
	int		was_quoted;

	original_token = ctx->tokens[token_idx];
	was_quoted = is_quoted_token(original_token);
	expanded = expand_token(original_token, ctx->exp, 0);
	if (!expanded)
		return (0);
	free(original_token);
	ctx->tokens[token_idx] = NULL;
	if (expanded[0] == '\0' && ! was_quoted)
	{
		free(expanded);
		return (2);
	}
	ctx->cmd->argv[ctx->args->a_i] = expanded;
	return (1);
}

static int	token_to_redir(t_args_ctx *ctx, int i)
{
	int		redir_type;
	char	*expanded;

	redir_type = get_redir_type(ctx->tokens[i]);
	ctx->cmd->redirs[ctx->args->r_i]. type = redir_type;
	expanded = get_redir_target(ctx->tokens[i + 1], redir_type, ctx->exp);
	if (!expanded)
		return (0);
	ctx->cmd->redirs[ctx->args->r_i].target = expanded;
	free(ctx->tokens[i]);
	free(ctx->tokens[i + 1]);
	ctx->tokens[i] = NULL;
	ctx->tokens[i + 1] = NULL;
	return (1);
}

static int	handle_redir_token(t_args_ctx *ctx)
{
	ctx->args->ok = token_to_redir(ctx, ctx->args->i);
	if (!ctx->args->ok)
		return (0);
	ctx->args->r_i++;
	ctx->args->i += 2;
	return (1);
}

int	handle_a_r_token(t_args_ctx *ctx)
{
	int	type;
	int	res;

	type = get_redir_type(ctx->tokens[ctx->args->i]);
	if (type != -1 && ctx->tokens[ctx->args->i + 1])
		return (handle_redir_token(ctx));
	res = token_to_argv(ctx, ctx->args->i);
	if (res == 0)
	{
		ctx->args->ok = 0;
		return (0);
	}
	if (res == 1)
		ctx->args->a_i++;
	ctx->args->i++;
	return (1);
}
