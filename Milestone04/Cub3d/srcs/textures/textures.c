/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:17 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:19 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game)
{
	game->textures.north = mlx_load_png(game->textures.no_path);
	if (!game->textures.north)
		return (error_msg("Failed to load the north texture"), 0);
	if (game->textures.north->width > 512 || game->textures.north->height > 512)
		return (error_msg("Invalid texture size (max size 512 x 512)"), 0);
	game->textures.south = mlx_load_png(game->textures.so_path);
	if (!game->textures.south)
		return (error_msg("Failed to load the south texture"), 0);
	if (game->textures.south->width > 512 || game->textures.south->height > 512)
		return (error_msg("Invalid texture size (max size 512 x 512)"), 0);
	game->textures.east = mlx_load_png(game->textures.ea_path);
	if (!game->textures.east)
		return (error_msg("Failed to load the east texture"), 0);
	if (game->textures.east->width > 512 || game->textures.east->height > 512)
		return (error_msg("Invalid texture size (max size 512 x 512)"), 0);
	game->textures.west = mlx_load_png(game->textures.we_path);
	if (!game->textures.west)
		return (error_msg("Failed to load the west texture"), 0);
	if (game->textures.west->width > 512 || game->textures.west->height > 512)
		return (error_msg("Invalid texture size (max size 512 x 512)"), 0);
	return (1);
}
