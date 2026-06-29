/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:44:38 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:44:41 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t n)
{
	unsigned char	*mem_ptr;
	unsigned char	uc_c;
	size_t			i;

	mem_ptr = (unsigned char *)mem;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		mem_ptr[i] = uc_c;
		i++;
	}
	return (mem);
}
