/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:47 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:49 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mm_draw_player(t_game *game, t_rect *rectangle_ctx,
	t_mm *minimap_ctx)
{
	int	player_size;

	player_size = 5;
	rectangle_ctx->color = 0xFF0000FF;
	rectangle_ctx->x = minimap_ctx->player_pixel_x - (player_size / 2);
	rectangle_ctx->y = minimap_ctx->player_pixel_y - (player_size / 2);
	rectangle_ctx->height_px = player_size;
	rectangle_ctx->width_px = player_size;
	mm_fill_rect(game, rectangle_ctx);
}

static void	mm_draw_dir(t_game *game, t_mm *minimap_ctx, t_rect *rectangle_ctx)
{
	double	ray_x;
	double	ray_y;
	int		step;
	int		length_pixels;

	ray_x = minimap_ctx->player_pixel_x;
	ray_y = minimap_ctx->player_pixel_y;
	length_pixels = minimap_ctx->scale;
	step = 0;
	rectangle_ctx->width_px = game->map.width * minimap_ctx->scale;
	rectangle_ctx->height_px = game->map.height * minimap_ctx->scale;
	while (step < length_pixels)
	{
		ray_x += game->player.dir.x;
		ray_y += game->player.dir.y;
		if (ray_x > 0 && ray_y > 0 && ray_x <= rectangle_ctx->width_px
			&& ray_y <= rectangle_ctx->height_px)
			mlx_put_pixel(game->images.frame, (int)ray_x,
				(int)ray_y, 0x0000FF);
		step++;
	}
}

static void	mm_draw_wall(t_game *game, t_rect *rectangle_ctx, t_mm *minimap_ctx)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	rectangle_ctx->color = 0x000000FF;
	rectangle_ctx->height_px = minimap_ctx->scale;
	rectangle_ctx->width_px = minimap_ctx->scale;
	while (map_y < game->map.height)
	{
		map_x = 0;
		while (map_x < game->map.width)
		{
			if (game->map.grid[map_y][map_x] == '1')
			{
				rectangle_ctx->x = minimap_ctx->origin_x
					+ map_x * minimap_ctx->scale;
				rectangle_ctx->y = minimap_ctx->origin_y
					+ map_y * minimap_ctx->scale;
				mm_fill_rect(game, rectangle_ctx);
			}
			map_x++;
		}
		map_y++;
	}
}

static void	mm_raycast(t_game *game, t_rect *rectangle_ctx, t_mm *mm_ctx)
{
	double	ray_x;
	double	ray_y;
	int		step;

	rectangle_ctx->width_px = game->map.width * mm_ctx->scale;
	rectangle_ctx->height_px = game->map.height * mm_ctx->scale;
	ray_x = game->player.pos.x;
	ray_y = game->player.pos.y;
	step = 0;
	while (step < game->map.width * game->map.height)
	{
		ray_x += game->player.dir.x * 0.05;
		ray_y += game->player.dir.y * 0.05;
		mm_ctx->map_x = floor(ray_x);
		mm_ctx->map_y = floor(ray_y);
		if (mm_ctx->map_x < 0 || mm_ctx->map_x >= game->map.width
			|| mm_ctx->map_y < 0 || mm_ctx->map_y >= game->map.height
			|| game->map.grid[mm_ctx->map_y][mm_ctx->map_x] == '1')
			break ;
		mm_ctx->ray_px_x = mm_ctx->origin_x + ray_x * mm_ctx->scale;
		mm_ctx->ray_px_y = mm_ctx->origin_y + ray_y * mm_ctx->scale;
		mlx_put_pixel(game->images.frame, (int)mm_ctx->ray_px_x,
			(int)mm_ctx->ray_px_y, 0x00FF00FF);
		step++;
	}
}

void	draw_minimap(t_game *game)
{
	t_mm	minimap_ctx;
	t_rect	rectangle_ctx;

	if (!game->map.grid)
		return ;
	init_mm_ctx(&minimap_ctx, game);
	rectangle_ctx.x = 10;
	rectangle_ctx.y = 10;
	rectangle_ctx.width_px = game->map.width * minimap_ctx.scale;
	rectangle_ctx.height_px = game->map.height * minimap_ctx.scale;
	rectangle_ctx.color = 0x553311FF;
	draw_rectangle(&rectangle_ctx, game);
	mm_draw_wall(game, &rectangle_ctx, &minimap_ctx);
	mm_draw_player(game, &rectangle_ctx, &minimap_ctx);
	mm_draw_dir(game, &minimap_ctx, &rectangle_ctx);
	mm_raycast(game, &rectangle_ctx, &minimap_ctx);
}
