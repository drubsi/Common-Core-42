/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:12:18 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 22:31:17 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	token_len(const char *str)
{
	if (!*str)
		return (0);
	if (is_space(*str))
		return (1);
	if (is_quote(*str))
		return (quote_len(str));
	if (is_redir(str))
		return (is_redir(str));
	return (word_len(str));
}

char	*dup_quoted(const char *str, int len)
{
	if (len < 2)
		return (ft_strdup(""));
	return (ft_substr(str, 1, len - 2));
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	count_tokens(const char *str)
{
	int	count;
	int	len;

	count = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str)
		{
			len = token_len(str);
			count++;
			str += len;
		}
	}
	return (count);
}
