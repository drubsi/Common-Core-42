/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:18:10 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 22:24:06 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_token_redirection(char *token)
{
	return (get_redir_type(token) != -1);
}

static int	is_token_pipe(char *token)
{
	return (token && token[0] == '|' && token[1] == '\0');
}

static int	is_token_valid_redir(char **tokens, int i, t_mshl *data)
{
	if (!tokens[i + 1])
	{
		put_error("syntax error: ", "unexpected end after redir `", tokens[i]);
		ft_putstr_fd("'\n", 2);
		data->exit_status = 2;
		return (0);
	}
	if (is_token_redirection(tokens[i + 1]) || is_token_pipe(tokens[i + 1]))
	{
		put_error("syntax error near unexpected token '", tokens[i + 1], "'\n");
		data->exit_status = 2;
		data->sintax_error = 1;
		return (0);
	}
	return (1);
}

int	is_valid_redir_sequence(char **tokens, t_mshl *data)
{
	int	i;

	i = 0;
	while (tokens && tokens[i])
	{
		if (is_token_redirection(tokens[i]))
		{
			if (!is_token_valid_redir(tokens, i, data))
				return (0);
		}
		if (is_token_pipe(tokens[i]))
		{
			put_error("syntax error near unexpected token '|'\n", "", "");
			data->exit_status = 2;
			return (0);
		}
		i++;
	}
	return (1);
}
