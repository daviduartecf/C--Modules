NAME	= unnecessary_violence

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRC_FILES:.c=.o)

# ============================================================================ #
#	COLORS                                                                     #
# ============================================================================ #

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
R_GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN 	= \033[1;36m

# ============================================================================ #
#	RULES                                                                      #
# ============================================================================ #

all: $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	@ echo "Compilating ${YELLOW}$(NAME) ${CLR_RMV}..."
	@ $(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@ echo "${R_GREEN}${GREEN}unnecessary_violence ${R_GREEN} ${GREEN}"
	@ echo "${R_GREEN}by ${GREEN}daduarte ${R_GREEN} ${GREEN}"
	@ echo "${CLR_RMV}"

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)
	@${RM} -f ${OBJS}

re: fclean all

.PHONY: all clean fclean re
