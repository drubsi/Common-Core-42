/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:03:39 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:25:27 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_is_rectangular(t_game *game)
{
	int	count_rows;
	int	count_column;
	int	expected_column;

	count_rows = 0;
	if (game->map->column == game->map->rows)
		ft_error_2 ("The map must be rectangular", game);
	expected_column = ft_strlen(game->map->validate_map[0]);
	while (count_rows < game->map->rows)
	{
		count_column = ft_strlen (game->map->validate_map[count_rows]);
		if (count_column != expected_column)
			ft_error_2 ("The map must be rectangular", game);
		count_rows++;
	}
}

void	is_map_closed(t_game *game)
{
	int	count_line;
	int	count_char;

	count_line = 0;
	count_char = 0;
	while (count_line < game->map->rows)
	{
		while (count_char < game->map->column)
		{
			if (game->map->map[0][count_char] != '1'
				|| game->map->map[game->map->rows - 1][count_char] != '1')
				ft_error_2("The map must be surrounded by walls", game);
			if (game->map->map[count_line][0] != '1'
				|| game->map->map[count_line][game->map->column - 1] != '1')
				ft_error_2("The map must be surrounded by walls", game);
			count_char++;
		}
		count_char = 0;
		count_line++;
	}
}

int	check_map_elements(t_game *game, char line)
{
	if (line == 'P')
		game->map->validate_player += 1;
	else if (line == 'E')
		game->map->validate_exit += 1;
	else if (line == 'C')
		game->map->validate_collect += 1;
	game->map->n_player = game->map->validate_player;
	game->map->n_exit = game->map->validate_exit;
	game->map->n_collectibles = game->map->validate_collect;
	return (0);
}

void	check_characters(t_game *game)
{
	int	rows;
	int	column;

	rows = 1;
	column = 1;
	while (rows < game->map->rows - 1)
	{
		while (column < game->map->column - 1)
		{
			if (game->map->map[rows][column] != '1'
				&& game->map->map[rows][column] != '0'
				&& game->map->map[rows][column] != 'P'
				&& game->map->map[rows][column] != 'E'
				&& game->map->map[rows][column] != 'C')
				ft_error_2("The map can only contain chars 1/0/P/E/C", game);
			column++;
		}
		column = 1;
		rows++;
	}
}

void	validate_elements(t_game *game)
{
	if (game->map->n_player != 1 || game->map->n_exit != 1
		|| game->map->n_collectibles < 1)
		ft_error_2("Must have min/max one P one E and at least one C", game);
}
