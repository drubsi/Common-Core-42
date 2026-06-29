/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:13:34 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:13:38 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_path_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->no_path)
	{
		free(textures->no_path);
		textures->no_path = NULL;
	}
	if (textures->so_path)
	{
		free(textures->so_path);
		textures->so_path = NULL;
	}
	if (textures->ea_path)
	{
		free(textures->ea_path);
		textures->ea_path = NULL;
	}
	if (textures->we_path)
	{
		free(textures->we_path);
		textures->we_path = NULL;
	}
}
