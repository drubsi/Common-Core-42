/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:47:25 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 22:32:07 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_forbidden_chars(char *s)
{
	int	in_squote;
	int	in_dquote;
	int	i;

	in_squote = 0;
	in_dquote = 0;
	i = 0;
	while (s[i])
	{
		if (!in_dquote && s[i] == '\'')
			in_squote = !in_squote;
		else if (!in_squote && s[i] == '"')
			in_dquote = !in_dquote;
		else if (!in_squote && !in_dquote && s[i] == ';')
			return (1);
		i++;
	}
	return (0);
}

char	*str_append(char *str, char c)
{
	char	*new_str;
	size_t	len;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	if (str)
		ft_memcpy(new_str, str, len);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(str);
	return (new_str);
}

int	append_single_quoted(char *str, int i, char **buf)
{
	*buf = str_append(*buf, str[i]);
	i++;
	while (str[i] && str[i] != '\'')
	{
		*buf = str_append(*buf, str[i]);
		i++;
	}
	if (str[i] == '\'')
	{
		*buf = str_append(*buf, str[i]);
		i++;
	}
	return (i);
}

int	append_double_quoted(char *str, int i, char **buf)
{
	*buf = str_append(*buf, str[i]);
	i++;
	while (str[i] && str[i] != '"')
	{
		*buf = str_append(*buf, str[i]);
		i++;
	}
	if (str[i] == '"')
	{
		*buf = str_append(*buf, str[i]);
		i++;
	}
	return (i);
}
