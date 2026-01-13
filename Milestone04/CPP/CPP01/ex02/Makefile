NAME	= Brain

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
OBJ_DIR	= obj
SRC_DIR	= src

SRCS	=	\
			src/main.cpp

OBJS	= $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all:	$(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@echo "Compilacion $(NAME)..."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "Compilacion completada."

clean:
		@echo "Eliminando archivos objeto..."
		@rm -rf $(OBJ_DIR)
		@echo "Limpieza de objetos completada."

fclean:
		@echo "Eliminando ejecutable..."
		@rm -f $(NAME) -rf $(OBJ_DIR)
		@echo "Eliminacion completa."

re:	fclean all

.PHONY: all clean fclean re