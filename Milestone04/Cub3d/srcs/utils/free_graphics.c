/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:13:44 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:13:47 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north)
	{
		mlx_delete_texture(textures->north);
		textures->north = NULL;
	}
	if (textures->south)
	{
		mlx_delete_texture(textures->south);
		textures->south = NULL;
	}
	if (textures->east)
	{
		mlx_delete_texture(textures->east);
		textures->east = NULL;
	}
	if (textures->west)
	{
		mlx_delete_texture(textures->west);
		textures->west = NULL;
	}
}

void	free_mlx(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
}

void	free_images(t_game *game)
{
	if (game->mlx && game->images.frame)
		mlx_delete_image(game->mlx, game->images.frame);
	game->images.frame = NULL;
}
