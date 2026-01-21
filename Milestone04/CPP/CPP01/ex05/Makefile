NAME	= Harl

CC		= c++
CFLAGS	= -g -Wall -Werror -Wextra -std=c++98
OBJ_DIR	= obj
INC_DIR	= includes
SRC_DIR	= src

SRCS	=	\
			src/main.cpp\
			src/Harl.cpp\

OBJS	= $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all:	$(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		$(CC) $(CFLAGS) -I$*INC_DIR -c $< -o $@
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@echo "Compilando $(NAME)..."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "Compilacion completada."

clean:
		@echo "Eliminando archivos objeto..."
		@rm -rf $(OBJ_DIR)
		@echo "Limpieza de objetos completada."

fclean:
		@echo "Eliminando ejecutable..."
		@rm -f $(NAME)
		@echo "Eliminacion completa."

re: fclean all

.PHONY: all clean fclean re