/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:21:00 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:38 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = i;
	while (src[i - j] && i + 1 < size)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
/*
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

size_t	strlcat(char *dst, const char *src, size_t dsize)
{
	const char *odst = dst;
	const char *osrc = src;
	size_t n = dsize;
	size_t dlen;

	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;

	if (n-- == 0)
		return(dlen + strlen(src));
	while (*src != '\0') {
		if (n != 0) {
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';

	return(dlen + (src - osrc));
}

int	main(void)
{
	char	src[6] = "world";
	char	dest[6] = "hello";
	char	dest2[6] = "hello";
	char	dest3[6] = "hello";

	printf("With my own function:\n\n");

	printf("before dest is: %s\n", dest);
	printf("value returned is: %lu\n", ft_strlcat(dest, src, 0));
	printf("after dest is: %s\n\n", dest);

	printf("before dest2 is: %s\n", dest2);
	printf("value returned is: %lu\n", ft_strlcat(dest2, src, 4));
	printf("after dest2 is: %s\n\n", dest2);

	printf("before dest3 is: %s\n", dest3);
	printf("value returned is: %lu\n", ft_strlcat(dest3, src, 5));
	printf("after dest3 is: %s\n\n", dest3);

	char	ok_src[6] = "world";
	char	ok_dest[6] = "hello";
	char	ok_dest2[6] = "hello";
	char	ok_dest3[6] = "hello";

	printf("With the original function:\n\n");

	printf("before ok_dest is: %s\n", ok_dest);
	printf("value returned is: %lu\n", strlcat(ok_dest, ok_src, 0));
	printf("after ok_dest is: %s\n\n", ok_dest);

	printf("before ok_dest2 is: %s\n", ok_dest2);
	printf("value returned is: %lu\n", strlcat(ok_dest2, ok_src, 4));
	printf("after ok_dest2 is: %s\n\n", ok_dest2);

	printf("before ok_dest3 is: %s\n", ok_dest3);
	printf("value returned is: %lu\n", strlcat(ok_dest3, ok_src, 5));
	printf("after ok_dest3 is: %s\n\n", ok_dest3);

	return (0);
}
*/
