# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 12:28:13 by drubio-s          #+#    #+#              #
#    Updated: 2026/02/05 17:55:21 by drubio-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = phonebook

CC		= c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
INC_DIR = includes
SRC_DIR = src
INCLUDES= -I$(INC_DIR)
SRC    =  \
			src/Contact.cpp\
			src/main.cpp\
			src/PhoneBook.cpp

OBJS             = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)
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
