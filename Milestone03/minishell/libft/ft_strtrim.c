/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:41 by adeestev          #+#    #+#             */
/*   Updated: 2024/11/26 09:06:32 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	if ((char *)s1 == NULL || (char *)set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	len = j - i + 1;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + i, len + 1);
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "abcabcHelloabcWorldcbaacc";
	char	*set = "abc";

	printf("Original string is: %s\n", str);
	printf("Set to search is: %s\n", set);
	printf("Trimmed string is: %s\n", ft_strtrim(str, set));
	return (0);
}
*/
