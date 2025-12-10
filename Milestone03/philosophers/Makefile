NAME = philo

CC = cc
CFLAGS = -g -Wall -Werror -Wextra -pthread

OBJ_DIR = obj
INC_DIR = includes
SRC_DIR = src

SRCS = \
	src/main.c \
	src/philosophers.c \
	src/state.c \
	src/threads.c \
	src/time.c \
	src/utils.c

OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "Compilando $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Compilacion de $(NAME) completada."

clean:
	@echo "Eliminando archivos objeto..."
	@rm -rf $(OBJ_DIR)
	@echo "Limpieza de objetos completada."

fclean: clean
	@echo "Eliminando ejecutable..."
	@rm -f $(NAME)
	@echo "Eliminacion completa."

re: fclean all

.PHONY: all clean fclean re
