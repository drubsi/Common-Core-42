/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:09:06 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:32:02 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		count += ft_printchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_printint(n / 10);
		count += ft_printint(n % 10);
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}
