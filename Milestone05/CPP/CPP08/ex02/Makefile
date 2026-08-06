NAME			=	MutantStack

CXX				=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g

OBJ_DIR			=	obj

SRC				=	main.cpp

HEADERS			=	MutantStack.hpp

OBJS			=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
