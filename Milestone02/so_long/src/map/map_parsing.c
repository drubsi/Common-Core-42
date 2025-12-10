/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:02:51 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:47:19 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Funciones para lectura y validacion del mapa*/
#include "../../includes/so_long.h"

void	read_and_init_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line (fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			check_map_elements(game, line[i]);
			i++;
		}
		if (i > game->map->column)
			game->map->column = i;
		game->map->rows += 1;
		free (line);
		line = get_next_line (fd);
	}
}

void	copy_map(int fd, t_game *game)
{
	char	*line;
	int		count_columns;
	int		count_rows;

	count_columns = 0;
	count_rows = 0;
	line = get_next_line (fd);
	while (line != NULL)
	{
		while (line[count_columns] != '\n' && line[count_columns] != '\0'
			&& count_columns < game->map->column)
		{
			game->map->map[count_rows][count_columns] = line[count_columns];
			count_columns++;
		}
		if (line[0] != '\n' && line[0] != '\0' && count_rows < game->map->rows)
		{
			game->map->map[count_rows][count_columns] = '\0';
			count_rows++;
			count_columns = 0;
		}
		free (line);
		line = get_next_line (fd);
	}
}

void	copy_validate_map(t_game *game)
{
	int	rows;
	int	column;

	rows = 0;
	column = 0;
	while (rows < game->map->rows)
	{
		while (column < game->map->column)
		{
			game->map->validate_map[rows][column]
				= game->map->map[rows][column];
			column++;
		}
		column = 0;
		rows++;
	}
}

void	max_size(t_game *game)
{
	if (game->map->rows > MAX_ROWS || game->map->column > MAX_COLUMN)
		ft_error_2("map dimensions exceeded", game);
}
