/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlefmtspec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:49:02 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:30:38 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handlefmtspec(va_list ap, char input)
{
	int	count;

	count = 0;
	if (input == 'c')
		count = ft_printchar(va_arg(ap, int));
	else if (input == 's')
		count = ft_printstr(va_arg(ap, char *));
	else if (input == 'p')
		count += ft_printptr(va_arg(ap, void *));
	else if (input == 'd')
		count = ft_printdec(va_arg(ap, int));
	else if (input == 'i')
		count = ft_printint(va_arg(ap, int));
	else if (input == 'u')
		count = ft_printundec(va_arg(ap, unsigned int));
	else if (input == 'x')
		count = ft_printlowhex(va_arg(ap, unsigned int));
	else if (input == 'X')
		count = ft_printuphex(va_arg(ap, unsigned int));
	else if (input == '%')
		count = (ft_printchar('%'));
	return (count);
}
