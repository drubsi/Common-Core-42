/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:49:44 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:32:54 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base(unsigned long long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_base(n / 16);
		count += ft_base(n % 16);
	}
	else
		count += ft_printchar(base[n % 16]);
	return (count);
}

int	ft_printptr(void *ptr)
{
	int					count;
	unsigned long long	n;

	count = 0;
	n = (unsigned long long)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count += ft_printstr("0x");
	count += ft_base(n);
	return (count);
}
