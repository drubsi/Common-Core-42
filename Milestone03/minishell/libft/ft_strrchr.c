/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:41:41 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/16 10:18:51 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			x;

	x = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		res = (char *) &s[i];
	return (res);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str[] = "hello_world";

	printf("%p\n", ft_strrchr(str, 'r'));
	printf("%p\n", ft_strrchr(str, 'R'));
	printf("%p\n", ft_strrchr(str, 'z'));
	printf("%p\n", ft_strrchr(str, 'o'));
	printf("\n");
	printf("%p\n", strrchr(str, 'r'));
	printf("%p\n", strrchr(str, 'R'));
	printf("%p\n", strrchr(str, 'z'));
	printf("%p\n", strrchr(str, 'o'));

	return (0);
}
*/
