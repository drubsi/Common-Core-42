/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:23:53 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:16:53 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			x;

	if (!s)
		return (NULL);
	x = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == x)
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str[] = "hello_world";

	printf("%p\n", ft_strchr(str, 'r'));
	printf("%p\n", ft_strchr(str, 'R'));
	printf("%p\n", ft_strchr(str, 'z'));

	printf("%p\n", strchr(str, 'r'));
	printf("%p\n", strchr(str, 'R'));
	printf("%p\n", strchr(str, 'z'));

	return (0);
}
*/
