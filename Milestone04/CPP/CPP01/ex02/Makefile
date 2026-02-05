NAME	= Brain

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
OBJ_DIR	= obj
SRC_DIR	= src
SRC	=	\
			src/main.cpp

OBJS	= $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all:	$(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@echo "Compiling $(NAME)..."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "$(NAME) compiled successfully."

clean:
		@echo "Removing object files..."
		@rm -rf $(OBJ_DIR)
		@echo "Object files removed."

fclean: clean
		@echo "Removing binary $(NAME)..."
		@rm -f $(NAME)
		@echo "Full cleanup complete."
re:	fclean all

.PHONY: all clean fclean re