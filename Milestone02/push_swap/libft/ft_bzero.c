/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:37:05 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:37:16 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *memory, size_t n)
{
	size_t			i;
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *)memory;
	i = 0;
	while (i < n)
	{
		*byte_ptr = 0;
		byte_ptr++;
		i++;
	}
}
