/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:51:23 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:51:29 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		i;
	char	*lc;

	i = 0;
	lc = NULL;
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
		{
			lc = (char *)&src[i];
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
	return (lc);
}
/*
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *src, char c);

int main() {
    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "Programming in C";
    const char *test_str3 = "";
    const char *test_str4 = NULL;

    // Caso 1: Caracter que existe en la cadena
    char *result1 = ft_strrchr(test_str1, 'o');
    if (result1)
        printf("Encontrado en test_str1: %s\n", result1);
    else
        printf("No encontrado en test_str1\n");

    // Caso 2: Caracter que no existe en la cadena
    char *result2 = ft_strrchr(test_str2, 'z');
    if (result2)
        printf("Encontrado en test_str2: %s\n", result2);
    else
        printf("No encontrado en test_str2\n");

    // Caso 3: Cadena vacía
    char *result3 = ft_strrchr(test_str3, 'a');
    if (result3)
        printf("Encontrado en test_str3: %s\n", result3);
    else
        printf("No encontrado en test_str3\n");

    // Caso 4: Cadena NULL
    char *result4 = ft_strrchr(test_str4, 'a');
    if (result4)
        printf("Encontrado en test_str4: %s\n", result4);
    else
        printf("No encontrado en test_str4\n");

    // Caso 5: Buscando el último carácter
    char *result5 = ft_strrchr(test_str1, 'l');
    if (result5)
        printf("Encontrado en test_str1 (último 'l'): %s\n", result5);
    else
        printf("No encontrado en test_str1 (último 'l')\n");

    return 0;
}
*/
