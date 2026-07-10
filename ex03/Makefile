NAME		= materia

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  AMateria.cpp \
			  Ice.cpp \
			  Cure.cpp \
			  Character.cpp \
			  MateriaSource.cpp

HDRS		= AMateria.hpp \
			  Ice.hpp \
			  Cure.hpp \
			  ICharacter.hpp \
			  Character.hpp \
			  IMateriaSource.hpp \
			  MateriaSource.hpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
