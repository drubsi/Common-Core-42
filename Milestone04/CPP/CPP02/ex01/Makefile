NAME	= fixed

CC		= c++
CFLAGS	= -g -Wall -Werror -Wextra -std=c++98
OBJ_DIR	= obj
INC_DIR	= includes
SRC_DIR	= src
INCLUDES= -I$(INC_DIR)
SRC	=	\
			src/main.cpp\
			src/Fixed.cpp

OBJS	= $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all:	$(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
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

re: fclean all

.PHONY: all clean fclean re