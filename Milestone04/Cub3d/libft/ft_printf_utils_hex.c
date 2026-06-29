/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:35:41 by drubio-s          #+#    #+#             */
/*   Updated: 2025/01/03 18:35:56 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char upper)
{
	char	ascii;
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, upper);
	if (n % 16 < 10)
	{
		ascii = (n % 16) + 48;
		write (1, &ascii, 1);
	}
	else
	{
		if (upper == 'X')
		{
			ascii = (n % 16) + 55;
			write (1, &ascii, 1);
		}
		else
		{
			ascii = (n % 16) + 87;
			write (1, &ascii, 1);
		}
	}
	return (len + 1);
}

int	ft_puthex_ul(unsigned long n)
{
	char	ascii;
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_ul(n / 16);
	if (n % 16 < 10)
	{
		ascii = (n % 16) + 48;
		write (1, &ascii, 1);
	}
	else
	{
		ascii = (n % 16) + 87;
		write (1, &ascii, 1);
	}
	return (len + 1);
}
