/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:52:17 by drubio-s          #+#    #+#             */
/*   Updated: 2024/12/22 11:14:56 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putnbr_u(va_arg (vargs, unsigned int)));
	else if (type == 'x')
		return (ft_puthex(va_arg (vargs, unsigned int), 'x'));
	else if (type == 'X')
		return (ft_puthex(va_arg (vargs, unsigned int), 'X'));
	else if (type == 'p')
		return (ft_putptr(va_arg (vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	vargs;
	int		cont;

	cont = 0;
	va_start (vargs, format);
	while (*format)
	{
		if (*format == '%')
		{
			cont += conversion (*++format, vargs);
			format++;
		}
		else
		{
			cont += (write (1, format, 1));
			format++;
		}
	}
	va_end (vargs);
	return (cont);
}
