/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:33:24 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/15 17:32:30 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;

	str1 = "hello_people";
	str2 = "hello_people";
	str3 = "hello_world";
	str4 = "hello_bilbao";
	str5 = "";
	str6 = "hello";
	str7 = "he";

	printf("With my own function; \n");
	printf("Value returned is: %d\n", ft_strncmp(str1, str2, 7));
	printf("Value returned is: %d\n", ft_strncmp(str2, str3, 7));
	printf("Value returned is: %d\n", ft_strncmp(str3, str4, 7));
	printf("Value returned is: %d\n", ft_strncmp(str3, str4, 5));
	printf("Value returned is: %d\n", ft_strncmp(str5, str4, 5));
	printf("Value returned is: %d\n", ft_strncmp(str3, str5, 5));
	printf("Value returned is: %d\n", ft_strncmp(str6, str7, 2));
	printf("Value returned is: %d\n", ft_strncmp(str7, str6, 2));
	printf("Value returned is: %d\n", ft_strncmp(str5, str6, 0));
	printf("Value returned is: %d\n", ft_strncmp(str6, str5, 0));
	printf("Value returned is: %d\n", ft_strncmp(str6, str5, 2));
	printf("Value returned is: %d\n", ft_strncmp(str5, str6, 2));
	printf("\n");

	printf("With the original function; \n");
	printf("Value returned is: %d\n", strncmp(str1, str2, 7));
	printf("Value returned is: %d\n", strncmp(str2, str3, 7));
	printf("Value returned is: %d\n", strncmp(str3, str4, 7));
	printf("Value returned is: %d\n", strncmp(str3, str4, 5));
	printf("Value returned is: %d\n", strncmp(str5, str4, 5));
	printf("Value returned is: %d\n", strncmp(str3, str5, 5));
	printf("Value returned is: %d\n", strncmp(str6, str7, 2));
	printf("Value returned is: %d\n", strncmp(str7, str6, 2));
	printf("Value returned is: %d\n", strncmp(str5, str6, 0));
	printf("Value returned is: %d\n", strncmp(str6, str5, 0));
	printf("Value returned is: %d\n", strncmp(str6, str5, 2));
	printf("Value returned is: %d\n", strncmp(str5, str6, 2));
	return (0);
}
*/
