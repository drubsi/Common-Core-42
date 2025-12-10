/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:25:01 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 16:40:27 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
//Inicializacion de MLX42 y ventana
int32_t	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map->column * WIDTH,
			game->map->rows * HEIGHT, "So_long Game", true);
	{
		if (!game->mlx)
			ft_error_2 ("Failed to start window", game);
	}
	load_textures(game);
	load_images(game);
	renderized_map(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_close_hook(game->mlx, &close_window, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
