/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:59:03 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/12 10:48:22 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "helloworld";
	char	dest1[11] = "xxxxxxxxxx";
	char	dest2[8] = "xxxxxxx";
	char	dest3[4] = "xxx";
	printf("%s %lu\n", dest1, ft_strlcpy(dest1, src, 0));
	printf("%s %lu\n", dest2, ft_strlcpy(dest2, src, 3));
	printf("%s %lu\n", dest3, ft_strlcpy(dest3, src, 7));
	return (0);
}
*/
