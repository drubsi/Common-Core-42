/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:38:12 by adeestev          #+#    #+#             */
/*   Updated: 2025/09/06 21:19:17 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*src;
	char		*dest;
	char		*dest1;

	src = "hello world";
	dest = ft_strdup(src);
	dest1 = strdup(src);

	printf("My function:\n");
	printf("source string is: %s and duplicated	one is: %s\n", src, dest);
	printf("Original one:\n");
	printf("source string is: %s and duplicated	one is: %s\n", src, dest1);
	return (0);
}
*/
