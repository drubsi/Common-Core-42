/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:42:49 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:42:56 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t n)
{
	unsigned char	*str_ptr;
	size_t			i;
	unsigned char	*found_ptr;

	str_ptr = (unsigned char *)str;
	i = 0;
	found_ptr = NULL;
	while (i < n)
	{
		if (str_ptr[i] == (unsigned char)c)
		{
			found_ptr = str_ptr + i;
			return (found_ptr);
		}
		i++;
	}
	return (found_ptr);
}
