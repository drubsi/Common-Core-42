/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:41:46 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/08 12:05:08 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
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

	x = 'A';
	y = 'a';
	z = '3';
	other = 42;
	printf("%d\n", ft_isalnum(x));
	printf("%d\n", ft_isalnum(y));
	printf("%d\n", ft_isalnum(z));
	printf("%d\n", ft_isalnum(other));
	printf("%d\n", isalnum(x));
	printf("%d\n", isalnum(y));
	printf("%d\n", isalnum(z));
	printf("%d\n", isalnum(other));
	return (0);
}
*/
