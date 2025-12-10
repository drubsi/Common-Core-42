/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:01:06 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/05 12:09:28 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define PNG_WALL "assets/textures/wall.png"
# define PNG_PIKA_RIGHT "assets/textures/pika_right.png"
# define PNG_GRASS "assets/textures/grass.png"
# define PNG_EXIT_OPEN "assets/textures/exit_open.png"
# define PNG_EXIT_CLOSE "assets/textures/exit_close.png"
# define PNG_COLLECTIBLE "assets/textures/lightning_bolt.png"
# define MAX_COLUMN 38
# define MAX_ROWS 18
# define WIDTH 100
# define HEIGHT 100
# define SIZE 100
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

typedef struct s_texture
{
	mlx_texture_t	*texture_grass;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_player_right;
	mlx_texture_t	*texture_exit_close;
	mlx_texture_t	*texture_exit_open;
	mlx_texture_t	*texture_collectible;
}	t_texture;

typedef struct s_images
{
	mlx_image_t	*img_grass;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_player_right;
	mlx_image_t	*img_exit_close;
	mlx_image_t	*img_exit_open;
	mlx_image_t	*img_collectible;
}	t_img;

typedef struct s_map
{
	char	**map;
	char	**validate_map;
	int		n_player;
	int		validate_player;
	int		n_collectibles;
	int		validate_collect;
	int		n_exit;
	int		validate_exit;
	int		new_x;
	int		new_y;
	int		check_x_exit;
	int		check_y_exit;
	int		check_x;
	int		check_y;
	int		column;
	int		rows;
	int		mov_count;
	int32_t	**width;
	int32_t	**height;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_texture	*texture;
	t_img		*images;
	t_map		*map;
	t_map		*player;
	t_map		*exit;
}	t_game;

//Error functions
void	ft_error_1(char *str_error);
void	ft_error_2(char *str_error, t_game *game);
//Map function
void	read_and_init_map(int fd, t_game *game);
void	validate_elements(t_game *game);
int		is_within_bounds(t_game *game, int x, int y);
void	check_characters(t_game *game);
void	copy_validate_map(t_game *game);
void	copy_map(int fd, t_game *game);
void	map_is_rectangular(t_game *game);
void	is_map_closed(t_game *game);
int		check_map_elements(t_game *game, char line);
void	check_coordinate_player(t_game *game);
int		check_cell(t_game *game, char *cell);
int		map_map(t_game *game, int x, int y);
void	track_map(t_game *game);
void	validate_map(t_game *game);
void	validate_caracters(t_game *game);
void	space_grid_map(t_game *game, const char *argv);
void	copy_map_grid(t_game *game, const char *argv);
void	check_parameters(int argc, const char **argv);
void	max_size(t_game *game);

//Memory functions
void	*init_memory_struct(size_t size);
void	*allocate_grid(char ***grid, int height, int width);
void	init_allocated_grids(t_game *game);
void	free_textures(t_game *game);
void	free_images(t_game *game);
void	free_grids(t_game *game);
void	free_structs(t_game *game);
void	free_game(t_game *game);
//MLX42 Functions
int32_t	init_mlx(t_game *game);
void	load_textures(t_game *game);
void	load_images(t_game *game);
void	render_map_1(t_game *game);
void	render_map_2(t_game *game);
void	render_map_3(t_game *game);
void	renderized_map(t_game *game);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_game *game, int direction);
void	refresh_escene(t_game *game, int old_check_x, int old_check_y);
void	validate_cell(t_game *game, int old_check_x, int old_check_y);
void	victory(t_game *game);
void	close_window(void *param);

#endif