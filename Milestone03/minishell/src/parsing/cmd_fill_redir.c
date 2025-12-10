/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:15:26 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 13:19:50 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_quoted_type(const char *token)
{
	int	len;

	len = ft_strlen(token);
	if (len >= 2)
	{
		if (token[0] == '\'' && token[len - 1] == '\'')
			return ('\'');
		if (token[0] == '"' && token[len - 1] == '"')
			return ('"');
	}
	return (0);
}

static char	*get_heredoc_delim(char *target, int quoted_type)
{
	if (quoted_type)
		return (dup_quoted(target, ft_strlen(target)));
	return (ft_strdup(target));
}

static char	*get_normal_redir(char *target, int quoted_type, t_exp_ctx *exp)
{
	char	*unquoted;
	char	*expanded;

	if (quoted_type)
	{
		unquoted = dup_quoted(target, ft_strlen(target));
		if (!unquoted)
			return (NULL);
		expanded = expand_token(unquoted, exp, quoted_type);
		free(unquoted);
		return (expanded);
	}
	return (expand_token(target, exp, 0));
}

char	*get_redir_target(char *target, int redir_type, t_exp_ctx *exp)
{
	int	quoted_type;

	quoted_type = get_quoted_type(target);
	if (redir_type == R_HEREDOC)
		return (get_heredoc_delim(target, quoted_type));
	return (get_normal_redir(target, quoted_type, exp));
}
