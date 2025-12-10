/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:06:46 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:16:50 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	token_count(char const *s, char delimiter)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != delimiter && i == 0)
		{
			i = 42;
			count++;
		}
		else if (*s == delimiter)
			i = 0;
		s++;
	}
	return (count);
}

static size_t	token_len(char const *s, char delimiter)
{
	size_t	len;

	len = 0;
	while (*s && *s != delimiter)
	{
		s++;
		len++;
	}
	return (len);
}

static void	ft_free(char **s, int i)
{
	while (s[i] != 0)
	{
		free(s[i]);
		i++;
	}
	free (s);
}

static int	fill(char **arr, const char *s, char delimiter)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			len = token_len(s, delimiter);
			arr[i] = malloc(len + 1);
			if (!arr[i])
			{
				ft_free(arr, 0);
				return (0);
			}
			ft_strlcpy(arr[i], s, len + 1);
			s = s + len;
			i++;
		}
	}
	return (42);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		tokens;

	if (!s)
		return (NULL);
	tokens = token_count(s, c);
	if (tokens < 0)
		return (NULL);
	arr = malloc((tokens + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (fill(arr, s, c) == 0)
		return (NULL);
	arr[tokens] = 0;
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*str = "Hello3people3in3this3little3world";
	char **result = ft_split(str, '3');
	int	i = 0;
	while (result[i])
		printf("%s\n", result[i++]);
	i = 0;
	while (result[i])
		free(result[i++]);
	free (result);
	return (0);
}
*/