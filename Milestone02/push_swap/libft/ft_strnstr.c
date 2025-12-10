/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:50:55 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:50:58 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[0] == '\0')
	{
		return ((char *)str1);
	}
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
			{
				return ((char *)(str1 + i));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
