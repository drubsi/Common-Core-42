/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:10:36 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:16:14 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned char	dest1[] = "destination";
	unsigned char	src1[] = "source_string";
	unsigned char	dest2[] = "destination";
	unsigned char	src2[] = "source_string";

	printf("%s %s\n", dest1, src1);
	ft_memcpy(dest1, src1, 9);
	printf("%s %s\n", dest1, src1);
	printf("%s %s\n", dest2, src2);
	memcpy(dest2, src2, 9);
	printf("%s %s\n", dest2, src2);
	return (0);
}
*/
