NAME		= PmergeMe
SRC			= main.cpp PmergeMe.cpp
OBJS		= $(SRC:.cpp=.o)

CXX			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -O3 -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
