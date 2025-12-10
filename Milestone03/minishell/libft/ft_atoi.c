/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:23:35 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:14:12 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*str = "    ";
	const char	*str1 = "+--++-78ef945";
	const char	*str2 = "-+re5645r4re";
	const char	*str3 = "ytr41e-s5f";
	const char	*str4 = "4191741s5f";
	const char	*str5 = "-4191741s5f";

	printf("With my own function:\n");
	printf("Value returned of str is: %d\n", ft_atoi(str));
	printf("Value returned of str1 is: %d\n", ft_atoi(str1));
	printf("Value returned of str2 is: %d\n", ft_atoi(str2));
	printf("Value returned of str3 is: %d\n", ft_atoi(str3));
	printf("Value returned of str4 is: %d\n", ft_atoi(str4));
	printf("Value returned of str5 is: %d\n", ft_atoi(str5));
	
	printf("\n");
	
	printf("With original function:\n");
	printf("Value returned of str is: %d\n", atoi(str));
	printf("Value returned of str1 is: %d\n", atoi(str1));
	printf("Value returned of str2 is: %d\n", atoi(str2));
	printf("Value returned of str3 is: %d\n", atoi(str3));
	printf("Value returned of str4 is: %d\n", atoi(str4));
	printf("Value returned of str5 is: %d\n", atoi(str5));
	return (0);
}
*/