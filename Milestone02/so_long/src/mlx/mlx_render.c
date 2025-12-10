/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:03:20 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:29:01 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_map_1(t_game *game)
{
	int	rows;
	int	column;

	rows = 0;
	while (rows < game->map->rows)
	{
		column = 0;
		while (column < game->map->column)
		{
			if (game->map->map[rows][column] == '1')
				if (mlx_image_to_window(game->mlx,
						game->images->img_wall,
						column * SIZE, rows * SIZE) < 0)
					ft_error_2 ("Failed to load images on map", game);
			if (game->map->map[rows][column] == '0')
				if (mlx_image_to_window(game->mlx,
						game->images->img_grass,
						column * SIZE, rows * SIZE) < 0)
					ft_error_2 ("Failed to load images on map", game);
			column++;
		}
		rows++;
	}
}

void	render_map_2(t_game *game)
{
	int	rows;
	int	column;

	rows = 0;
	while (rows < game->map->rows)
	{
		column = 0;
		while (column < game->map->column)
		{
			if (game->map->map[rows][column] == 'P')
				if (mlx_image_to_window(game->mlx,
						game->images->img_player_right,
						column * SIZE, rows * SIZE) < 0)
					ft_error_2 ("Failed to load images on map", game);
			if (game->map->map[rows][column] == 'E')
				if (mlx_image_to_window(game->mlx,
						game->images->img_exit_close,
						column * SIZE, rows * SIZE) < 0)
					ft_error_2 ("Failed to load images on map", game);
			column++;
		}
		rows++;
	}
}

void	render_map_3(t_game *game)
{
	int	rows;
	int	column;

	rows = 0;
	while (rows < game->map->rows)
	{
		column = 0;
		while (column < game->map->column)
		{
			if (game->map->map[rows][column] == 'C')
				if (mlx_image_to_window(game->mlx,
						game->images->img_collectible,
						column * SIZE, rows * SIZE) < 0)
					ft_error_2 ("Failed to load images on map", game);
			column++;
		}
		rows++;
	}
}

void	refresh_escene(t_game *game, int old_check_x, int old_check_y)
{
	if (mlx_image_to_window(game->mlx, game->images->img_grass,
			old_check_y * SIZE, old_check_x * SIZE) < 0)
		ft_error_2 ("Failed to load images on map", game);
	if (mlx_image_to_window(game->mlx, game->images->img_player_right,
			game->map->check_y * SIZE, game->map->check_x * SIZE) < 0)
		ft_error_2 ("Failed to load images on map", game);
	if ((game->map->map[game->map->check_x][game->map->check_y]
		!= 'E' && game->map->n_collectibles != 0))
		if (mlx_image_to_window(game->mlx,
				game->images->img_exit_close,
				game->map->check_y_exit * SIZE,
				game->map->check_x_exit * SIZE) < 0)
			ft_error_2 ("Failed to load images on map", game);
}
