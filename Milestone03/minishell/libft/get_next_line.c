/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:05:26 by adeestev          #+#    #+#             */
/*   Updated: 2025/08/31 17:28:52 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delete_line(char **data)
{
	char	*newline_pos;
	char	*remaining_str;
	size_t	i;
	size_t	j;

	newline_pos = ft_strchr(*data, '\n');
	if (!newline_pos)
	{
		free(*data);
		*data = NULL;
		return ;
	}
	remaining_str = malloc((ft_strlen(newline_pos)) * sizeof(char));
	i = 0;
	j = ft_strlen(*data) - ft_strlen(newline_pos) + 1;
	while (j < ft_strlen(*data))
		remaining_str[i++] = (*data)[j++];
	remaining_str[i] = '\0';
	free(*data);
	*data = remaining_str;
	if (**data == 0)
	{
		free(*data);
		*data = NULL;
	}
}

static void	extract_line(char **data, char **extracted_line)
{
	char	*newline_pos;
	size_t	line_length;
	size_t	i;

	newline_pos = ft_strchr(*data, '\n');
	line_length = ft_strlen(*data) - ft_strlen(newline_pos) + 2;
	*extracted_line = (char *)malloc(line_length * sizeof(char));
	if (!extracted_line)
		return ;
	i = 0;
	while (i < (line_length - 1))
	{
		(*extracted_line)[i] = (*data)[i];
		i++;
	}
	(*extracted_line)[i] = '\0';
}

static int	read_data(int fd, char **data, char *buffer)
{
	int		bytes_read;
	char	*new_data;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0 || buffer == NULL)
	{
		free (*data);
		*data = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (bytes_read);
	new_data = ft_strjoin(*data, buffer);
	free(*data);
	*data = new_data;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*extracted_line;
	char		*buffer;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	while (ft_strchr(data, '\n') == NULL && bytes_read > 0)
		bytes_read = read_data(fd, &data, buffer);
	free(buffer);
	if (bytes_read == -1 || ft_strlen(data) == 0)
		return (NULL);
	extract_line(&data, &extracted_line);
	delete_line(&data);
	return (extracted_line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free (line);
	}
	return (0);
}
*/
