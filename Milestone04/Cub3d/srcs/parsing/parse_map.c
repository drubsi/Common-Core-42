/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:44 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:24:10 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Main function that parses the map from .cub file
 * 
 * @param game main game structure
 * @param file_lines lines from .cub file
 * @param map_start index where the map starts
 * @return int 1 if success, 0 if error
 */
int	parse_map(t_game *game, char **file_lines, int map_start)
{
	char	**raw;
	char	**padded;
	int		width;
	int		height;

	if (!game || !file_lines)
		return (0);
	raw = extract_map_lines(file_lines, map_start, &height);
	if (raw == NULL)
		return (0);
	get_map_dimensions(raw, &width, &height);
	padded = pad_map_lines(raw, width, height);
	free_lines(raw);
	if (padded == NULL)
		return (0);
	game->map.grid = padded;
	game->map.width = width;
	game->map.height = height;
	if (!check_valid_chars(game->map.grid))
		return (error_msg("no valid chars"), 0);
	if (!check_single_player(game->map.grid))
		return (error_msg("no single player"), 0);
	if (!find_player_position(game))
		return (error_msg("no valid player postion"), 0);
	return (1);
}

/**
 * @brief Extracts only the map lines from file_lines
 * 
 * @param file_lines lines from .cub file
 * @param map_start index where the map starts
 * @param map_height pointer to store map height
 * @return char** array of map lines, NULL if error
 */
char	**extract_map_lines(char **file_lines, int map_start, int *map_height)
{
	int		i;
	char	**result;
	size_t	len;

	i = map_start;
	while (file_lines[i])
		i++;
	*map_height = i - map_start;
	result = ft_calloc(*map_height + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < *map_height)
	{
		result[i] = ft_strdup(file_lines[map_start + i]);
		if (!result[i])
			return (free_lines(result), NULL);
		len = ft_strlen(result[i]);
		if (len > 0 && result[i][len - 1] == '\n')
			result[i][len - 1] = '\0';
		i++;
	}
	return (result);
}

/**
 * @brief Calculates map dimensions (width and height)
 * 
 * @param map 2D map
 * @param width pointer to store max width
 * @param height pointer to store height
 */
void	get_map_dimensions(char **map, int *width, int *height)
{
	int	i;
	int	len;
	int	max_width;

	i = 0;
	max_width = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	*height = i;
	*width = max_width;
}

/**
 * @brief Pads short lines with spaces to make the map uniform
 * 
 * @param map original 2D map
 * @param width desired max width
 * @param height map height
 * @return char** padded map, NULL if error
 */
char	**pad_map_lines(char **map, int width, int height)
{
	char	**pad_map;
	int		i;
	int		j;

	i = 0;
	pad_map = ft_calloc(height + 1, sizeof(char *));
	if (!pad_map)
		return (NULL);
	while (map[i] != NULL)
	{
		pad_map[i] = ft_calloc(width + 1, sizeof(char));
		if (!pad_map[i])
			return (free_lines(pad_map), NULL);
		j = -1;
		while (++j < width)
		{
			if (j < (int)ft_strlen(map[i]))
				pad_map[i][j] = map[i][j];
			else
				pad_map[i][j] = ' ';
		}
		i++;
	}
	return (pad_map);
}

/**
 * @brief check for valid items
 * 
 * @param map 
 * @return int true or false
 */
int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
