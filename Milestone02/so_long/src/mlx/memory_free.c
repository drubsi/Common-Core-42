/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:56 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 10:31:13 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_textures(t_game *game)
{
	if (!game->texture)
		return ;
	if (game->texture->texture_grass)
		mlx_delete_texture (game->texture->texture_grass);
	if (game->texture->texture_wall)
		mlx_delete_texture (game->texture->texture_wall);
	if (game->texture->texture_exit_close)
		mlx_delete_texture (game->texture->texture_exit_close);
	if (game->texture->texture_exit_open)
		mlx_delete_texture (game->texture->texture_exit_open);
	if (game->texture->texture_player_right)
		mlx_delete_texture (game->texture->texture_player_right);
	if (game->texture->texture_collectible)
		mlx_delete_texture (game->texture->texture_collectible);
}

void	free_images(t_game *game)
{
	if (!game->images)
		return ;
	if (game->images->img_grass)
		mlx_delete_image (game->mlx, game->images->img_grass);
	if (game->images->img_wall)
		mlx_delete_image (game->mlx, game->images->img_wall);
	if (game->images->img_exit_close)
		mlx_delete_image (game->mlx, game->images->img_exit_close);
	if (game->images->img_exit_open)
		mlx_delete_image (game->mlx, game->images->img_exit_open);
	if (game->images->img_player_right)
		mlx_delete_image (game->mlx, game->images->img_player_right);
	if (game->images->img_collectible)
		mlx_delete_image (game->mlx, game->images->img_collectible);
}

void	free_grids(t_game *game)
{
	int	rows;

	rows = 0;
	if (!game->map->map || !game->map->validate_map)
		return ;
	while (rows < game->map->rows)
	{
		free (game->map->map[rows]);
		free (game->map->validate_map[rows]);
		rows++;
	}
	free (game->map->map);
	free (game->map->validate_map);
}

void	free_structs(t_game *game)
{
	if (!game)
		return ;
	if (game->texture)
		free (game->texture);
	if (game->images)
		free (game->images);
	if (game->map)
		free (game->map);
	if (game->mlx)
		mlx_terminate (game->mlx);
	free (game);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures (game);
	free_images (game);
	free_grids (game);
	free_structs (game);
}
