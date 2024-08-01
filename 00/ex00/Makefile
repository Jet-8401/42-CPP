NAME		= megaphone
SRC			= megaphone.cpp
OBJS		= $(SRC=.cpp:.o)

CXX			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
