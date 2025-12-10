/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:11:43 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/23 12:31:34 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(nmemb * size);
	i = 0;
	if (tmp == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	*arr2;
	size_t	i;
	size_t	count;

	count = 5;
	arr = (int *)ft_calloc(count, sizeof(int));
	arr2 = (int *)calloc(count, sizeof(int));

	i = 0;
	printf("arr content: \n");
	while (i < count)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	i = 0;
	printf("arr2 content: \n");
	while (i < count)
	{
		printf("%d ", arr2[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/
