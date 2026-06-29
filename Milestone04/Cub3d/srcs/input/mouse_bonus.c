/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:10 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:11 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cursor_callback(double xpos, double ypos, void *param)
{
	t_game	*game;
	double	dx_event;

	(void)ypos;
	game = (t_game *)param;
	game->input.center_x = (SCREEN_WIDTH / 2);
	dx_event = xpos - game->input.center_x;
	game->input.mouse_dx += dx_event;
}
