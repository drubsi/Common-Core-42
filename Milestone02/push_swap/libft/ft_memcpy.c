/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:44:03 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:44:06 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_dest;
	unsigned char	*uc_src;
	size_t			i;

	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		i++;
	}
	return (dest);
}
