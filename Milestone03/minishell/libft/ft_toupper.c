/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:31:20 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/08 15:43:51 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c\n", ft_toupper('d'));
	printf("%c\n", ft_toupper('E'));
	printf("%c\n", ft_toupper('+'));
	printf("%c\n", toupper('d'));
	printf("%c\n", toupper('E'));
	printf("%c\n", toupper('+'));
	return (0);
}
*/
