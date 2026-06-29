NAME		= cub3D

# Compilador y flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf

# Directorios
SRC_DIR		= srcs
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= MLX42

# Archivos fuente - PARSING (Backend)
PARSING_SRC	= parser.c parse_config.c parse_map.c parse_utils.c validate_map.c player.c file_utils.c

# Archivos fuente - INIT (Frontend)
INIT_SRC	= init_engine.c init_core.c init_mlx.c

# Archivos fuente - MOVEMENTS
MOVE_SRC	= player_move.c player_rotate.c

# Archivos fuente - INPUT
INPUT_SRC	= keyboard.c

# Archivos fuente - EVENTS
EVENTS_SRC	= close_hook.c

# Archivos fuente - UTILS (Backend)
UTILS_SRC	= error.c free_game.c free_graphics.c free_parsing.c utils.c

# Archivos fuente - RAYCASTING (Frontend)
RAYCAST_SRC	= dda.c raycast_utils.c

# Archivos fuente - RENDERING (Frontend)
RENDER_SRC	= render_frame.c draw_bg.c

# Archivos fuente - SIMULATION & TEXTURES
SIM_SRC		= update.c
TEX_SRC		= textures.c

# Main
MAIN_SRC	= main.c

# Archivos BONUS
RENDER_BONUS_SRC = render_frame_bonus.c draw_bg.c minimap_bonus.c utils_minimap_bonus.c
SIM_BONUS_SRC = update_bonus.c
INPUT_BONUS_SRC	= mouse_bonus.c keyboard.c
INIT_BONUS_SRC	= init_core.c init_engine.c init_mlx_bonus.c

# Construir paths completos
SRCS		= $(addprefix $(SRC_DIR)/, $(MAIN_SRC)) \
			  $(addprefix $(SRC_DIR)/parsing/, $(PARSING_SRC)) \
			  $(addprefix $(SRC_DIR)/init/, $(INIT_SRC)) \
			  $(addprefix $(SRC_DIR)/movements/, $(MOVE_SRC)) \
			  $(addprefix $(SRC_DIR)/raycasting/, $(RAYCAST_SRC)) \
			  $(addprefix $(SRC_DIR)/render/, $(RENDER_SRC)) \
			  $(addprefix $(SRC_DIR)/events/, $(EVENTS_SRC)) \
			  $(addprefix $(SRC_DIR)/input/, $(INPUT_SRC)) \
			  $(addprefix $(SRC_DIR)/sim/, $(SIM_SRC)) \
			  $(addprefix $(SRC_DIR)/textures/, $(TEX_SRC)) \
			  $(addprefix $(SRC_DIR)/utils/, $(UTILS_SRC))

BONUS_SRCS	= $(addprefix $(SRC_DIR)/, $(MAIN_SRC)) \
			  $(addprefix $(SRC_DIR)/parsing/, $(PARSING_SRC)) \
			  $(addprefix $(SRC_DIR)/init/, $(INIT_BONUS_SRC)) \
			  $(addprefix $(SRC_DIR)/movements/, $(MOVE_SRC)) \
			  $(addprefix $(SRC_DIR)/raycasting/, $(RAYCAST_SRC)) \
			  $(addprefix $(SRC_DIR)/render/, $(RENDER_BONUS_SRC)) \
			  $(addprefix $(SRC_DIR)/events/, $(EVENTS_SRC)) \
			  $(addprefix $(SRC_DIR)/input/, $(INPUT_BONUS_SRC)) \
			  $(addprefix $(SRC_DIR)/sim/, $(SIM_BONUS_SRC)) \
			  $(addprefix $(SRC_DIR)/textures/, $(TEX_SRC)) \
			  $(addprefix $(SRC_DIR)/utils/, $(UTILS_SRC))

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Librerías
LIBFT		= $(LIBFT_DIR)/libft.a
MLX42		= $(MLX_DIR)/build/libmlx42.a

# Flags para MLX42
# Linux
MLX_FLAGS	= -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
# macOS (descomentar si es necesario)
# MLX_FLAGS	= -L$(MLX_DIR)/build -lmlx42 -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Includes
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)/include

# Colores
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
NC			= \033[0m

# **************************************************************************** #
#				    RULES				     #
# **************************************************************************** #

all: $(MLX42) $(LIBFT) $(NAME)

bonus: .bonus

.bonus: $(MLX42) $(LIBFT) $(BONUS_OBJS)
	@echo "$(YELLOW)Linking $(NAME) (bonus)...$(NC)"
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) bonus compiled successfully!$(NC)"
	@touch .bonus

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilar libft
$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@echo "$(GREEN)✓ libft compiled$(NC)"

# Compilar MLX42 (solo si no existe)
$(MLX42):
	@echo "$(YELLOW)Building MLX42...$(NC)"
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		cd $(MLX_DIR) && cmake -B build && cmake --build build -j4; \
	fi
	@echo "$(GREEN)✓ MLX42 built$(NC)"

# Limpiar objetos
clean:
	@echo "$(RED)Cleaning objects...$(NC)"
	$(RM) $(OBJ_DIR) .bonus
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

# Limpiar todo
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	$(RM) $(NAME) .bonus
re: fclean all

# Limpiar incluyendo MLX42
cleanall: fclean
	@echo "$(RED)Cleaning MLX42 build...$(NC)"
	$(RM) $(MLX_DIR)/build

# Debug build
debug: CFLAGS += -fsanitize=address
debug: re

# Norminette
norm:
	@echo "$(YELLOW)Running norminette...$(NC)"
	@norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re cleanall debug norm
