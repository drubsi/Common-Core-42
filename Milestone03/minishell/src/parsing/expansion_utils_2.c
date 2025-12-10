/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:58:43 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 22:27:20 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	expand_dollar_in_dquote(const char *token, t_exp_ctx *ctx,
				t_expand_state *st)
{
	char	*tmp;
	int		next;

	next = st->i + 1;
	if (!token[next] || token[next] == '"' || token[next] == ' ')
	{
		st->result = expand_append_char(st->result, '$');
		st->i++;
		return (1);
	}
	tmp = expand_var(token, &st->i, ctx);
	if (!tmp)
		return (0);
	st->result = ft_strjoin_free(st->result, tmp);
	free(tmp);
	return (1);
}

char	*expand_exit_status(int *i, t_exp_ctx *ctx)
{
	*i += 2;
	return (ft_itoa(ctx->last_status));
}

char	*expand_named_var(const char *token, int *i, t_exp_ctx *ctx)
{
	int		start;
	int		len;
	char	*var;
	char	*value;

	start = *i + 1;
	len = get_varname_len(token, start);
	var = ft_substr(token, start, len);
	if (!var)
		return (NULL);
	value = get_env_value(var, ctx->env);
	free(var);
	*i += len + 1;
	return (value);
}
