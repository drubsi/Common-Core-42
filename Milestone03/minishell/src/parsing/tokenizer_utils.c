/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:00:38 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/11 15:08:02 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	is_redir(const char *str)
{
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		return (2);
	if (str[0] == '<' || str[0] == '>')
		return (1);
	return (0);
}

int	word_len(const char *str)
{
	int	len;

	len = 0;
	while (str[len] && !is_space(str[len])
		&& !is_quote(str[len]) && !is_redir(&str[len]))
		len++;
	return (len);
}

int	quote_len(const char *str)
{
	int	len;

	len = 1;
	while (str[len] && str[len] != str[0])
		len++;
	if (str[len] == str[0])
		len++;
	return (len);
}
