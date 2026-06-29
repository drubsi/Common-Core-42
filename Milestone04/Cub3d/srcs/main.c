/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:12:53 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:13:04 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Usage: ./cub3D <map.cub>"), 1);
	if (!check_extension(argv[1], ".cub"))
		return (error_msg("File must have .cub extension"), 1);
	init_game(&game);
	init_safe_game(&game);
	if (!parse_file(argv[1], &game))
		return (free_game(&game), 1);
	if (!validate_map(&game))
		return (error_msg("Map is not closed"), free_game(&game), 1);
	if (!init_game_mlx(&game))
	{
		free_game(&game);
		return (1);
	}
	ft_printf("Map parsed and validated successfully!\n");
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
