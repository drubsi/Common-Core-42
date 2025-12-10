/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:44 by adeestev          #+#    #+#             */
/*   Updated: 2025/10/05 11:17:06 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *dst, const char *src, size_t *i)
{
	size_t	j;

	j = 0;
	if (!src)
		return ;
	while (src[j])
	{
		dst[*i] = src[j];
		(*i)++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	total_len;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(total_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	copy_str(res, s1, &i);
	copy_str(res, s2, &i);
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "welcome";
	char	*str2 = "people";

	printf("%s\n", ft_strjoin(str, str2));
	return (0);
}
*/
