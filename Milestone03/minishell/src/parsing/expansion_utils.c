/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:51:14 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 23:30:29 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_var(const char *token, int *i, t_exp_ctx *ctx)
{
	int		start;
	int		len;

	start = *i + 1;
	if (token[start] == '?')
		return (expand_exit_status(i, ctx));
	if (token[start] == '"' || token[start] == '\'')
	{
		(*i)++;
		return (ft_strdup(""));
	}
	len = get_varname_len(token, start);
	if (len == 0)
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	return (expand_named_var(token, i, ctx));
}

char	*expand_append_char(char *result, char c)
{
	char	buf[2];
	char	*tmp;

	buf[0] = c;
	buf[1] = '\0';
	tmp = ft_strjoin_free(result, buf);
	return (tmp);
}

static int	is_valid_var_char(char c, int i)
{
	if (i == 0)
		return (ft_isalpha(c) || c == '_' || c == '?');
	return (ft_isalnum(c) || c == '_');
}

int	get_varname_len(const char *token, int start)
{
	int	len;

	len = 0;
	while (token[start + len]
		&& is_valid_var_char(token[start + len], len))
		len++;
	return (len);
}

char	*get_env_value(const char *var, t_list *env)
{
	t_env	*env_entry;

	while (env)
	{
		env_entry = (t_env *)env->content;
		if (ft_strncmp(env_entry->key, var,
				ft_strlen(var) + 1) == 0)
		{
			if (env_entry->value == NULL)
				return (ft_strdup(""));
			return (ft_strdup(env_entry->value));
		}
		env = env->next;
	}
	return (ft_strdup(""));
}
