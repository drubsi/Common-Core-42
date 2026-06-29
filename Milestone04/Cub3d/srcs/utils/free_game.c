/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:13:56 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:00 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map.grid);
	free_images(game);
	free_path_textures(&game->textures);
	free_textures(&game->textures);
	free_mlx(game->mlx);
	get_next_line(-1);
}
