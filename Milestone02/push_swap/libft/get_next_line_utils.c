/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:37 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/05 18:28:40 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_zero(char *str, unsigned long int size )
{
	unsigned long int	i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

void	*calloc_gnl(unsigned long int n, unsigned long int size)
{
	char	*result;

	result = malloc (n * size);
	if (!result)
		return (NULL);
	ft_zero(result, (n * size));
	return (result);
}

char	*ft_findchr(const char *str, int chr)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*string;
	int		i;
	int		j;
	int		total;

	i = 0;
	j = 0;
	total = ft_strlen_gnl(str1) + ft_strlen_gnl(str2);
	string = (char *) calloc_gnl(total + 1, sizeof (char));
	if (!string)
		return (NULL);
	while (str1 && str1[i])
	{
		string[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		string[i] = str2[j];
		i++;
		j++;
	}
	string[i] = 0;
	return (string);
}
