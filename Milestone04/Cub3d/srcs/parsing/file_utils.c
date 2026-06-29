/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:53 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:54 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Counts elements in NULL-terminated string array
 * 
 * @param lines Array of strings
 * @return int Number of elements
 */
int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

/**
 * @brief Frees a NULL-terminated string array
 * 
 * @param lines Array to free
 */
void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

/**
 * @brief Counts the number of lines in the file
 * 
 * @param fd file descriptor
 * @return int number of lines in the file
 */
static int	count_file_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

/**
 * @brief Reads all lines from file and stores them in char **
 * 
 * @param filename path to the file
 * @return char** array of lines, NULL if error
 */
char	**read_file_lines(char *filename)
{
	int		fd;
	int		i;
	int		num_lines;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	num_lines = count_file_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = ft_calloc(num_lines + 1, sizeof(char *));
	if (!lines)
		return (close(fd), NULL);
	i = 0;
	while (i < num_lines)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			return (close(fd), free_lines(lines), NULL);
		i++;
	}
	return (close(fd), lines);
}
