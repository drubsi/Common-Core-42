/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:56:00 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/01 14:19:08 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	x;
	int	y;
	int	z;
	int	other;

	x = 0;
	y = 42;
	z = 127;
	other = 156;
	printf("%d\n", ft_isascii(x));
	printf("%d\n", ft_isascii(y));
	printf("%d\n", ft_isascii(z));
	printf("%d\n", ft_isascii(other));
	printf("%d\n", isascii(x));
	printf("%d\n", isascii(y));
	printf("%d\n", isascii(z));
	printf("%d\n", isascii(other));
	return (0);
}
*/
