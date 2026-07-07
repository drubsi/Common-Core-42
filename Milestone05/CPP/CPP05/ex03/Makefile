NAME			=	Bureaucrat

CXX				=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g

OBJ_DIR			=	obj

SRC				=	main.cpp \
					Bureaucrat.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					Intern.cpp

HEADERS			=	Bureaucrat.hpp \
					AForm.hpp \
					ShrubberyCreationForm.hpp \
					RobotomyRequestForm.hpp \
					PresidentialPardonForm.hpp \
					Intern.hpp

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
	rm -f $(NAME) *_shrubbery

re: fclean all

.PHONY: all clean fclean re