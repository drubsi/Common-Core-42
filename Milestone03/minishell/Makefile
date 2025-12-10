# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 20:05:18 by adeestev          #+#    #+#              #
#    Updated: 2025/12/01 18:44:21 by adeestev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	src/parsing/builtin_utils.c\
		src/parsing/cmd_fill.c\
		src/parsing/cmd_fill_helpers.c\
		src/parsing/cmd_fill_redir.c\
		src/parsing/cmd_parser.c\
		src/parsing/cmd_parser_utils.c\
		src/parsing/expansion_utils.c\
		src/parsing/expansion_utils_2.c\
		src/parsing/expansion.c\
		src/parsing/parser.c\
		src/parsing/parser_utils.c\
		src/parsing/parser_alloc.c\
		src/parsing/redir_utils.c\
		src/parsing/split_pipes.c\
		src/parsing/syntax_validator.c\
		src/parsing/tokenizer.c\
		src/parsing/tokenizer_helpers.c\
		src/parsing/tokenizer_utils.c\
		src/parsing/tokenizer_utils_2.c\
		src/utils/utils.c\
		src/utils/helpers.c\
		src/execution/env/env_build.c\
		src/execution/env/env_free.c\
		src/execution/env/env_set.c\
		src/execution/env/env_get.c\
		src/execution/env/env_to_envp.c\
		src/execution/env/env_utils.c\
		src/execution/executor/child.c\
		src/execution/executor/command.c\
		src/execution/executor/exec_external.c\
		src/execution/executor/exec_external_errors.c\
		src/execution/executor/fd_utils.c\
		src/execution/executor/heredoc_exec.c\
		src/execution/executor/heredoc_utils.c\
		src/execution/executor/pipeline_cleanup.c\
		src/execution/executor/pipeline.c\
		src/execution/executor/wait.c\
		src/execution/executor/exec_pipeline.c\
		src/execution/path/path_join.c\
		src/execution/path/path_not_exec.c \
		src/execution/path/resolve_path.c\
		src/execution/redirs/redir_heredoc.c\
		src/execution/redirs/redirs_apply.c\
		src/execution/redirs/redirs_errors.c\
		src/execution/redirs/redirs_types.c\
		src/builtins/builtin_cd.c\
		src/builtins/builtin_echo.c\
		src/builtins/builtin_env.c\
		src/builtins/builtin_exit.c\
		src/builtins/builtin_export.c\
		src/builtins/builtin_pwd.c\
		src/builtins/builtin_unset.c\
		src/builtins/export_utils.c\
		src/builtins/exec_builtin.c\
		src/signals/signals.c\
		src/main.c
		
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft
RL_LIB = -lreadline

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) $(RL_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "object files have been deleted"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) has been deleted"

re: fclean all

.PHONY: all clean fclean re
