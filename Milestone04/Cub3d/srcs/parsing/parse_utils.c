/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:35 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:39 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief check if line is empty
 * 
 * @param line 
 * @return int 
 */
int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

/**
 * @brief Removes leading and trailing whitespace
 * 
 * @param line 
 * @return char* New allocated string without surrounding spaces
 */
char	*ft_trim_spaces(char *line)
{
	char	*start;
	int		len;

	while (*line && ft_isspace(*line))
		line++;
	start = line;
	len = ft_strlen(line);
	while (len > 0 && ft_isspace(line[len - 1]))
		len--;
	return (ft_substr(start, 0, len));
}

/**
 * @brief Checks if the line is a texture identifier (NO, SO, WE, EA)
 *
 * @param line line to check
 * @return int 1 if texture line, 0 if not
 */
int	is_texture_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "NO\t", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "SO\t", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "WE\t", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "EA\t", 3) == 0)
		return (1);
	return (0);
}

/**
 * @brief Checks if the line is a color identifier (F or C)
 *
 * @param line line to check
 * @return int 1 if color line, 0 if not
 */
int	is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "F\t", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "C\t", 2) == 0)
		return (1);
	return (0);
}

/**
 * @brief Checks if the line is part of the map (contains 0, 1, N, S, E, W)
 *
 * @param line line to check
 * @return int 1 if map line, 0 if not
 */
int	is_map_line(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			has_map_char = 1;
		else if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (has_map_char);
}
