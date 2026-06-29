/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:27 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:29 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Identifies the type of line
 * 
 * @param line line to identify
 * @return t_line_type LINE_EMPTY, LINE_TEXTURE, LINE_COLOR, 
 * 		LINE_MAP, or LINE_ERROR
 */
t_line_type	identify_line_type(char *line)
{
	if (!line || !*line)
		return (LINE_EMPTY);
	if (is_empty_line(line))
		return (LINE_EMPTY);
	if (is_texture_line(line))
		return (LINE_TEXTURE);
	if (is_color_line(line))
		return (LINE_COLOR);
	if (is_map_line(line))
		return (LINE_MAP);
	return (LINE_ERROR);
}

/**
 * @brief Processes a line according to its type and calls the 
 * 		corresponding parser
 * 
 * @param line line to process
 * @param game main game structure
 * @param map_started flag indicating if map parsing has started
 * @return int 1 if success, 0 if error
 */
int	process_line(char *line, t_game *game, int *map_start_idx, int idx)
{
	t_line_type	type;

	type = identify_line_type(line);
	if (type == LINE_ERROR)
		return (0);
	if (type == LINE_EMPTY)
	{
		if (*map_start_idx != -1)
			return (0);
		return (1);
	}
	if (type == LINE_TEXTURE)
		return (parse_texture(line, game));
	if (type == LINE_COLOR)
		return (parse_color(line, game));
	if (type == LINE_MAP)
	{
		if (*map_start_idx == -1)
			*map_start_idx = idx;
		return (1);
	}
	return (0);
}

/**
 * @brief Main parsing function
 *        1. Validates file extension
 *        2. Reads all lines
 *        3. Processes each line
 *        4. Validates the complete map
 * 
 * @param filename path to .cub file
 * @param game main game structure
 * @return int 1 if success, 0 if error
 */
int	parse_file(char *filename, t_game *game)
{
	char	**lines;
	int		i;
	int		map_start_idx;

	if (!check_extension(filename, ".cub"))
		return (error_msg("Invalid file extension"), 0);
	lines = read_file_lines(filename);
	if (!lines)
		return (error_msg("Cannot read file"), 0);
	i = 0;
	map_start_idx = -1;
	while (lines[i])
	{
		if (!process_line(lines[i], game, &map_start_idx, i))
			return (free_lines(lines), error_msg("Invalid line in file"), 0);
		i++;
	}
	if (map_start_idx == -1)
		return (free_lines(lines), error_msg("No map found"), 0);
	if (!parse_map(game, lines, map_start_idx))
		return (free_lines(lines), 0);
	free_lines(lines);
	return (1);
}
