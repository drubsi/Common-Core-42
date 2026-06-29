/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:14:25 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:14:27 by cvon-hee         ###   ########.fr       */
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
	{
		apply_rotation(game, angle);
		game->player.angle_total += angle;
	}
	render_frame(game);
}
