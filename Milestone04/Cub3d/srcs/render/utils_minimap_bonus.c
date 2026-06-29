/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:36 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:37 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mm_fill_rect(t_game *game, t_rect *rectangle)
{
	int	y;
	int	x;

	y = 0;
	while (y < rectangle->height_px)
	{
		x = 0;
		while (x < rectangle->width_px)
		{
			mlx_put_pixel(game->images.frame, (rectangle->x + x),
				(rectangle->y + y), rectangle->color);
			x++;
		}
		y++;
	}
}

void	init_mm_ctx(t_mm *mm_ctx, t_game *game)
{
	mm_ctx->origin_x = 10;
	mm_ctx->origin_y = 10;
	mm_ctx->scale = 12;
	mm_ctx->player_pixel_x = mm_ctx->origin_x
		+ (int)(game->player.pos.x * mm_ctx->scale);
	mm_ctx->player_pixel_y = mm_ctx->origin_y
		+ (int)(game->player.pos.y * mm_ctx->scale);
}

void	draw_rectangle(t_rect *rectangle, t_game *game)
{
	mm_fill_rect(game, rectangle);
}
