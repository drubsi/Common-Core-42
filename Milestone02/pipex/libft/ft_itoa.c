/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:42:15 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 10:01:34 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_allocate_str(int digits, int is_negative)
{
	int		total_chars;
	char	*str;

	total_chars = digits + is_negative + 1;
	str = malloc(sizeof(char) * total_chars);
	if (!str)
		return (NULL);
	return (str);
}

static void	ft_fill_str(char *str, int n, int digits, int is_negative)
{
	int	i;

	i = digits + is_negative - 1;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		digits;
	int		is_negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_count_digits(n);
	is_negative = ft_sign(&n);
	str = ft_allocate_str(digits, is_negative);
	if (!str)
		return (NULL);
	str[digits + is_negative] = '\0';
	ft_fill_str(str, n, digits, is_negative);
	return (str);
}
