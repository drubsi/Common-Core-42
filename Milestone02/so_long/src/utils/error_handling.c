/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:00:47 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 19:50:10 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error_1(char *str_error)
{
	ft_printf ("Error\n%s.\n", str_error);
	exit (1);
}

void	ft_error_2(char *str_error, t_game *game)
{
	ft_printf ("Error.\n%s.\n", str_error);
	if (game)
	{
		if (game->texture)
			free_textures (game);
		if (game->images)
			free_images (game);
		if (game->map)
			free_grids (game);
		if (game->mlx)
			mlx_close_window (game->mlx);
		free_structs (game);
		exit (2);
	}
}
