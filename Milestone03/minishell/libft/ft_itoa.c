/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:02:15 by adeestev          #+#    #+#             */
/*   Updated: 2024/12/07 12:16:21 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_fill_string(char *str, int n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_fill_string(str, n, len);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int	num = -2147483648;
	int	num2 = -2147483647;
	int	num3 = 0;
	int	num4 = 42;
	int	num5 = 2147483647;
	char	*str;

	str = ft_itoa(num);
	printf("value of num is %d and the string obtained is %s\n", num, str);
	free (str);
	str = ft_itoa(num2);
	printf("value of num2 is %d and the string obtained is %s\n", num2, str);
	free (str);
	str = ft_itoa(num3);
	printf("value of num3 is %d and the string obtained is %s\n", num3, str);
	free (str);
	str = ft_itoa(num4);
	printf("value of num4 is %d and the string obtained is %s\n", num4, str);
	free (str);
	str = ft_itoa(num5);
	printf("value of num5 is %d and the string obtained is %s\n", num5, str);
	free (str);
	return (0);
}
*/