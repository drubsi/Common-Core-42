/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:16:13 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:16:18 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_keys(t_game *game, double *angle)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window (game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		*angle -= ROT_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		*angle += ROT_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward_backward(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_forward_backward(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left_right(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_left_right(game, 1);
}
