/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:04:16 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/04 19:18:36 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_parameters(int argc, const char **argv)
{
	const char	*ext;

	if (argc < 2)
		ft_error_1 ("Map is missing in the call");
	if (argc > 2)
		ft_error_1 ("Too many arguments in call");
	ext = ft_strrchr (argv[1], '.');
	if (!ext)
		ft_error_1 ("The file has no extension");
	if (ft_strncmp (ext, ".ber", 5) != 0)
		ft_error_1 ("The file must be .ber");
	return ;
}

void	close_window(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window (game->mlx);
	free_game (game);
	exit (0);
}

int	main(int argc, const char **argv)
{
	t_texture			*texture;
	t_img				*img;
	t_game				*game;
	t_map				*map;

	check_parameters (argc, argv);
	map = (t_map *)init_memory_struct (sizeof(t_map));
	texture = (t_texture *)init_memory_struct (sizeof(t_texture));
	img = (t_img *)init_memory_struct (sizeof(t_img));
	game = (t_game *)init_memory_struct (sizeof(t_game));
	game->map = map;
	game->images = img;
	game->texture = texture;
	space_grid_map (game, argv[1]);
	copy_map_grid (game, argv[1]);
	validate_map (game);
	track_map (game);
	init_mlx (game);
	free_game (game);
	return (0);
}
