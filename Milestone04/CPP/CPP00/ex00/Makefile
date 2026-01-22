# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:16:27 by drubio-s          #+#    #+#              #
#    Updated: 2025/12/19 11:24:08 by drubio-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

SRCS	= megaphone.cpp

OBJ		= $(SRCS:.cpp=.o)

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

RM		= rm -rf

all:	$(NAME)

$(NAME):$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re