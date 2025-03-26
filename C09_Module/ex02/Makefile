NAME	= PmergeMe

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRC		= main.cpp RPN.cpp
OBJS	= $(SRC:.cpp=.o)

# Colors
CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
R_GREEN	= \033[0;32m
YELLOW	= \033[1;33m

all: $(NAME)

%.o: %.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ echo "Compiling ${YELLOW}$(NAME)${CLR_RMV}..."
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "${R_GREEN}Container compiled successfully!${CLR_RMV}"

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
