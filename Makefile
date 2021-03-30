NAME			=	figure
FLAGS			=	-Wall -Werror -Wextra -g
LIBS			= 	-lsfml-graphics -lsfml-window -lsfml-system

HEADERS			=	AFigure.hpp \
					Circle.hpp \
					includes.hpp \
					Rectangle.hpp \
					RotMatrix.hpp \
					Triangle.hpp \

SRC				=	AFigure.cpp \
					Circle.cpp \
					Rectangle.cpp \
					RotMatrix.cpp \
					Triangle.cpp \
					main.cpp \

OBJ_DIR = ./bin/
SRC_DIR = ./src/

OBJ_LIST = $(patsubst %.cpp, %.o, $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@clang++ -D_GLIBCXX_DEBUG $(FLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@printf "\nDanone! ✅\n$(NAME) is ready to run! ✅\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@clang++ -c $(FLAGS) -D_GLIBCXX_DEBUG $< -o $@
	@printf "\033[2K\r Compiling... $< ⌛"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@printf " '"$(OBJ_DIR)"' has been deleted. 🗑️\n"

fclean: clean
	@rm -f $(NAME)
	@printf " '"$(NAME)"' has been deleted. 🗑️\n"

re: fclean all

.PHONY: all clean fclean re run
