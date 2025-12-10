/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:01:24 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/16 11:33:51 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*str;

	x = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == x)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str[] = "hello_world";

	printf("%p\n", ft_memchr(str, 'r', 4));
	printf("%p\n", ft_memchr(str, 'r', 11));
	printf("%p\n", ft_memchr(str, 'R', 11));
	printf("%p\n", ft_memchr(str, 'o', 7));
	printf("%p\n", ft_memchr(str, 'o', 11));
	printf("\n");
	printf("%p\n", memchr(str, 'r', 4));
	printf("%p\n", memchr(str, 'r', 11));
	printf("%p\n", memchr(str, 'R', 11));
	printf("%p\n", memchr(str, 'o', 7));
	printf("%p\n", memchr(str, 'o', 11));

	return (0);
}
*/
