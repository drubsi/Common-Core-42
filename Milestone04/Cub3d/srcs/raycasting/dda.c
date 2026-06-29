/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:17 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:18 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda_values(t_game *game, t_dda *dda)
{
	dda->hit_map_x = floor(game->player.pos.x);
	dda->hit_map_y = floor(game->player.pos.y);
	if (dda->ray_dir_x < 0)
		dda->step_x = -1;
	else
		dda->step_x = 1;
	if (dda->ray_dir_y < 0)
		dda->step_y = -1;
	else
		dda->step_y = 1;
	dda->delta_dist_x = fabs(1.0 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->ray_dir_y);
	if (dda->ray_dir_x < 0)
		dda->side_dist_x = (game->player.pos.x - dda->hit_map_x)
			* dda->delta_dist_x;
	else
		dda->side_dist_x = (dda->hit_map_x + 1.0 - game->player.pos.x)
			* dda->delta_dist_x;
	if (dda->ray_dir_y < 0)
		dda->side_dist_y = (game->player.pos.y - dda->hit_map_y)
			* dda->delta_dist_y;
	else
		dda->side_dist_y = (dda->hit_map_y + 1.0 - game->player.pos.y)
			* dda->delta_dist_y;
	dda->hit = 0;
}

static void	advance_dda_in_grid(t_game *game, t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->hit_map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->hit_map_y += dda->step_y;
		dda->side = 1;
	}
	if (game->map.grid[dda->hit_map_y][dda->hit_map_x] == '1')
		dda->hit = 1;
}

static void	calc_dda_dist(t_game *game, t_dda *dda)
{
	if (dda->side == 0)
		dda->dist = (dda->hit_map_x - game->player.pos.x
				+ (1 - dda->step_x) / 2.0) / dda->ray_dir_x;
	else
		dda->dist = (dda->hit_map_y - game->player.pos.y
				+ (1 - dda->step_y) / 2.0) / dda->ray_dir_y;
}

void	cast_ray(t_game *game, t_dda *dda)
{
	init_dda_values(game, dda);
	while (dda->hit == 0)
	{
		advance_dda_in_grid(game, dda);
	}
	calc_dda_dist(game, dda);
}
