/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:21 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:22 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game_mlx(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", false);
	if (!game->mlx)
	{
		error_msg("Error: failed to initialize MLX");
		return (0);
	}
	if (!load_textures(game))
		return (0);
	game->images.frame = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->images.frame)
	{
		error_msg("Error: failed to create MLX image");
		return (0);
	}
	if (mlx_image_to_window(game->mlx, game->images.frame, 0, 0) < 0)
	{
		error_msg("Error: failed to attach image to window");
		return (0);
	}
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_loop_hook(game->mlx, update, game);
	mlx_close_hook(game->mlx, &close_window, game);
	return (1);
}
