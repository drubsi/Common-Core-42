/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:03 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:04 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player forward or backward along their current direction 
 * 			vector.
 *    Includes basic wall collision detection to allow sliding against walls.
 * 
 * @param game The main game structure containing map and player context.
 * @param dir_sign 1.0 to move forward (W), -1.0 to move backward (S).
 */

void	move_forward_backward(t_game *game, double dir_sign)
{
	double	new_x;
	double	new_y;
	double	offset_x;
	double	offset_y;

	offset_x = game->player.dir.x * PLAYER_RADIUS * dir_sign;
	offset_y = game->player.dir.y * PLAYER_RADIUS * dir_sign;
	new_x = game->player.pos.x + game->player.dir.x * MOVE_SPEED * dir_sign;
	new_y = game->player.pos.y + game->player.dir.y * MOVE_SPEED * dir_sign;
	if (game->map.grid[(int)(game->player.pos.y)]
		[(int)(new_x + offset_x)] != '1')
		game->player.pos.x = new_x;
	if (game->map.grid[(int)(new_y + offset_y)]
		[(int)(game->player.pos.x)] != '1')
		game->player.pos.y = new_y;
}

/**
 * @brief Moves the player left or right (strafing) perpendicular to their 
 * 			direction. Includes basic wall collision detection.
 * 
 * @param game The main game structure.
 * @param dir_sign 1.0 to move right (D), -1.0 to move left (A).
 */

void	move_left_right(t_game *game, double dir_sign)
{
	double	new_x;
	double	new_y;
	double	offset_x;
	double	offset_y;

	offset_x = -game->player.dir.y * PLAYER_RADIUS * dir_sign;
	offset_y = game->player.dir.x * PLAYER_RADIUS * dir_sign;
	new_x = game->player.pos.x
		+ (-game->player.dir.y * MOVE_SPEED * dir_sign);
	new_y = game->player.pos.y
		+ (game->player.dir.x * MOVE_SPEED * dir_sign);
	if (game->map.grid[(int)(game->player.pos.y)]
		[(int)(new_x + offset_x)] != '1')
		game->player.pos.x = new_x;
	if (game->map.grid[(int)(new_y + offset_y)]
		[(int)(game->player.pos.x)] != '1')
		game->player.pos.y = new_y;
}
