/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:18:57 by adeestev          #+#    #+#             */
/*   Updated: 2024/12/08 11:21:16 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void ft_is_even(unsigned int i, char *str)
{
		if (i % 2 == 0)
			*str = '_';
}

int	main(void)
{
	char	str[] = "Every char in even position will be changed";
	printf("Before the function applied my string is:\n%s\n", str);
	ft_striteri(str, ft_is_even);
	printf("After the function applied my string is:\n%s\n", str);
	return (0);
}
*/