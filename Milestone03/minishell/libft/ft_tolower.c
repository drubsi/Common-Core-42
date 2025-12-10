/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:05:54 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/08 15:46:17 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c\n", ft_tolower('d'));
	printf("%c\n", ft_tolower('E'));
	printf("%c\n", ft_tolower('+'));
	printf("%c\n", tolower('d'));
	printf("%c\n", tolower('E'));
	printf("%c\n", tolower('+'));
	return (0);
}
*/
