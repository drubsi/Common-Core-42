/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:50:22 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:50:26 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!s || !f)
		return (NULL);
	if (!new_s)
		return (NULL);
	while (s[i] != '\0')
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
