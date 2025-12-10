/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:26 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:15:54 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_read(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		bytes;

	buff = (char *) calloc_gnl (BUFFER_SIZE + 1, sizeof (char));
	if (!buff)
		return (NULL);
	bytes = 1;
	if (!str)
		str = (char *) calloc_gnl(1, sizeof (char));
	while (!ft_findchr(str, '\n') && bytes > 0)
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if ((bytes <= 0) || ((bytes == 0) && (!str || str[0] == '\0')))
		{
			free (buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = ft_strjoin(str, buff);
		free(str);
		str = temp;
	}
	free (buff);
	return (str);
}*/
char	*ft_read(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		bytes;

	buff = (char *) calloc_gnl (BUFFER_SIZE + 1, sizeof (char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_findchr(str, '\n') && bytes > 0)
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if ((bytes < 0) || ((bytes == 0) && (!str || str[0] == '\0')))
		{
			free (buff);
			free (str);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = ft_strjoin(str, buff);
		free(str);
		str = temp;
	}
	free (buff);
	return (str);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *) calloc_gnl(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		line[i++] = str[j++];
	if (str[i] == '\n')
		line[i++] = str[j];
	return (line);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	new_str = (char *) calloc_gnl((ft_strlen_gnl(str) - i) + 1, sizeof (char));
	if (!new_str)
	{
		free (str);
		return (NULL);
	}
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	free (str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
		backup = (char *) calloc_gnl(1, sizeof (char));
	backup = ft_read(fd, backup);
	if (!backup || backup[0] == '\0')
	{
		free (backup);
		return (NULL);
	}
	line = ft_line(backup);
	backup = ft_new_str(backup);
	return (line);
}
/*char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(backup);
		return (NULL);
	}
	backup = ft_read(fd, backup);
	if (!backup || backup[0] == '\0')
	{
		free (backup);
		backup = NULL;
		return (NULL);
	}
	line = ft_line(backup);
	backup = ft_new_str(backup);
	return (line);
}*/
