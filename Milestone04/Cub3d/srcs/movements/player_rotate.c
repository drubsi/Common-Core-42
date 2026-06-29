/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:00 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:01 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	apply_rotation(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cosine;
	double	sine;

	cosine = cos(angle);
	sine = sin(angle);
	old_dir_x = game->player.dir.x;
	old_plane_x = game->player.plane.x;
	game->player.dir.x
		= game->player.dir.x * cosine - game->player.dir.y * sine;
	game->player.dir.y = old_dir_x * sine + game->player.dir.y * cosine;
	game->player.plane.x
		= game->player.plane.x * cosine - game->player.plane.y * sine;
	game->player.plane.y = old_plane_x * sine + game->player.plane.y * cosine;
}
