CP=c++
CFLAGS=-Wall -Wextra -Werror
SRCS=main.cpp ClapTrap.cpp FragTrap.cpp
NAME=fragtrap
OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	$(CP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
