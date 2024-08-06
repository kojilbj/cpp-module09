CP=c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
NAME=gungy
SRC=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
