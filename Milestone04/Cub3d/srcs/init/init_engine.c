/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:27 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:28 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_safe_images(t_images *images)
{
	images->frame = NULL;
}

void	init_safe_render(t_render *render)
{
	render->color = 0;
	render->height = SCREEN_HEIGHT;
	render->width = SCREEN_WIDTH;
}

void	init_safe_player(t_player *player)
{
	player->angle_total = 0;
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->pos.x = 0;
	player->pos.y = 0;
}

void	init_safe_input(t_input *input)
{
	input->mouse_dx = 0;
	input->center_x = 0;
}

void	init_safe_dda(t_dda *dda)
{
	dda->line_height = 0;
	dda->delta_dist_x = 0;
	dda->delta_dist_y = 0;
	dda->dist = 0;
	dda->draw_end = 0;
	dda->draw_start = 0;
	dda->hit = 0;
	dda->hit_map_x = 0;
	dda->hit_map_y = 0;
	dda->dda_face = 0;
	dda->ray_dir_x = 0;
	dda->ray_dir_y = 0;
	dda->screen_center_y = 0;
	dda->side = 0;
	dda->side_dist_x = 0;
	dda->side_dist_y = 0;
	dda->step_x = 0;
	dda->step_y = 0;
	dda->tex_pos = 0;
	dda->tex_step = 0;
	dda->tex_x = 0;
	dda->tex_y = 0;
	dda->wall_hit = 0;
}
