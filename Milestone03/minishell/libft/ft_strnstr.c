/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:35:01 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/19 10:18:53 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		while (big[k] == little[j]
			&& little[j] && big[k] && k < len)
		{
			k++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	main(void)
{
	const char	str[] = "hello_world";
	const char	str1[] = "hel";
	const char	str2[] = "wor";
	const char	str3[] = "bye";
	const char	str4[] = "";

	printf("With my own function:\n");
	printf("%p\n", ft_strnstr(str, str1, 11));
	printf("%p\n", ft_strnstr(str, str2, 11));
	printf("%p\n", ft_strnstr(str, str2, 4));
	printf("%p\n", ft_strnstr(str, str2, 3));
	printf("%p\n", ft_strnstr(str, str2, 8));
	printf("%p\n", ft_strnstr(str, str3, 11));
	printf("%p\n", ft_strnstr(str, str3, 3));
	printf("%p\n", ft_strnstr(str, str4, 11));
	printf("%p\n", ft_strnstr(str, str4, 3));
	printf("\n");

	printf("With original function:\n");
	printf("%p\n", strnstr(str, str1, 11));
	printf("%p\n", strnstr(str, str2, 11));
	printf("%p\n", strnstr(str, str2, 4));
	printf("%p\n", strnstr(str, str2, 3));
	printf("%p\n", strnstr(str, str2, 8));
	printf("%p\n", strnstr(str, str3, 11));
	printf("%p\n", strnstr(str, str3, 3));
	printf("%p\n", strnstr(str, str4, 11));
	printf("%p\n", strnstr(str, str4, 3));

	return (0);
}
*/
