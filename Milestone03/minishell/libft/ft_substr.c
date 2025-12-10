/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:30:48 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:55 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	src_len;
	char	*dest;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (len > src_len - start)
		len = src_len - start;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (s + start), (len + 1));
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char const *s = "hello_world";
	printf("%s\n", s);
	printf("%s\n", ft_substr(s, 4, 5));
	printf("%s\n", ft_substr(s, 4, 23));
	printf("%s\n", ft_substr(s, 23, 4));
	return (0);
}
*/
