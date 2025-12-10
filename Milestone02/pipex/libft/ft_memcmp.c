/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:43:43 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:43:47 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *block1, const void *block2, size_t n)
{
	unsigned char	*uc_block1;
	unsigned char	*uc_block2;
	size_t			i;

	uc_block1 = (unsigned char *)block1;
	uc_block2 = (unsigned char *)block2;
	i = 0;
	while (i < n)
	{
		if (uc_block1[i] != uc_block2[i])
		{
			return (uc_block1[i] - uc_block2[i]);
		}
		i++;
	}
	return (0);
}
