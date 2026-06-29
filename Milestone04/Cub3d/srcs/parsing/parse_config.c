/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:49 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:50 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Extracts texture path from config line
 * 
 * @param line Line like "NO ./textures/north.png"
 * @return char* Extracted path or NULL if invalid
 */
static char	*extract_path(char *line)
{
	char	*path;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	i += 2;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	start = i;
	while (line[i] && line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
		i++;
	len = i - start;
	if (len == 0)
		return (NULL);
	path = ft_substr(line, start, len);
	return (path);
}

/**
 * @brief Parses texture line and assigns path to game struct
 * 
 * @param line Texture line (NO, SO, WE, EA)
 * @param game Main game structure
 * @return int 1 if success, 0 if error
 */
int	parse_texture(char *line, t_game *game)
{
	char	*trimmed;
	char	*path;

	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	path = extract_path(line);
	if (!path)
		return (0);
	if (ft_strncmp(trimmed, "NO", 2) == 0)
		game->textures.no_path = path;
	else if (ft_strncmp(trimmed, "SO", 2) == 0)
		game->textures.so_path = path;
	else if (ft_strncmp(trimmed, "WE", 2) == 0)
		game->textures.we_path = path;
	else if (ft_strncmp(trimmed, "EA", 2) == 0)
		game->textures.ea_path = path;
	else
		return (free(path), 0);
	return (1);
}

/**
 * @brief Converts RGB values (0-255) to int color
 * 
 * @param r Red component
 * @param g Green component
 * @param b Blue component
 * @return int Combined RGBA color value
 */
static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

/**
 * @brief Parses "R,G,B" string and returns int color
 * 
 * @param str Color string like "255,128,0"
 * @param color Pointer to store result
 * @return int 1 if success, 0 if invalid format or values
 */
static int	parse_rgb(char *str, int *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		if (rgb)
			free_split(rgb);
		return (0);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	*color = rgb_to_int(r, g, b);
	return (1);
}

/**
 * @brief Parses floor (F) or ceiling (C) color line
 * 
 * @param line Color line like "F 255,128,0"
 * @param game Main game structure
 * @return int 1 if success, 0 if error
 */
int	parse_color(char *line, t_game *game)
{
	char	*trimmed;
	char	*color_str;
	int		color;

	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	color_str = trimmed + 1;
	while (*color_str == ' ' || *color_str == '\t')
		color_str++;
	if (!parse_rgb(color_str, &color))
		return (0);
	if (*trimmed == 'F')
		game->floor_color = color;
	else if (*trimmed == 'C')
		game->ceiling_color = color;
	else
		return (0);
	return (1);
}
