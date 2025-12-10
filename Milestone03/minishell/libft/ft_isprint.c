/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:41 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/08 12:20:03 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	x = 23;
	y = 42;
	z = 127;
	printf("%d\n", ft_isprint(x));
	printf("%d\n", ft_isprint(y));
	printf("%d\n", ft_isprint(z));
	printf("%d\n", isprint(x));
	printf("%d\n", isprint(y));
	printf("%d\n", isprint(z));
	return (0);
}
*/
