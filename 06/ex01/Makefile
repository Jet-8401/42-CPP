NAME		= serialize
SRC			= main.cpp Serializer.cpp Data.cpp
OBJS		= $(SRC:.cpp=.o)

CXX			= c++
CPPFLAGS	= -O3 -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
