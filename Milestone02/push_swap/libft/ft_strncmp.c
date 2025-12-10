/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:50:39 by drubio-s          #+#    #+#             */
/*   Updated: 2024/10/11 07:50:41 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

int main() {
    // Casos de prueba
    const char *test1_a = "Hello, World!";
    const char *test1_b = "Hello, World!";
    const char *test2_a = "Hello, World!";
    const char *test2_b = "Hello, there!";
    const char *test3_a = "Hello";
    const char *test3_b = "Hello, World!";
    const char *test4_a = "Hi";
    const char *test4_b = "Hello, World!";
    const char *test5_a = "Hello, World!";
    const char *test5_b = "Hello, World!";
    const char *test6_a = "Hello";
    const char *test6_b = "Hello, World!";
    const char *test7_a = "Hello, World!";
    const char *test7_b = "Hello";
    
    // Prueba con diferentes valores de n
    size_t n1 = 13; // Comparar toda la cadena
    size_t n2 = 5;  // Comparar los primeros 5 caracteres
    size_t n3 = 0;  // Comparar 0 caracteres
    size_t n4 = 5;  // Comparar hasta el quinto carácter
    size_t n5 = 20; // Comparar más de la longitud de la cadena
    
    printf("Test 1 (Equal): %d\n", ft_strncmp(test1_a, test1_b, n1)); 
	// Debe devolver 0
    printf("Test 2 (Different): %d\n", ft_strncmp(test2_a, test2_b, n1)); 
	// Debe devolver un valor < 0
    printf("Test 3 (s1 shorter): %d\n", ft_strncmp(test3_a, test3_b, n2)); 
	// Debe devolver 0
    printf("Test 4 (s2 shorter): %d\n", ft_strncmp(test4_b, test4_a, n4)); 
	// Debe devolver < 0
    printf("Test 5 (Equal, with n < length):
	%d\n", ft_strncmp(test5_a, test5_b, n2));
	// Debe devolver 0
    printf("Test 6 (s1 shorter with longer n):
	%d\n", ft_strncmp(test6_a, test6_b, n5));
	// Debe devolver < 0
    printf("Test 7 (s2 shorter with longer n):
	%d\n", ft_strncmp(test7_a, test7_b, n5));
	// Debe devolver > 0
    printf("Test 8 (n = 0): %d\n", ft_strncmp(test1_a, test1_b, n3));
	// Debe devolver 0
    
    return 0;
}
*/
