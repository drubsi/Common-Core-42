# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 12:28:13 by drubio-s          #+#    #+#              #
#    Updated: 2025/12/29 11:10:24 by drubio-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = phonebook

CC		= c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
INC_DIR = includes
SRC_DIR = src

SRCS    =  \
			src/contact.cpp\
			src/main.cpp\
			src/phoneBook.cpp

OBJS             = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
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
