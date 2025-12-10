/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:46:59 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/15 18:55:40 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	next_word(const char *s, char c, size_t *start)
{
	size_t	len;

	len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	return (len);
}

static char	**free_all(char **res, size_t i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*allocate_and_copy(const char *s, char c, size_t *start)
{
	size_t	len;
	char	*word;

	len = next_word(s, c, start);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*start], len + 1);
	*start += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	words;
	size_t	start;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		res[i] = allocate_and_copy(s, c, &start);
		if (!res[i])
			return (free_all(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
