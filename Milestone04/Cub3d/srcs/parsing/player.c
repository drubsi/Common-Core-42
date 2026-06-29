/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:24 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:27:39 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_dir(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir = (t_vector){0, -1};
		game->player.plane = (t_vector){0.66, 0};
	}
	else if (c == 'S')
	{
		game->player.dir = (t_vector){0, 1};
		game->player.plane = (t_vector){-0.66, 0};
	}
	else if (c == 'E')
	{
		game->player.dir = (t_vector){1, 0};
		game->player.plane = (t_vector){0, 0.66};
	}
	else if (c == 'W')
	{
		game->player.dir = (t_vector){-1, 0};
		game->player.plane = (t_vector){0, -0.66};
	}
}

/**
 * @brief Set the player orientation object
 * 
 * @param game main game structure
 * @param i row index
 * @param j column index
 * @return int 1 if player found, 0 if not
 */
static int	set_player_orientation(t_game *game, int i, int j)
{
	char	c;

	while (j < game->map.width)
	{
		c = game->map.grid[i][j];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos = (t_vector){j + 0.5, i + 0.5};
			init_player_dir(game, c);
			game->map.grid[i][j] = '0';
			return (1);
		}
		j++;
	}
	return (0);
}

/**
 * @brief Finds the player's initial position (N/S/E/W)
 * 
 * @param game main game structure
 * @return int 1 if found, 0 if not found
 */
int	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game || !game->map.grid)
		return (0);
	while (i < game->map.height)
	{
		j = 0;
		if (set_player_orientation(game, i, j))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks that there is exactly one player in the map
 * 
 * @param map 2D map
 * @return int 1 if exactly one, 0 if 0 or more than 1
 */
int	check_single_player(char **map)
{
	int	i;
	int	j;
	int	count;

	if (!map || !map[0])
		return (0);
	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count == 1);
}
