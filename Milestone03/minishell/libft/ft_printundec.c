/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:07:05 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:33:27 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printundec(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_printundec(n / 10);
		count += ft_printundec(n % 10);
	}
	else if (n < 10)
		count += ft_printchar(n + '0');
	return (count);
}
