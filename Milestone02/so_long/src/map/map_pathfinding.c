/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:03:07 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 19:41:30 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_within_bounds(t_game *game, int x, int y)
{
	return (x >= 1 && x < game->map->rows - 1
		&& y >= 1 && y < game->map->column - 1);
}

void	check_coordinate_player(t_game *game)
{
	int	rows;
	int	column;

	rows = 1;
	column = 1;
	while (rows < game->map->rows - 1)
	{
		while (column < game->map->column - 1)
		{
			if (game->map->map[rows][column] == 'P')
			{
				game->map->check_x = rows;
				game->map->check_y = column;
			}
			else if (game->map->map[rows][column] == 'E')
			{
				game->map->check_x_exit = rows;
				game->map->check_y_exit = column;
			}
			column++;
		}
		column = 1;
		rows++;
	}
}

int	check_cell(t_game *game, char *cell)
{
	if (!cell)
		return (0);
	if (*cell == '1' || *cell == 'V')
		return (0);
	if (*cell == 'C')
		game->map->validate_collect--;
	if (*cell == 'E')
		game->map->validate_exit = 0;
	if (*cell == 'P')
	{
		*cell = 'V';
		game->map->validate_player = 0;
		return (0);
	}
	*cell = 'V';
	return (1);
}

int	map_map(t_game *game, int x, int y)
{
	static const int	dx[4] = {-1, 1, 0, 0};
	static const int	dy[4] = {0, 0, -1, 1};
	int					i;
	int					new_x;
	int					new_y;

	i = 0;
	while (i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (is_within_bounds(game, new_x, new_y))
		{
			if (check_cell (game, &game->map->validate_map[new_x][new_y]) == 1)
			{
				if (game->map->validate_exit == 0
					&& game->map->validate_collect == 0)
					return (1);
				if (map_map (game, new_x, new_y))
					return (1);
			}
		}
		i++;
	}
	return (0);
}

void	track_map(t_game *game)
{
	check_coordinate_player (game);
	while (game->map->validate_player != 0 && game->map->validate_exit != 0
		&& game->map->validate_collect != 0)
	{
		if (map_map (game, game->map->check_x, game->map->check_y) != 1)
			ft_error_2("There is no valid route on the map", game);
	}
}
