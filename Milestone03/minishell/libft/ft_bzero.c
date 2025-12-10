/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:47:22 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:14:18 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	unsigned char	str[] = "funny_times";
	unsigned char	str2[] = "funny_again";

	printf("%s\n", str);
	ft_bzero(str, 3);
	printf("%s\n", str);
	printf("%s\n", str2);
	bzero(str2, 3);
	printf("%s\n", str2);
	return (0);
}
*/
