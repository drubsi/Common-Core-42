/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:29 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:30 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update(void *param)
{
	t_game	*game;
	double	angle;

	game = (t_game *)param;
	angle = 0;
	press_keys(game, &angle);
	if (game->input.mouse_dx != 0)
	{
		angle += game->input.mouse_dx * 0.0005;
		game->player.angle_total += angle;
		game->input.mouse_dx = 0;
	}
	if (angle != 0)
	{
		apply_rotation(game, angle);
		game->player.angle_total += angle;
	}
	mlx_set_mouse_pos(game->mlx, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	render_frame(game);
}
