/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:32 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:33 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	if (!game)
		return ;
	ft_bzero(game, sizeof(t_game));
	game->floor_color = -1;
	game->ceiling_color = -1;
}

void	init_safe_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	init_safe_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->no_path = NULL;
	textures->south = NULL;
	textures->so_path = NULL;
	textures->east = NULL;
	textures->ea_path = NULL;
	textures->west = NULL;
	textures->we_path = NULL;
}

void	init_safe_game(t_game *game)
{
	init_safe_map(&game->map);
	init_safe_player(&game->player);
	init_safe_textures(&game->textures);
	init_safe_images(&game->images);
	init_safe_render(&game->render);
	init_safe_input(&game->input);
	game->mlx = NULL;
	game->ceiling_color = -1;
	game->floor_color = -1;
}
