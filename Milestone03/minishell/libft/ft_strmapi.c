/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:31:19 by adeestev          #+#    #+#             */
/*   Updated: 2024/12/08 09:27:42 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
#include <stdio.h>

char ft_is_even(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
    else
        return ('_');
}

int	main(void)
{
	char const	*str = "Every char in even position will be changed";
	char	*updated_str = ft_strmapi(str, ft_is_even);
	printf("%s\n", updated_str);
	free(updated_str);
	return (0);
}
*/