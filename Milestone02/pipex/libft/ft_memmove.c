/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:44:20 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:44:24 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	if (n == 0 || dest == NULL || src == NULL)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			uc_dest[n - 1] = uc_src[n - 1];
			n--;
		}
	}
	return (dest);
}
