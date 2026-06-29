/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:51:44 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:51:46 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	get_trim_index(char const *s, char const *set, int is_start)
{
	size_t	i;

	if (is_start)
	{
		i = 0;
		while (s[i] && is_in_set(s[i], set))
			i++;
	}
	else
	{
		i = ft_strlen(s) - 1;
		while (i > 0 && is_in_set(s[i], set))
			i--;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	start = get_trim_index(s1, set, 1);
	end = get_trim_index(s1, set, 0);
	if (start >= end)
		return (ft_strdup(""));
	len = end - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, len +1);
	return (new_str);
}
