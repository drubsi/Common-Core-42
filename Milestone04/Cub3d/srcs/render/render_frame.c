/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:40 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:41 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*get_texture_face(t_dda *dda, t_textures tex)
{
	if (dda->dda_face == 0)
		return (tex.north);
	else if (dda->dda_face == 1)
		return (tex.south);
	else if (dda->dda_face == 2)
		return (tex.east);
	else
		return (tex.west);
}

static int	get_color_draw(mlx_texture_t *tex, t_dda *dda)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	int				index;

	index = (dda->tex_y * tex->width + dda->tex_x) * 4;
	r = tex->pixels[index + 0];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	draw_wall_column(t_game *game, mlx_texture_t *tex,
								int x, t_dda *dda)
{
	int				start;
	int				end;
	int				color;

	start = dda->draw_start;
	end = dda->draw_end;
	if (start < 0)
		start = 0;
	if (end >= (int)game->images.frame->height)
		end = (int)game->images.frame->height - 1;
	dda->tex_pos += (start - dda->draw_start) * dda->tex_step;
	while (start < end)
	{
		dda->tex_y = (int)dda->tex_pos;
		if (dda->tex_y < 0)
			dda->tex_y = 0;
		if (dda->tex_y >= (int)tex->height)
			dda->tex_y = tex->height - 1;
		dda->tex_pos += dda->tex_step;
		color = get_color_draw(tex, dda);
		mlx_put_pixel(game->images.frame, x, start, color);
		start++;
	}
}

static void	init_ray_direction(int x, t_game *game, t_dda *dda)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)SCREEN_WIDTH - 1.0;
	dda->ray_dir_x = game->player.dir.x + game->player.plane.x * camera_x;
	dda->ray_dir_y = game->player.dir.y + game->player.plane.y * camera_x;
}

void	render_frame(t_game *game)
{
	int				x;
	t_dda			dda;
	mlx_texture_t	*tex;

	x = 0;
	draw_floor_ceiling(game);
	while (x < SCREEN_WIDTH)
	{
		init_safe_dda(&dda);
		init_ray_direction(x, game, &dda);
		cast_ray(game, &dda);
		calculate_wall_projection(game->images.frame, &dda);
		get_wall_face(&dda);
		calc_wall_hit(game, &dda);
		tex = get_texture_face(&dda, game->textures);
		if (!tex)
			continue ;
		calc_text_x(&dda, tex);
		setup_tex_vertical(&dda, tex);
		draw_wall_column(game, tex, x, &dda);
		x++;
	}
}
