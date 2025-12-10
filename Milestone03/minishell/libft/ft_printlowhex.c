/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:31 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:32:21 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printlowhex(unsigned int n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_printlowhex(n / 16);
		count += ft_printlowhex(n % 16);
	}
	else
		count += ft_printchar(base[n % 16]);
	return (count);
}
