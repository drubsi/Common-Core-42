/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:35:59 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/16 12:32:09 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned char	str1[] = "hello_world";
	unsigned char	str2[] = "hello_world";
	unsigned char	str3[] = "hello_wo";
	unsigned char	str4[] = "hello_bilbao";

	printf("With my own function:\n");
	printf("Compares 0 of str1 and str2 is: %d\n", ft_memcmp(str1, str2, 0));
	printf("Compares 0 of str1 and str4 is: %d\n", ft_memcmp(str1, str4, 0));
	printf("Compares 11 of str1 and str2 is: %d\n", ft_memcmp(str1, str2, 11));
	printf("Compares 7 of str1 and str2 is: %d\n", ft_memcmp(str1, str2, 7));
	printf("Compares 5 of str1 and str3 is: %d\n", ft_memcmp(str1, str3, 5));
	printf("Compares 11 of str1 and str3 is: %d\n", ft_memcmp(str1, str3, 11));
	printf("Compares 11 of str3 and str1 is: %d\n", ft_memcmp(str3, str1, 11));
	printf("Compares 11 of str1 and str4 is: %d\n", ft_memcmp(str1, str4, 11));
	printf("Compares 11 of str4 and str1 is: %d\n", ft_memcmp(str4, str1, 11));
	printf("Compares 3 of str1 and str4 is: %d\n", ft_memcmp(str1, str4, 3));
	printf("Compares 9 of str1 and str4 is: %d\n", ft_memcmp(str1, str4, 9));
	printf("\n");
	printf("With original function:\n");
	printf("Compares 0 of str1 and str2 is: %d\n", memcmp(str1, str2, 0));
	printf("Compares 0 of str1 and str4 is: %d\n", memcmp(str1, str4, 0));
	printf("Compares 11 of str1 and str2 is: %d\n", memcmp(str1, str2, 11));
	printf("Compares 7 of str1 and str2 is: %d\n", memcmp(str1, str2, 7));
	printf("Compares 5 of str1 and str3 is: %d\n", memcmp(str1, str3, 5));
	printf("Compares 11 of str1 and str3 is: %d\n", memcmp(str1, str3, 11));
	printf("Compares 11 of str3 and str1 is: %d\n", memcmp(str3, str1, 11));
	printf("Compares 11 of str1 and str4 is: %d\n", memcmp(str1, str4, 11));
	printf("Compares 11 of str4 and str1 is: %d\n", memcmp(str4, str1, 11));
	printf("Compares 3 of str1 and str4 is: %d\n", memcmp(str1, str4, 3));
	printf("Compares 9 of str1 and str4 is: %d\n", memcmp(str1, str4, 9));
	return (0);
}
*/
