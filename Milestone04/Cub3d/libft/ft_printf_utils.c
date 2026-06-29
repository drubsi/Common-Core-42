/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:30:45 by drubio-s          #+#    #+#             */
/*   Updated: 2024/12/22 08:49:59 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if ((write (1, &c, 1)) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	cont;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
		{
			return (6);
		}
		return (6);
	}
	cont = 0;
	while (*str)
	{
		if (write(1, str, 1) == -1)
		{
			return (-1);
		}
		cont++;
		str++;
	}
	return (cont);
}

int	ft_putnbr(int n)
{
	char	ascii;
	int		len;

	len = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
		len++;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	ascii = (n % 10) + 48;
	write (1, &ascii, 1);
	return (len + 1);
}

int	ft_putnbr_u(unsigned int n)
{
	char	ascii;
	int		len;

	len = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (n >= 10)
		len += ft_putnbr_u(n / 10);
	ascii = (n % 10) + 48;
	write (1, &ascii, 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				len;

	len = 0;
	p = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else
		write (1, "0x", 2);
	len++;
	len += ft_puthex_ul(p);
	return (len + 1);
}
