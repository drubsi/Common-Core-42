/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:28:00 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:02 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
//Eventos de teclado y movimiento del jugador
void	validate_cell(t_game *game, int old_check_x, int old_check_y)
{
	if (game->map->map[game->map->check_x][game->map->check_y] == '1')
	{
		game->map->check_x = old_check_x;
		game->map->check_y = old_check_y;
		return ;
	}
	else
		game->map->mov_count++;
	if (game->map->map[game->map->check_x][game->map->check_y] == 'C')
	{
		game->map->n_collectibles--;
		game->map->map[game->map->check_x][game->map->check_y] = 'V';
	}
	ft_printf ("Movimientos Realizados: %d\n", game->map->mov_count);
	victory (game);
}

void	move_player(t_game *game, int direction)
{
	int	old_check_x;
	int	old_check_y;

	old_check_x = game->map->check_x;
	old_check_y = game->map->check_y;
	if (direction == UP)
		game->map->check_x -= 1;
	else if (direction == DOWN)
		game->map->check_x += 1;
	else if (direction == RIGHT)
		game->map->check_y += 1;
	else if (direction == LEFT)
		game->map->check_y -= 1;
	validate_cell (game, old_check_x, old_check_y);
	refresh_escene (game, old_check_x, old_check_y);
}

void	process_input(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player (game, UP);
		else if (keydata.key == MLX_KEY_S)
			move_player (game, DOWN);
		else if (keydata.key == MLX_KEY_A)
			move_player (game, LEFT);
		else if (keydata.key == MLX_KEY_D)
			move_player (game, RIGHT);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window (game->mlx);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		process_input (keydata, game);
	}
}

void	victory(t_game *game)
{
	if (game->map->n_collectibles == 0)
	{
		mlx_delete_image (game->mlx, game->images->img_exit_close);
		mlx_image_to_window (game->mlx, game->images->img_exit_open,
			game->map->check_y_exit * SIZE, game->map->check_x_exit * SIZE);
	}
	if (game->map->map[game->map->check_x][game->map->check_y]
			== 'E' && game->map->n_collectibles == 0)
	{
		ft_printf ("You Win!\n");
		mlx_close_window (game->mlx);
	}
}
