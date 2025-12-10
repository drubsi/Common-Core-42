/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:41:10 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:29:41 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Funciones de inicializacion de memoria*/
#include "../../includes/so_long.h"//OK

void	*init_memory_struct(size_t size)
{
	void	*new_struct;

	new_struct = ft_calloc (1, size);
	if (!new_struct)
		ft_error_1("Failed to initialize structure memory");
	return (new_struct);
}

void	*allocate_grid(char ***grid, int height, int width)
{
	int	i;

	i = 0;
	*grid = ft_calloc (height, sizeof(char *));
	if (!*grid)
		ft_error_1("Failed to initialize array memory");
	while (i < height)
	{
		(*grid)[i] = ft_calloc (width + 1, sizeof(char));
		if (!(*grid)[i])
		{
			while (--i >= 0)
				free ((*grid)[i]);
			free (*grid);
			ft_error_1("Failed to initialize structure memory");
		}
		i++;
	}
	return (*grid);
}
