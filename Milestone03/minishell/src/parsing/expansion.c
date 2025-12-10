/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:35:29 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/25 16:17:03 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_single_quote_exp(const char *token, t_expand_state *st)
{
	st->i++;
	while (token[st->i] && token[st->i] != '\'')
	{
		st->result = expand_append_char(st->result, token[st->i]);
		st->i++;
	}
	if (token[st->i] == '\'')
		st->i++;
	return (1);
}

static int	handle_double_quote_exp(const char *token, t_exp_ctx *ctx,
				t_expand_state *st)
{
	st->i++;
	while (token[st->i] && token[st->i] != '"')
	{
		if (token[st->i] == '$')
		{
			if (!expand_dollar_in_dquote(token, ctx, st))
				return (0);
		}
		else
		{
			st->result = expand_append_char(st->result, token[st->i]);
			st->i++;
		}
	}
	if (token[st->i] == '"')
		st->i++;
	return (1);
}

static int	handle_unquoted_char(const char *token, t_exp_ctx *ctx,
				t_expand_state *st)
{
	char	*tmp;

	if (token[st->i] == '$')
	{
		tmp = expand_var(token, &st->i, ctx);
		if (!tmp)
			return (0);
		st->result = ft_strjoin_free(st->result, tmp);
		free(tmp);
	}
	else
	{
		st->result = expand_append_char(st->result, token[st->i]);
		st->i++;
	}
	return (1);
}

static char	*expand_general(const char *token, t_exp_ctx *ctx)
{
	t_expand_state	st;

	st.i = 0;
	st.in_single = 0;
	st.in_double = 0;
	st.result = ft_strdup("");
	if (!st.result)
		return (NULL);
	while (token[st.i])
	{
		if (token[st.i] == '\'')
		{
			if (!handle_single_quote_exp(token, &st))
				return (free(st.result), NULL);
		}
		else if (token[st.i] == '"')
		{
			if (!handle_double_quote_exp(token, ctx, &st))
				return (free(st.result), NULL);
		}
		else if (!handle_unquoted_char(token, ctx, &st))
			return (free(st.result), NULL);
	}
	return (st.result);
}

char	*expand_token(const char *token, t_exp_ctx *ctx, int quoted_type)
{
	(void)quoted_type;
	return (expand_general(token, ctx));
}
