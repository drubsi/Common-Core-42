/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuphex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:57:21 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:33:41 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printuphex(unsigned int n)
{
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += ft_printuphex(n / 16);
		count += ft_printuphex(n % 16);
	}
	else
		count += ft_printchar(base[n % 16]);
	return (count);
}
