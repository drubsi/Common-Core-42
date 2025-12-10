/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:36:13 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/07 11:46:48 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_redir_type(const char *token)
{
	if (!token)
		return (-1);
	if (ft_strncmp(token, "<", 2) == 0)
		return (R_IN);
	if (ft_strncmp(token, ">", 2) == 0)
		return (R_OUT);
	if (ft_strncmp(token, ">>", 3) == 0)
		return (R_APPEND);
	if (ft_strncmp(token, "<<", 3) == 0)
		return (R_HEREDOC);
	return (-1);
}

int	count_redirs(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (get_redir_type(tokens[i]) != -1)
		{
			count ++;
			i += 2;
		}
		else
			i++;
	}
	return (count);
}
