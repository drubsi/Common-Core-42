/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:35 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 16:41:35 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
//Carga de textures y sprites
void	load_textures(t_game *game)
{
	game->texture->texture_grass = mlx_load_png (PNG_GRASS);
	game->texture->texture_wall = mlx_load_png (PNG_WALL);
	game->texture->texture_exit_close = mlx_load_png (PNG_EXIT_CLOSE);
	game->texture->texture_exit_open = mlx_load_png (PNG_EXIT_OPEN);
	game->texture->texture_player_right = mlx_load_png (PNG_PIKA_RIGHT);
	game->texture->texture_collectible = mlx_load_png (PNG_COLLECTIBLE);
	if (!game->texture->texture_grass || !game->texture->texture_wall
		|| !game->texture->texture_exit_close
		|| !game->texture->texture_exit_open
		|| !game->texture->texture_player_right
		|| !game->texture->texture_collectible)
		ft_error_2 ("Failed to load textures", game);
}

void	load_images(t_game *game)
{
	game->images->img_grass = mlx_texture_to_image (game->mlx,
			game->texture->texture_grass);
	game->images->img_wall = mlx_texture_to_image (game->mlx,
			game->texture->texture_wall);
	game->images->img_exit_close = mlx_texture_to_image (game->mlx,
			game->texture->texture_exit_close);
	game->images->img_exit_open = mlx_texture_to_image (game->mlx,
			game->texture->texture_exit_open);
	game->images->img_player_right = mlx_texture_to_image (game->mlx,
			game->texture->texture_player_right);
	game->images->img_collectible = mlx_texture_to_image (game->mlx,
			game->texture->texture_collectible);
	if (!game->images->img_grass || !game->images->img_wall
		|| !game->images->img_exit_close || !game->images->img_exit_open
		|| !game->images->img_player_right || !game->images->img_collectible)
		ft_error_2 ("Failed to load images", game);
}
