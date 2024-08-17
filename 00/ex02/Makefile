NAME		= account
SRC			= Account.cpp tests.cpp
OBJS		= $(SRC:.cpp=.o)

CXX			= c++
CPPFLAGS	= -std=c++98
#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
