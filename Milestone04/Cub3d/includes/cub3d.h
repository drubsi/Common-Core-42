/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:06:46 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 21:06:50 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define PLAYER_RADIUS 0.1

typedef enum e_line_type
{
	LINE_EMPTY,
	LINE_TEXTURE,
	LINE_COLOR,
	LINE_MAP,
	LINE_ERROR
}	t_line_type;

typedef enum e_dir
{
	NORTH	= 0,
	SOUTH	= 1,
	EAST	= 2,
	WEST	= 3
}	t_dir;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_input
{
	int		center_x;
	double	mouse_dx;
}	t_input;
typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		angle_total;
}	t_player;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_mlx;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
}	t_textures;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}	t_map;
typedef struct s_rect
{
	int			x;
	int			y;
	int			width_px;
	int			height_px;
	int			color;
}	t_rect;

typedef struct s_mm
{
	int			origin_x;
	int			origin_y;
	int			map_x;
	int			map_y;
	int			scale;
	double		player_pixel_x;
	double		player_pixel_y;
	double		ray_px_x;
	double		ray_px_y;
}	t_mm;

typedef struct s_render
{
	int			width;
	int			height;
	int			color;
}	t_render;

typedef struct s_dda
{
	double		line_height;
	int			screen_center_y;
	int			draw_start;
	int			draw_end;
	int			hit;
	int			hit_map_x;
	int			hit_map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	double		dist;
	double		wall_hit;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
	int			dda_face;

}	t_dda;

typedef struct s_images
{
	mlx_image_t		*frame;
}	t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_textures	textures;
	t_images	images;
	t_render	render;
	t_input		input;
	t_player	player;
	t_map		map;
	int			floor_color;
	int			ceiling_color;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// --- Init ---
void		init_game(t_game *game);
int			init_game_mlx(t_game *game);
int			load_textures(t_game *game);
void		init_safe_game(t_game *game);
void		init_safe_dda(t_dda *dda);
void		init_safe_images(t_images *images);
void		init_safe_render(t_render *render);
void		init_safe_player(t_player *player);
void		init_safe_dda(t_dda *dda);
void		init_safe_input(t_input *input);
void		init_safe_textures(t_textures *textures);

// --- Parsing ---
int			parse_file(char *file, t_game *game);
t_line_type	identify_line_type(char *line);
int			process_line(char *line, t_game *game, int *map_start_idx, int idx);
int			parse_texture(char *line, t_game *game);
int			parse_color(char *line, t_game *game);
int			parse_map(t_game *game, char **file_lines, int map_start);
char		**extract_map_lines(char **file_lines, int map_start,
				int *map_height);
void		get_map_dimensions(char **map, int *width, int *height);
char		**pad_map_lines(char **map, int width, int height);
int			check_valid_chars(char **map);
int			find_player_position(t_game *game);
int			check_single_player(char **map);
int			is_empty_line(char *line);
int			is_texture_line(char *line);
int			is_color_line(char *line);
int			is_map_line(char *line);
char		*ft_trim_spaces(char *line);
char		**read_file_lines(char *filename);
void		free_lines(char **lines);
int			count_lines(char **lines);
int			validate_map(t_game *game);
void		fill(char **tab, t_point size, t_point cur, int *exit_flag);
int			flood_fill(char **tab, t_point size, t_point *begin);

// --- Rendering & Raycasting ---
void		render_frame(t_game *game);
void		draw_floor_ceiling(t_game *game);
void		mm_fill_rect(t_game *game, t_rect *rectangle);
void		init_mm_ctx(t_mm *mm_ctx, t_game *game);
void		draw_rectangle(t_rect *rectangle, t_game *game);
void		draw_minimap(t_game *game);
void		cast_ray(t_game *game, t_dda *dda);
void		calculate_wall_projection(mlx_image_t *img, t_dda *dda);
void		get_wall_face(t_dda *dda);
void		calc_wall_hit(t_game *game, t_dda *dda);
void		calc_text_x(t_dda *dda, mlx_texture_t *tex);
void		setup_tex_vertical(t_dda *dda, mlx_texture_t *tex);

// --- Events & Input ---
void		press_keys(t_game *game, double *angle);
void		close_window(void *param);
void		cursor_callback(double xpos, double ypos, void *param);

// --- Movements & Simulation ---
void		move_forward_backward(t_game *game, double dir_sign);
void		move_left_right(t_game *game, double dir_sign);
void		apply_rotation(t_game *game, double angle);
void		update(void *param);

// --- Utils ---
void		error_msg(char *msg);
int			check_extension(char *file, char *ext);
void		free_game(t_game *game);
void		free_map(char **map);
void		free_path_textures(t_textures *textures);
void		free_textures(t_textures *textures);
void		free_mlx(mlx_t *mlx);
void		free_images(t_game *game);
char		**make_area(char **tab, t_point size);
void		free_split(char **split);

#endif