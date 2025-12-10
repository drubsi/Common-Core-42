/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:43:19 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/21 21:02:51 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	has_unclosed_quotes(char *str)
{
	int	i;
	int	in_squote;
	int	in_dquote;

	i = 0;
	in_squote = 0;
	in_dquote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (str[i] == '"' && !in_squote)
			in_dquote = !in_dquote;
		i++;
	}
	if (in_squote || in_dquote)
	{
		put_error("minishell: syntax error: unclosed quotes\n", "", "");
		return (1);
	}
	return (0);
}

static int	handle_redir(char *str, int i, char **buf)
{
	int	len_redir;
	int	j;

	len_redir = is_redir(&str[i]);
	j = 0;
	while (j < len_redir)
	{
		*buf = str_append(*buf, str[i + j]);
		j++;
	}
	return (i + len_redir);
}

static int	fill_next_token(char *str, int i, char **buf)
{
	if (is_redir(&str[i]))
		return (handle_redir(str, i, buf));
	while (str[i] && !is_space(str[i]) && !is_redir(&str[i]))
	{
		if (str[i] == '\'')
			i = append_single_quoted(str, i, buf);
		else if (str[i] == '"')
			i = append_double_quoted(str, i, buf);
		else
		{
			*buf = str_append(*buf, str[i]);
			i++;
		}
	}
	return (i);
}

static int	tokenize_loop(char *str, char **tokens)
{
	int		tok;
	int		i;
	char	*buf;

	tok = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		buf = NULL;
		i = fill_next_token(str, i, &buf);
		if (buf)
		{
			tokens[tok] = buf;
			tok++;
		}
	}
	tokens[tok] = NULL;
	return (1);
}

char	**tokenize(char *str)
{
	char	**tokens;
	int		n_tokens;

	if (has_forbidden_chars(str))
	{
		put_error("minishell: syntax error: forbidden character\n", "", "");
		return (NULL);
	}
	if (has_unclosed_quotes(str))
		return (NULL);
	n_tokens = count_tokens(str);
	tokens = malloc(sizeof(char *) * (n_tokens + 1));
	if (!tokens)
		return (NULL);
	if (!tokenize_loop(str, tokens))
	{
		free(tokens);
		return (NULL);
	}
	return (tokens);
}
