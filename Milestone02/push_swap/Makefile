NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= -Iincludes -Ilibft
LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo "Compilando push_swap..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_LIB):
	@echo "Compilando libft..."
	make -s -C $(LIBFT_DIR)

clean:
	@echo "Limpiando objetos..."
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Limpiando ejecutable..."
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
