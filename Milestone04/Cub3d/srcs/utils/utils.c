/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:13:22 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:13:26 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_area(char **tab, t_point size)
{
	int		i;
	char	**area;

	i = 0;
	area = ft_calloc(size.y + 1, sizeof(char *));
	if (!area)
		return (NULL);
	while (tab[i])
	{
		area[i] = ft_strdup(tab[i]);
		if (!area[i])
			return (free_map(area), NULL);
		i++;
	}
	return (area);
}
