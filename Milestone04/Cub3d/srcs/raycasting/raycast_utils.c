/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:07 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:08 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_projection(mlx_image_t *img, t_dda *dda)
{
	dda->line_height = img->height / dda->dist;
	dda->screen_center_y = img->height / 2;
	dda->draw_start = dda->screen_center_y - (dda->line_height / 2);
	dda->draw_end = dda->screen_center_y + (dda->line_height / 2);
}

void	get_wall_face(t_dda *dda)
{
	if (dda->side == 1)
	{
		if (dda->ray_dir_y < 0)
			dda->dda_face = SOUTH;
		else
			dda->dda_face = NORTH;
	}
	else if (dda->side == 0)
	{
		if (dda->ray_dir_x < 0)
			dda->dda_face = EAST;
		else
			dda->dda_face = WEST;
	}
}

void	calc_wall_hit(t_game *game, t_dda *dda)
{
	if (dda->side == 1)
		dda->wall_hit = (game->player.pos.x + dda->ray_dir_x * dda->dist);
	else
		dda->wall_hit = (game->player.pos.y + dda->ray_dir_y * dda->dist);
	dda->wall_hit -= floor(dda->wall_hit);
}

void	calc_text_x(t_dda *dda, mlx_texture_t *tex)
{
	double	tex_x_precise;

	tex_x_precise = dda->wall_hit * tex->width;
	if (dda->side == 0 && dda->ray_dir_x < 0)
		tex_x_precise = tex->width - tex_x_precise - 1;
	else if (dda->side == 1 && dda->ray_dir_y > 0)
		tex_x_precise = tex->width - tex_x_precise - 1;
	dda->tex_x = (int)tex_x_precise;
	if (dda->tex_x < 0)
		dda->tex_x = 0;
	if (dda->tex_x >= (int)tex->width)
		dda->tex_x = (int)tex->width - 1;
}

void	setup_tex_vertical(t_dda *dda, mlx_texture_t *tex)
{
	dda->tex_step = (double)tex->height / dda->line_height;
	dda->tex_pos = (dda->draw_start - SCREEN_HEIGHT / 2
			+ dda->line_height / 2) * dda->tex_step;
}
