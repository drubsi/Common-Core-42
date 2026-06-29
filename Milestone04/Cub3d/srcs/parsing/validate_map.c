/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:15:21 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:15:22 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Main map validation function
 * 
 * @param game main game structure
 * @return int 1 if valid, 0 if invalid
 */
int	validate_map(t_game *game)
{
	t_point	size;
	t_point	start;

	size.x = game->map.width;
	size.y = game->map.height;
	start.x = (int) game->player.pos.x;
	start.y = (int) game->player.pos.y;
	return (flood_fill(game->map.grid, size, &start));
}

/**
 * @brief Recursive flood fill to check if map is enclosed by walls
 * 
 * @param tab copy of the map for filling
 * @param size map dimensions (width, height)
 * @param cur current position being checked
 * @param exit_flag set to 1 if map is open (space or out of bounds found)
 */
void	fill(char **tab, t_point size, t_point cur, int *exit_flag)
{
	char	*to_fill;

	to_fill = "0NSEW";
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
	{
		*exit_flag = 1;
		return ;
	}
	if (ft_isspace(tab[cur.y][cur.x]))
		*exit_flag = 1;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != to_fill[0] && tab[cur.y][cur.x] != to_fill[1]
		&& tab[cur.y][cur.x] != to_fill[2] && tab[cur.y][cur.x] != to_fill[3]
		&& tab[cur.y][cur.x] != to_fill[4]))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, exit_flag);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, exit_flag);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, exit_flag);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, exit_flag);
}

/**
 * @brief Checks if map is closed using flood fill algorithm
 * 
 * @param tab 2D map array
 * @param size map dimensions (width, height)
 * @param begin starting position (player position)
 * @return int 1 if map is closed, 0 if map is open
 */
int	flood_fill(char **tab, t_point size, t_point *begin)
{
	int		*exit_flag;
	char	**aux;

	exit_flag = malloc(sizeof(int));
	*exit_flag = 0;
	aux = make_area(tab, size);
	fill(aux, size, *begin, exit_flag);
	if (*exit_flag)
		return (free_map(aux), free(exit_flag), 0);
	else
		return (free_map(aux), free(exit_flag), 1);
}
