
# **************************************************************************** #
#                                MAKEFILE                                      #
# **************************************************************************** #

NAME = so_long

# Compilador y Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = includes/libft
MLX42_DIR = includes/MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -I$(MLX42_DIR)/include -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

# Archivos fuente
SRCS = \
	$(SRC_DIR)/game/manager.c \
	$(SRC_DIR)/game/so_long.c \
	$(SRC_DIR)/map/map_parsing.c \
	$(SRC_DIR)/map/map_pathfinding.c \
	$(SRC_DIR)/map/map_validation.c \
	$(SRC_DIR)/mlx/memory_free.c \
	$(SRC_DIR)/mlx/mlx_events.c \
	$(SRC_DIR)/mlx/mlx_init_game.c \
	$(SRC_DIR)/mlx/mlx_render.c \
	$(SRC_DIR)/mlx/mlx_textures.c \
	$(SRC_DIR)/utils/error_handling.c \
	$(SRC_DIR)/utils/memory_alloc.c

# Archivos objeto
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Librerias
LIBS = -L$(LIBFT_DIR) -lft $(MLX42_FLAGS)

# Target principal
all: $(MLX42_LIB) $(LIBFT_DIR)/libft.a $(NAME)

# Compilacion final
$(NAME): $(OBJS)
	@echo "Compilando $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "Compilacion de $(NAME) completada."

# Regla para compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Crear directorio de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regla para compilar MLX42
$(MLX42_LIB):
	@echo "Compilando MLX42..."
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build
	@echo "MLX42 compilado correctamente."

# Regla para compilar libft
$(LIBFT_DIR)/libft.a:
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft compilada correctamente."

# Limpieza de archivos objeto
clean:
	@echo "Eliminando archivos objeto..."
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@if [ -d $(MLX42_DIR)/build ]; then make -C $(MLX42_DIR)/build clean; fi
	@echo "Limpieza de objetos completada."

# Limpieza completa
fclean: clean
	@echo "Eliminando ejecutable y librerias..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_DIR)/build
	@echo "Eliminación completa."

# Recompilacion completa
re: fclean all

# Phony targets para evitar conflictos con archivos del mismo nombre
.PHONY: all clean fclean re
