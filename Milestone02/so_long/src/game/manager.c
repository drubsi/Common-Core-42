/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:08:26 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:46:46 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_map(t_game *game)
{
	map_is_rectangular (game);
	is_map_closed (game);
	validate_elements (game);
}

void	space_grid_map(t_game *game, const char *argv)
{
	int		fd;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
		ft_error_1 ("Failed to open map");
	read_and_init_map (fd, game);
	init_allocated_grids (game);
	close (fd);
}

void	copy_map_grid(t_game *game, const char *argv)
{
	int		fd;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
		ft_error_1 ("Failed to open map");
	copy_map (fd, game);
	close (fd);
	max_size (game);
	check_characters (game);
	copy_validate_map (game);
}

void	renderized_map(t_game *game)
{
	render_map_1 (game);
	render_map_2 (game);
	render_map_3 (game);
}

void	init_allocated_grids(t_game *game)
{
	allocate_grid (&game->map->map, game->map->rows, game->map->column);
	allocate_grid (&game->map->validate_map,
		game->map->rows, game->map->column);
}
